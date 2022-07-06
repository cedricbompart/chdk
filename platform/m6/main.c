#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

#include "main.h"

void startup(int core) {
	if (!core) { // core 0 only
		long *bss = &link_bss_start;
		// sanity check
		if ((long) &link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
			while (1)
				;
		}
		// initialize .bss segment
		while (bss < &link_bss_end)
			*bss++ = 0;
	}
	boot();
}

/**
 * @header shooting.h
 */
int get_effective_focal_length(__attribute__ ((unused))int zp) {
	return _GetLensCurrentFocalLength() * 1600;
}

/**
 * @header shooting.h
 */
int get_focal_length(__attribute__ ((unused))int zp) {
	return _GetLensCurrentFocalLength() * 1000;
}

/**
 * @header shooting.h
 */
int get_zoom_x(__attribute__ ((unused))int zp) {
	// TODO: why the 100 ?
	return _GetLensCurrentFocalLength() * 100
			/ (_GetLensWideFocalLength() * 100);
}

/**
 * @header battery.h
 */
long get_vbatt_min() {
	return 2 * 3300;
}

/**
 * @header battery.h
 */
long get_vbatt_max() {
	return 2 * 4168;  // 4168 original battery just charged ASM1989
}
