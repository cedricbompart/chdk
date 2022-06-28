/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
                              // Found in sub_FFABBB58 (1.00a) --> "CMP     R0, #6" and
                              // filewritetask() jump table has 7 calls to loc_FFABB944
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    int file_offset;
    int full_size;
    int unkn2, unkn3;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int seek_flag;      // offset from start 0x4c = 76 bytes = 19 words
    int unkn4, unkn5;
    char name[32];      // offset from start 0x58 = 88 bytes = 22 words
} fwt_data_struct;
// seek_flag is different:
// seek state is activated (from state 0xc, open) when
// (word at 0x4c) AND 0x40
// OR
// write offset is not 0
#define FWT_MUSTSEEK    0x40   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0x40   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"


/*************************************************************/
//** filewritetask @ 0xFFAB8CF0 - 0xFFAB8EB8, length=115
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R5, =0xB584 \n"
"    MOV     R6, #0 \n"

"loc_FFAB8CFC:\n"
"    LDR     R0, [R5, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF829E30 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x409 \n"
"    LDRNE   R1, =0xFFAB8EE4 /*'dwFWrite.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFAB8CFC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EAC \n"
"    B       loc_FFAB8EB4 \n"
"    B       loc_FFAB8D68 \n"
"    B       loc_FFAB8E28 \n"
"    B       loc_FFAB8E58 \n"
"    B       loc_FFAB8DDC \n"
"    B       loc_FFAB8E20 \n"

"loc_FFAB8D68:\n"
"    MOV     R4, R5 \n"
"    STR     R6, [SP] \n"

"loc_FFAB8D70:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF82A0AC /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAB8D9C \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF829E30 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FFAB8D70 \n"

"loc_FFAB8D9C:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FFAB8DD0 \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF8B0664 \n"
"    LDR     R0, =0xFC03C \n"
"    BL      sub_FF83222C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8300F8 \n"

"loc_FFAB8DD0:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFAB8CFC \n"

"loc_FFAB8DDC:\n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x58 \n"
"    BL      sub_FF83222C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF82FFB8 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x47 \n"
"    BL      sub_FF8B0664 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF82F038 \n"
"    ADD     R0, R4, #0x58 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_A\n" // skip creating directory
//mod end

"    BL      sub_FF8281A4 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF8B0664 \n"
"    ADD     R0, R4, #0x58 \n"
"    B       loc_FFAB8E8C \n"

"loc_FFAB8E20:\n"
"    BL      sub_FFAB89A4_my \n"  // --> Patched. Old value = 0xFFAB89A4. Open stage
"    B       loc_FFAB8CFC \n"

"loc_FFAB8E28:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    MOV     R2, #0 \n"
"    BL      fwt_lseek \n"  // --> Patched. Old value = _lseek.
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x10] \n"
"    MOVEQ   R0, #7 \n"
"    BLEQ    sub_FFAB88E4 \n"
"    B       loc_FFAB8CFC \n"

"loc_FFAB8E58:\n"
"    MOV     R4, R0 \n"
"    LDRSB   R0, [R0, #0x58] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAB8CFC \n"
"    STRB    R0, [SP, #4] \n"
"    ADD     R0, R4, #0x58 \n"
"    STRB    R6, [SP, #5] \n"
"    BL      sub_FF83222C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF82FFB8 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_B\n" // skip flushing the cache
//mod end

"    ADD     R0, SP, #4 \n"
"    BL      sub_FF82F050 \n"
"loc_B:\n"
"    ADD     R0, R4, #0x58 \n"

"loc_FFAB8E8C:\n"
"loc_A:\n"
"    BL      sub_FF83222C \n"
"    LDR     R1, [R5, #0x1C] \n"
"    BL      sub_FF8300F8 \n"
"    LDR     R1, [R5, #0x14] \n"
"    CMP     R1, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    BLXNE   R1 \n"
"    B       loc_FFAB8CFC \n"

"loc_FFAB8EAC:\n"
"    BL      sub_FFAB9100_my \n"  // --> Patched. Old value = 0xFFAB9100. Write stage
"    B       loc_FFAB8CFC \n"

"loc_FFAB8EB4:\n"
"    BL      sub_FFAB8B5C_my \n"  // --> Patched. Old value = 0xFFAB8B5C. Close stage
"    B       loc_FFAB8CFC \n"
);
}

/*************************************************************/
//** sub_FFAB89A4_my @ 0xFFAB89A4 - 0xFFAB8B58, length=110
void __attribute__((naked,noinline)) sub_FFAB89A4_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"

