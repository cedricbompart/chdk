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
//** boot @ 0xFF00000C - 0xFF000160, length=86
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
"    MOV     R0, #0x35 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000035 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF00002F \n"
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
"    LDR     R0, =0xFF4B5064 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x11C18 \n"

"loc_FF00013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF00013C \n"
"    LDR     R1, =0x18A7FC \n"
"    MOV     R2, #0 \n"

"loc_FF000154:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF000154 \n"
"    B       sub_FF000358_my \n"  // --> Patched. Old value = 0xFF000358.
);
}

/*************************************************************/
//** sub_FF000358_my @ 0xFF000358 - 0xFF0003C0, length=27
void __attribute__((naked,noinline)) sub_FF000358_my() {

    //http://chdk.setepontos.com/index.php/topic,4194.0.html
    *(int*)0x1938=(int)taskHook;
    *(int*)0x193C=(int)taskHook;

    // Replacement of sub_FF85FC4C (sub_FF834388) for correct power-on.
    // (short press = playback mode, long press = record mode)
    *(int*)(0x25E4) = (*(int*)0xC022012C)&1 ? 0x200000 : 0x100000;

asm volatile (
"    LDR     R0, =0xFF0003D0 \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF000408 \n"

"loc_FF000364:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000364 \n"
"    LDR     R0, =0xFF000408 \n"
"    MOV     R1, #0x4B0 \n"
"    LDR     R3, =0xFF00061C \n"

"loc_FF000380:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF000380 \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x6C4 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF0003B4:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF0003B4 \n"
"    BL      sub_FF0011B0_my \n"  // --> Patched. Old value = 0xFF0011B0.
);
}

/*************************************************************/
//** sub_FF0011B0_my @ 0xFF0011B0 - 0xFF00125C, length=44
void __attribute__((naked,noinline)) sub_FF0011B0_my() {
asm volatile (
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x74 \n"
"    MOV     R1, #0x74 \n"
"    MOV     R0, SP \n"
"    BL      sub_FF3B60A8 /*_bzero*/ \n"
"    MOV     R0, #0x53000 \n"
"    STR     R0, [SP, #4] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x18A7FC \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x371F80 \n"
"    STR     R0, [SP, #8] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0xC] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x18] \n"
"    MOV     R0, #0x68 \n"
"    STR     R0, [SP, #0x1C] \n"
"    LDR     R1, =0x379C00 \n"
"    LDR     R0, =0x19B \n"
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
"    LDR     R1, =sub_FF005EE0_my \n"  // --> Patched. Old value = 0xFF005EE0.
"    MOV     R2, #0 \n"
"    MOV     R0, SP \n"
"    BL      sub_FF0034C4 \n"
"    ADD     SP, SP, #0x74 \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF005EE0_my @ 0xFF005EE0 - 0xFF005F54, length=30
void __attribute__((naked,noinline)) sub_FF005EE0_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF000B28 \n"
"    BL      sub_FF00A374 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF005FF4 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF005B18 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF005FFC /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF00600C /*'/_term'*/ \n"
"    BL      sub_FF005C00 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF006014 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    LDR     R0, =0xFF00600C /*'/_term'*/ \n"
"    BL      sub_FF003CA8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF006028 /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF009D00 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF006034 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF001690 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF006040 /*'armlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       taskcreate_Startup_my \n"  // --> Patched. Old value = 0xFF00FD54.
);
}

