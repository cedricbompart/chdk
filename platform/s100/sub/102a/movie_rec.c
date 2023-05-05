/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(__attribute__ ((unused))int a, __attribute__ ((unused))int b) {}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF1CC43C - 0xFF1CC5B4, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF1CB1AC \n"
"    LDR     R7, =0xFF1CBEA8 \n"
"    LDR     R4, =0x9BB8 \n"
"    LDR     R9, =0x6D6 \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF1CC45C:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02AFD0 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF1CC598 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF1CC598 \n"
"    B       loc_FF1CC538 \n"
"    B       loc_FF1CC55C \n"
"    B       loc_FF1CC56C \n"
"    B       loc_FF1CC574 \n"
"    B       loc_FF1CC57C \n"
"    B       loc_FF1CC584 \n"
"    B       loc_FF1CC540 \n"
"    B       loc_FF1CC58C \n"
"    B       loc_FF1CC54C \n"
"    B       loc_FF1CC598 \n"
"    B       loc_FF1CC594 \n"
"    B       loc_FF1CC504 \n"
"    B       loc_FF1CC4D4 \n"

"loc_FF1CC4D4:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R5, [R4, #0x34] \n"
"    STRH    R5, [R4, #6] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF4] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF1CC524 \n"

"loc_FF1CC504:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF4] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF1CC524:\n"
"    LDR     R2, =0xFF1CA740 \n"
"    LDR     R1, =0xC7A08 \n"
"    LDR     R0, =0xFF1CA854 \n"
"    BL      sub_FF047D68 \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC538:\n"
"    BL      sub_FF1CBA8C \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC540:\n"
"    LDR     R1, [R4, #0xF4] \n"
"    BLX     R1 \n"
"    LDR     R0, =0x9C3C \n"         //added, see FF1CC398
"    BL      set_quality \n"         //added
"    B       loc_FF1CC598 \n"

"loc_FF1CC54C:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF369524 \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC55C:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC56C:\n"
"    BL      sub_FF1CAE10 \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC574:\n"
"    BL      sub_FF1CAB08 \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC57C:\n"
"    BL      sub_FF1CA8AC \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC584:\n"
"    BL      sub_FF1CA4CC \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC58C:\n"
"    BL      sub_FF1CA44C \n"
"    B       loc_FF1CC598 \n"

"loc_FF1CC594:\n"
"    BL      sub_FF1CCB10 \n"

"loc_FF1CC598:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF1CA1A0 /*'MovieRecorder.c'*/ \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_FF02B948 /*_PostMessageQueueStrictly*/ \n"
"    B       loc_FF1CC45C \n"
);
}
