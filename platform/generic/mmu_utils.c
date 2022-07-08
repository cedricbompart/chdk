#include "lolevel.h"
#include "mmu_utils.h"

#define SECTION_SIZE (0x100000)
#define L2_LARGEPAGE_MEMTYPE_MASK (0x700c)

// load next word to PC, word aligned
#define LDRW_PC_PC_T2 0xf000f8df

unsigned get_l2_largepage_flags_from_l1_section(unsigned addr,
		unsigned l1tableaddr) {
	// alignment check
	if (l1tableaddr & 0x3fff) {
		return 0xffffffff;
	}
	// sanitize address
	addr &= 0xfff00000;
	unsigned l1at = l1tableaddr;
	if (addr < 0x2000000) {
		return 0xffffffff;
		//l1at = l1tableaddr + 0x4000 + 0x400 + 0x400 + coreid * 0x80;
	}
	unsigned sat = (addr >> 20) << 2;
	unsigned *entry = (unsigned*) (l1at + sat);
	unsigned val = *entry;
	// must be section or supersection
	if ((val & 3) != 2) {
		return 0xffffffff;
	}
	unsigned retval = 0;
	retval |= (val & 0x38000) >> 6; // nG, S, APX bits
	retval |= (val & 0x7000); // TEX bits (mem type, cacheability)
	retval |= (val & 0x10) << 11; // XN bit
	retval |= (val & 0xc); // C, B bits (mem type, cacheability)
	retval |= (val & 0xc00) >> 6; // AP bits
	return retval;
}

int split_l1_supersection(unsigned addr, unsigned l1tableaddr) {
	// alignment check
	if (l1tableaddr & 0x3fff) {
		return -1;
	}
	// sanitize address
	addr &= 0xff000000;
	unsigned l1at = l1tableaddr;
	if (addr < 0x2000000) {
		return -3;
		//l1at = l1tableaddr + 0x4000 + 0x400 + 0x400 + coreid * 0x80;
	}
	unsigned modat = (addr >> 24) << 6;
	unsigned n, m = 0;
	for (n = 0; n < 16; n++) {
		unsigned *entry = (unsigned*) (l1at + modat + n * 4);
		unsigned val = *entry;
		// leave when not supersection
		if ((val & 0x40003) != 0x40002) {
			return -2;
		}
		*entry = (val & 0xfffbffff) | m;
		m += SECTION_SIZE;
	}
	return 0;
}

int assign_l2_table_to_l1_section(unsigned addr, unsigned l1tableaddr,
		unsigned l2tableaddr) {
	// alignment check
	if (l1tableaddr & 0x3fff || l2tableaddr & 0x3ff) {
		return -1;
	}
	// sanitize address
	addr &= 0xfff00000;
	unsigned l1at = l1tableaddr;
	if (addr < 0x2000000) {
		return -1;
		//l1at = l1tableaddr + 0x4000 + 0x400 + 0x400 + coreid * 0x80;
	}
	unsigned modat = (addr >> 20) << 2;
	unsigned *entry = (unsigned*) (l1at + modat);
	unsigned val = *entry;
	// must be section or L2 reference, not supersection
	if ((val & 0x40003) == 0x40002) {
		return -2;
	}
	*entry = l2tableaddr | 1;
	return 0;
}

int create_l2_table(unsigned addr, unsigned l2tableaddr, unsigned flags) {
	// alignment check
	if (l2tableaddr & 0x3ff) {
		return -1;
	}
	// sanitize address
	addr &= 0xfff00000;
	// set 'large page' flag
	flags = (flags & 0xfffffffc) | 1;
	unsigned m, n;
	for (n = 0; n < SECTION_SIZE; n += PAGE_SIZE) {
		for (m = 0; m < 16; m++) {
			unsigned *entry = (unsigned*) (l2tableaddr + m * 4);
			*entry = (addr + n) | flags;
		}
		l2tableaddr += 0x40;
	}
	return 0;
}

int replace_large_page_in_l2_table(unsigned addr, unsigned replacement,
		unsigned l2tableaddr, unsigned flags) {
	// alignment check
	if (l2tableaddr & 0x3ff || addr & 0xffff || replacement & 0xffff) {
		return -1;
	}
	// set 'large page' flag
	flags = (flags & 0xfffffffc) | 1;
	addr = (addr >> 16) & 0xf;
	l2tableaddr += addr * 0x40;
	unsigned m;
	for (m = 0; m < 16; m++) {
		unsigned *entry = (unsigned*) (l2tableaddr + m * 4);
		*entry = replacement | flags;
	}
	return 0;
}

void replace_rom_page(unsigned romaddr, unsigned ramaddr, unsigned l2addr,
		unsigned flags) {
	// copy 64kB "large" page to RAM
	_memcpy((void*) ramaddr, (void*) romaddr, PAGE_SIZE);
	// make L2 table entry point to copied ROM content
	replace_large_page_in_l2_table(romaddr, ramaddr, l2addr, flags);
}

void replace_section_with_l2_tbl(unsigned romaddr, unsigned l1addr,
		unsigned l2addr, unsigned flags) {
	// make a L2 table
	create_l2_table(romaddr, l2addr, flags);
	// assign the new L2 table to the desired section of ROM (covers 1MB)
	assign_l2_table_to_l1_section(romaddr, l1addr, l2addr);
}

void place_fw_hook_t2_64b(unsigned orig, void *new, unsigned origram) {
	unsigned *newa = (unsigned*) ((unsigned) new & 0xfffffffc);
	*newa = *(unsigned*) orig;
	*(newa + 1) = *(unsigned*) (orig + 4);
	*(newa + 2) = LDRW_PC_PC_T2;
	*(newa + 3) = (orig + 8) | 1;
	*(unsigned*) (origram) = LDRW_PC_PC_T2;
	*(unsigned*) (origram + 4) = ((unsigned) new + 16) | 1;
}

void place_fw_patch_t2_64b(void *new, unsigned origram) {
	*(unsigned*) (origram) = LDRW_PC_PC_T2;
	*(unsigned*) (origram + 4) = ((unsigned) new) | 1;
}

