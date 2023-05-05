#ifndef M6_LOADER_MAIN_H
#define M6_LOADER_MAIN_H

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

#endif
