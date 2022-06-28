#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

static long *nrflag = (long*)(0x8b64+0x00);  // Found @ ff9f718c & ff9f71d4
#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

#define PAUSE_FOR_FILE_COUNTER 150           // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated
#include "../../../generic/capt_seq.c"

//** capt_seq_task  @ 0xFF872424 

void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "LDR     R4, =0x376CC\n"
      "LDR     R7, =0x2BA8\n"
      "MOV     R6, #0\n"
"loc_FF872434:\n"
      "LDR     R0, [R7, #4]\n"
      "MOV     R2, #0\n"
      "MOV     R1, SP\n"
      "BL      sub_003F7218 \n" // RAM
      "TST     R0, #1\n"
      "BEQ     loc_FF872460\n"
      "LDR     R1, =0x493\n"
      "LDR     R0, =0xFF871F90 \n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
      "BL      _ExitTask \n"
      "LDMFD   SP!, {R3-R9,PC}\n"
"loc_FF872460:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x20\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF8726BC\n"
      "B       loc_FF8724F4\n"
      "B       loc_FF87250C\n"
      "B       loc_FF872570\n"
      "B       loc_FF872584\n"
      "B       loc_FF87257C\n"
      "B       loc_FF872590\n"
      "B       loc_FF872598\n"
      "B       loc_FF8725A0\n"
      "B       loc_FF8725BC\n"
      "B       loc_FF8725E8\n"
      "B       loc_FF8725C8\n"
      "B       loc_FF8725D4\n"
      "B       loc_FF8725DC\n"
      "B       loc_FF8725F0\n"
      "B       loc_FF8725F8\n"
      "B       loc_FF872600\n"
      "B       loc_FF872608\n"
      "B       loc_FF872610\n"
      "B       loc_FF87261C\n"
      "B       loc_FF872624\n"
      "B       loc_FF87262C\n"
      "B       loc_FF872634\n"
      "B       loc_FF87263C\n"
      "B       loc_FF872648\n"
      "B       loc_FF872650\n"
      "B       loc_FF872658\n"
      "B       loc_FF872660\n"
      "B       loc_FF872668\n"
      "B       loc_FF872674\n"
      "B       loc_FF87267C\n"
      "B       loc_FF872688\n"
      "B       loc_FF8726C8\n"
"loc_FF8724F4:\n"
      "BL		shooting_expo_iso_override\n"       // added
      "BL      sub_FF872C3C\n"
      "BL      shooting_expo_param_override\n"      // added
      "BL      sub_FF870230\n"
//      "LDR     R0, [R4, #0x28]\n"
//      "CMP     R0, #0\n"
//      "BLNE    sub_FF968DD4\n" // above 3 lines removed - redundant with added lines below
      "MOV     R0, #0\n"         // patch added
      "STR     R0, [R4,#0x28]\n" //fixes overrides  behavior at short shutter press
      "B       loc_FF8726C8\n"
"loc_FF87250C:\n"
      "LDR     R5, [R0, #0x10]\n"
      "LDR     R0, [R4, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF872548\n"
      "BL      sub_FF873B4C\n"
      "MOV     R1, R5\n"
      "BL      sub_FF873BA4\n"
      "LDR     R0, =0x10F\n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x24\n"
      "BL      _SetPropertyCase \n"
      "MOV     R2, #4\n"
      "ADD     R1, R5, #0x28\n"
      "MOV     R0, #0x2C\n"
      "BL      _SetPropertyCase \n"
"loc_FF872548:\n"
      "MOV     R0, R5\n"
//      "BL      sub_FF968D38\n" //original
      "BL      sub_FF968D38_my \n" //patch
      "BL      capt_seq_hook_raw_here \n" // patch
      "MOV     R8, R0\n"
      "MOV     R2, R5\n"
      "MOV     R1, #1\n"
      "BL      sub_FF8706E0\n"
      "TST     R8, #1\n"
      "MOVEQ   R0, R5\n"
      "BLEQ    sub_FF9686B4\n"
      "B       loc_FF8726C8\n"
"loc_FF872570:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF872F0C\n"
      "B       loc_FF8726C8\n"
"loc_FF87257C:\n"
      "BL      sub_FF872890\n"
      "B       loc_FF872588\n"
"loc_FF872584:\n"
      "BL      sub_FF872C1C\n"
"loc_FF872588:\n"
      "STR     R6, [R4, #0x28]\n"
      "B       loc_FF8726C8\n"
