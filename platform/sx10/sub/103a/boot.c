/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();
extern void task_RotaryEncoder();
void JogDial_task_my(void);

void taskHook(context_t **context)
{
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    // Replace firmware task addresses with ours
    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_RotaryEncoder)     tcb->entry = (void*)JogDial_task_my;
    if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask() {
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF81000C - 0xFF810160, length=86
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    MOV     R1, #0 \n"
"    MCR     p15, 0, R1, c7, c10, 4 \n"
"    MCR     p15, 0, R1, c7, c5 \n"
"    MCR     p15, 0, R1, c7, c6 \n"
"    MOV     R0, #0x3D \n"
"    MCR     p15, 0, R0, c6, c0 \n"
"    MOV     R0, #0xC000002F \n"
"    MCR     p15, 0, R0, c6, c1 \n"
"    MOV     R0, #0x33 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000033 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF80002D \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 3 \n"
"    MRC     p15, 0, R0, c1, c0 \n"
"    ORR     R0, R0, #0x1000 \n"
"    ORR     R0, R0, #4 \n"
"    ORR     R0, R0, #1 \n"
"    MCR     p15, 0, R0, c1, c0 \n"
"    MOV     R1, #0x80000006 \n"
"    MCR     p15, 0, R1, c9, c1 \n"
"    MOV     R1, #6 \n"
"    MCR     p15, 0, R1, c9, c1, 1 \n"
"    MRC     p15, 0, R1, c1, c0 \n"
"    ORR     R1, R1, #0x50000 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    LDR     R2, =0xC0200000 \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R2, #0x10C] \n"
"    MOV     R1, #0xFF \n"
"    STR     R1, [R2, #0xC] \n"
"    STR     R1, [R2, #0x1C] \n"
"    STR     R1, [R2, #0x2C] \n"
"    STR     R1, [R2, #0x3C] \n"
"    STR     R1, [R2, #0x4C] \n"
"    STR     R1, [R2, #0x5C] \n"
"    STR     R1, [R2, #0x6C] \n"
"    STR     R1, [R2, #0x7C] \n"
"    STR     R1, [R2, #0x8C] \n"
"    STR     R1, [R2, #0x9C] \n"
"    STR     R1, [R2, #0xAC] \n"
"    STR     R1, [R2, #0xBC] \n"
"    STR     R1, [R2, #0xCC] \n"
"    STR     R1, [R2, #0xDC] \n"
"    STR     R1, [R2, #0xEC] \n"
"    STR     R1, [R2, #0xFC] \n"
"    LDR     R1, =0xC0400008 \n"
"    LDR     R2, =0x430005 \n"
"    STR     R2, [R1] \n"
"    MOV     R1, #1 \n"
"    LDR     R2, =0xC0243100 \n"
"    STR     R2, [R1] \n"
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFFB9B3EC \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x10A58 \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R1, =0xACB74 \n"
"    MOV     R2, #0 \n"

"loc_FF810154:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF810154 \n"
"    B       sub_FF8101A0_my \n"  // --> Patched. Old value = 0xFF8101A0.
);
}

/*************************************************************/
//** sub_FF8101A0_my @ 0xFF8101A0 - 0xFF810208, length=27
void __attribute__((naked,noinline)) sub_FF8101A0_my() {

    *(int*)0x1930=(int)taskHook;
    *(int*)0x1934=(int)taskHook;

    // replacement of sub_FF8218C8 for correct power-on.
    //(short press = playback mode, long press = record mode)
    *(int*)(0x25BC+0x4)= (*(int*)0xC0220134)&1 ? 0x2000000 : 0x1000000;

asm volatile (
"    LDR     R0, =0xFF810218 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810250 \n"

"loc_FF8101AC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8101AC \n"
"    LDR     R0, =0xFF810250 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF810464 \n"

"loc_FF8101C8:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8101C8 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF8101FC:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF8101FC \n"
"    BL      sub_FF810F94_my \n"  // --> Patched. Old value = 0xFF810F94.
);
}