/*************************************************************/
//** taskcreate_Startup_my @ 0xFF00FD54 - 0xFF00FD80, length=12
void __attribute__((naked,noinline)) taskcreate_Startup_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
"    BL      sub_FF02B74C \n"
"    BL      sub_FF02B964 /*_EnableDispatch*/ \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =sub_FF00FC6C_my \n"  // --> Patched. Old value = 0xFF00FC6C.
"    MOV     R2, #0x200 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00FDA0 /*'Booting'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** sub_FF00FC6C_my @ 0xFF00FC6C - 0xFF00FD50, length=58
void __attribute__((naked,noinline)) sub_FF00FC6C_my() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    MOV     R5, #0 \n"
//"  BL      _sub_FF056DAC \n"  // --> Nullsub call removed.
"    BL      sub_FF025C30 \n"
"    BL      sub_FF023C70 \n"
"    BL      sub_FF02D904 \n"
"    BL      sub_FF024E90 \n"
"    BL      sub_FF02389C \n"
"    BL      sub_FF023C0C \n"
"    BL      sub_FF02D674 \n"
"    LDR     R7, =0xC0220000 \n"
"    MOVS    R9, R0 \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF00FD00 \n"
"    BL      sub_FF0263C0 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF00FD00 \n"
"    LDR     R0, [R7, #0xD4] \n"
"    BICS    R4, R8, R0 \n"
"    BEQ     loc_FF00FCCC \n"
"    MOV     R0, #0x12C \n"
"    BL      _SleepTask \n"
"    LDR     R0, [R7, #0xD4] \n"
"    BIC     R4, R8, R0 \n"

"loc_FF00FCCC:\n"
"    LDR     R0, [R7, #0x12C] \n"
"    BIC     R6, R8, R0 \n"
"    BL      sub_FF023C34 \n"
"    CMP     R0, #1 \n"
"    MOVEQ   R5, #1 \n"
"    ORR     R0, R6, R4 \n"
"    ORRS    R0, R0, R5 \n"
"    BNE     loc_FF00FD10 \n"
"    BL      sub_FF024064 \n"
"    MOV     R0, #0x44 \n"
"    STR     R0, [R7, #0x1C] \n"
"    BL      sub_FF024258 \n"

"loc_FF00FCFC:\n"
"    B       loc_FF00FCFC \n"

"loc_FF00FD00:\n"
"    LDR     R0, [R7, #0x12C] \n"
"    BIC     R6, R8, R0 \n"
"    LDR     R0, [R7, #0xD4] \n"
"    BIC     R4, R8, R0 \n"

"loc_FF00FD10:\n"
"    MOV     R3, R5 \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R6 \n"
//"  BL      _sub_FF056DB4 \n"  // See begin of sub_FF00038C_my
//"  BL      _sub_FF056DB0 \n"  // --> Nullsub call removed.
"    LDR     R1, =0x3CE000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF02BBBC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF00FBF4.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF00FD94 /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF00FBF4 - 0xFF00FC4C, length=23
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF006588 \n"
//"  BL      _sub_FF057868 \n"  // --> Nullsub call removed.
//"  BL      _sub_FF02D7AC \n"  // SD1stInit, Diskboot
"    BL      sub_FF0933B8 \n"
"    LDR     R1, =0x30101 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF02AC78 \n"
"    LDR     R1, =0xC0220000 \n"
"    MOV     R0, #8 \n"
"    STR     R0, [R1, #0x9C] \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF02A9A8 \n"
"    BL      sub_FF02227C \n"
"    BL      sub_FF02D934 \n"
"    BL      sub_FF02AEF0 \n"
"    BL      sub_FF02DAB8_my \n"  // --> Patched. Old value = 0xFF02DAB8.

"    BL      CreateTask_spytask\n"  // added

"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF0248DC.
"    LDR     PC, =0xFF00FC3C \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF02DAB8_my @ 0xFF02DAB8 - 0xFF02DACC, length=6
void __attribute__((naked,noinline)) sub_FF02DAB8_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF0941FC_my \n"  // --> Patched. Old value = 0xFF0941FC.
"    BL      sub_FF08FAC4 \n"
"    BL      sub_FF090384 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF09302C \n"
);
}