"loc_FF872590:\n"
      "BL      sub_FF872C24\n"
      "B       loc_FF8726C8\n"
"loc_FF872598:\n"
      "BL      sub_FF872DF4\n"
      "B       loc_FF8725C0\n"
"loc_FF8725A0:\n"
      "LDR     R5, [R0, #0x10]\n"
      "MOV     R0, R5\n"
      "BL      sub_FF968E6C\n"
      "MOV     R2, R5\n"
      "MOV     R1, #9\n"
      "BL      sub_FF8706E0\n"
      "B       loc_FF8726C8\n"
"loc_FF8725BC:\n"
      "BL      sub_FF872E74\n"
"loc_FF8725C0:\n"
      "BL      sub_FF870230\n"
      "B       loc_FF8726C8\n"
"loc_FF8725C8:\n"
      "LDR     R0, [R4, #0x58]\n"
      "BL      sub_FF8732FC\n"
      "B       loc_FF8726C8\n"
"loc_FF8725D4:\n"
      "BL      sub_FF8736BC\n"
      "B       loc_FF8726C8\n"
"loc_FF8725DC:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF873720\n"
      "B       loc_FF8726C8\n"
"loc_FF8725E8:\n"
      "BL      sub_FF872C1C\n"
      "B       loc_FF8726C8\n"
"loc_FF8725F0:\n"
      "BL      sub_FF967A58\n"
      "B       loc_FF8726C8\n"
"loc_FF8725F8:\n"
      "BL      sub_FF967CB8\n"
      "B       loc_FF8726C8\n"
"loc_FF872600:\n"
      "BL      sub_FF967D70\n"
      "B       loc_FF8726C8\n"
"loc_FF872608:\n"
      "BL      sub_FF967E44\n"
      "B       loc_FF8726C8\n"
"loc_FF872610:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF9680A4\n"
      "B       loc_FF8726C8\n"
"loc_FF87261C:\n"
      "BL      sub_FF968214\n"
      "B       loc_FF8726C8\n"
"loc_FF872624:\n"
      "BL      sub_FF9682A8\n"
      "B       loc_FF8726C8\n"
"loc_FF87262C:\n"
      "BL      sub_FF968364\n"
      "B       loc_FF8726C8\n"
"loc_FF872634:\n"
      "BL      sub_FF873080\n"
      "B       loc_FF8726C8\n"
"loc_FF87263C:\n"
      "BL      sub_FF873104\n"
      "BL      sub_FF8322CC\n"
      "B       loc_FF8726C8\n"
"loc_FF872648:\n"
      "BL      sub_FF967F14\n"
      "B       loc_FF8726C8\n"
"loc_FF872650:\n"
      "BL      sub_FF967F54\n"
      "B       loc_FF8726C8\n"
"loc_FF872658:\n"
      "BL      sub_FF875028\n"
      "B       loc_FF8726C8\n"
"loc_FF872660:\n"
      "BL      sub_FF87509C\n"
      "B       loc_FF8726C8\n"
"loc_FF872668:\n"
      "LDR     R0, [R0, #0xC]\n"
      "BL      sub_FF96848C\n"
      "B       loc_FF8726C8\n"
"loc_FF872674:\n"
      "BL      sub_FF9684FC\n"
      "B       loc_FF8726C8\n"
"loc_FF87267C:\n"
      "BL      sub_FF875104\n"
      "BL      sub_FF8750BC\n"
      "B       loc_FF8726C8\n"
"loc_FF872688:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF96956C\n"
      "MOV     R0, #1\n"
      "BL      sub_FF969694\n"
      "LDRH    R0, [R4, #0x9C]\n"
      "CMP     R0, #4\n"
      "LDRNEH  R0, [R4]\n"
      "SUBNE   R1, R0, #0x8200\n"
      "SUBNES  R1, R1, #0x2E\n"
      "BNE     loc_FF8726C8\n"
      "BL      sub_FF87509C\n"
      "BL      sub_FF875560\n"
      "B       loc_FF8726C8\n"
"loc_FF8726BC:\n"
      "LDR     R1, =0x5F4\n"
      "LDR     R0, =0xFF871F90 \n" // "SsShootTask.c"
      "BL      _DebugAssert \n"
"loc_FF8726C8:\n"
      "LDR     R0, [SP]\n"
      "LDR     R1, [R0, #4]\n"
      "LDR     R0, [R7]\n"
      "BL      sub_003FAC6C\n"
      "LDR     R5, [SP]\n"
      "LDR     R0, [R5, #8]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x117\n"
      "LDREQ   R0, =0xFF871F90 \n" // "SsShootTask.c"
      "BLEQ    _DebugAssert \n"
      "STR     R6, [R5, #8]\n"
      "B       loc_FF872434\n"
	);
}

