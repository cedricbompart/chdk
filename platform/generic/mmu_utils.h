/**
 * Cortex A9
 *
 * Smallest possible L1 chunk is 1MB (a supersection is 16MB).
 * A L2 table is for splitting a 1MB chunk into 64kB or even 4kB chunks.
 * The fewer/larger chunks the better performance.
 *
 * The below translation table manipulation functions assume the Canon FW table arrangement:
 * - 0x4000 bytes of L1 table for both cores, describing addresses from 32MB upwards
 * - 0x400 bytes of L2 table describing address range 0...1024kB, core0
 * - 0x400 bytes of L2 table describing address range 0...1024kB, core1
 * - 0x80 bytes of L1 table describing address range 0...32MB, core0
 * - 0x80 bytes of L1 table describing address range 0...32MB, core1
 *
 * @note manipulation of the first 32MB is not supported (those are core-specific and RAM anyway).
 */

#ifndef MMU_UTILS_H
#define MMU_UTILS_H

#define PAGE_SIZE (0x10000)

#define B_INSTR_ARM(pc,dest) \
    ( 0xEA000000 \
    | ((( ((unsigned)dest) - ((unsigned)pc) - 8 ) >> 2) & 0x00FFFFFF) \
    )

// thumb-2 32-bit bl instruction (verification pending)
#define BL_INSTR_T1(addr, target) \
    ( 0xd000f000 \
    | (( (((unsigned)target-(unsigned)addr-4)>>1) & 0x7ff) << 16) \
    | ( (((unsigned)target-(unsigned)addr-4)>>12) & 0x3ff) \
    | ( (((unsigned)target-(unsigned)addr-4)&0x80000000)?0x400:0) \
    | (( (((unsigned)target-(unsigned)addr-4)&0x80000000) == \
      ((((unsigned)target-(unsigned)addr-4)&0x400000)<<9))?0x8000000:0) \
    | (( (((unsigned)target-(unsigned)addr-4)&0x80000000) == \
      ((((unsigned)target-(unsigned)addr-4)&0x800000)<<8))?0x20000000:0) \
    )

// thumb-2 16-bit branch instruction, t2 encoding
#define B_INSTR_T2(addr, target) \
    ( 0xe000 \
    | ( (((unsigned)target - (unsigned)addr - 4) >> 1) & 0x7ff ) \
    )

// thumb-2 32-bit branch instruction (verification pending)
#define B_INSTR_T4(addr, target) \
    ( 0x9000f000 \
    | (( (((unsigned)target-(unsigned)addr-4)>>1) & 0x7ff) << 16) \
    | ( (((unsigned)target-(unsigned)addr-4)>>12) & 0x3ff) \
    | ( (((unsigned)target-(unsigned)addr-4)&0x80000000)?0x400:0) \
    | (( (((unsigned)target-(unsigned)addr-4)&0x80000000) == \
      ((((unsigned)target-(unsigned)addr-4)&0x400000)<<9))?0x8000000:0) \
    | (( (((unsigned)target-(unsigned)addr-4)&0x80000000) == \
      ((((unsigned)target-(unsigned)addr-4)&0x800000)<<8))?0x20000000:0) \
    )

/**
 * Retrieves L1 translation table flags in L2 table large page entry format.
 *
 * @param addr        address of source virtual memory chunk (section or supersection in L1 table)
 * @param l1tableaddr physical address of Canon-style L1 table (the 16kB aligned main L1 table at its start, to be exact)
 * @return 0xffffffff in case of inappropriate table address or unexpected L1 table content, otherwise the flags are returned
 */
unsigned get_l2_largepage_flags_from_l1_section(unsigned addr,
		unsigned l1tableaddr);

/**
 * Split a 16MB supersection into 16 sections (in place), so that L2 tables can be assigned to them.
 *
 * @param addr        address of 16MB chunk of virtual memory
 * @param l1tableaddr physical address of Canon-style L1 table (the 0x4000-byte-aligned main L1 table at its start, to be exact)
 * @return nonzero in case of inappropriate table address or missing supersection
 */