/*************************************************************/
//** sub_FF0941FC_my @ 0xFF0941FC - 0xFF094258, length=24
void __attribute__((naked,noinline)) sub_FF0941FC_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF026310 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    LDR     R4, =0x48D8 \n"
"    LDRNE   R0, =0xFF02BBC4 \n"
"    STRNE   R0, [R4, #4] \n"
"    LDRNE   R0, =0xFF02BBC8 \n"
"    STRNE   R0, [R4, #8] \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R0, [R4] \n"
"    CMP     R0, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R5, =0x727C0 \n"  // --> Patched. Old value = 0x927C0. (steal 128kB from UI memory)
"    MOV     R0, R5 \n"
"    BL      sub_FF02BBCC /*_malloc_strictly*/ \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF001274 \n"
"    TST     R0, #1 \n"
"    STR     R0, [R4] \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0x4D \n"
"    LDR     R0, =0xFF094278 /*'UiMemory.c'*/ \n"
"    B       _DebugAssert \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF0248DC - 0xFF0248FC, length=9
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    LDR     R4, =0x1C44 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     sub_FF024910 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF0248A8.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw
"    LDR     PC, =0xFF024900 \n"  // Continue in firmware
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF096FCC - 0xFF096FE8, length=8
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF08C78C \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF08C7B8 \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    LDR     PC, =0xFF096FEC \n"  // Continue in firmware
);
}

/*************************************************************/
//** JogDial_task_my @ 0xFF0579AC - 0xFF057CDC, length=205
void __attribute__((naked,noinline)) JogDial_task_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    SUB     SP, SP, #0x1C \n"
"    BL      sub_FF057D4C \n"
"    LDR     R12, =0x2600 \n"
"    LDR     R6, =0xFF3BD370 \n"
"    MOV     R0, #0 \n"
"    ADD     R10, SP, #8 \n"
"    ADD     R9, SP, #0xC \n"

// Save pointer for kbd.c routine
"    LDR     R2, =jog_position \n"
"    STR     R9, [R2] \n"

"loc_FF0579CC:\n"
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
"    BLT     loc_FF0579CC \n"

"loc_FF0579FC:\n"
"    LDR     R0, =0x2600 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R0, #8] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B184 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    LDRNE   R1, =0x236 \n"
"    LDRNE   R0, =0xFF057C64 /*'RotaryEncoder.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP] \n"
"    AND     R4, R0, #0xFF \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x100 \n"
"    BEQ     loc_FF057A6C \n"
"    CMP     R0, #0x200 \n"
"    BEQ     loc_FF057AA4 \n"
"    CMP     R0, #0x300 \n"
"    BEQ     loc_FF057CAC \n"
"    CMP     R0, #0x400 \n"
"    BNE     loc_FF0579FC \n"
"    CMP     R4, #0 \n"
"    LDRNE   R1, =0x2C1 \n"
"    LDRNE   R0, =0xFF057C64 /*'RotaryEncoder.c'*/ \n"
"    BLNE    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    LDR     R0, [R6, R0, LSL#2] \n"

"loc_FF057A64:\n"
"    BL      sub_FF057D30 \n"
"    B       loc_FF0579FC \n"

"loc_FF057A6C:\n"
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
"    LDR     R0, =0x260C \n"
"    LDR     R0, [R0, R4, LSL#2] \n"
"    BL      sub_FF02C130 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF0578F8 \n"
"    ORR     R3, R4, #0x200 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x28 \n"
"    BL      sub_FF02C04C /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF0579FC \n"
"    MOV     R1, #0x248 \n"
"    B       loc_FF057C50 \n"

"loc_FF057AA4:\n"
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
"    BNE     loc_FF057B28 \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF057C0C \n"
"    LDR     R7, =0x260C \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF02C130 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF057904 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF02C04C /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF057C0C \n"
"    LDR     R1, =0x261 \n"
"    B       loc_FF057C04 \n"