//** sub_FF968D38_my  @ 0xFF968D38
//CHECK THIS!!!
void __attribute__((naked,noinline)) sub_FF968D38_my() {
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x376CC\n"
      "MOV     R6, R0\n"
      "LDR     R0, [R5, #0x28]\n"
      "MOV     R4, #0\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF968D68\n"
      "MOV     R0, #0xC\n"
      "BL      sub_FF876C00\n"
      "TST     R0, #1\n"
      "MOVNE   R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
"loc_FF968D68:\n"
      "BL      sub_FF872C2C\n"
      "LDR     R0, [R5, #0x28]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF968DB8\n"
      "MOV     R0, R6\n"
      "BL      sub_FF9685F4\n"
      "TST     R0, #1\n"
      "LDMNEFD SP!, {R4-R6,PC}\n"
      "MOV     R0, R6\n"
      "BL      sub_FF968988\n"
      "BL      sub_FF96934C\n"

//This was not tested:
//begin patch
      "BL      wait_until_remote_button_is_released\n"
      "BL      capt_seq_hook_set_nr\n"
//end patch
      "MOV     R0, #2\n"
      "BL      sub_FF878360\n"
      "LDR     R0, [R5, #0x8C]\n"
      "TST     R0, #0x10\n"
      "BNE     loc_FF968DC8\n"
      "MOV     R0, R6\n"
      "BL      sub_FFA87D48\n"  //original
//      "BL      sub_FFA87D48_my \n" //This function calls "SsStandardCaptureSeq.c"
      "MOV     R4, R0\n"
      "B       loc_FF968DCC\n"
"loc_FF968DB8:\n"
      "LDR     R0, =0x694C\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF968DCC\n"
"loc_FF968DC8:\n"
      "MOV     R4, #0x1D\n"
"loc_FF968DCC:\n"
      "MOV     R0, R4\n"
      "LDMFD   SP!, {R4-R6,PC}\n"
	);
}

