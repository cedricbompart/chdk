#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup()
{
    long *bss = &link_bss_start;

    // sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
    started();
    shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
    *bss++ = 0;
    boot();
}

// Focus length table in firmware @ 0xfffee354
#define NUM_FL      195 // 195 zoom steps
#define NUM_DATA    2   // 2 words each entry, FL in MM*1000, 100
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 4.3         24      ( 24/4.3) * 43 = 240  (min FL)
// 180.6     1008    (1008/180.6) * 43 = 240  (max FL)
#define CF_EFL      240
#define CF_EFL_DIV  43

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    return focus_len_table[zp*NUM_DATA];
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/focus_len_table[0];
}

// uses NB-6LH
long get_vbatt_min()
{
    return 3250;
}

long get_vbatt_max()
{
    return 4065;
}