int split_l1_supersection(unsigned addr, unsigned l1tableaddr);

/**
 * Assign a L2 table to a 1MB section of virtual address range, usually requires previous use of <code>split_l1_supersection</code>.
 *
 * @apram addr        address of virtual memory chunk (16MB, aligned to 16MB)
 * @param l1tableaddr physical address of Canon-style L1 table (the 16kB aligned main L1 table at its start, to be exact)
 * @param l2tableaddr physical address of L2 table (1024 bytes, 1024-byte alignment)
 * @return nonzero in case of inappropriate table address or unexpected L1 table content
 */
int assign_l2_table_to_l1_section(unsigned addr, unsigned l1tableaddr,
		unsigned l2tableaddr);

/**
 * Create L2 table for 1MB memory at addr, with large pages (64kB).
 *
 * @param addr        address of virtual memory chunk (1MB, aligned to 1MB)
 * @param l2tableaddr physical address of L2 table (1024 bytes, 1024-byte alignment)
 * @param flags       flags in the new page table entries (should probably match those in respective part of L1 table)
 * @return nonzero in case of inappropriate table address
 */
int create_l2_table(unsigned addr, unsigned l2tableaddr, unsigned flags);

/**
 * Patch one large (64kB) page in L2 table to point to a different part of physical memory.
 *
 * @param addr        offset of virtual memory chunk (64kB, aligned to 64kB) inside the 1MB range of L2 table
 * @param replacement address of physical memory chunk (64kB, aligned to 64kB)
 * @param l2tableaddr physical address of L2 table (1024 bytes, 1024-byte alignment)
 * @param flags       flags in the new page table entries (should probably match those in respective part of L1 table)
 * @return nonzero in case of inappropriate addresses
 */
int replace_large_page_in_l2_table(unsigned addr, unsigned replacement,
		unsigned l2tableaddr, unsigned flags);

/**
 * Replace a 64kB large ROM page with its RAM copy.
 *
 * @param romaddr start of ROM page (64kB aligned), has to fall within the range of L2 table
 * @param ramaddr suitable 64kB aligned RAM address
 * @param l2addr  existing L2 table's address
 * @param flags   L2 table entry flags
 */
void replace_rom_page(unsigned romaddr, unsigned ramaddr, unsigned l2addr,
		unsigned flags);

/**
 * Replace L1 section with newly created L2 table.
 *
 * @param romaddr start of ROM section (1024kB aligned)
 * @param l1addr  address of Canon-style MMU tables
 * @param l2addr  L2 table to be placed at this address (0x400-byte alignment)
 * @param flags   L2 table entry flags
 */
void replace_section_with_l2_tbl(unsigned romaddr, unsigned l1addr,
		unsigned l2addr, unsigned flags);

/**
 * Function to place a hook, requires 32-bit alignment, assumes thumb2 code.
 * The hook function needs 4 words space at its start after which the hook code must be placed.
 * When the hook is finished, jumping to start takes care of returning to "ROM".
 * Hook code must save and restore registers (either everything or according to context).
 * The replaced two words must contain an integer number of instructions, must not contain branch target also,
 * the copied instructions must not depend on PC (such as branches, ldr, adr, etc).
 *
 * @param orig    original "ROM" address, must actually be RAM mapped there
 * @param new     address of hook code in RAM
 * @param origram RAM representation of 'orig' (that can be written)
 */
void place_fw_hook_t2_64b(unsigned orig, void *new, unsigned origram);

/**
 * Version of <code>place_fw_hook_t2_64b</code> for non-hook use.
 *
 * @param new     address of replacement code in RAM
 * @param origram address of code in RAM, typically in a copied 64kB ROM page
 */
void place_fw_patch_t2_64b(void *new, unsigned origram);

#endif
