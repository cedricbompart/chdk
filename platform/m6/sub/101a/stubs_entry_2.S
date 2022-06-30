#include "stubs_asm.h"

// from Ghidra; each address needs to add 1 THUMB bit
NHSTUB(CancelHPTimer,                       0xe0178e9f) // TODO: different method signature
NHSTUB(DeleteDirectory_Fut,                 0xe0334fdd)
NHSTUB(DeleteFile_Fut,                      0xe0334f93)
NHSTUB(Feof_Fut,                            0xe0335189)
NHSTUB(Fflush_Fut,                          0xe03351b3)
NHSTUB(GetDrive_TotalClusters,              0xe003a195)
NHSTUB(RenameFile_Fut,                      0xe0334f31)
NHSTUB(SetFileAttributes,                   0xe035f66f)
NHSTUB(SetFileTimeStamp,                    0xe035f627) // TODO: different method signature
NHSTUB(SetHPTimerAfterNow,                  0xe0178e05)
NHSTUB(_sqrt,                               0xdffd619d) // TODO: different method signature, CalcSqrt, CalcSqrt_FW
NHSTUB(apex2us,                             0xe01217c7)
NHSTUB(exmem_ualloc,                        0xe00744f7)
NHSTUB(exmem_ufree,                         0xe0074553)
NHSTUB(reboot_fw_update,                    0xe039b733)

IGNORE(EngDrvRead)
NHSTUB(EngDrvRead_FW,                       0xe05b1d13) // in wrappers

NHSTUB(GetLensCurrentFocalLength,           0xe03f4561)
NHSTUB(GetLensWideFocalLength,              0xe03f4573)

NHSTUB(EnterToCompensationEVF,              0x00000000) // TODO
NHSTUB(ExitFromCompensationEVF,             0x00000000) // TODO
NHSTUB(ExpCtrlTool_StartContiAE,            0x00000000) // TODO
NHSTUB(ExpCtrlTool_StopContiAE,             0x00000000) // TODO
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0x00000000) // TODO: GetFocusLensSubjectDistance, GetFocusLensSubjectDistanceNumber_FW, GetFocusLensSubjectDistance_FW
NHSTUB(MoveFocusLensToDistance,             0x00000000) // TODO: MoveFocusLensWithDistance_FW
NHSTUB(Restart,                             0x00000000) // TODO
NHSTUB(TurnOffBackLight,                    0x00000000) // TODO
NHSTUB(TurnOnBackLight,                     0x00000000) // TODO
NHSTUB(WriteSDCard,                         0x00000000) // TODO


