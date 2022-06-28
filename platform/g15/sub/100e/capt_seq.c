/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 300  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF085738 - 0xFF085A4C, length=198
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R4, =0x43964 \n"
"    LDR     R7, =0x3888 \n"
"    MOV     R6, #0 \n"

"loc_FF085748:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_0068BDE0 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF085774 \n"
"    LDR     R1, =0x491 \n"
"    LDR     R0, =0xFF085084 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF085774:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF085A14 \n"
"    B       loc_FF085828 \n"
"    B       loc_FF085840 \n"
"    B       loc_FF08584C \n"
"    B       loc_FF085860 \n"
"    B       loc_FF085858 \n"
"    B       loc_FF08586C \n"
"    B       loc_FF085874 \n"
"    B       loc_FF08587C \n"
"    B       loc_FF085898 \n"
"    B       loc_FF0858EC \n"
"    B       loc_FF0858A4 \n"
"    B       loc_FF0858B0 \n"
"    B       loc_FF0858B8 \n"
"    B       loc_FF0858D4 \n"
"    B       loc_FF0858DC \n"
"    B       loc_FF0858E4 \n"
"    B       loc_FF0858F4 \n"
"    B       loc_FF0858FC \n"
"    B       loc_FF085904 \n"
"    B       loc_FF08590C \n"
"    B       loc_FF085914 \n"
"    B       loc_FF08591C \n"
"    B       loc_FF085924 \n"
"    B       loc_FF08592C \n"
"    B       loc_FF085934 \n"
"    B       loc_FF08593C \n"
"    B       loc_FF085948 \n"
"    B       loc_FF085950 \n"
"    B       loc_FF08595C \n"
"    B       loc_FF085964 \n"
"    B       loc_FF085994 \n"
"    B       loc_FF08599C \n"
"    B       loc_FF0859A4 \n"
"    B       loc_FF0859AC \n"
"    B       loc_FF0859B4 \n"
"    B       loc_FF0859BC \n"
"    B       loc_FF0859C8 \n"
"    B       loc_FF0859D0 \n"
"    B       loc_FF0859DC \n"
"    B       loc_FF085A20 \n"

"loc_FF085828:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF08600C \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF08288C \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x28]\n"                  // added, fixes overrides  behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF1E5E48 \n"
"    B       loc_FF085A20 \n"

"loc_FF085840:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF085B68_my \n"  // --> Patched. Old value = 0xFF085B68.
"    B       loc_FF085A20 \n"

"loc_FF08584C:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF0863A4 \n"
"    B       loc_FF085A20 \n"

"loc_FF085858:\n"
"    BL      sub_FF085CBC \n"
"    B       loc_FF085864 \n"

"loc_FF085860:\n"
"    BL      sub_FF085FEC \n"

"loc_FF085864:\n"
"    STR     R6, [R4, #0x28] \n"
"    B       loc_FF085A20 \n"

"loc_FF08586C:\n"
"    BL      sub_FF085FF4 \n"
"    B       loc_FF085A20 \n"

"loc_FF085874:\n"
"    BL      sub_FF086250 \n"
"    B       loc_FF08589C \n"

"loc_FF08587C:\n"
"    LDR     R5, [R0, #0x10] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF1E5F14 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF08331C \n"
"    B       loc_FF085A20 \n"

"loc_FF085898:\n"
"    BL      sub_FF08630C \n"

"loc_FF08589C:\n"
"    BL      sub_FF08288C \n"
"    B       loc_FF085A20 \n"

"loc_FF0858A4:\n"
"    LDR     R0, [R4, #0x58] \n"
"    BL      sub_FF086C10 \n"
"    B       loc_FF085A20 \n"

"loc_FF0858B0:\n"
"    BL      sub_FF086FA8 \n"
"    B       loc_FF085A20 \n"

"loc_FF0858B8:\n"
"    LDRH    R0, [R4] \n"
"    SUB     R1, R0, #0x8200 \n"
"    SUBS    R1, R1, #0x39 \n"
"    MOVNE   R0, #0 \n"
"    MOVEQ   R0, #1 \n"
"    BL      sub_FF08700C \n"
"    B       loc_FF085A20 \n"

"loc_FF0858D4:\n"
"    BL      sub_FF0871F4 \n"
"    B       loc_FF085A20 \n"

"loc_FF0858DC:\n"
"    BL      sub_FF087668 \n"
"    B       loc_FF085A20 \n"

"loc_FF0858E4:\n"
"    BL      sub_FF08771C \n"
"    B       loc_FF085A20 \n"

