#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1
#define NR_AUTO (-1)

#include "../../../generic/capt_seq.c"

char *current_raw_addr;

void captseq_raw_addr_init_my(char **ptr) {
	if ((unsigned) ptr < 0x1000) {
		current_raw_addr = NULL;
		return;
	}
	current_raw_addr = *(ptr + 0x40 / 4); // 0xe005211a
}

void clear_current_raw_addr(void) {
	current_raw_addr = NULL;
}
