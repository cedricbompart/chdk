/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

// Forward declarations
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

void taskHook(context_t **context)
{
    task_t *tcb=(task_t*)((char*)context-offsetof(task_t, context));

    // Replace firmware task addresses with ours
    if(tcb->entry == (void*)task_CaptSeq)          tcb->entry = (void*)capt_seq_task;
    if(tcb->entry == (void*)task_InitFileModules)  tcb->entry = (void*)init_file_modules_task;
    if(tcb->entry == (void*)task_RotaryEncoder)    tcb->entry = (void*)JogDial_task_my;
    if(tcb->entry == (void*)task_MovieRecord)      tcb->entry = (void*)movie_record_task;
    if(tcb->entry == (void*)task_ExpDrv)           tcb->entry = (void*)exp_drv_task;
    if(tcb->entry == (void*)task_FileWrite)        tcb->entry = (void*)filewritetask;
}

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask() {
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
   Pointer to stack location where jogdial task records previous and
   current jogdial positions
-----------------------------------------------------------------------*/
short *jog_position;

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF00000C - 0xFF000184, length=95
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
"    MOV     R0, #0x37 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000037 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    LDR     R0, =0xD000002B \n"
"    MCR     p15, 0, R0, c6, c7 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x33333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x33333330 \n"
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
"    LDR     R0, =0xFF680924 \n"
"    LDR     R1, =0x685000 \n"
"    LDR     R3, =0x69544C \n"

"loc_FF000144:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000144 \n"
"    LDR     R0, =0xFF66DAAC \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x14778 \n"

"loc_FF000160:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000160 \n"
"    LDR     R1, =0x193A24 \n"
"    MOV     R2, #0 \n"

"loc_FF000178:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000178 \n"
"    B       sub_FF00038C_my \n"  // --> Patched. Old value = 0xFF00038C.
);
}

/*************************************************************/
//** sub_FF00038C_my @ 0xFF00038C - 0xFF0003F4, length=27
void __attribute__((naked,noinline)) sub_FF00038C_my() {

    //http://chdk.setepontos.com/index.php/topic,4194.0.html
    *(int*)0x1938=(int)taskHook;
    *(int*)0x193C=(int)taskHook;

    // From SX260: funnel testings for 100b sx260
    // Replacement of sub_FF04D3E8 for correct power-on.
    // (short press = playback mode, long press = record mode)
    *(int*)(0x2618+0x4) = (*(int*)0xC022F48C)&4 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF000404 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF00043C \n"

"loc_FF000398:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000398 \n"
"    LDR     R0, =0xFF00043C \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF000650 \n"

"loc_FF0003B4:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF0003B4 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003E8:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003E8 \n"
"    BL      sub_FF0011E4_my \n"  // --> Patched. Old value = 0xFF0011E4.
);
}

/*************************************************************/
//** sub_FF0011E4_my @ 0xFF0011E4 - 0xFF001290, length=44
void __attribute__((naked,noinline)) sub_FF0011E4_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_00690448 /*_bzero*/ \n"
"    MOV     R0, #0x67000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x193A24 \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x55D440 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x565C00 \n"
"    LDR     R0, =0x1CD \n"
"    STR     R1, [SP] \n"
"    STR     R0, [SP, #0x20] \n"
"    MOV     R0, #0x96 \n"
"    STR     R2, [SP, #0x10] \n"
"    STR     R1, [SP, #0x14] \n"
"    STR     R0, [SP, #0x24] \n"
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
"    LDR     R1, =sub_FF004294_my \n"  // --> Patched. Old value = 0xFF004294.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_00686778 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF004294_my @ 0xFF004294 - 0xFF004308, length=30
void __attribute__((naked,noinline)) sub_FF004294_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000B5C \n"
"    BL      sub_FF0053B8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043A8 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF003ECC \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043B0 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF0043C0 /*'/_term'*/ \n"
"    BL      sub_FF003FB4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043C8 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF0043C0 /*'/_term'*/ \n"
"    BL      sub_FF0029D4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043DC /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF004D54 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043E8 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF0016D4 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF0043F4 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF00B1C0.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF00B1C0 - 0xFF00B1EC, length=12
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_0068C118 \n"
"    BL      sub_0068C330 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =sub_FF00B19C_my \n"  // --> Patched. Old value = 0xFF00B19C.
"    MOV     R2, #0x200 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00B2C8 /*'Booting'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF00B19C_my @ 0xFF00B19C - 0xFF00B1BC, length=9
void __attribute__((naked,noinline)) sub_FF00B19C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
//"  BL      _sub_FF04D3E0 \n"  // --> Nullsub call removed.
"    BL      sub_FF02040C \n"
"    BL      sub_FF01E134 \n"
"    BL      sub_FF0272DC \n"
"    BL      sub_FF01E854 \n"
"    BL      sub_FF01D8E8 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF00B1F0_my \n"  // --> Patched. Old value = 0xFF00B1F0.
);
}