//** sub_FFA87D48_my  @ 0xFFA87D48 
/*
void __attribute__((naked,noinline)) sub_FFA87D48_my() {
asm volatile (
      "STMFD   SP!, {R3-R9,LR}\n"
      "MOV     R4, R0\n"
      "LDR     R1, =0xB624\n"
      "MOV     R2, #4\n"
      "MOV     R0, #0x130\n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1\n"
      "MOVNE   R1, #0x230\n"
      "LDRNE   R0, =0xFFA87F74\n" // "SsStandardCaptureSeq.c"
      "BLNE    _DebugAssert \n"
      "LDR     R6, =0xB61C\n"
      "LDR     R0, [R6, #8]\n"
      "AND     R0, R0, #0xFF00\n"
      "CMP     R0, #0x600\n"
      "LDRNE   R0, =0xFF9686CC\n"
      "LDREQ   R0, =0xFFA87AC0\n"
      "MOVNE   R1, R4\n"
      "MOVEQ   R1, #0\n"
      "BL      sub_FF8A6598\n"
      "MOV     R0, R4\n"
      "BL      sub_FF968684\n"
      "MOV     R0, R4\n"
      "BL      sub_FF968A58\n"
      "MOV     R8, R0\n"
      "LDR     R1, =0xB620\n"
      "MOV     R2, #4\n"
      "MOV     R0, #0x8A\n"
      "BL      _GetPropertyCase \n"
      "TST     R0, #1\n"
      "LDRNE   R1, =0x23D\n"
      "LDRNE   R0, =0xFFA87F74\n" // "SsStandardCaptureSeq.c"
      "BLNE    _DebugAssert \n"
      "BL      sub_FF874DA0\n"
      "BL      sub_FF968C60\n"
      "CMP     R8, #0xA\n"
      "MOV     R7, #0\n"
      "MOV     R5, #1\n"
      "ADDCC   PC, PC, R8, LSL #2\n"
      "B       loc_FFA87EA8\n"
      "B       loc_FFA87EA8\n"
      "B       loc_FFA87E0C\n"
      "B       loc_FFA87E1C\n"
      "B       loc_FFA87E38\n"
      "B       loc_FFA87E48\n"
      "B       loc_FFA87E74\n"
      "B       loc_FFA87EA8\n"
      "B       loc_FFA87EA8\n"
      "B       loc_FFA87EA8\n"
      "B       loc_FFA87E8C\n"
"loc_FFA87E0C:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF8A65B4\n"
      "STRH    R7, [R4, #0x10]\n"
      "B       loc_FFA87E9C\n"
"loc_FFA87E1C:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF8A65B4\n"
      "MOV     R0, R4\n"
      "STRH    R5, [R4, #0x10]\n"
      "BL      sub_FFA87BD0\n"
"loc_FFA87E30:\n"
      "MOV     R5, R0\n"
      "B       loc_FFA87EB8\n"
"loc_FFA87E38:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF8A65B4\n"
      "MOV     R0, #1\n"
      "B       loc_FFA87E54\n"
"loc_FFA87E48:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF8A65B4\n"
      "MOV     R0, #2\n"
"loc_FFA87E54:\n"
      "BL      sub_FF8A6718\n"
      "MOV     R0, R4\n"
      "STRH    R5, [R4, #0x10]\n"
      "BL      sub_FFA87BD0\n"
      "MOV     R5, R0\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8A6718\n"
      "B       loc_FFA87EB8\n"
"loc_FFA87E74:\n"
      "MOV     R0, #1\n"
      "BL      sub_FF8A65B4\n"
      "MOV     R0, R4\n"
      "STRH    R7, [R4, #0x10]\n"
      "BL      sub_FFA87C98\n"
      "B       loc_FFA87E30\n"
"loc_FFA87E8C:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8A65B4\n"
      "MOV     R0, #4\n"
      "STRH    R0, [R4, #0x10]\n"
"loc_FFA87E9C:\n"
      "MOV     R0, R4\n"
      "BL      sub_FFA87B50\n"
      "B       loc_FFA87E30\n"
"loc_FFA87EA8:\n"
      "LDR     R1, =0x286\n"
      "LDR     R0, =0xFFA87F74\n" // "SsStandardCaptureSeq.c"
      "BL      _DebugAssert \n"
      "MOV     R5, #0x1D\n"
"loc_FFA87EB8:\n"
      "BL      sub_FF968CB0\n"
      "TST     R5, #1\n"
      "MOVNE   R0, R5\n"
      "BNE     loc_FFA87F50\n"
      "MOV     R0, R4\n"
      "BL      sub_FF968B84\n"
      "MOV     R0, R4\n"
      "BL      sub_FF968B20\n"
      "LDR     R0, [R6]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FFA87EF8\n"
      "LDRH    R0, [R4, #0x10]\n"
      "CMP     R0, #1\n"
      "CMPNE   R0, #3\n"
      "CMPNE   R0, #5\n"
      "BEQ     loc_FFA87F4C\n"
"loc_FFA87EF8:\n"
      "BL      sub_FF969854\n"
      "LDR     R5, =0x2A3\n"
      "LDR     R2, =0x3A98\n"
      "LDR     R3, =0xFFA87F74\n" // "SsStandardCaptureSeq.c"
      "MOV     R1, #0xC\n"
      "STR     R5, [SP]\n"
      "BL      sub_FF876E68\n"
      "CMP     R0, #0\n"
      "MOVNE   R1, R5\n"
      "LDRNE   R0, =0xFFA87F74\n" // "SsStandardCaptureSeq.c"
      "BLNE    _DebugAssert \n"
      "LDR     R0, =0x376CC\n"
      "LDR     R1, [R0, #0x8C]\n"
      "TST     R1, #2\n"
      "BNE     loc_FFA87F4C\n"
      "LDRH    R0, [R0, #0x9A]\n"
      "CMP     R0, #3\n"
      "LDRNE   R0, [R4, #8]\n"
      "CMPNE   R0, #1\n"
      "MOVLS   R0, R4\n"
      "BLLS    sub_FF968754\n"
"loc_FFA87F4C:\n"
      "MOV     R0, #0\n"
"loc_FFA87F50:\n"
      "LDMFD   SP!, {R3-R9,PC}\n"
	);
}
*/

//** exp_drv_task  @ 0xFF8B1AD0 

void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
      "STMFD   SP!, {R4-R9,LR}\n"
      "SUB     SP, SP, #0x2C\n"
      "LDR     R6, =0x3E3C\n"
      "LDR     R7, =0xBB8\n"
      "LDR     R4, =0x5467C\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STR     R0, [SP, #0xC]\n"
