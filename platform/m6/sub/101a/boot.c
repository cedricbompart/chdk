#include "cache.h"

#include "../../../generic/mmu_utils.h"
#include "boot.h"
#include "debug.h"

#define CHDK_MMUTBL_START 0xdffda400
#define CHDK_PAGES_START  0x11d0000
#define CANON_TABLES_AT   0xdffc0000

static int no_chdk_please = 0;

void CreateTask_spytask() {

}

void startup_mode_fix(void) {
	int startupmode = *(int*) 0x9eb0;
	switch (startupmode) {
	case 0x1000000: // rec
		break;
	default:
		no_chdk_please = 1;
	}
}

void __attribute__((naked,noinline,aligned(4))) patch_E0020668() {
	asm volatile (
			"bl         CreateTask_spytask\n"
			"bl         sub_E02796AE\n" // execute overwritten instruction
			"bl         sub_E010E954\n"// execute overwritten instruction
			"ldr        pc, =0xe0020671\n"// -> back to ROM
	);
}

void plant_hacks_for_e0020000(unsigned addr) {
	// switch off card instead of exec'ing diskboot
	*(unsigned*) (addr + 0x0644) = BL_INSTR_T1(0xE0020644, 0xE04B3F3A);
	// conditionally start SpyTask
	place_fw_patch_t2_64b(patch_E0020668, addr + 0x0668);
}

void __attribute__((naked,noinline,aligned(4))) patch_E0079DA4() {
	asm volatile (
			"bl         sub_e007006e\n" // startup mode inquiry
			"bl         startup_mode_fix\n"// +
			"bl         sub_e007a49c\n"// <kbd_read_keys>
			"ldr        r3, =0x6a1a8\n"
			"ldr        pc, =0xe0079dad\n"// -> back to ROM
	);
}

void plant_hacks_for_e0070000(unsigned addr) {
	// insert startup mode handling
	place_fw_patch_t2_64b(patch_E0079DA4, addr + 0x9DA4);
	// nop (benign 16-bit instruction, added to replace 1st half of destroyed 32-bit instruction)
	*(unsigned short*) (addr + 0x9DA2) = 0xbf00;
}

// following should be integrated in dcache_clean_all
void l2_cache_sync(void) {
	*(int*) 0xc1100730 = 0;
}

void setup_mmu_for_chdk(int core) {
	if (core == 0) {
		unsigned l2adr = CHDK_MMUTBL_START;
		unsigned rompagecopy = CHDK_PAGES_START;

		// at the beginning, ROM tables are in use
		// first, make a fresh copy of the ROM translation tables to its usual place in RAM
		_make_copy_of_canon_mmutables(CANON_TABLES_AT);
		// get flags of ROM area
		unsigned flags = get_l2_largepage_flags_from_l1_section(ROMBASEADDR,
		CANON_TABLES_AT);

		// split first 16MB of ROM area into sections
		split_l1_supersection(ROMBASEADDR, CANON_TABLES_AT);

		{
			// create L2 table for following 1MB ROM section
			replace_section_with_l2_tbl(0xe0000000, CANON_TABLES_AT, l2adr,
					flags);

			replace_rom_page(0xe0020000, rompagecopy, l2adr, flags);
			plant_hacks_for_e0020000(rompagecopy);
			rompagecopy += PAGE_SIZE;

			replace_rom_page(0xe0070000, rompagecopy, l2adr, flags);
			plant_hacks_for_e0070000(rompagecopy);
			rompagecopy += PAGE_SIZE;

			l2adr += 0x400;
		}
	}
	icache_flush_all();
	dcache_clean_all();
	l2_cache_sync();
	_set_canon_mmu_tables_to(CANON_TABLES_AT);
}

void __attribute__((naked,noinline)) park_current_core_then_continue() {
	asm volatile(
			"    movs      r4, r0\n"
			"    movw      r0, #0xA\n"
			"    movt      r0, #0\n"
			"    bl        park_current_core\n"
			"    bx        r4\n"
			"park_current_core:\n"
			"    mov       r3, lr\n"
			"    bl        disable_branch_prediction\n"
			"pcr1:\n"
			"    dsb       sy\n"
			"    wfi       \n"
			"    movw      r1, #0x10C\n"
			"    movt      r1, #0xC100\n"
			"    ldr       r2, [r1, #0]\n"
			"    subs      r1, r2, r0\n"
			"    movw      r1, #0x110\n"
			"    movt      r1, #0xC100\n"
			"    str       r2, [r1, #0]\n"
			"    bne.n     pcr1\n"
			"    dsb       sy\n"
			"    bl        enable_branch_prediction\n"
			"    bx        r3\n"
			"disable_branch_prediction:\n"
			"    mrc       p15, 0, r1, c1, c0, 0\n"
			"    bic.w     r1, r1, #0x800\n"
			"    mcr       p15, 0, r1, c1, c0, 0\n"
			"    dsb       sy\n"
			"    isb       sy\n"
			"    bx        lr\n"
			"enable_branch_prediction:\n"
			"    mcr       p15, 0, r1, c7, c5, 6\n"
			"    dsb       sy\n"
			"    mrc       p15, 0, r1, c1, c0, 0\n"
			"    orr.w     r1, r1, #0x800\n"
			"    mcr       p15, 0, r1, c1, c0, 0\n"
			"    dsb       sy\n"
			"    isb       sy\n"
			"    bx        lr\n"
	);
}