/*************************************************************/
//** sub_FF00B1F0_my @ 0xFF00B1F0 - 0xFF00B2C0, length=53
void __attribute__((naked,noinline)) sub_FF00B1F0_my() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    BL      sub_FF027078 \n"
"    MOVS    R6, R0 \n"
"    BNE     loc_FF00B254 \n"
"    BL      sub_FF020D40 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF00B254 \n"
"    MOV     R0, #0x37 \n"
"    BL      sub_FF0255E8 \n"
"    RSBS    R5, R0, #1 \n"
"    MOVCC   R5, #0 \n"
"    MOV     R0, #0x36 \n"
"    BL      sub_FF0255E8 \n"
"    RSBS    R4, R0, #1 \n"
"    MOVCC   R4, #0 \n"
"    ORRS    R0, R4, R5 \n"
"    BNE     loc_FF00B274 \n"
"    BL      sub_FF01E2C0 \n"
"    BL      sub_0068A7F8 /*_GetSRAndDisableInterrupt*/ \n"
"    LDR     R2, =0xC022C000 \n"
"    LDR     R1, [R2, #0x30C] \n"
"    BIC     R1, R1, #0x300 \n"
"    STR     R1, [R2, #0x30C] \n"
"    BL      sub_0068A7FC /*_SetSR*/ \n"

"loc_FF00B250:\n"
"    B       loc_FF00B250 \n"

"loc_FF00B254:\n"
"    MOV     R0, #0x36 \n"
"    BL      sub_FF0255E8 \n"
"    RSBS    R4, R0, #1 \n"
"    MOVCC   R4, #0 \n"
"    MOV     R0, #0x37 \n"
"    BL      sub_FF0255E8 \n"
"    RSBS    R5, R0, #1 \n"
"    MOVCC   R5, #0 \n"

"loc_FF00B274:\n"
"    MOV     R3, #0 \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R4 \n"
//"  BL      _sub_FF04D3E8 \n"  // See begin of sub_FF00038C_my
//"  BL      _sub_FF04D3E4 \n"  // --> Nullsub call removed.
"    BL      sub_0068C118 \n"
"    LDR     R1, =0x5CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF0253D4 \n"
"    BL      sub_0068C330 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00B140.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00B2DC /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3-R7,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00B140 - 0xFF00B198, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF0048D4 \n"
//"  BL      _sub_FF04DD7C \n"  // --> Nullsub call removed.
//"  BL      _sub_FF027184 \n"  // start diskboot.bin
"    BL      sub_FF027444 \n"
"    BL      sub_FF027610 \n"
//"  BL      _sub_FF027438 \n"  // --> Nullsub call removed.
"    BL      sub_FF02730C \n"
"    BL      sub_FF025308 \n"
"    BL      sub_FF027618 \n"

"    BL      CreateTask_spytask\n"  // added

"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF01F188.
"    LDR     PC, =0xFF00B16C \n"  // Continue in firmware
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF01F188 - 0xFF01F1A8, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C60 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF01F1BC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF01F154.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF01F1AC \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF08BBC4 - 0xFF08BBE0, length=8
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF080D64 \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF080D98 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    LDR     PC, =0xFF08BBE4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF04DEB0 - 0xFF04E1CC, length=200
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x1C \n"
"    BL      sub_FF04E23C \n"
"    LDR     R12, =0x262C \n"
"    LDR     R6, =0xFF441730 \n"
"    MOV     R0, #0 \n"
"    ADD     R10, SP, #8 \n"
"    ADD     R9, SP, #0xC \n"

// Save pointer for kbd.c routine
"    LDR     R2, =jog_position \n"
"    STR     R9, [R2] \n"