"loc_FF057B28:\n"
"    MOV     R0, R2 \n"
"    RSBLT   R0, R0, #0 \n"
"    MOVLE   R7, #0 \n"
"    MOVGT   R7, #1 \n"
"    CMP     R0, #0xFF \n"
"    BLS     loc_FF057B64 \n"
"    LDR     R0, =0x7FFF \n"
"    CMP     R2, #0 \n"
"    SUBLE   R0, R0, R3 \n"
"    ADDLE   R0, R0, R1 \n"
"    SUBGT   R0, R0, R1 \n"
"    ADDGT   R0, R0, R3 \n"
"    MVN     R1, #0x8000 \n"
"    SUB     R0, R0, R1 \n"
"    EOR     R7, R7, #1 \n"

"loc_FF057B64:\n"
"    STR     R0, [SP, #4] \n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    ADDEQ   R0, R6, R5, LSL#2 \n"
"    LDREQ   R0, [R0, #8] \n"
"    BEQ     loc_FF057BA0 \n"
"    ADD     R8, R6, R5, LSL#2 \n"
"    ADD     R1, R8, R7, LSL#2 \n"
"    LDR     R1, [R1, #0x10] \n"
"    CMP     R1, R0 \n"
"    BEQ     loc_FF057BA8 \n"
"    LDR     R0, [R8, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF024498 \n"
"    LDR     R0, [R8, #8] \n"

"loc_FF057BA0:\n"
"    MOV     R1, #0 \n"
"    BL      sub_FF024498 \n"

"loc_FF057BA8:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    ADD     R7, R0, R7, LSL#2 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R1, [SP, #4] \n"
"    BL      sub_FF024498 \n"
"    LDR     R0, [R7, #0x10] \n"
"    LDR     R7, =0x260C \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    LDRH    R1, [R11] \n"
"    LDR     R0, [SP, #0x18] \n"
"    STRH    R1, [R0] \n"
"    LDR     R0, [R7, R4, LSL#2] \n"
"    BL      sub_FF02C130 /*_CancelTimer*/ \n"
"    LDR     R2, =0xFF057904 \n"
"    ORR     R3, R4, #0x300 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, #0x1F4 \n"
"    BL      sub_FF02C04C /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R7, R4, LSL#2] \n"
"    BEQ     loc_FF057C0C \n"
"    LDR     R1, =0x2A3 \n"

"loc_FF057C04:\n"
"    LDR     R0, =0xFF057C64 /*'RotaryEncoder.c'*/ \n"
"    BL      _DebugAssert \n"

"loc_FF057C0C:\n"
"    ADD     R0, R6, R5, LSL#2 \n"
"    LDR     R0, [R0, #0x18] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF057CA4 \n"
"    LDR     R0, =0x2600 \n"
"    LDR     R0, [R0, #0x10] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF057CA4 \n"
"    LDR     R2, =0xFF0578F8 \n"
"    ORR     R3, R4, #0x400 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF02C04C /*_SetTimerAfter*/ \n"
"    TST     R0, #1 \n"
"    CMPNE   R0, #0x15 \n"
"    STR     R0, [R10, R4, LSL#2] \n"
"    BEQ     loc_FF0579FC \n"
"    LDR     R1, =0x2AA \n"

"loc_FF057C50:\n"
"    LDR     R0, =0xFF057C64 /*'RotaryEncoder.c'*/ \n"
"    BL      _DebugAssert \n"
"    B       loc_FF0579FC \n"

"loc_FF057CA4:\n"
"    LDR     R0, [R6, R5, LSL#2] \n"
"    B       loc_FF057A64 \n"

"loc_FF057CAC:\n"
"    LDR     R0, [R9, R4, LSL#2] \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, #0x2B4 \n"
"    LDREQ   R0, =0xFF057C64 /*'RotaryEncoder.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    RSB     R0, R4, R4, LSL#3 \n"
"    ADD     R0, R6, R0, LSL#2 \n"
"    LDR     R0, [R0, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF024498 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R9, R4, LSL#2] \n"
"    B       loc_FF0579FC \n"
);
}
