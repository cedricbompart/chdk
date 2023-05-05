#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "kbd_common.h"
#include "levent.h"

#include "kbd.h"

static long kbd_status = 0;
static long kbd_mod_prev_1 = 0xffffffff;

ssymkeys symkeys[] = {
		{ 0x00020000, 0, 0x9a1, 0x9a2 }, // KEY_SHOOT_HALF
		{ 0x00040000, 0, 0x9a3, 0x9a4 }, // KEY_SHOOT_FULL_ONLY
		{ 0, 0, 0, 0 } };

// use by kbd_common
long kbd_new_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_prev_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
long kbd_mod_state[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

KeyMap keymap[] = { { 0, KEY_PLAYBACK, 0x00000002 }, // Found @0xe05e4cdc, levent 0x101 (uses inverted logic in physw_status)
		{ 0, KEY_WIFI, 0x00000004 }, // Found @0xe05e4ce4, levent 0x103 (uses inverted logic in physw_status)
		{ 1, KEY_MENU, 0x00000080 }, // Found @0xe05e4d1c, levent 0x15
		{ 1, KEY_UP, 0x00000100 }, // Found @0xe05e4d24, levent 0x06
		{ 1, KEY_DOWN, 0x00000200 }, // Found @0xe05e4d2c, levent 0x07
		{ 1, KEY_RIGHT, 0x00000400 }, // Found @0xe05e4d34, levent 0x09
		{ 1, KEY_LEFT, 0x00000800 }, // Found @0xe05e4d3c, levent 0x08
		{ 1, KEY_SET, 0x00001000 }, // Found @0xe05e4d44, levent 0x0a
		{ 1, KEY_ERASE, 0x00008000 }, // Found @0xe05e4d5c, levent 0x0b
		{ 2, KEY_VIDEO, 0x00002000 }, // Found @0xe05e4db4, levent 0x02
		{ 0, 0, 0 } };

/**
 * @header usb_remote.h
 */
int get_usb_bit() {
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return ((usb_physw[USB_IDX] & USB_MASK) == USB_MASK);
}

/**
 * @header kbd_common.h
 */
void kbd_fetch_data(long *dst) {
	_GetKbdState(dst);
	_kbd_read_keys_r2(dst);
}

void my_kbd_read_keys() {
	kbd_prev_state[0] = kbd_new_state[0];
	kbd_prev_state[1] = kbd_new_state[1];
	kbd_prev_state[2] = kbd_new_state[2];

	// note assumed kbd_pwr_on has been called if needed
	kbd_fetch_data(physw_status); // has to be physw_status

	kbd_new_state[0] = physw_status[0] ^ KEYS_INV0; // invert button(s) for CHDK use
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];

	static long kbd_status_prev = 0;
	kbd_status = kbd_process();

	if (kbd_status == 0) {
		// handle sw1 and sw2
		if (kbd_status_prev != 0) {
			int n = 0;
			while (symkeys[n].bit) {
				if (symkeys[n].chdkstate) {
					PostLogicalEventToUI(symkeys[n].unpresse, 0);
					symkeys[n].chdkstate = 0;
				}
				n++;
			}
			_post_msg_3_to_physw_releasesw();
		}

	} else { // override keys
		// invert button(s) before writing back to physw_status
		physw_status[0] = ((kbd_new_state[0] & (~KEYS_MASK0))
				| (kbd_mod_state[0] & KEYS_MASK0)) ^ KEYS_INV0;

		physw_status[1] = (kbd_new_state[1] & (~KEYS_MASK1))
				| (kbd_mod_state[1] & KEYS_MASK1);

		physw_status[2] = (kbd_new_state[2] & (~KEYS_MASK2))
				| (kbd_mod_state[2] & KEYS_MASK2);

		// handle sw1 and sw2 from kbd_mod_state, emit events
		// TODO: event order won't necessarily match a real hw sequence (shoot_half might be released sooner than shoot_full and so on)
		int n = 0;
		while (symkeys[n].bit) {
			long bit = symkeys[n].bit;
			if ((kbd_mod_state[1] & bit) < (kbd_mod_prev_1 & bit)) {
				PostLogicalEventToUI(symkeys[n].presse, 0);
				symkeys[n].chdkstate = 1;
			} else if ((kbd_mod_state[1] & bit) > (kbd_mod_prev_1 & bit)) {
				PostLogicalEventToUI(symkeys[n].unpresse, 0);
				symkeys[n].chdkstate = 0;
			}
			n++;
		}
		kbd_mod_prev_1 = kbd_mod_state[1];
	}
	kbd_status_prev = kbd_status;

	// USB and SD read-only are standard
	kbd_update_physw_bits();
}

long __attribute__((naked,noinline)) wrap_kbd_p1_f() {
	asm volatile(
			"push    {r1-r7, lr}\n"
			"movs    r4, #0\n"
			"bl      my_kbd_read_keys\n"
			"b       _kbd_p1_f_cont\n"
	);

	return 0;
}

/**
 * @header lolevel.h
 */
void __attribute__((naked,noinline)) mykbd_task() {
	// initialize our own kbd_new_state[] array with the current physical status
	kbd_new_state[0] = physw_status[0] ^ KEYS_INV0;
	kbd_new_state[1] = physw_status[1];
	kbd_new_state[2] = physw_status[2];

	while (physw_run) {
		_SleepTask(physw_sleep_delay);

		if (wrap_kbd_p1_f() == 1) {
			_kbd_p2_f();
		}
	}

	_ExitTask();
}