//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
"    MOV   R0, R4\n"      //data block start, commented out as R0 is already holding what we need
"    BL filewrite_main_hook\n"
"    MOV     R0, R4\n"      //restore register(s)
//hook end

"    LDR     R0, [R0, #0x4C] \n"
"    SUB     SP, SP, #0x3C \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFAB8B2C \n"
"    LDR     R7, =0xB584 \n"
"    LDR     R0, [R7, #0x18] \n"
"    CMP     R0, #0 \n"
"    BLXNE   R0 \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF83222C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF82FFB8 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x47 \n"
"    BL      sub_FF8B0664 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF82F038 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R5, =0x301 \n"
"    TST     R0, #0x10 \n"
"    MOVNE   R5, #9 \n"
"    BNE     loc_FFAB8A0C \n"
"    TST     R0, #0x40 \n"
"    MOVNE   R5, #1 \n"

"loc_FFAB8A0C:\n"
"    TST     R0, #0x20 \n"
"    BNE     loc_FFAB8A20 \n"
"    LDR     R0, [R4, #0x54] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFAB8A24 \n"

"loc_FFAB8A20:\n"
"    ORR     R5, R5, #0x8000 \n"

"loc_FFAB8A24:\n"
"    LDR     R9, =0x1B6 \n"
"    ADD     R8, R4, #0x58 \n"
"    LDR     R6, [R4, #0xC] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FFAB8AA4 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF8281A4 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R8 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006BA828 \n"
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
"    BL      sub_FF82F91C \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.

"loc_FFAB8AA4:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R7, #4] \n"
"    BNE     loc_FFAB8AEC \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x48 \n"
"    BL      sub_FF8B0664 \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF83222C \n"
"    LDR     R1, [R7, #0x1C] \n"
"    BL      sub_FF8300F8 \n"
"    LDR     R1, [R7, #0x14] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FFAB8B54 \n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    LDR     R0, =0x9200001 \n"
"    BX      R1 \n"

"loc_FFAB8AEC:\n"
"    LDR     R0, =0xFC03C \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x58 \n"
"    BL      sub_006BAA10 /*_dry_memcpy*/ \n"

//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_C\n" // jump over the next block
//mod end

"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FFAB8B2C \n"
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF827E74 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x9200017 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x10] \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FFAB8B50 \n"

"loc_FFAB8B2C:\n"
"loc_C:\n"
"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x40 \n"
"    LDREQ   R0, [R4, #4] \n"
"    CMPEQ   R0, #0 \n"
"    MOVNE   R1, R4 \n"
"    MOVNE   R0, #9 \n"
"    BLNE    sub_FFAB88E4 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, #0 \n"

"loc_FFAB8B50:\n"
"    BL      sub_FFAB88E4 \n"

"loc_FFAB8B54:\n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FFAB9100_my @ 0xFFAB9100 - 0xFFAB91E4, length=58
void __attribute__((naked,noinline)) sub_FFAB9100_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFAB912C \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFAB9148 \n"
"    B       loc_FFAB913C \n"

"loc_FFAB912C:\n"
"    LDR     R2, =0x35E \n"
"    LDR     R1, =0xFFAB8EE4 /*'dwFWrite.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FFAB913C:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFAB91E0 \n"

"loc_FFAB9148:\n"
"    LDR     R9, =0xB584 \n"
"    MOV     R4, R7 \n"

"loc_FFAB9150:\n"
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
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFAB91B0 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FFAB913C \n"

"loc_FFAB91B0:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R2, =0x389 \n"
"    ADD     R8, R8, R0 \n"
"    LDRCS   R1, =0xFFAB8EE4 /*'dwFWrite.c'*/ \n"
"    MOVCS   R0, #0 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFAB9150 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFAB91E0:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFAB88E4 \n"
"    .ltorg\n" //+
);
}

/*************************************************************/
//** sub_FFAB8B5C_my @ 0xFFAB8B5C - 0xFFAB8B9C, length=17
void __attribute__((naked,noinline)) sub_FFAB8B5C_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x4C] \n"
"    LDR     R5, =0xB584 \n"
"    TST     R0, #2 \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     sub_FFAB8CD0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFAB8BB0 \n"
"    LDR     R1, [R4, #0x54] \n"
"    LDR     R6, =0x9200003 \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFAB8B9C \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end

"    BL      sub_FF827BC8 \n"
"    B       sub_FFAB8BA0 \n"

"loc_FFAB8B9C:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFAB8BA0 \n"  // Continue in firmware
);
}