"loc_FF0858EC:\n"
"    BL      sub_FF085FEC \n"
"    B       loc_FF085A20 \n"

"loc_FF0858F4:\n"
"    BL      sub_FF1E3804 \n"
"    B       loc_FF085A20 \n"

"loc_FF0858FC:\n"
"    BL      sub_FF1E3A98 \n"
"    B       loc_FF085A20 \n"

"loc_FF085904:\n"
"    BL      sub_FF1E3B68 \n"
"    B       loc_FF085A20 \n"

"loc_FF08590C:\n"
"    BL      sub_FF1E3C1C \n"
"    B       loc_FF085A20 \n"

"loc_FF085914:\n"
"    BL      sub_FF1E3D1C \n"
"    B       loc_FF085A20 \n"

"loc_FF08591C:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF085940 \n"

"loc_FF085924:\n"
"    BL      sub_FF1E4314 \n"
"    B       loc_FF085A20 \n"

"loc_FF08592C:\n"
"    BL      sub_FF1E43A8 \n"
"    B       loc_FF085A20 \n"

"loc_FF085934:\n"
"    BL      sub_FF1E4450 \n"
"    B       loc_FF085A20 \n"

"loc_FF08593C:\n"
"    MOV     R0, #1 \n"

"loc_FF085940:\n"
"    BL      sub_FF1E41B0 \n"
"    B       loc_FF085A20 \n"

"loc_FF085948:\n"
"    BL      sub_FF0865F0 \n"
"    B       loc_FF085A20 \n"

"loc_FF085950:\n"
"    BL      sub_FF086684 \n"
"    BL      sub_FF1E72C8 \n"
"    B       loc_FF085A20 \n"

"loc_FF08595C:\n"
"    BL      sub_FF1E3FF0 \n"
"    B       loc_FF085A20 \n"

"loc_FF085964:\n"
"    MOV     R2, #2 \n"
"    ADD     R1, R4, #0x62 \n"
"    MOV     R0, #0x6F \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x592 \n"
"    LDRNE   R0, =0xFF085084 /*'SsShootTask.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDRH    R0, [R4, #0x62] \n"
"    CMP     R0, #1 \n"
"    BLEQ    sub_FF1E3FE4 \n"
"    B       loc_FF085A20 \n"

"loc_FF085994:\n"
"    BL      sub_FF1E410C \n"
"    B       loc_FF085A20 \n"

"loc_FF08599C:\n"
"    BL      sub_FF1E739C \n"
"    B       loc_FF085A20 \n"

"loc_FF0859A4:\n"
"    BL      sub_FF01DA10 \n"
"    B       loc_FF085A20 \n"

"loc_FF0859AC:\n"
"    BL      sub_FF08B8D4 \n"
"    B       loc_FF085A20 \n"

"loc_FF0859B4:\n"
"    BL      sub_FF08B9D4 \n"
"    B       loc_FF085A20 \n"

"loc_FF0859BC:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF1E4558 \n"
"    B       loc_FF085A20 \n"

"loc_FF0859C8:\n"
"    BL      sub_FF1E45C8 \n"
"    B       loc_FF085A20 \n"

"loc_FF0859D0:\n"
"    BL      sub_FF08BB60 \n"
"    BL      sub_FF08BA2C \n"
"    B       loc_FF085A20 \n"

"loc_FF0859DC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1E6744 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF1E6878 \n"
"    LDRH    R0, [R4, #0xA4] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R1, R0, #0x4200 \n"
"    SUBNES  R1, R1, #0x2E \n"
"    BNE     loc_FF085A20 \n"
"    BL      sub_FF08B9D4 \n"
"    BL      sub_FF08C278 \n"
"    BL      sub_FF08BF80 \n"
"    B       loc_FF085A20 \n"

"loc_FF085A14:\n"
"    LDR     R1, =0x5F2 \n"
"    LDR     R0, =0xFF085084 /*'SsShootTask.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF085A20:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0068BB50 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xFF085084 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_FF085748 \n"
);
}

/*************************************************************/
//** sub_FF085B68_my @ 0xFF085B68 - 0xFF085C08, length=41
void __attribute__((naked,noinline)) sub_FF085B68_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x43964 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF085BB8 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x30 \n"
"    BLNE    sub_FF08A1C4 \n"
"    BL      sub_FF089C8C \n"
"    MOV     R1, R6 \n"
"    BL      sub_FF089CE4 \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R6, #0x78 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R6, #0x7C \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"