"loc_FF8B1AF0:\n"
      "LDR     R0, [R6, #0x20]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #0x28\n"
      "BL      sub_003F7218\n"
      "LDR     R0, [SP, #0xC]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF8B1B3C\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x14\n"
      "CMPNE   R0, #0x15\n"
      "CMPNE   R0, #0x16\n"
      "CMPNE   R0, #0x17\n"
      "BEQ     loc_FF8B1C9C\n"
      "CMP     R0, #0x2A\n"
      "BEQ     loc_FF8B1C24\n"
      "ADD     R1, SP, #0xC\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8B1A80\n"
"loc_FF8B1B3C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x30\n"
      "BNE     loc_FF8B1B68\n"
      "BL      sub_FF8B2EB0\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #1\n"
      "BL      sub_003FAC6C\n"
      "BL      _ExitTask \n"
      "ADD     SP, SP, #0x2C\n"
      "LDMFD   SP!, {R4-R9,PC}\n"
"loc_FF8B1B68:\n"
      "CMP     R1, #0x2F\n"
      "BNE     loc_FF8B1B84\n"
      "LDR     R2, [R0, #0x8C]!\n"
      "LDR     R1, [R0, #4]\n"
      "MOV     R0, R1\n"
      "BLX     R2\n"
      "B       loc_FF8B2158\n"
"loc_FF8B1B84:\n"
      "CMP     R1, #0x28\n"
      "BNE     loc_FF8B1BD4\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8AD3E4\n"
      "MOV     R1, #0x80\n"
      "BL      sub_FF959AD8\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x80\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "LDRNE   R1, =0x157A\n"
      "BNE     loc_FF8B1C90\n"
"loc_FF8B1BC0:\n"
      "LDR     R1, [SP, #0x28]\n"
      "LDR     R0, [R1, #0x90]\n"
      "LDR     R1, [R1, #0x8C]\n"
      "BLX     R1\n"
      "B       loc_FF8B2158\n"
"loc_FF8B1BD4:\n"
      "CMP     R1, #0x29\n"
      "BNE     loc_FF8B1C1C\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8B1A80\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FACA0\n"
      "LDR     R0, =0xFF8AD3F4\n"
      "MOV     R1, #0x100\n"
      "BL      sub_FF959C78\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #0x100\n"
      "BL      sub_003FABAC\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8B1BC0\n"
      "LDR     R1, =0x1584\n"
      "B       loc_FF8B1C90\n"
"loc_FF8B1C1C:\n"
      "CMP     R1, #0x2A\n"
      "BNE     loc_FF8B1C34\n"
"loc_FF8B1C24:\n"
      "LDR     R0, [SP, #0x28]\n"
      "ADD     R1, SP, #0xC\n"
      "BL      sub_FF8B1A80\n"
      "B       loc_FF8B1BC0\n"
"loc_FF8B1C34:\n"
      "CMP     R1, #0x2D\n"
      "BNE     loc_FF8B1C4C\n"
      "BL      sub_FF89E640\n"
      "BL      sub_FF89F328\n"
      "BL      sub_FF89EE90\n"
      "B       loc_FF8B1BC0\n"
"loc_FF8B1C4C:\n"
      "CMP     R1, #0x2E\n"
      "BNE     loc_FF8B1C9C\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R1, #4\n"
      "BL      sub_003FACA0\n"
      "LDR     R1, =0xFF8AD414\n"
      "LDR     R0, =0xFFFFF400\n"
      "MOV     R2, #4\n"
      "BL      sub_FF89E090\n"
      "BL      sub_FF89E320\n"
      "LDR     R0, [R6, #0x1C]\n"
      "MOV     R2, R7\n"
      "MOV     R1, #4\n"
      "BL      sub_003FAAC8\n"
      "TST     R0, #1\n"
      "BEQ     loc_FF8B1BC0\n"
      "LDR     R1, =0x15AC\n"
"loc_FF8B1C90:\n"
      "LDR     R0, =0xFF8ADB08\n"
      "BL      _DebugAssert \n"
      "B       loc_FF8B1BC0\n"
"loc_FF8B1C9C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R8, #1\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x12\n"
      "CMPNE   R1, #0x13\n"
      "BNE     loc_FF8B1D04\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8B0020\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B32B4\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x98]\n"
      "LDR     R3, [R0, #0x94]\n"
      "B       loc_FF8B201C\n"
