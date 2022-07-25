#ifndef M6_BOOT_H
#define M6_BOOT_H

extern void _set_canon_mmu_tables_to(unsigned addr);
extern void _make_copy_of_canon_mmutables(unsigned dest_addr);
extern int _CreateTask(char *name, int prio, int stack_size, void *entry, int parm);
extern int _PostLogicalEventToUI(int event, int unk);
extern void task_InitFileModules(void);

#endif
