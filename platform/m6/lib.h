#ifndef M6_LIB_H
#define M6_LIB_H

#define LED   0xD20801E0 // green LED on the back
#define CB_W  480
#define CB_H  270

extern int active_bitmap_buffer;
extern void *viewport_buffers[];
extern void *current_viewport_buffer;
extern char *current_raw_addr;
extern void *current_fb_d;
extern char jpeg_count_str[];

extern void _transfer_src_overlay(int);
extern void _VTMLock();
extern void _VTMUnlock();
extern int _GetVRAMVPixelsSize();

char *bitmap_buffer[2] = { (char*) 0x7FE80000, (char*) 0x7FD00000 };
void *opacity_buffer[2] = { (void*) 0x7FC40000, (void*) 0x7FB80000 };

int display_needs_refresh = 0;

unsigned char* chdk_rgba = NULL;

int bm_h = CB_H;

#endif
