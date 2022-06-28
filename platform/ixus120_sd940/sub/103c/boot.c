/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

#define LED_GREEN  0xC0220130
#define LED_ORANGE 0xC0220134
#define LED_AF     0xC0223030

const char * const new_sa = &_end;

// Forward declarations
void Battery_door_hack();

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

void taskHook(context_t **context)
{
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    // Replace firmware task addresses with ours
    if(tcb->entry == (void*)task_CaptSeq)           tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)   tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_MovieRecord)       tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)            tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_FileWrite)         tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask() {
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
};

/*-------------------------------------------------------
	Memory Map:
		1900		MEMBASEADDR				start of data	used for initialized vars
		df03								end of data
		df04								start of bss - used for zeroed/uninited vars
		13ca17								end of bss
		13ca18		MEMISOSTART				start of our data / bss
		174000		MEMISOSTART+MEMIOSIZE	end of our data/bss (approx)
		???									end of memory

		400000								video buffers ??

		ff810000	ROMBASEADDR				start of rom
		ffffffff							end of rom
-------------------------------------------------------*/


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
"    LDR     R0, =0xFFBBECD0 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0xDF04 \n"

"loc_FF81013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81013C \n"
"    LDR     R1, =0x13CA18 \n"
"    MOV     R2, #0 \n"

"loc_FF810154:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF810154 \n"
"    B       sub_FF810354_my \n"  // --> Patched. Old value = 0xFF810354.
);
}

/*************************************************************/
//** sub_FF810354_my @ 0xFF810354 - 0xFF8103BC, length=27
void __attribute__((naked,noinline)) sub_FF810354_my() {

    *(int*)0x1938=(int)taskHook;
    *(int*)0x1940=(int)taskHook;

    // replacement of sub_FF8586DC for correct power-on.
    if ((*(int*) 0xC0220128) & 1)    // look at play switch
        *(int*)(0x22FC) = 0x400000;  // start in play mode
    else
        *(int*)(0x22FC) = 0x200000;  // start in rec mode

asm volatile (
"    LDR     R0, =0xFF8103CC \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF810404 \n"

"loc_FF810360:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF810360 \n"
"    LDR     R0, =0xFF810404 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF810618 \n"

"loc_FF81037C:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF81037C \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF8103B0:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF8103B0 \n"
"    BL      sub_FF811178_my \n"  // --> Patched. Old value = 0xFF811178.
);
}

/*************************************************************/
//** sub_FF811178_my @ 0xFF811178 - 0xFF811224, length=44
void __attribute__((naked,noinline)) sub_FF811178_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R0, SP \n"
"    MOV     R1, #0x74 \n"
"    BL      sub_FFB07C00 /*_bzero*/ \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x13CA18 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x2F9C00 \n"
"    LDR     R1, =0x2F24A8 \n"
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
"    LDR     R1, =sub_FF815E34_my \n"  // --> Patched. Old value = 0xFF815E34.
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
"    BL      sub_FF8133E4 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF815E34_my @ 0xFF815E34 - 0xFF815EA8, length=30
void __attribute__((naked,noinline)) sub_FF815E34_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF810B08 \n"
"    BL      sub_FF81A148 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F48 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF815A70 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F50 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF815F60 /*'/_term'*/ \n"
"    BL      sub_FF815B58 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F68 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF815F60 /*'/_term'*/ \n"
"    BL      sub_FF813BE0 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F7C /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF819B5C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F88 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF81165C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF815F94 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF81F868.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF81F868 - 0xFF81F8DC, length=30
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF8586D4 \n"  // --> Nullsub call removed.
"    BL      sub_FF83A0E4 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81F8A0 \n"
"    BL      sub_FF8586B8 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF81F8A0 \n"
"    BL      sub_FF8329A4 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R1, #0x1C] \n"
"    BL      sub_FF832B94 \n"

"loc_FF81F89C:\n"
"    B       loc_FF81F89C \n"

"loc_FF81F8A0:\n"
//"  BL      _sub_FF8586DC \n"  // Removed for correct power-on
//"  BL      _sub_FF8586D8 \n"  // --> Nullsub call removed.
"    BL      sub_FF838394 \n"
"    LDR     R1, =0x34E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8387DC \n"
"    BL      sub_FF838588 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF81F804.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF81F8E8 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R12,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF81F804 - 0xFF81F864, length=25
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF816490 \n"
"    BL      sub_FF8343EC \n"
"    BL      sub_FF832660 \n"
//"  BL      _sub_FF858E3C \n"  // --> Nullsub call removed.
"    BL      sub_FF83A308 \n"
//"  BL      _sub_FF83A1B8 \n"  // start diskboot.bin
"    BL      sub_FF88ACEC \n"
"    BL      sub_FF83135C \n"
"    BL      sub_FF83A338 \n"
"    BL      sub_FF837B38 \n"
"    BL      sub_FF83A4AC \n"

"    BL      CreateTask_spytask\n"  // added

"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF8331F8.
"    BL      sub_FF835FB4 \n"
"    BL      sub_FF83A4C4 \n"
//"  BL      _sub_FF830694 \n"  // --> Nullsub call removed.

#if defined(OPT_RUN_WITH_BATT_COVER_OPEN)
"    BL      Battery_door_hack\n"  // added
#endif

