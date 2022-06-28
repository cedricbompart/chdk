#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H

// plaform specific keyboard defines, see core/kbd_common.c for documentation
// non-standard key state update to handle inverted keys, etc

// from signature finder
#define SD_READONLY_FLAG    0x00000020 // Found @0xe05e4d0c, levent 0x30a
#define SD_READONLY_IDX     1
#define USB_MASK            0x20000000 // Found @0xe05e4e2c, levent 0x302
#define USB_IDX             2
#define BATTCOVER_FLAG      0x01000000 // Found @0xe05e4cf4, levent 0x305
#define BATTCOVER_IDX       0
#define HOTSHOE_FLAG        0x00010000 // Found @0xe05e4dc4, levent 0x304
#define HOTSHOE_IDX         2

// handwrittten
#define KEYS_MASK0 (0x00000006) // TODO: check
#define KEYS_MASK1 (0x00063f80) // TODO: check
#define KEYS_MASK2 (0x00000000) // TODO: check

#endif
