#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
                              // corresponds to filewritetask() jump table entries 0-6

/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required
 * name is not currently used
 */
// Copied from G7X port - appears to be the same
typedef struct
{
    int unkn1;
    int file_offset;
    int maybe_full_size;
    int unkn2, unkn3;
    int unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int maybe_seek_flag;
    int unkn5, unkn6;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/

void __attribute__((naked,noinline))
filewritetask()
{
    asm volatile (
            //capdis -f=chdk -s=0xe03af92b -c=42 -stubs PRIMARY.BIN 0xe0000000
            "    ldr     r5, =0x00036344\n"
            "    push    {r3, lr}\n"
            "loc_e03af92e:\n"
            "    movs    r2, #0\n"
            "    mov     r1, sp\n"
            "    ldr     r0, [r5, #0x14]\n"
            "    bl      sub_dffc9de0\n"
            "    cbz     r0, loc_e03af946\n"
            "    movs    r0, #0\n"
            "    movw    r2, #0x405\n"
            "    ldr     r1, =0xe03af9f4\n" //  *"dwFWrite.c"
            "    bl      sub_dffc96f4\n"
            "loc_e03af946:\n"
            "    ldr     r0, [sp]\n"
            "    ldr     r1, [r0]\n"
            "    cmp     r1, #0xd\n"
            "    bhs     loc_e03af92e\n"
            "    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
            "branchtable_e03af952:\n"
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 0)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 1)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 2)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 3)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 4)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 5)
            "    .byte((loc_e03af998 - branchtable_e03af952) / 2)\n" // (case 6)
            "    .byte((loc_e03af99e - branchtable_e03af952) / 2)\n" // (case 7)
            "    .byte((loc_e03af960 - branchtable_e03af952) / 2)\n" // (case 8)
            "    .byte((loc_e03af972 - branchtable_e03af952) / 2)\n" // (case 9)
            "    .byte((loc_e03af992 - branchtable_e03af952) / 2)\n" // (case 10)
            "    .byte((loc_e03af966 - branchtable_e03af952) / 2)\n" // (case 11)
            "    .byte((loc_e03af96c - branchtable_e03af952) / 2)\n" // (case 12)
            ".align 1\n"
            "loc_e03af960:\n"
            "    bl      sub_e03afb30\n"
            "    b       loc_e03af92e\n"
            "loc_e03af966:\n"
            "    bl      sub_e03afb7c\n"
            "    b       loc_e03af92e\n"
            "loc_e03af96c:\n"
            "    bl      sub_e03af6a4_my\n"     // Patched
            "    b       loc_e03af92e\n"
            "loc_e03af972:\n"
            "    ldr     r1, [r0, #4]\n"
            "    mov     r4, r0\n"
            "    ldr     r0, [r5, #8]\n"
            "    movs    r2, #0\n"
            "    bl      sub_e0374088\n"
            "    adds    r0, r0, #1\n"
            "    bne     loc_e03af92e\n"
            "    mov     r1, r4\n"
            "    ldr     r0, =0x09200001\n"
            "    adds    r0, #0x12\n"
            "    str     r0, [r4, #0x14]\n"
            "    movs    r0, #7\n"
            "    bl      sub_e03af62a\n"
            "    b       loc_e03af92e\n"
            "loc_e03af992:\n"
            "    bl      sub_e03afbda\n"
            "    b       loc_e03af92e\n"
            "loc_e03af998:\n"
            "    bl      sub_e03afc4c_my\n"     // Patched
            "    b       loc_e03af92e\n"
            "loc_e03af99e:\n"
            "    bl      sub_e03af7dc_my\n"     // Patched
            "    b       loc_e03af92e\n"
    );
}