"loc_FF085BB8:\n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x20 \n"
"    MOV     R0, R6 \n"
"    BEQ     loc_FF085BD0 \n"
"    BL      sub_FF1E6D10 \n"
"    B       loc_FF085BD4 \n"

"loc_FF085BD0:\n"
"    BL      sub_FF1E5BD0_my \n"  // --> Patched. Old value = 0xFF1E5BD0.
"    BL      capt_seq_hook_raw_here \n" // +++

"loc_FF085BD4:\n"
"    MOV     R4, R0 \n"
"    MOV     R2, R6 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF08331C \n"
"    TST     R4, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF1E4B70 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #2 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    B       sub_FF0834C4 \n"
);
}

/*************************************************************/
//** sub_FF1E5BD0_my @ 0xFF1E5BD0 - 0xFF1E5E44, length=158
void __attribute__((naked,noinline)) sub_FF1E5BD0_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R6, =0x43964 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R6, #0x28] \n"
"    LDR     R5, =0x420D \n"
"    CMP     R0, #0 \n"
"    MOV     R7, #0 \n"
"    BNE     loc_FF1E5C74 \n"
"    LDR     R1, [R6, #0x94] \n"
"    TST     R1, #6 \n"
"    BNE     loc_FF1E5C10 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF08DE58 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1E5C74 \n"
"    B       loc_FF1E5C6C \n"

"loc_FF1E5C10:\n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF1E5C54 \n"
"    LDRH    R0, [R6, #0x9E] \n"
"    CMP     R0, #3 \n"
"    BNE     loc_FF1E5C40 \n"
"    TST     R1, #2 \n"
"    BNE     loc_FF1E5C74 \n"

"loc_FF1E5C40:\n"
"    BL      sub_FF018804 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1E5C74 \n"
"    BL      sub_FF08DEC0 \n"
"    B       loc_FF1E5C6C \n"

"loc_FF1E5C54:\n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF08DE58 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF1E5C74 \n"
"    BL      sub_FF1E65C0 \n"
"    BL      sub_FF082F38 \n"

"loc_FF1E5C6C:\n"
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF1E5C74:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF1E7410 \n"
"    BL      sub_FF085FFC \n"
"    LDR     R0, [R6, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1E5E30 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF1E4A54 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R3-R7,PC} \n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #0x40 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF1E5CE0 \n"
"    BL      sub_FF1E6A38 \n"
"    MOV     R3, #0xB3 \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFF1E5EF0 /*'SsCaptureSeq.c'*/ \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_FF08E0D0 \n"

"loc_FF1E5CE0:\n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #4 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BLS     loc_FF1E5D14 \n"
"    LDR     R0, [R6, #0x98] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF1E5D20 \n"

"loc_FF1E5D14:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FF1E4F9C \n"
"    BL      sub_FF1E6504 \n"
"    BL      wait_until_remote_button_is_released\n" // +++
"    BL      capt_seq_hook_set_nr\n" // +++

"loc_FF1E5D20:\n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF13785C \n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #4 \n"
"    BEQ     loc_FF1E5D78 \n"
"    LDR     R0, [R6, #0x98] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FF1E5D78 \n"
"    LDRH    R0, [R6] \n"
"    CMP     R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #3 \n"
"    BLLS    sub_FF13785C \n"

"loc_FF1E5D78:\n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #0x40 \n"
"    BEQ     loc_FF1E5DE0 \n"
"    LDR     R0, =0x181 \n"
"    MOV     R2, #4 \n"
"    MOV     R1, SP \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R1, #0xD4 \n"
"    LDRNE   R0, =0xFF1E5EF0 /*'SsCaptureSeq.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF1E5DC0 \n"
"    BL      sub_FF1E6A38 \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_0068BB50 /*_SetEventFlag*/ \n"
"    B       loc_FF1E5DE0 \n"

"loc_FF1E5DC0:\n"
"    BL      sub_FF1E6A38 \n"
"    MOV     R1, #0x8000 \n"
"    BL      sub_0068BB84 /*_ClearEventFlag*/ \n"
"    LDR     R2, =0xFF1E5BBC \n"
"    LDR     R0, [SP] \n"
"    MOV     R3, #0x8000 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF020C0C /*_SetTimerAfter*/ \n"

