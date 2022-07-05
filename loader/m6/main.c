#include "../generic/check_compat.c"

#define LED 0xD20801E0

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

typedef struct {
	const char *str;
	const char *fw_str;
	void (*dcc_by_mva)(void *addr, long len);
	void (*ici_by_mva)(void *addr, long len);
	void (*core_unblock)(unsigned coreid);
} ld_ver_t;

ld_ver_t fw = { "GM1.01A",  //
		(void*) 0xE03CFDF0, //
		(void*) 0xE036BA79, // dcache_clean_range
		(void*) 0xE036BB4D, // icache_flush_range
		(void*) 0xE0523D73  //
		};

int __attribute__((naked)) get_core_id() {
	asm volatile (
			"mrc     p15, #0, r0, c0, c0, #5\n"
			"ands    r0, #0xf\n"
			"bx      lr\n"
	);
}

/**
 * @see loader entry
 */
void __attribute__((noreturn)) my_restart() {
	void (*cont)(int coreid) = (void*)(MEMISOSTART | 1);
	int coreid = get_core_id();

	if (!coreid) { /* core 0 only */
		check_compat();

		long *dst = (long*)MEMISOSTART;
		const long *src = blob_chdk_core;
		long length = (blob_chdk_core_size + 3) >> 2;

		core_copy(src, dst, length);

		set_led(LED, 1, LEDCNTRL_NEW4); /* green LED on */

		fw.dcc_by_mva(dst, length<<2);
		fw.ici_by_mva(dst, length<<2);
		fw.core_unblock(1); /* core 1 */
	}

	cont(coreid);
	while(1);
}