/*************************************************************/
//** sub_FF810F94_my @ 0xFF810F94 - 0xFF811040, length=44
void __attribute__((naked,noinline)) sub_FF810F94_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFB003D0 /*_bzero*/ \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0xACB74 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x2B9C00 \n"
"    LDR     R1, =0x2B24A8 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R1, R0 \n"
"    ADD     R3, SP, #0xC \n"
"    STR     R2, [SP] \n"
"    STMIA   R3, {R0-R2} \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R0, =0x19B \n"
"    LDR     R1, =sub_FF814D8C_my \n"  // --> Patched. Old value = 0xFF814D8C.
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x96 \n"
"    STR     R0, [SP, #0x24] \n"
"    MOV     R0, #0x78 \n"
"    STR     R0, [SP, #0x28] \n"
"    MOV     R0, #0x64 \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x30] \n"
"    STR     R0, [SP, #0x34] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x5C] \n"
"    MOV     R0, #0x800 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0xA0 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x280 \n"
"    STR     R0, [SP, #0x68] \n"
"    MOV     R0, SP \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF812D38 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF814D8C_my @ 0xFF814D8C - 0xFF814E00, length=30
void __attribute__((naked,noinline)) sub_FF814D8C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF810940 \n"
"    BL      sub_FF81901C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EA0 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8149B4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EA8 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF814EB8 /*'/_term'*/ \n"
"    BL      sub_FF814A9C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EC0 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF814EB8 /*'/_term'*/ \n"
"    BL      sub_FF813548 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814ED4 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF818BA4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EE0 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF811478 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF814EEC /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF81C1A8.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF81C1A8 - 0xFF81C21C, length=30
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF84AED0 \n"  // --> Nullsub call removed.
"    BL      sub_FF829940 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81C1E0 \n"
"    BL      sub_FF84AEB4 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81C1E0 \n"
"    BL      sub_FF821050 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0x1C] \n"
"    BL      sub_FF82123C \n"

"loc_FF81C1DC:\n"
"    B       loc_FF81C1DC \n"

"loc_FF81C1E0:\n"
//"  BL      _sub_FF84AED8 \n"  // Removed for correct power-on
//"  BL      _sub_FF84AED4 \n"  // --> Nullsub call removed.
"    BL      sub_FF827AC8 \n"
"    LDR     R1, =0x30E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF827F10 \n"
"    BL      sub_FF827CBC /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81C144.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF81C228 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R12,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81C144 - 0xFF81C1A4, length=25
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF8153CC \n"
"    BL      sub_FF822A24 \n"
"    BL      sub_FF820CE8 \n"
//"  BL      _sub_FF84B83C \n"  // --> Nullsub call removed.
"    BL      sub_FF829B48 \n"
//"  BL      _sub_FF829A08 \n"  // start diskboot.bin
"    BL      sub_FF881240 \n"
"    BL      sub_FF81FAA0 \n"
"    BL      sub_FF829B98 \n"
"    BL      sub_FF8270C8 \n"
"    BL      sub_FF829D04 \n"
"    BL      CreateTask_spytask\n"  // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF8217B8.
"    BL      sub_FF8249EC \n"
"    BL      sub_FF829D1C \n"
//"  BL      _sub_FF81EEF8 \n"  // --> Nullsub call removed.
"    BL      sub_FF82062C \n"
"    BL      sub_FF829718 \n"
"    BL      sub_FF820C98 \n"
"    BL      sub_FF820548 \n"
"    BL      sub_FF81FAD4 \n"
"    BL      sub_FF82A854 \n"
"    BL      sub_FF820520 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF815490 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF8217B8 - 0xFF8217D8, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C24 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF8217EC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF821784.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF8217DC \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF884AF4 - 0xFF884B28, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF87A018 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF87A044_my \n"  // --> Patched. Old value = 0xFF87A044.
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    MOVEQ   R0, R5 \n"
"    LDMEQFD SP!, {R4-R6,LR} \n"
"    MOVEQ   R1, #0 \n"
"    BEQ     _PostLogicalEventToUI \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF87A044_my @ 0xFF87A044 - 0xFF87A048, length=2
void __attribute__((naked,noinline)) sub_FF87A044_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF85AB08_my \n"  // --> Patched. Old value = 0xFF85AB08.
"    LDR     PC, =0xFF87A04C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF85AB08_my @ 0xFF85AB08 - 0xFF85AB48, length=17
void __attribute__((naked,noinline)) sub_FF85AB08_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF85A5C8 \n"
"    LDR     R4, =0x1A784 \n"
"    MOV     R5, #0 \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FF85B028 \n"
"    CMP     R0, #0 \n"
"    LDREQ   R0, =0x2A70 \n"
"    STREQ   R5, [R0, #0x10] \n"
"    STREQ   R5, [R0, #0x14] \n"
"    STREQ   R5, [R0, #0x18] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF85A608 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF85A944_my \n"  // --> Patched. Old value = 0xFF85A944.
"    LDR     PC, =0xFF85AB4C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF85A944_my @ 0xFF85A944 - 0xFF85A978, length=14
void __attribute__((naked,noinline)) sub_FF85A944_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x2A70 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x14] \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R6 \n"
"    LDR     R0, =0x1A784 \n"
"    ADD     R4, R0, R1, LSL#2 \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R6 \n"
"    BL      sub_FF85A6D4_my \n"  // --> Patched. Old value = 0xFF85A6D4.
"    LDR     PC, =0xFF85A97C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF85A6D4_my @ 0xFF85A6D4 - 0xFF85A838, length=90
void __attribute__((naked,noinline)) sub_FF85A6D4_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    MOV     R0, #0x17 \n"
"    MUL     R1, R0, R1 \n"
"    LDR     R0, =0x1A784 \n"
"    MOV     R6, #0 \n"
"    ADD     R7, R0, R1, LSL#2 \n"
"    LDR     R0, [R7, #0x3C] \n"
"    MOV     R5, #0 \n"
"    CMP     R0, #6 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FF85A820 \n"
"    B       loc_FF85A738 \n"
"    B       loc_FF85A720 \n"
"    B       loc_FF85A720 \n"
"    B       loc_FF85A720 \n"
"    B       loc_FF85A720 \n"
"    B       loc_FF85A818 \n"
"    B       loc_FF85A720 \n"