"loc_FF8B1D04:\n"
      "CMP     R1, #0x14\n"
      "CMPNE   R1, #0x15\n"
      "CMPNE   R1, #0x16\n"
      "CMPNE   R1, #0x17\n"
      "BNE     loc_FF8B1DBC\n"
      "ADD     R3, SP, #0xC\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8B0280\n"
      "CMP     R0, #1\n"
      "MOV     R9, R0\n"
      "CMPNE   R9, #5\n"
      "BNE     loc_FF8B1D58\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, R9\n"
      "LDR     R1, [R0, #0x7C]!\n"
      "LDR     R12, [R0, #0x10]!\n"
      "LDR     R3, [R0, #4]\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "B       loc_FF8B1D90\n"
"loc_FF8B1D58:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R9, #2\n"
      "LDR     R3, [R0, #0x90]\n"
      "CMPNE   R9, #6\n"
      "BNE     loc_FF8B1DA4\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "MOV     R1, #1\n"
      "MOV     R0, SP\n"
      "BLX     R12\n"
      "LDR     R0, [SP, #0x28]\n"
      "MOV     R2, SP\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_FF8B1770\n"
"loc_FF8B1D90:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R2, [SP, #0xC]\n"
      "MOV     R1, R9\n"
      "BL      sub_FF8B19C0\n"
      "B       loc_FF8B2024\n"
"loc_FF8B1DA4:\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R12, [R0, #0x8C]\n"
      "MOV     R2, R9\n"
      "ADD     R0, R0, #4\n"
      "BLX     R12\n"
      "B       loc_FF8B2024\n"
