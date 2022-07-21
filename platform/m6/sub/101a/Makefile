OBJS=boot.o stubs_auto.o stubs_entry.o stubs_entry_2.o mmu_utils.o debug.o
STUBS_AUTO_DEPS=boot.c

include ../../../makefile_sub.inc

mmu_utils.o: $(platform)/generic/mmu_utils.c
	@echo $< '->' $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<