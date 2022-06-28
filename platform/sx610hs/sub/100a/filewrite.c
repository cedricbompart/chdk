/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

#ifdef CAM_HAS_FILEWRITETASK_HOOK
// debug
#define FILEWRITE_DEBUG_LOG 1
extern void _LogCameraEvent(int id,const char *fmt,...);

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks


// comments below from elph180, firmware code appears very similar, offsets verified
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1; // message number
    int file_offset;
    int maybe_full_size; // maybe, on g7x wasn't always full size
    int unkn2, unkn3;
    int unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int maybe_seek_flag;      // 0x2083 jpeg, 0x100 create dir, 0x200 CacheFlush
    int unkn5, unkn6;
    char name[32];      // offset from start 0x5c, from Open case
} fwt_data_struct;
/*
observed message sequences
JPEG
12 maybe_full_size = 0x004437ac (=actual size), seek_flag = 0x2083
 0 chunk 0-0x004437ac
 1 chunk 0-0
 7 close

new directory
11 seek_flag = 0x100
before m 12 for shot, after raw hook in capt_seq

after shot
10 A/ seek_flag 0x200
*/

#include "../../../generic/filewrite.c"

#ifdef FILEWRITE_DEBUG_LOG
void log_fwt_msg(fwt_data_struct *fwd)
{
    int m=fwd->unkn1;
    _LogCameraEvent(0x60,"fw m:%d o:0x%08x fs:0x%08x sf:0x%x",m,fwd->file_offset,fwd->maybe_full_size,fwd->maybe_seek_flag);
    _LogCameraEvent(0x60,"fw %s",fwd->name);
    if(m >= 0 && m <=6) {
        _LogCameraEvent(0x60,"fw chunk adr:0x%08x l:0x%08x",fwd->pdc[m].address,fwd->pdc[m].length);
    }
    _LogCameraEvent(0x60,"fw u %08x %08x %08x %08x %08x %08x",fwd->unkn2,fwd->unkn3,fwd->unkn4,fwd->unkn5,fwd->unkn6);
}

void log_fwt_start(void)
{
    _LogCameraEvent(0x60,"fw start");
}
#endif


/*************************************************************/
//** filewritetask @ 0xFF397488 - 0xFF3975C8, length=81
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
#ifdef FILEWRITE_DEBUG_LOG
"bl log_fwt_start\n"
#endif
"    LDR     R5, =0xF2C4 \n"

"loc_FF397490:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x14] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_006B8490 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x477 \n"
"    LDRNE   R1, =0xFF3975FC /*'dwFWrite.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
#ifdef FILEWRITE_DEBUG_LOG
"ldr     r0, [sp,#8]\n"
"bl log_fwt_msg\n"
#endif
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF397490 \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975BC \n"
"    B       loc_FF3975C4 \n"
"    B       loc_FF3974FC \n"
"    B       loc_FF397584 \n"
"    B       loc_FF3975B4 \n"
"    B       loc_FF397574 \n"
"    B       loc_FF39757C \n"

"loc_FF3974FC:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP] \n"

"loc_FF397504:\n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R1, SP \n"
"    BL      sub_006B870C /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF397530 \n"
"    LDR     R0, [R5, #0x14] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_006B8490 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF397504 \n"

"loc_FF397530:\n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R4, R5 \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF397568 \n"
"    BL      _Close \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #8] \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF0C61D0 \n"
"    LDR     R0, =0x18E4E4 \n"
"    BL      sub_FF030C9C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF02EB58 \n"

"loc_FF397568:\n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF397490 \n"

"loc_FF397574:\n"
"    BL      sub_FF39781C \n"
"    B       loc_FF397490 \n"

"loc_FF39757C:\n"
"    BL      sub_FF3970B0_my \n"  // --> Patched. Old value = 0xFF3970B0. msg 12 - open, main hook
"    B       loc_FF397490 \n"

"loc_FF397584:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #8] \n"
"    MOV     R2, #0 \n"
"    BL      _lseek \n"
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVEQ   R0, #7 \n"
"    BLEQ    sub_FF396FE8 \n"
"    B       loc_FF397490 \n"

"loc_FF3975B4:\n"
"    BL      sub_FF3978BC \n"
"    B       loc_FF397490 \n"

"loc_FF3975BC:\n"
"    BL      sub_FF397958_my \n"  // --> Patched. Old value = 0xFF397958. msg 0-6 - write chunk
"    B       loc_FF397490 \n"

"loc_FF3975C4:\n"
"    BL      sub_FF397288_my \n"  // --> Patched. Old value = 0xFF397288. msg 0-7 - close
"    B       loc_FF397490 \n"
);
}

/*************************************************************/
//** sub_FF3970B0_my @ 0xFF3970B0 - 0xFF397284, length=118
void __attribute__((naked,noinline)) sub_FF3970B0_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  MOV   R0, R4\n"      //data block start, commented out as R0 is already holding what we need
"    BL filewrite_main_hook\n"
"    MOV     R0, R4\n"      //restore register(s)
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R7, =0xF2C4 \n"
"    TST     R0, #5 \n"
"    SUB     SP, SP, #0x3C \n"
"    BEQ     loc_FF3970F4 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    CMP     R0, #0 \n"
"    BLXNE   R0 \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF030C9C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF02EA18 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x47 \n"
"    BL      sub_FF0C61D0 \n"