"loc_FF8B1DBC:\n"
      "CMP     R1, #0x24\n"
      "CMPNE   R1, #0x25\n"
      "BNE     loc_FF8B1E08\n"
      "LDR     R1, [R0, #0x7C]\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R1, R0, R1, LSL #2\n"
      "SUB     R1, R1, #8\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "BL      sub_FF8AF00C\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R3, [R0, #0x8C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8AF44C\n"
      "B       loc_FF8B2024\n"
"loc_FF8B1E08:\n"
      "ADD     R1, R0, #4\n"
      "LDMIA   R1, {R2,R3,R9}\n"
      "STMIA   R5, {R2,R3,R9}\n"
      "LDR     R1, [R0]\n"
      "CMP     R1, #0x28\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B1EC4\n"
      "B       loc_FF8B1EC4\n"
      "B       loc_FF8B1ECC\n"
      "B       loc_FF8B1ED4\n"
      "B       loc_FF8B1ED4\n"
      "B       loc_FF8B1ED4\n"
      "B       loc_FF8B1EC4\n"
      "B       loc_FF8B1ECC\n"
      "B       loc_FF8B1ED4\n"
      "B       loc_FF8B1ED4\n"
      "B       loc_FF8B1EEC\n"
      "B       loc_FF8B1EEC\n"
      "B       loc_FF8B1FF8\n"
      "B       loc_FF8B2000\n"
      "B       loc_FF8B2000\n"
      "B       loc_FF8B2000\n"
      "B       loc_FF8B2000\n"
      "B       loc_FF8B2008\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B1EDC\n"
      "B       loc_FF8B1EE4\n"
      "B       loc_FF8B1EE4\n"
      "B       loc_FF8B1EE4\n"
      "B       loc_FF8B1EF8\n"
      "B       loc_FF8B1EF8\n"
      "B       loc_FF8B1F00\n"
      "B       loc_FF8B1F38\n"
      "B       loc_FF8B1F70\n"
      "B       loc_FF8B1FA8\n"
      "B       loc_FF8B1FE0\n"
      "B       loc_FF8B1FE0\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B200C\n"
      "B       loc_FF8B1FE8\n"
      "B       loc_FF8B1FF0\n"
"loc_FF8B1EC4:\n"
      "BL      sub_FF8AD98C\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1ECC:\n"
      "BL      sub_FF8ADC30\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1ED4:\n"
      "BL      sub_FF8ADE58\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1EDC:\n"
      "BL      sub_FF8AE17C\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1EE4:\n"
      "BL      sub_FF8AE394\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1EEC:\n"
//      "BL      sub_FF8AE740\n"  //original
      "BL      sub_FF8AE740_my\n" //patched
      "MOV     R8, #0\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1EF8:\n"
      "BL      sub_FF8AE880\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1F00:\n"
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B2F44\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1F38:\n"
      "LDRH    R1, [R0, #4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B30B4\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1F70:\n"
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R0, #6]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R4, #8]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B3168\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1FA8:\n"
      "LDRH    R1, [R4]\n"
      "STRH    R1, [SP, #0x1C]\n"
      "LDRH    R1, [R4, #2]\n"
      "STRH    R1, [SP, #0x1E]\n"
      "LDRH    R1, [R4, #4]\n"
      "STRH    R1, [SP, #0x20]\n"
      "LDRH    R1, [R4, #6]\n"
      "STRH    R1, [SP, #0x22]\n"
      "LDRH    R1, [R0, #0xC]\n"
      "STRH    R1, [SP, #0x24]\n"
      "LDRH    R1, [R4, #0xA]\n"
      "STRH    R1, [SP, #0x26]\n"
      "BL      sub_FF8B3210\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1FE0:\n"
      "BL      sub_FF8AEDC0\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1FE8:\n"
      "BL      sub_FF8AF550\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1FF0:\n"
      "BL      sub_FF8AF834\n"
      "B       loc_FF8B200C\n"
"loc_FF8B1FF8:\n"
      "BL      sub_FF8AFAF4\n"
      "B       loc_FF8B200C\n"
"loc_FF8B2000:\n"
      "BL      sub_FF8AFCB0\n"
      "B       loc_FF8B200C\n"
"loc_FF8B2008:\n"
      "BL      sub_FF8AFE18\n"
"loc_FF8B200C:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R1, [R0, #0x7C]\n"
      "LDR     R2, [R0, #0x90]\n"
      "LDR     R3, [R0, #0x8C]\n"
"loc_FF8B201C:\n"
      "ADD     R0, R0, #4\n"
      "BLX     R3\n"
"loc_FF8B2024:\n"
      "LDR     R0, [SP, #0x28]\n"
      "LDR     R0, [R0]\n"
      "CMP     R0, #0x10\n"
      "BEQ     loc_FF8B205C\n"
      "BGT     loc_FF8B204C\n"
      "CMP     R0, #1\n"
      "CMPNE   R0, #4\n"
      "CMPNE   R0, #0xE\n"
      "BNE     loc_FF8B2090\n"
      "B       loc_FF8B205C\n"
"loc_FF8B204C:\n"
      "CMP     R0, #0x13\n"
      "CMPNE   R0, #0x17\n"
      "CMPNE   R0, #0x1A\n"
      "BNE     loc_FF8B2090\n"
"loc_FF8B205C:\n"
      "LDRSH   R0, [R4]\n"
      "CMN     R0, #0xC00\n"
      "LDRNESH R1, [R4, #8]\n"
      "CMNNE   R1, #0xC00\n"
      "STRNEH  R0, [SP, #0x1C]\n"
      "STRNEH  R1, [SP, #0x24]\n"
      "BNE     loc_FF8B2090\n"
      "ADD     R0, SP, #0x10\n"
      "BL      sub_FF8B34C0\n"
      "LDRH    R0, [SP, #0x10]\n"
      "STRH    R0, [SP, #0x1C]\n"
      "LDRH    R0, [SP, #0x18]\n"
      "STRH    R0, [SP, #0x24]\n"
"loc_FF8B2090:\n"
      "LDR     R0, [SP, #0x28]\n"
      "CMP     R8, #1\n"
      "BNE     loc_FF8B20E0\n"
      "LDR     R1, [R0, #0x7C]\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, R1, R1, LSL #1\n"
      "ADD     R0, R0, R1, LSL #2\n"
      "SUB     R8, R0, #8\n"
      "LDR     R0, =0x5467C\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x54688\n"
      "MOV     R2, #0xC\n"
      "ADD     R1, SP, #0x1C\n"
      "BL      sub_003FC17C\n"
      "LDR     R0, =0x54694\n"
      "MOV     R2, #0xC\n"
      "MOV     R1, R8\n"
      "BL      sub_003FC17C\n"
      "B       loc_FF8B2158\n"
"loc_FF8B20E0:\n"
      "LDR     R0, [R0]\n"
      "MOV     R3, #1\n"
      "CMP     R0, #0xB\n"
      "BNE     loc_FF8B2124\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "BL      sub_FF8AD76C\n"
      "MOV     R3, #1\n"
      "MOV     R2, #0\n"
      "STRD    R2, [SP]\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, #0\n"
      "B       loc_FF8B2154\n"
"loc_FF8B2124:\n"
      "MOV     R2, #1\n"
      "STRD    R2, [SP]\n"
      "MOV     R3, R2\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FF8AD76C\n"
      "MOV     R3, #1\n"
      "MOV     R2, R3\n"
      "MOV     R1, R3\n"
      "MOV     R0, R3\n"
      "STR     R3, [SP]\n"
      "STR     R3, [SP, #4]\n"
"loc_FF8B2154:\n"
      "BL      sub_FF8AD8D8\n"
"loc_FF8B2158:\n"
      "LDR     R0, [SP, #0x28]\n"
      "BL      sub_FF8B2EB0\n"
      "B       loc_FF8B1AF0\n"
	);
}

