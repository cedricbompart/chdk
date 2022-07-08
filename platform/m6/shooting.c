#include "file_counter.h"
#include "camera.h"
#include "time.h"
#include "platform_shooting.h"

/**
 * @header file_counter.h
 */
long get_file_next_counter() {
	return get_file_counter();
}

/**
 * @header file_counter.h
 */
long get_target_file_num() {
	return get_exposure_counter();
}

/**
 * @header file_counter.h
 */
void get_target_dir_name(char *out) {
	if (!out) {
		return;
	}
	extern void _GetImageFolder(char*, int, int, int);
	_GetImageFolder(out, get_file_next_counter(), CAM_DATE_FOLDER_NAMING,
			time(NULL));
}