"loc_FF3970F4:\n"
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF397258 \n"
"    LDR     R0, [R4, #0x10] \n"
"    BL      sub_FF02D8BC \n"
"    LDR     R0, [R4, #0x50] \n"
"    LDR     R5, =0x301 \n"
"    TST     R0, #0x10 \n"
"    MOVNE   R5, #9 \n"
"    BNE     loc_FF397124 \n"
"    TST     R0, #0x40 \n"
"    MOVNE   R5, #1 \n"

"loc_FF397124:\n"
"    TST     R0, #0x20 \n"
"    BNE     loc_FF397138 \n"
"    LDR     R0, [R4, #0x58] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF39713C \n"

"loc_FF397138:\n"
"    ORR     R5, R5, #0x8000 \n"

"loc_FF39713C:\n"
"    LDR     R9, =0x1B6 \n"
"    ADD     R8, R4, #0x5C \n"
"    LDR     R6, [R4, #0x10] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FF3971BC \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF027684 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R8 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006DAA10 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R6, [SP, #0x30] \n"
"    STR     R6, [SP, #0x34] \n"
"    STR     R6, [SP, #0x38] \n"
"    BL      sub_FF02E37C \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      _Open \n"

"loc_FF3971BC:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R7, #8] \n"
"    BNE     loc_FF397218 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF0C61D0 \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF030C9C \n"
"    LDR     R1, [R7, #0x20] \n"
"    BL      sub_FF02EB58 \n"
"    LDR     R0, [R7, #0x18] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF397280 \n"
"    LDR     R5, =0x9200001 \n"
"    MOV     R0, R4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF396F84 \n"
"    LDR     R1, [R7, #0x18] \n"
"    MOV     R0, R5 \n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    BX      R1 \n"

"loc_FF397218:\n"
"    LDR     R0, =0x18E4E4 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x5C \n"
"    BL      sub_006DABF8 /*_dry_memcpy*/ \n"
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_C\n" // jump over the next block
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FF397258 \n"
"    LDR     R1, [R4, #0xC] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF027354 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x9200017 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FF39727C \n"

"loc_FF397258:\n"
"loc_C:\n"
"    LDR     R0, [R4, #0x50] \n"
"    TST     R0, #0x40 \n"
"    LDREQ   R0, [R4, #4] \n"
"    CMPEQ   R0, #0 \n"
"    MOVNE   R1, R4 \n"
"    MOVNE   R0, #9 \n"
"    BLNE    sub_FF396FE8 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, #0 \n"

"loc_FF39727C:\n"
"    BL      sub_FF396FE8 \n"

"loc_FF397280:\n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FF397958_my @ 0xFF397958 - 0xFF397A3C, length=58
void __attribute__((naked,noinline)) sub_FF397958_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF397984 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x18]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF3979A0 \n"
"    B       loc_FF397994 \n"

"loc_FF397984:\n"
"    MOV     R2, #0x3B4 \n"
"    LDR     R1, =0xFF3975FC /*'dwFWrite.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF397994:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FF397A38 \n"

"loc_FF3979A0:\n"
"    LDR     R9, =0xF2C4 \n"
"    MOV     R4, R7 \n"

"loc_FF3979A8:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #8] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FF397A08 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x14] \n"
"    B       loc_FF397994 \n"

"loc_FF397A08:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R2, =0x3DE \n"
"    LDRCS   R1, =0xFF3975FC /*'dwFWrite.c'*/ \n"
"    ADD     R8, R8, R0 \n"
"    MOVCS   R0, #0 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF3979A8 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FF397A38:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FF396FE8 \n"
);
}

/*************************************************************/
//** sub_FF397288_my @ 0xFF397288 - 0xFF39731C, length=38
void __attribute__((naked,noinline)) sub_FF397288_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x50] \n"
"    LDR     R5, =0xF2C4 \n"
"    TST     R0, #0xA \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     sub_FF397454 \n"
"    TST     R0, #2 \n"
"    BEQ     sub_FF397330 \n"
"    TST     R0, #0x80 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    LDRNE   R1, [R4, #8] \n"
"    CMPNE   R1, R0 \n"
"    BEQ     loc_FF3972F8 \n"
"    LDR     R0, [R5, #8] \n"
"    BL      sub_FF027354 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x9200017 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FF3972F8 \n"
"    LDR     R0, [R4, #8] \n"
"    ADD     R1, SP, #0x20 \n"
"    STR     R0, [R4, #4] \n"
"    ADD     R0, R4, #0x5C \n"
"    BL      sub_FF02E2C4 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #4] \n"
"    STREQ   R0, [SP, #0x28] \n"

"loc_FF3972F8:\n"
"    LDR     R0, [R5, #8] \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF397330 \n"
"    LDR     R1, [R4, #0x58] \n"
"    LDR     R6, =0x9200003 \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FF39731C \n"
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
"    BL      sub_FF0270A8 \n"
"    B       sub_FF397320 \n"

"loc_FF39731C:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF397320 \n"  // Continue in firmware
);
}
#endif // CAM_HAS_FILEWRITETASK_HOOK