//** sub_FF8AE740_my  @ 0xFF8AE740 

void __attribute__((naked,noinline)) sub_FF8AE740_my() {
asm volatile (
      "STMFD   SP!, {R4-R8,LR}\n"
      "LDR     R7, =0x3E3C\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R7, #0x1C]\n"
      "MOV     R1, #0x3E\n"
      "BL      sub_003FACA0\n"
      "MOV     R2, #0\n"
      "LDRSH   R0, [R4, #4]\n"
      "MOV     R1, R2\n"
      "BL      sub_FF8AD474\n"
      "MOV     R6, R0\n"
      "LDRSH   R0, [R4, #6]\n"
      "BL      sub_FF8AD5C4\n"
      "LDRSH   R0, [R4, #8]\n"
      "BL      sub_FF8AD61C\n"
      "LDRSH   R0, [R4, #0xA]\n"
      "BL      sub_FF8AD674\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "MOV     R1, #0\n"
      "BL      sub_FF8AD6CC\n"
      "MOV     R5, R0\n"
      "LDR     R0, [R4]\n"
      "LDR     R8, =0x54694\n"
      "CMP     R0, #0xB\n"
      "MOVEQ   R6, #0\n"
      "MOVEQ   R5, R6\n"
      "BEQ     loc_FF8AE7D4\n"
      "CMP     R6, #1\n"
      "BNE     loc_FF8AE7D4\n"
      "LDRSH   R0, [R4, #4]\n"
      "LDR     R1, =0xFF8AD3D4\n"
      "MOV     R2, #2\n"
      "BL      sub_FF959B5C\n"
      "STRH    R0, [R4, #4]\n"
      "MOV     R0, #0\n"
      "STR     R0, [R7, #0x28]\n"
      "B       loc_FF8AE7DC\n"
"loc_FF8AE7D4:\n"
      "LDRH    R0, [R8]\n"
      "STRH    R0, [R4, #4]\n"
"loc_FF8AE7DC:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R8, #8]\n"
      "BNE     loc_FF8AE7F8\n"
      "LDRSH   R0, [R4, #0xC]\n"
      "LDR     R1, =0xFF8AD458\n"
      "MOV     R2, #0x20\n"
      "BL      sub_FF8B2F00\n"
"loc_FF8AE7F8:\n"
      "STRH    R0, [R4, #0xC]\n"
      "LDRSH   R0, [R4, #6]\n"
//      "BL      sub_FF89E38C\n"  //original
      "BL      sub_FF89E38C_my\n" //patched
      "B       sub_FF8AE804 \n" // continue in firmware
	);
}

//** sub_FF89E38C_my  @ 0xFF89E38C 

void __attribute__((naked,noinline)) sub_FF89E38C_my() {
asm volatile (
      "STMFD   SP!, {R4-R6,LR}\n"
      "LDR     R5, =0x3AC8\n"
      "MOV     R4, R0\n"
      "LDR     R0, [R5, #4]\n"
      "CMP     R0, #1\n"
      "LDRNE   R1, =0x14D\n"
      "LDRNE   R0, =0xFF89E1C4\n"
      "BLNE    _DebugAssert \n"
      "CMN     R4, #0xC00\n"
      "LDREQSH R4, [R5, #2]\n"
      "CMN     R4, #0xC00\n"
      "LDREQ   R1, =0x153\n"
      "LDREQ   R0, =0xFF89E1C4\n"
      "STRH    R4, [R5, #2]\n"
      "BLEQ    _DebugAssert \n"
      "MOV     R0, R4\n"
//      "BL      _apex2us \n" //original apex2us function
      "BL      apex2us \n"    //patch
      "MOV     R4, R0\n"
      "BL      sub_FF8EC4E4\n"
      "MOV     R0, R4\n"
      "BL      sub_FF8F4CEC\n"
      "TST     R0, #1\n"
      "LDMEQFD SP!, {R4-R6,PC}\n"
      "LDMFD   SP!, {R4-R6,LR}\n"
      "MOV     R1, #0x158\n"
      "LDR     R0, =0xFF89E1C4\n"
      "B       _DebugAssert \n"
	);
}