"loc_FF85A720:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ualloc \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FF85A740 \n"

"loc_FF85A738:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"

"loc_FF85A740:\n"
"    LDR     R12, [R7, #0x4C] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R8 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF85A76C \n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ufree \n"
"    B       loc_FF85A738 \n"

"loc_FF85A76C:\n"
"    MOV     R0, R8 \n"
"    BL      sub_FF92AE88 \n"

"    MOV     R1, R4\n"              //  pointer to MBR in R1
"    BL      mbr_read_dryos\n"      //  total sectors count in R0 before and after call

// Start of DataGhost's FAT32 autodetection code
// Policy: If there is a partition which has type W95 FAT32, use the first one of those for image storage
// According to the code below, we can use R1, R2, R3 and R12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    MOV     R12, R4\n"             // Copy the MBR start address so we have something to work with
"    MOV     LR, R4\n"              // Save old offset for MBR signature
"    MOV     R1, #1\n"              // Note the current partition number
"    B       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    CMP     R1, #4\n"              // Did we already see the 4th partition?
"    BEQ     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    ADD     R12, R12, #0x10\n"     // Second partition
"    ADD     R1, R1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    LDRB    R2, [R12, #0x1BE]\n"   // Partition status
"    LDRB    R3, [R12, #0x1C2]\n"   // Partition type (FAT32 = 0xB)
"    CMP     R3, #0xB\n"            // Is this a FAT32 partition?
"    CMPNE   R3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    CMPNE   R3, #0x7\n"            // exFat?
"    BNE     dg_sd_fat32\n"         // No, it isn't. Loop again.
"    CMP     R2, #0x00\n"           // It is, check the validity of the partition type
"    CMPNE   R2, #0x80\n"
"    BNE     dg_sd_fat32\n"         // Invalid, go to next partition
                                    // This partition is valid, it's the first one, bingo!
"    MOV     R4, R12\n"             // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

"    LDRB    R1, [R4, #0x1C9] \n"
"    LDRB    R3, [R4, #0x1C8] \n"
"    LDRB    R12, [R4, #0x1CC] \n"
"    MOV     R1, R1, LSL#24 \n"
"    ORR     R1, R1, R3, LSL#16 \n"
"    LDRB    R3, [R4, #0x1C7] \n"
"    LDRB    R2, [R4, #0x1BE] \n"
//"  LDRB    LR, [R4, #0x1FF] \n"  // replaced below
"    ORR     R1, R1, R3, LSL#8 \n"
"    LDRB    R3, [R4, #0x1C6] \n"
"    CMP     R2, #0 \n"
"    CMPNE   R2, #0x80 \n"
"    ORR     R1, R1, R3 \n"
"    LDRB    R3, [R4, #0x1CD] \n"
"    MOV     R3, R3, LSL#24 \n"
"    ORR     R3, R3, R12, LSL#16 \n"
"    LDRB    R12, [R4, #0x1CB] \n"
"    ORR     R3, R3, R12, LSL#8 \n"
"    LDRB    R12, [R4, #0x1CA] \n"
"    ORR     R3, R3, R12 \n"
//"  LDRB    R12, [R4, #0x1FE] \n"  // replaced below
"    LDRB    R12, [LR,#0x1FE]\n"    // replace instructions above - First MBR signature byte (0x55), LR is original offset.
"    LDRB    LR, [LR,#0x1FF]\n"     // replace instructions above - Last MBR signature byte (0xAA), LR is original offset.
"    MOV     R4, #0 \n"
"    BNE     loc_FF85A7F4 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FF85A7F4 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R6, R1 \n"
"    MOVEQ   R5, R3 \n"
"    MOVEQ   R4, #1 \n"