void __attribute__((naked,noinline))
sub_e03af6a4_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe03af6a5 -c=126 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r4, r5, r6, r7, r8, sb, lr}\n"
            "    mov     r4, r0\n"

            //hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
            //"  mov   r0, r4\n"      //data block start, commented out as R0 is already holding what we need
            "    bl filewrite_main_hook\n"
            "    mov     r0, r4\n"      //restore register(s)

            "    ldr     r0, [r0, #0x50]\n"
            "    sub     sp, #0x3c\n"
            "    lsls    r1, r0, #0x1f\n"
            "    bne     loc_e03af6b6\n"
            "    lsls    r0, r0, #0x1d\n"
            "    bpl     loc_e03af77a\n"
            "loc_e03af6b6:\n"
            "    ldr     r6, =0x00036344\n"
            "    ldr     r0, [r6, #0x1c]\n"
            "    cbz     r0, loc_e03af6be\n"
            "    blx     r0\n"
            "loc_e03af6be:\n"
            "    add.w   r0, r4, #0x5c\n"
            "    mov     r7, r0\n"
            "    bl      sub_e03753e0\n"
            "    movs    r1, #0\n"
            "    bl      sub_e0036d66\n"
            "    movs    r1, #0\n"
            "    movs    r0, #0x47\n"
            "    bl      sub_e03719e0\n"
            "    ldrb.w  r0, [r4, #0x50]\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_e03af77a\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    bl      sub_e045e5fe\n"
            "    ldr     r1, [r4, #0x50]\n"
            "    movw    r0, #0x301\n"
            "    lsls    r2, r1, #0x1b\n"
            "    bpl     loc_e03af6f2\n"
            "    movs    r0, #9\n"
            "    b       loc_e03af6f8\n"
            "loc_e03af6f2:\n"
            "    lsls    r2, r1, #0x19\n"
            "    bpl     loc_e03af6f8\n"
            "    movs    r0, #1\n"
            "loc_e03af6f8:\n"
            "    lsls    r1, r1, #0x1a\n"
            "    bmi     loc_e03af702\n"
            "    ldr     r1, [r4, #0x58]\n"
            "    cmp     r1, #1\n"
            "    bne     loc_e03af706\n"
            "loc_e03af702:\n"
            "    orr     r0, r0, #0x8000\n"
            "loc_e03af706:\n"
            "    ldr     r5, [r4, #0x10]\n"
            "    mov     sb, r0\n"
            "    mov.w   r2, #0x1b6\n"
            "    mov     r1, r0\n"
            "    mov     r8, r2\n"
            "    mov     r0, r7\n"

//            "    bl      sub_e0373e7a\n"    // Open
            "    bl      fwt_open\n"    // +

            "    adds    r1, r0, #1\n"
            "    bne     loc_e03af756\n"
            "    mov     r0, r7\n"
            "    bl      sub_e0374354\n"
            "    movs    r2, #0xf\n"
            "    mov     r1, r7\n"
            "    mov     r0, sp\n"
            "    blx     sub_dffcc618\n"
            "    movs    r0, #0\n"
            "    movw    r1, #0x41ff\n"
            "    strb.w  r0, [sp, #0xf]\n"
            "    str     r1, [sp, #0x20]\n"
            "    movs    r1, #0x10\n"
            "    strd    r0, r5, [sp, #0x28]\n"
            "    mov     r0, sp\n"
            "    str     r1, [sp, #0x24]\n"
            "    add     r1, sp, #0x20\n"
            "    str     r5, [sp, #0x30]\n"
            "    str     r5, [sp, #0x34]\n"
            "    bl      sub_e040272c\n"
            "    mov     r2, r8\n"
            "    mov     r1, sb\n"
            "    mov     r0, r7\n"
            "    bl      sub_e0373e7a\n"
            "loc_e03af756:\n"
            "    mov     r5, r0\n"
            "    str     r0, [r6, #8]\n"
            "    adds    r0, r0, #1\n"
            "    beq     loc_e03af79a\n"
            "    movs    r2, #0x20\n"
            "    ldr     r0, =0x00218988\n"
            "    mov     r1, r7\n"
            "    blx     sub_dffcc598\n"

            // TODO looks equivalent to G7X, not verified that it's required
            //mod start
            "    LDR     r3, =current_write_ignored\n"
            "    LDR     r3, [r3]\n"
            "    cbnz    r3,loc_C\n" // jump over the next block
            //mod end

            "    ldrb.w  r0, [r4, #0x50]\n"
            "    lsls    r0, r0, #0x18\n"
            "    bpl     loc_e03af77a\n"
            "    ldr     r1, [r4, #0xc]\n"
            "    mov     r0, r5\n"
            "    bl      sub_e037415c\n"
            "    cbz     r0, loc_e03af7ca\n"
            "loc_e03af77a:\n"
            "loc_C:\n"  // +
            "    ldrb.w  r0, [r4, #0x50]\n"
            "    lsls    r0, r0, #0x19\n"
            "    bmi     loc_e03af786\n"
            "    ldr     r0, [r4, #4]\n"
            "    cbz     r0, loc_e03af78e\n"
            "loc_e03af786:\n"
            "    movs    r0, #9\n"
            "    mov     r1, r4\n"
            "    bl      sub_e03af62a\n"
            "loc_e03af78e:\n"
            "    movs    r0, #0\n"
            "    mov     r1, r4\n"
            "loc_e03af792:\n"
            "    add     sp, #0x3c\n"
            "    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
            "    b       sub_e03af62a\n"    // jump to FW
            "loc_e03af79a:\n"
            "    movs    r1, #0\n"
            "    movs    r0, #0x48\n"
            "    bl      sub_e03719e0\n"
            "    mov     r0, r7\n"
            "    bl      sub_e03753e0\n"
            "    ldr     r1, [r6, #0x20]\n"
            "    bl      sub_e0036dc4\n"
            "    ldr     r0, [r6, #0x18]\n"
            "    cmp     r0, #0\n"
            "    beq     loc_e03af7d6\n"
            "    mov     r0, r4\n"
            "    ldr     r5, =0x09200001\n"
            "    mov     r1, r5\n"
            "    bl      sub_e03af5f0\n"
            "    ldr     r1, [r6, #0x18]\n"
            "    add     sp, #0x3c\n"
            "    mov     r0, r5\n"
            "    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
            "    bx      r1\n"
            "loc_e03af7ca:\n"
            "    ldr     r0, =0x09200001\n"
            "    mov     r1, r4\n"
            "    adds    r0, #0x16\n"
            "    str     r0, [r4, #0x14]\n"
            "    movs    r0, #7\n"
            "    b       loc_e03af792\n"
            "loc_e03af7d6:\n"
            "    add     sp, #0x3c\n"
            "    pop.w   {r4, r5, r6, r7, r8, sb, pc}\n"
    );
}

