#include "stubs_asm.h"

DEF_CONST(uiprop_count,                     0x000000e8) // found 0x0xe025db4a

FAKEDEF(focus_busy,                         1)
FAKEDEF(zoom_busy,                          1)
FAKEDEF(canon_shoot_menu_active,            1)

DEF(current_fb_d,                           0x0000fd84) // found 0xe00c0ae2 (0xfd58 + 0x2c)
DEF(recreview_hold,                         0x99e8) // found 0xe033c384 (0x9998 + 0x50)
DEF(simple_movie_status,                    0xb464) // found 0xe00dbb72 (0xb390 + 0x80 + 0x54)
DEF(current_viewport_buffer,                0x00008870) // found 0xe03676da (0x8848 + 0x20 + 0x8)
DEF(viewport_buffers,                       0xe05e3e08)

IGNORE(bitmap_buffer)