"loc_FF1E5DE0:\n"
"    LDR     R0, [R6, #0x94] \n"
"    AND     R0, R0, #6 \n"
"    CMP     R0, #0 \n"
"    LDRNEH  R0, [R6] \n"
"    CMPNE   R0, R5 \n"
"    LDRNEH  R0, [R6, #0xA2] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #2 \n"
"    BLLS    sub_FF08F6D4 \n"
"    LDR     R0, [R6, #0x94] \n"
"    TST     R0, #0x10 \n"
"    MOV     R0, R4 \n"
"    BEQ     loc_FF1E5E24 \n"
"    BL      sub_FF38FAD4 \n"
"    B       loc_FF1E5E28 \n"

"loc_FF1E5E24:\n"
"    BL      sub_FF1E55F8 \n"

"loc_FF1E5E28:\n"
"    MOV     R7, R0 \n"
"    B       loc_FF1E5E40 \n"

"loc_FF1E5E30:\n"
"    LDR     R0, =0x98E8 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R7, #0x1D \n"

"loc_FF1E5E40:\n"
"    MOV     R0, R7 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF0CB104 - 0xFF0CB794, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4DBC \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x61A08 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF0CB124:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_0068BDE0 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF0CB170 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF0CB2D0 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF0CB258 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0CB0B4 \n"

"loc_FF0CB170:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF0CB19C \n"
"    BL      sub_FF0CC638 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0068BB50 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0CB19C:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF0CB1B8 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF0CB78C \n"

"loc_FF0CB1B8:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF0CB208 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0068BB84 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0C6808 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF07C130 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0068BA90 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1643 \n"
"    BNE     loc_FF0CB2C4 \n"

"loc_FF0CB1F4:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF0CB78C \n"

"loc_FF0CB208:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF0CB250 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0CB0B4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0068BB84 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF0C6818 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF07CEE4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0068BA90 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0CB1F4 \n"
"    LDR     R1, =0x164D \n"
"    B       loc_FF0CB2C4 \n"

"loc_FF0CB250:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF0CB268 \n"

"loc_FF0CB258:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF0CB0B4 \n"
"    B       loc_FF0CB1F4 \n"

"loc_FF0CB268:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF0CB280 \n"
"    BL      sub_FF0B559C \n"
"    BL      sub_FF0B6374 \n"
"    BL      sub_FF0B5E84 \n"
"    B       loc_FF0CB1F4 \n"

"loc_FF0CB280:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF0CB2D0 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0068BB84 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF0C6838 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF0B4FE0 \n"
"    BL      sub_FF0B527C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0068B9AC /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF0CB1F4 \n"
"    LDR     R1, =0x1675 \n"

"loc_FF0CB2C4:\n"
"    LDR     R0, =0xFF0C6FB8 /*'ExpDrv.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0CB1F4 \n"

"loc_FF0CB2D0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF0CB338 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0C957C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0CCA44 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF0CB650 \n"

"loc_FF0CB338:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF0CB3F0 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0C97E0 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF0CB38C \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF0CB3C4 \n"

"loc_FF0CB38C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF0CB3D8 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF0CADA4 \n"

"loc_FF0CB3C4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF0CB054 \n"
"    B       loc_FF0CB658 \n"

"loc_FF0CB3D8:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF0CB658 \n"

"loc_FF0CB3F0:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF0CB43C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF0C8544 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0C89A0 \n"
"    B       loc_FF0CB658 \n"

"loc_FF0CB43C:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB4F8 \n"
"    B       loc_FF0CB4F8 \n"
"    B       loc_FF0CB500 \n"
"    B       loc_FF0CB508 \n"
"    B       loc_FF0CB508 \n"
"    B       loc_FF0CB508 \n"
"    B       loc_FF0CB4F8 \n"
"    B       loc_FF0CB500 \n"
"    B       loc_FF0CB508 \n"
"    B       loc_FF0CB508 \n"
"    B       loc_FF0CB520 \n"
"    B       loc_FF0CB520 \n"
"    B       loc_FF0CB62C \n"
"    B       loc_FF0CB634 \n"
"    B       loc_FF0CB634 \n"
"    B       loc_FF0CB634 \n"
"    B       loc_FF0CB634 \n"
"    B       loc_FF0CB63C \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB510 \n"
"    B       loc_FF0CB518 \n"
"    B       loc_FF0CB518 \n"
"    B       loc_FF0CB518 \n"
"    B       loc_FF0CB52C \n"
"    B       loc_FF0CB52C \n"
"    B       loc_FF0CB534 \n"
"    B       loc_FF0CB56C \n"
"    B       loc_FF0CB5A4 \n"
"    B       loc_FF0CB5DC \n"
"    B       loc_FF0CB614 \n"
"    B       loc_FF0CB614 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB640 \n"
"    B       loc_FF0CB61C \n"
"    B       loc_FF0CB624 \n"