"loc_FF85A7F4:\n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ufree \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF85A82C \n"
"    MOV     R6, #0 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF92AE88 \n"
"    MOV     R5, R0 \n"
"    B       loc_FF85A82C \n"

"loc_FF85A818:\n"
"    MOV     R5, #0x40 \n"
"    B       loc_FF85A82C \n"

"loc_FF85A820:\n"
"    LDR     R1, =0x37A \n"
"    LDR     R0, =0xFF85A6C8 /*'Mounter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF85A82C:\n"
"    STR     R6, [R7, #0x44]! \n"
"    MOV     R0, #1 \n"
"    STR     R5, [R7, #4] \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF84B8D8 - 0xFF84B9D0, length=63
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R3-R11,LR} \n"
"    BL      sub_FF84BA88 \n"
"    LDR     R11, =0x80000B01 \n"
"    LDR     R8, =0xFFB0AFA8 \n"
"    LDR     R7, =0xC0240000 \n"
"    LDR     R6, =0x25D8 \n"
"    MOV     R9, #1 \n"
"    MOV     R10, #0 \n"

"loc_FF84B8F8:\n"
"    LDR     R3, =0x1AE \n"
"    LDR     R0, [R6, #0xC] \n"
"    LDR     R2, =0xFF84BB30 /*'JogDial.c'*/ \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF827DF8 /*_TakeSemaphoreStrictly*/ \n"
"    MOV     R0, #0x28 \n"
"    BL      _SleepTask \n"
//------------------  added code ---------------------
"labelA:\n"
"    LDR     R0, =jogdial_stopped\n"
"    LDR     R0, [R0]\n"
"    CMP     R0, #1\n"
"    BNE     labelB\n"
"    MOV     R0, #40\n"
"    BL      _SleepTask\n"
"    B       labelA\n"
"labelB:\n"
//------------------  original code ------------------
"    LDR     R0, [R7, #0x104] \n"
"    MOV     R0, R0, ASR#16 \n"
"    STRH    R0, [R6] \n"
"    LDRSH   R2, [R6, #2] \n"
"    SUB     R1, R0, R2 \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FF84B9BC \n"
"    MOV     R5, R1 \n"
"    RSBLT   R5, R5, #0 \n"
"    MOVLE   R4, #0 \n"
"    MOVGT   R4, #1 \n"
"    CMP     R5, #0xFF \n"
"    BLS     loc_FF84B970 \n"
"    CMP     R1, #0 \n"
"    RSBLE   R1, R2, #0xFF \n"
"    ADDLE   R1, R1, #0x7F00 \n"
"    ADDLE   R0, R1, R0 \n"
"    RSBGT   R0, R0, #0xFF \n"
"    ADDGT   R0, R0, #0x7F00 \n"
"    ADDGT   R0, R0, R2 \n"
"    ADD     R5, R0, #0x8000 \n"
"    ADD     R5, R5, #1 \n"
"    EOR     R4, R4, #1 \n"

"loc_FF84B970:\n"
"    LDR     R0, [R6, #0x14] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF84B9B4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF84B99C \n"
"    LDR     R1, [R8, R4, LSL#2] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF84B9A4 \n"
"    LDR     R0, =0xB01 \n"
"    BL      sub_FF880C58 \n"

"loc_FF84B99C:\n"
"    MOV     R0, R11 \n"
"    BL      sub_FF880C58 \n"

"loc_FF84B9A4:\n"
"    LDR     R0, [R8, R4, LSL#2] \n"
"    MOV     R1, R5 \n"
"    STR     R0, [R6, #0x1C] \n"
"    BL      sub_FF880B80 \n"

"loc_FF84B9B4:\n"
"    LDRH    R0, [R6] \n"
"    STRH    R0, [R6, #2] \n"

"loc_FF84B9BC:\n"
"    STR     R10, [R7, #0x100] \n"
"    STR     R9, [R7, #0x108] \n"
"    LDR     R0, [R6, #0x10] \n"
"    CMP     R0, #0 \n"
"    BLNE    _SleepTask \n"
"    B       loc_FF84B8F8 \n"
);
}