void __attribute__((naked,noinline))
sub_e03afc4c_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe03afc4d -c=64 -stubs PRIMARY.BIN 0xe0000000
            "    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
            "    mov     r5, r0\n"
            "    ldr     r0, [r0]\n"
            "    cmp     r0, #6\n"
            "    bhi     loc_e03afcac\n"
            "    add.w   r0, r5, r0, lsl #3\n"
            "    ldrd    r7, r6, [r0, #0x18]\n"
            "    cbz     r6, loc_e03afcaa\n"
            "    ldr.w   sl, =0x00036344\n"
            "    mov     r4, r6\n"
            "    mov.w   sb, #0x1000000\n"
            "loc_e03afc6c:\n"
            "    ldr     r0, [r5, #4]\n"
            "    cmp     r4, sb\n"
            "    mov     r1, r4\n"
            "    bls     loc_e03afc76\n"
            "    mov     r1, sb\n"
            "loc_e03afc76:\n"
            "    lsls    r2, r0, #8\n"
            "    beq     loc_e03afc88\n"
            "    bic     r0, r0, #0xff000000\n"
            "    rsb.w   r0, r0, #0x1000000\n"
            "    cmp     r1, r0\n"
            "    bls     loc_e03afc88\n"
            "    mov     r1, r0\n"
            "loc_e03afc88:\n"
            "    ldr.w   r0, [sl, #8]\n"
            "    mov     r8, r1\n"
            "    mov     r2, r1\n"
            "    mov     r1, r7\n"

//            "    bl      sub_e037404a\n"    //j_Write_FW
            "    bl      fwt_write\n"   // +

            "    ldr     r1, [r5, #4]\n"
            "    cmp     r8, r0\n"
            "    add     r1, r0\n"
            "    str     r1, [r5, #4]\n"
            "    beq     loc_e03afcc6\n"
            "    adds    r0, r0, #1\n"
            "    beq     loc_e03afcc0\n"
            "    ldr     r0, =0x09200006\n"
            "    adds    r0, #0xf\n"
            "loc_e03afca8:\n"
            "    str     r0, [r5, #0x14]\n"
            "loc_e03afcaa:\n"
            "    b       loc_e03afcba\n"
            "loc_e03afcac:\n"
            "    mov.w   r2, #0x348\n"
            "    ldr     r1, =0xe03afa00\n" //  *"dwFWrite.c"
            "    movs    r0, #0\n"
            "    bl      sub_dffc96f4\n"
            "loc_e03afcba:\n"
            "    movs    r0, #7\n"
            "    mov     r1, r5\n"
            "    b       loc_e03afce6\n"
            "loc_e03afcc0:\n"
            "    ldr     r0, =0x09200006\n"
            "    subs    r0, r0, #1\n"
            "    b       loc_e03afca8\n"
            "loc_e03afcc6:\n"
            "    subs    r4, r4, r0\n"
            "    add     r7, r0\n"
            "    cmp     r4, r6\n"
            "    blo     loc_e03afcdc\n"
            "    movw    r2, #0x372\n"
            "    ldr     r1, =0xe03afa00\n" //  *"dwFWrite.c"
            "    movs    r0, #0\n"
            "    bl      sub_dffc96f4\n"
            "loc_e03afcdc:\n"
            "    cmp     r4, #0\n"
            "    bne     loc_e03afc6c\n"
            "    ldr     r0, [r5]\n"
            "    mov     r1, r5\n"
            "    adds    r0, r0, #1\n"
            "loc_e03afce6:\n"
            "    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
            "    b       sub_e03af62a\n"    // jump to FW
    );
}