void __attribute__((naked,noinline)) sub_e00200f8_my() {
	//  capdis -f=chdk -jfw -stubs -s=0xe00200f9 -c=2 PRIMARY.BIN 0xe0000000
	asm volatile (
			"    push    {r4, r5, r6, lr}\n"
			"    ldr     r0, =0x002b413f\n" // heap start, modify here
			"    ldr     pc, =0xe00200fd\n"// Continue in firmware
			".ltorg\n"
	);
}

/**
 * @see main startup
 */
void __attribute__((naked,noinline)) boot() {
	// capdis -f=chdk -stubs -s=0xe0020011 -c=6 PRIMARY.BIN 0xe0000000
	asm volatile (
			"    ldr     r0, =0xe0020200\n"
			"    mcr     p15, #0, r0, c12, c0, #0\n"
			"    isb     sy\n"
			"    movw    r0, #0x2000\n"
			"    movt    r0, #0\n"
			"    mov     sp, r0\n"
	);

	// handle 2 cores
	asm volatile (
			"    mrc     p15, #0, r0, c0, c0, #5\n"
			"    ands    r0, #0xf\n"
			"    beq     loc_boot\n"
			"    adr     r0, loc_boot\n"
			"    orr     r0, #1\n"
			"    bl      park_current_core_then_continue\n"
			"loc_boot:\n"
			"    mrc     p15, #0, r0, c0, c0, #5\n"
			"    ands    r0, #0xf\n"
			"    bl      setup_mmu_for_chdk\n"
	);

	// capdis -f=chdk -stubs -s=0xe0020025 -c=59 PRIMARY.BIN 0xe0000000
	asm volatile (
			"    mrc     p15, #0, r5, c0, c0, #5\n"
			"    ands    r0, r5, #0xf\n"
			"    bne     loc_e0020032\n"
			"    b.w     loc_e002003c\n"
			"loc_e0020032:\n"
			"    b.w     sub_e00200f8_my\n"
			"loc_e002003c:\n"
			"    ldr     r0, =0xe115d544\n"
			"    ldr     r1, =0x00008000\n"
			"    ldr     r3, =0x00068524\n"
			"loc_e0020042:\n"
			"    cmp     r1, r3\n"
			"    itt     lo\n"
			"    ldrlo   r2, [r0], #4\n"
			"    strlo   r2, [r1], #4\n"
			"    blo     loc_e0020042\n"
			"    ldr     r1, =0x002b4138\n"
			"    mov.w   r2, #0\n"
			"loc_e0020056:\n"
			"    cmp     r3, r1\n"
			"    it      lo\n"
			"    strlo   r2, [r3], #4\n"
			"    blo     loc_e0020056\n"
			"    ldr     r0, =0xe11bda68\n"
			"    ldr     r1, =0x01900000\n"
			"    ldr     r3, =0x01901444\n"
			"loc_e0020066:\n"
			"    cmp     r1, r3\n"
			"    itt     lo\n"
			"    ldrlo   r2, [r0], #4\n"
			"    strlo   r2, [r1], #4\n"
			"    blo     loc_e0020066\n"
			"    ldr     r0, =0x01900000\n"
			"    ldr     r1, =0x00001444\n"
			"    bl      _dcache_clean_by_mva\n"
			"    ldr     r0, =0x01900000\n"
			"    ldr     r1, =0x00001444\n"
			"    bl      _icache_branchpr_invalidate\n"
			"    ldr     r0, =0xe11beeac\n"
			"    ldr     r1, =0xdffc4900\n"
			"    ldr     r3, =0xdffd9ba0\n"
			"loc_e002008a:\n"
			"    cmp     r1, r3\n"
			"    itt     lo\n"
			"    ldrlo   r2, [r0], #4\n"
			"    strlo   r2, [r1], #4\n"
			"    blo     loc_e002008a\n"
			"    ldr     r1, =0xdffd9ba0\n"
			"    mov.w   r2, #0\n"
			"loc_e002009e:\n"
			"    cmp     r3, r1\n"
			"    it      lo\n"
			"    strlo   r2, [r3], #4\n"
			"    blo     loc_e002009e\n"
			"    ldr     r0, =0xdffc4900\n"
			"    ldr     r1, =0x000152a0\n"
			"    bl      _dcache_clean_by_mva\n"
			"    ldr     r0, =0xdffc4900\n"
			"    ldr     r1, =0x000152a0\n"
			"    bl      _icache_branchpr_invalidate\n"
			"    b       loc_e0020032\n"// +
	);

}
