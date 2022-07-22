#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

#include "lib.h"

void shutdown_soft() {
	_PostLogicalEventForNotPowerType(0x1005, 0);
}

/**
 * @see main startup
 */
void shutdown() {
	while (1)
		_SleepTask(500);
}

/**
 * @header debug_led.h
 */
void debug_led(int state) {
	volatile long *p = (void*) LED;
	*p = ((state) ? 0x4d0002 : 0x4c0003);
}

/**
 * Power Led = first entry in table (led 0).
 * AF Assist Lamp = second entry in table (led 1).
 *
 * @header debug_led.h
 */
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
	static char led_table[2] = { 0, 4 };
	_LEDDrive(led_table[led % sizeof(led_table)], state <= 1 ? !state : state);
}

/**
 * @header keyboard.h
 */
void JogDial_CW(void) {
	_PostLogicalEventToUI(0x872, 1); // RotateJogDialRight
}

/**
 * @header keyboard.h
 */
void JogDial_CCW(void) {
	_PostLogicalEventToUI(0x873, 1); // RotateJogDialLeft
}

/**
 * @header properties.h
 */
int get_flash_params_count(void) {
	return 0x113; // see j_PTM_BackupUIProperty_FW
}

/**
 * @header raw_buffer.h
 */
char* hook_raw_image_addr() {
	if (current_raw_addr) {
		return current_raw_addr;
	}
	return (char*) 0x48c57740; // TODO
}

/**
 * @header viewport.h
 */
void vid_bitmap_refresh() {
	_VTMLock();
	_transfer_src_overlay(active_bitmap_buffer & 1);
	_VTMUnlock();
}

/**
 * @header viewport.h
 */
void* vid_get_viewport_live_fb() {
	int i;
	for (i = 0; i < 4; i++) {
		if (current_viewport_buffer == viewport_buffers[i]) {
			return viewport_buffers[(i + 1) & 3];
		}
	}
	return 0;
}

/**
 * @header viewport.h
 */
void* vid_get_bitmap_fb() {
	// for live view send YUV instead of RGBA
	return bitmap_buffer[active_bitmap_buffer & 1];
}

/**
 * @header viewport.h
 */
void* vid_get_viewport_fb_d() {
	return current_fb_d;
}

/**
 * @header viewport.h
 */
void* vid_get_viewport_fb() {
	return viewport_buffers[0];
}

/**
 * @header viewport.h
 */
long vid_get_viewport_height() {
	if (camera_info.state.mode_play) {
		return CAM_SCREEN_HEIGHT;
	}
	return _GetVRAMVPixelsSize();
}

/**
 * @header viewport.h
 */
int vid_get_viewport_type() {
	return LV_FB_YUV8B;
}

/**
 * @header viewport.h
 */
void* vid_get_opacity_active_buffer() {
	return opacity_buffer[active_bitmap_buffer & 1];
}

/**
 * @header sd_card.h
 */
char* camera_jpeg_count_str() {
	return jpeg_count_str;
}