"loc_FF0CB4F8:\n"
"    BL      sub_FF0C6DCC \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB500:\n"
"    BL      sub_FF0C710C \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB508:\n"
"    BL      sub_FF0C7378 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB510:\n"
"    BL      sub_FF0C7670 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB518:\n"
"    BL      sub_FF0C788C \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB520:\n"
"    BL      sub_FF0C7C74_my \n"  // --> Patched. Old value = 0xFF0C7C74.
"    MOV     R8, #0 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB52C:\n"
"    BL      sub_FF0C7DB4 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB534:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0CC6CC \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB56C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0CC844 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB5A4:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0CC8F8 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB5DC:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF0CC9A0 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB614:\n"
"    BL      sub_FF0C82D8 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB61C:\n"
"    BL      sub_FF0C8AA4 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB624:\n"
"    BL      sub_FF0C8D8C \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB62C:\n"
"    BL      sub_FF0C9048 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB634:\n"
"    BL      sub_FF0C9208 \n"
"    B       loc_FF0CB640 \n"

"loc_FF0CB63C:\n"
"    BL      sub_FF0C9370 \n"

"loc_FF0CB640:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF0CB650:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF0CB658:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF0CB690 \n"
"    BGT     loc_FF0CB680 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF0CB6C4 \n"
"    B       loc_FF0CB690 \n"

"loc_FF0CB680:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF0CB6C4 \n"

"loc_FF0CB690:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF0CB6C4 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF0CCC50 /*_get_current_exp*/ \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF0CB6C4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF0CB714 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x61A08 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_00690174 \n"
"    LDR     R0, =0x61A14 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_00690174 \n"
"    LDR     R0, =0x61A20 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_00690174 \n"
"    B       loc_FF0CB78C \n"

"loc_FF0CB714:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF0CB758 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0C6BA0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF0CB788 \n"

"loc_FF0CB758:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF0C6BA0 \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF0CB788:\n"
"    BL      sub_FF0C6D18 \n"

"loc_FF0CB78C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF0CC638 \n"
"    B       loc_FF0CB124 \n"
);
}

/*************************************************************/
//** sub_FF0C7C74_my @ 0xFF0C7C74 - 0xFF0C7DB0, length=80
void __attribute__((naked,noinline)) sub_FF0C7C74_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4DBC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0068BB84 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF0C68A0 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0C6A00 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF0C6A58 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF0C6AB0 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF0C6B08 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x61A20 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF0C7D08 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF0C7D08 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF0C67F8 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF07C450 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF0C7D10 \n"

"loc_FF0C7D08:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF0C7D10:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF0C7D2C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF0C687C \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF0CC688 \n"

"loc_FF0C7D2C:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF0B52E8_my \n"  // --> Patched. Old value = 0xFF0B52E8.
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF0B5B3C \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF0B5BC4 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF0C0A64 \n"
"    LDR     R4, =0xBB8 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF0C7D84 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #2 \n"
"    BL      sub_0068BA90 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R0, =0xFF0C6FB8 /*'ExpDrv.c'*/ \n"
"    MOVNE   R1, #0x820 \n"
"    BLNE    _DebugAssert \n"

"loc_FF0C7D84:\n"
"    CMP     R5, #1 \n"
"    LDMNEFD SP!, {R4-R8,PC} \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R2, R4 \n"
"    MOV     R1, #0x20 \n"
"    BL      sub_0068BA90 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R8,PC} \n"
"    LDMFD   SP!, {R4-R8,LR} \n"
"    LDR     R1, =0x825 \n"
"    LDR     R0, =0xFF0C6FB8 /*'ExpDrv.c'*/ \n"
"    B       _DebugAssert \n"
);
}

/*************************************************************/
//** sub_FF0B52E8_my @ 0xFF0B52E8 - 0xFF0B5350, length=27
void __attribute__((naked,noinline)) sub_FF0B52E8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x4A28 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R1, #0x154 \n"
"    LDRNE   R0, =0xFF0B50E4 /*'Shutter.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x15A \n"
"    LDREQ   R0, =0xFF0B50E4 /*'Shutter.c'*/ \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF137010 \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF140788 \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    LDR     R1, =0x15F \n"
"    LDR     R0, =0xFF0B50E4 /*'Shutter.c'*/ \n"
"    B       _DebugAssert \n"
);
}