void __attribute__((naked,noinline))
sub_e03af7dc_my() {
    asm volatile (
            //capdis -f=chdk -s=0xe03af7dd -c=140 -stubs PRIMARY.BIN 0xe0000000
            "    push    {r4, r5, r6, r7, lr}\n"
            "    mov     r4, r0\n"
            "    ldr     r0, [r0, #0x50]\n"
            "    sub     sp, #0x3c\n"
            "    ldr     r5, =0x00036344\n"
            "    add.w   r7, r4, #0x5c\n"
            "    lsls    r1, r0, #0x1e\n"
            "    bmi     loc_e03af7f4\n"
            "    lsls    r0, r0, #0x1c\n"
            "    bmi     loc_e03af844\n"
            "    b       loc_e03af90e\n"
            "loc_e03af7f4:\n"
            "    lsls    r0, r0, #0x18\n"
            "    bpl     loc_e03af826\n"
            "    ldrd    r1, r0, [r4, #8]\n"
            "    cmp     r1, r0\n"
            "    beq     loc_e03af826\n"
            "    ldr     r0, [r5, #8]\n"
            "    bl      sub_e037415c\n"
            "    cbz     r0, loc_e03af81a\n"
            "    ldr     r0, [r4, #8]\n"
            "    add     r1, sp, #0x20\n"
            "    str     r0, [r4, #4]\n"
            "    mov     r0, r7\n"
            "    bl      sub_e04026b6\n"
            "    cmp     r0, #1\n"
            "    beq     loc_e03af822\n"
            "    b       loc_e03af826\n"
            "loc_e03af81a:\n"
            "    ldr     r0, =0x09200001\n"
            "    adds    r0, #0x16\n"
            "    str     r0, [r4, #0x14]\n"
            "    b       loc_e03af826\n"
            "loc_e03af822:\n"
            "    ldr     r0, [r4, #4]\n"
            "    str     r0, [sp, #0x28]\n"
            "loc_e03af826:\n"
            "    ldr     r0, [r5, #8]\n"
            "    adds    r1, r0, #1\n"
            "    beq     loc_e03af844\n"
            "    ldr     r1, [r4, #0x58]\n"
            "    ldr     r6, =0x09200001\n"
            "    adds    r6, r6, #2\n"
            "    cmp     r1, #1\n"
            "    beq     loc_e03af84c\n"

            "loc_D:\n"
//            "    bl      sub_e0373eb6\n"    // Close
            "    bl      fwt_close\n" // +

            "loc_e03af83a:\n"
            "    cbz     r0, loc_e03af83e\n"
            "    str     r6, [r4, #0x14]\n"
            "loc_e03af83e:\n"
            "    mov.w   r0, #-1\n"
            "    str     r0, [r5, #8]\n"
            "loc_e03af844:\n"
            "    ldrb    r0, [r4, #0x14]\n"
            "    lsls    r0, r0, #0x1f\n"
            "    beq     loc_e03af852\n"
            "    b       loc_e03af8f8\n"
            "loc_e03af84c:\n"

            //mod start
            "    LDR R3, =current_write_ignored\n"
            "    LDR R3, [R3]\n"
            "    cbz R3, loc_E\n"
            "    b       loc_D\n" // jump over the next block
            "loc_E:\n"
            //mod end

            "    bl      sub_e0373ee8\n"
            "    b       loc_e03af83a\n"
            "loc_e03af852:\n"
            "    ldr     r0, [r4, #0x50]\n"
            "    lsls    r1, r0, #0x1f\n"
            "    beq     loc_e03af874\n"
            "    movw    r0, #0x81ff\n"
            "    str     r0, [sp, #0x20]\n"
            "    movs    r0, #0x20\n"
            "    str     r0, [sp, #0x24]\n"
            "    ldr     r0, [r4, #4]\n"
            "    str     r0, [sp, #0x28]\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    str     r0, [sp, #0x2c]\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    str     r0, [sp, #0x30]\n"
            "    ldr     r0, [r4, #0x10]\n"
            "    str     r0, [sp, #0x34]\n"
            "    b       loc_e03af896\n"
            "loc_e03af874:\n"
            "    lsls    r0, r0, #0x1b\n"
            "    bpl     loc_e03af896\n"
            "    add     r1, sp, #0x20\n"
            "    mov     r0, r7\n"
            "    bl      sub_e04026b6\n"
            "    cbnz    r0, loc_e03af88e\n"
            "    movs    r0, #0\n"
            "    movw    r2, #0x3ca\n"
            "    ldr     r1, =0xe03af9f4\n" //  *"dwFWrite.c"
            "    bl      sub_dffc96f4\n"
            "loc_e03af88e:\n"
            "    ldr     r0, [sp, #0x28]\n"
            "    ldr     r1, [r4, #4]\n"
            "    add     r0, r1\n"
            "    str     r0, [sp, #0x28]\n"
            "loc_e03af896:\n"
            "    ldrb.w  r0, [r4, #0x50]\n"
            "    mvns    r0, r0\n"
            "    lsls    r0, r0, #0x19\n"
            "    bpl     loc_e03af8a8\n"
            "    add     r1, sp, #0x20\n"
            "    mov     r0, r7\n"
            "    bl      sub_e040272c\n"
            "loc_e03af8a8:\n"
            "    ldr     r0, [r4, #0x50]\n"
            "    lsls    r1, r0, #0x1e\n"
            "    bpl     loc_e03af8f8\n"
            "    lsls    r0, r0, #0x1a\n"
            "    bpl     loc_e03af8f8\n"
            "    movs    r2, #0x20\n"
            "    mov     r1, r7\n"
            "    mov     r0, sp\n"
            "    blx     sub_dffcc598\n"
            "    mov     r0, sp\n"
            "    bl      sub_e037e6c6\n"
            "    add     r0, sp, r0\n"
            "    movs    r1, #0x54\n"
            "    strb    r1, [r0, #-0x3]\n"
            "    movs    r1, #0x4d\n"
            "    strb    r1, [r0, #-0x2]\n"
            "    movs    r1, #0x50\n"
            "    strb    r1, [r0, #-0x1]\n"
            "    mov     r1, sp\n"
            "    mov     r0, r7\n"
            "    bl      sub_e045e7d8\n"
            "    cbnz    r0, loc_e03af8ec\n"
            "    movs    r0, #0\n"
            "    mov.w   r2, #0x1ae\n"
            "    ldr     r1, =0xe03afa00\n" //  *"dwFWrite.c"
            "    bl      sub_dffc96f4\n"
            "loc_e03af8ec:\n"
            "    mov     r0, sp\n"
            "    bl      sub_e0402a1a\n"
            "    mov     r0, r7\n"
            "    bl      sub_e0402a1a\n"
            "loc_e03af8f8:\n"
            "    movs    r1, #0\n"
            "    movs    r0, #0x48\n"
            "    bl      sub_e03719e0\n"
            "    mov     r0, r7\n"
            "    bl      sub_e03753e0\n"
            "    ldr     r1, [r5, #0x20]\n"
            "    bl      sub_e0036dc4\n"
            "    b       loc_e03af912\n"
            "loc_e03af90e:\n"
            "    ldr     r0, [r5, #0x20]\n"
            "    blx     r0\n"
            "loc_e03af912:\n"
            "    ldr     r0, [r5, #0x18]\n"
            "    cmp     r0, #0\n"
            "    beq     loc_e03af926\n"
            "    ldr     r1, [r4, #0x14]\n"
            "    mov     r0, r4\n"
            "    bl      sub_e03af5f0\n"
            "    ldr     r1, [r5, #0x18]\n"
            "    ldr     r0, [r4, #0x14]\n"
            "    blx     r1\n"
            "loc_e03af926:\n"
            "    add     sp, #0x3c\n"
            "    pop     {r4, r5, r6, r7, pc}\n"
    );
}