"loc_FF04DED0:\n"
"    ADD     R2, SP, #0x14 \n"
"    MOV     R1, #0 \n"
"    ADD     R4, R2, R0, LSL#1 \n"
"    ADD     R3, SP, #0x10 \n"
"    STRH    R1, [R4] \n"
"    ADD     R4, R3, R0, LSL#1 \n"
"    STRH    R1, [R4] \n"
"    STR     R1, [R9, R0, LSL#2] \n"
"    STR     R1, [R10, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #1 \n"
"    BLT     loc_FF04DED0 \n"

"loc_FF04DF00:\n"
"    LDR     R0, =0x262C \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_0068BBE4 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x200 \n"
"    LDRNE   R0, =0xFF04E15C /*'RotaryEncoder.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF04DF70 \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF04DFA8 \n"
"    CMP     R0, #0x300 \n"
"    BEQ     loc_FF04E1A0 \n"
"    CMP     R0, #0x400 \n"
"    BNE     loc_FF04DF00 \n"
"    CMP     R4, #0 \n"
"    LDRNE   R1, =0x27A \n"
"    LDRNE   R0, =0xFF04E15C /*'RotaryEncoder.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R0, LSL#2] \n"

"loc_FF04DF68:\n"
"    BL      sub_FF04E220 \n"
"    B       loc_FF04DF00 \n"

"loc_FF04DF70:\n"
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
"    LDR     R0, =0x2638 \n"
"    LDR     R0, [R0, R4, LSL#2] \n"
"    BL      sub_FF025BC4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF04DDFC \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF025AE0 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF04DF00 \n"
"    LDR     R1, =0x212 \n"
"    B       loc_FF04E14C \n"

"loc_FF04DFA8:\n"
"    RSB     R5, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    LDR     R1, =0xC0240000 \n"
"    ADD     R0, R1, R0, LSL#8 \n"
"    LDR     R0, [R0, #0x104] \n"
"    MOV     R1, R0, ASR#16 \n"
"    ADD     R0, SP, #0x14 \n"
"    ADD     R11, R0, R4, LSL#1 \n"
"    ADD     R0, SP, #0x10 \n"
"    ADD     R0, R0, R4, LSL#1 \n"
"    STRH    R1, [R11] \n"
"    STR     R0, [SP, #0x18] \n"
"    LDRSH   R3, [R0] \n"
"    SUB     R2, R1, R3 \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF04E02C \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF04E108 \n"
"    LDR     R7, =0x2638 \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF025BC4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF04DE08 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF025AE0 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF04E108 \n"
"    LDR     R1, =0x22B \n"
"    B       loc_FF04E100 \n"

"loc_FF04E02C:\n"
"    MOV     R0, R2 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF04E068 \n"
"    LDR     R0, =0x7FFF \n"
"    CMP     R2, #0 \n"
"    SUBLE   R0, R0, R3 \n"
"    ADDLE   R0, R0, R1 \n"
"    SUBGT   R0, R0, R1 \n"
"    ADDGT   R0, R0, R3 \n"
"    MVN     R1, #0x8000 \n"
"    SUB     R0, R0, R1 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF04E068:\n"
"    STR     R0, [SP, #4] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF04E0A0 \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF04E0A4 \n"
"    LDR     R0, [R8, #0xC] \n"
"    BL      sub_FF01F1E0 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF04E0A0:\n"
"    BL      sub_FF01F1E0 \n"

"loc_FF04E0A4:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #4] \n"
"    BL      sub_FF01F1F0 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x2638 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDRH    R1, [R11] \n"
"    LDR     R0, [SP, #0x18] \n"
"    STRH    R1, [R0] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF025BC4 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF04DE08 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF025AE0 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF04E108 \n"
"    MOV     R1, #0x25C \n"

"loc_FF04E100:\n"
"    LDR     R0, =0xFF04E15C /*'RotaryEncoder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF04E108:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF04E198 \n"
"    LDR     R0, =0x262C \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF04E198 \n"
"    LDR     R2, =0xFF04DDFC \n"
"    ORR     R3, R4, #0x400 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF025AE0 /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF04DF00 \n"
"    LDR     R1, =0x263 \n"

"loc_FF04E14C:\n"
"    LDR     R0, =0xFF04E15C /*'RotaryEncoder.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF04DF00 \n"

"loc_FF04E198:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    B       loc_FF04DF68 \n"

"loc_FF04E1A0:\n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x26D \n"
"    LDREQ   R0, =0xFF04E15C /*'RotaryEncoder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF01F1E0 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    B       loc_FF04DF00 \n"
);
}