"    BL      sub_FF831FB8 \n"
"    BL      sub_FF839EC0 \n"
"    BL      sub_FF832614 \n"
"    BL      sub_FF831EC4 \n"
"    BL      sub_FF831390 \n"
"    BL      sub_FF83AF44 \n"
"    BL      sub_FF831E9C \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF8165B0 \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF8331F8 - 0xFF833218, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C38 \n"
"    LDR     R0, [R4, #0x10] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF83322C \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF8331C4.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF83321C \n"  // Continue in firmware
);
}
/*************************************************************/
//** Battery_door_hack - loop hack that allows startup with battery door open
#if defined(OPT_RUN_WITH_BATT_COVER_OPEN)
void __attribute__((naked,noinline)) Battery_door_hack() {
asm volatile (
"		STMFD   SP!, {R4-R6,LR} \n"
"		LDR     R0, =0x400000 \n"
"loop1: \n"
"		nop\n"
"       SUBS   R0,R0,#1 \n"
"		BNE    loop1 \n"
"       LDMFD   SP!, {R4-R6,PC} \n"
);
}
#endif

/*************************************************************/
//** init_file_modules_task @ 0xFF88E57C - 0xFF88E5B0, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF885224 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF885250_my \n"  // --> Patched. Old value = 0xFF885250.
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
//** sub_FF885250_my @ 0xFF885250 - 0xFF885258, length=3
void __attribute__((naked,noinline)) sub_FF885250_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    MOV     R0, #3 \n"
"    BL      sub_FF8683A0_my \n"  // --> Patched. Old value = 0xFF8683A0.
"    LDR     PC, =0xFF88525C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8683A0_my @ 0xFF8683A0 - 0xFF8683F4, length=22
void __attribute__((naked,noinline)) sub_FF8683A0_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    MOV     R8, R0 \n"
"    BL      sub_FF868320 \n"
"    LDR     R1, =0x366A0 \n"
"    MOV     R6, R0 \n"
"    ADD     R4, R1, R0, LSL#7 \n"
"    LDR     R0, [R4, #0x6C] \n"
"    CMP     R0, #4 \n"
"    LDREQ   R1, =0x804 \n"
"    LDREQ   R0, =0xFF867E6C /*'Mounter.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF867BC0 \n"
"    LDR     R0, [R4, #0x38] \n"
"    BL      sub_FF8689BC \n"
"    CMP     R0, #0 \n"
"    STREQ   R0, [R4, #0x6C] \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF867C50 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF867FD4_my \n"  // --> Patched. Old value = 0xFF867FD4.
"    LDR     PC, =0xFF8683F8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF867FD4_my @ 0xFF867FD4 - 0xFF867FFC, length=11
void __attribute__((naked,noinline)) sub_FF867FD4_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, =0x366A0 \n"
"    ADD     R4, R0, R5, LSL#7 \n"
"    LDR     R0, [R4, #0x6C] \n"
"    TST     R0, #2 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4, #0x38] \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF867CD0_my \n"  // --> Patched. Old value = 0xFF867CD0.
"    LDR     PC, =0xFF868000 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF867CD0_my @ 0xFF867CD0 - 0xFF867E40, length=93
void __attribute__((naked,noinline)) sub_FF867CD0_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, =0x366A0 \n"
"    MOV     R8, #0 \n"
"    ADD     R5, R0, R1, LSL#7 \n"
"    LDR     R0, [R5, #0x3C] \n"
"    MOV     R7, #0 \n"
"    CMP     R0, #7 \n"
"    MOV     R6, #0 \n"
"    ADDLS   PC, PC, R0, LSL#2 \n"
"    B       loc_FF867E28 \n"
"    B       loc_FF867D34 \n"
"    B       loc_FF867D1C \n"
"    B       loc_FF867D1C \n"
"    B       loc_FF867D1C \n"
"    B       loc_FF867D1C \n"
"    B       loc_FF867E20 \n"
"    B       loc_FF867D1C \n"
"    B       loc_FF867D1C \n"

"loc_FF867D1C:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x200 \n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ualloc \n"
"    MOVS    R4, R0 \n"
"    BNE     loc_FF867D3C \n"

"loc_FF867D34:\n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R4-R10,PC} \n"

"loc_FF867D3C:\n"
"    LDR     R12, [R5, #0x50] \n"
"    MOV     R3, R4 \n"
"    MOV     R2, #1 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R9 \n"
"    BLX     R12 \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF867D68 \n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ufree \n"
"    B       loc_FF867D34 \n"

"loc_FF867D68:\n"
"    LDR     R1, [R5, #0x64] \n"
"    MOV     R0, R9 \n"
"    BLX     R1 \n"

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
"    BNE     loc_FF867DF4 \n"
"    CMP     R0, R1 \n"
"    BCC     loc_FF867DF4 \n"
"    ADD     R2, R1, R3 \n"
"    CMP     R2, R0 \n"
"    CMPLS   R12, #0x55 \n"
"    CMPEQ   LR, #0xAA \n"
"    MOVEQ   R7, R1 \n"
"    MOVEQ   R6, R3 \n"
"    MOVEQ   R4, #1 \n"
"    BEQ     loc_FF867DF8 \n"

"loc_FF867DF4:\n"
"    MOV     R4, R8 \n"

"loc_FF867DF8:\n"
"    MOV     R0, #2 \n"
"    BL      _exmem_ufree \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF867E34 \n"
"    LDR     R1, [R5, #0x64] \n"
"    MOV     R7, #0 \n"
"    MOV     R0, R9 \n"
"    BLX     R1 \n"
"    MOV     R6, R0 \n"
"    B       loc_FF867E34 \n"

"loc_FF867E20:\n"
"    MOV     R6, #0x40 \n"
"    B       loc_FF867E34 \n"

"loc_FF867E28:\n"
"    LDR     R1, =0x568 \n"
"    LDR     R0, =0xFF867E6C /*'Mounter.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF867E34:\n"
"    STR     R7, [R5, #0x44]! \n"
"    STMIB   R5, {R6,R8} \n"
"    MOV     R0, #1 \n"
"    LDMFD   SP!, {R4-R10,PC} \n"
);
}
