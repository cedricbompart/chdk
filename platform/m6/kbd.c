#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "kbd_common.h"
#include "levent.h"

int get_usb_bit() {
	long usb_physw[3];
	usb_physw[USB_IDX] = 0;
	_kbd_read_keys_r2(usb_physw);
	return ((usb_physw[USB_IDX] & USB_MASK) == USB_MASK);
}

KeyMap keymap[] = {
    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xe05e4cdc, levent 0x101 (uses inverted logic in physw_status)
    { 0, KEY_WIFI            ,0x00000004 }, // Found @0xe05e4ce4, levent 0x103 (uses inverted logic in physw_status)
    { 1, KEY_MENU            ,0x00000080 }, // Found @0xe05e4d1c, levent 0x15
    { 1, KEY_UP              ,0x00000100 }, // Found @0xe05e4d24, levent 0x06
    { 1, KEY_DOWN            ,0x00000200 }, // Found @0xe05e4d2c, levent 0x07
    { 1, KEY_RIGHT           ,0x00000400 }, // Found @0xe05e4d34, levent 0x09
    { 1, KEY_LEFT            ,0x00000800 }, // Found @0xe05e4d3c, levent 0x08
    { 1, KEY_SET             ,0x00001000 }, // Found @0xe05e4d44, levent 0x0a
    { 1, KEY_ERASE           ,0x00008000 }, // Found @0xe05e4d5c, levent 0x0b
    { 2, KEY_VIDEO           ,0x00002000 }, // Found @0xe05e4db4, levent 0x02
    { 0, 0, 0 }
};
