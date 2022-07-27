#include "stubs_asm.h"

#define NULL_SUB 0xE0020755

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
NHSTUB(GetImageFolder,                      0xe02e3031)
NHSTUB(WriteSDCard,                         0xe04faf19)
NHSTUB(MakeSDCardBootable,                  0xe036111b)
NHSTUB(post_msg_3_to_physw_releasesw,       0xe0070a3b)

IGNORE(EngDrvRead)
NHSTUB(EngDrvRead_FW,                       0xe05b1d13) // in wrappers

NHSTUB(GetLensCurrentFocalLength,           0xe03f4561)
NHSTUB(GetLensWideFocalLength,              0xe03f4573)

NHSTUB(VTMLock,                             NULL_SUB)
NHSTUB(VTMUnlock,                           NULL_SUB)

// MMU
NHSTUB(dcache_clean_by_mva,                 0xe036ba79)
NHSTUB(clean_l2_cache_by_phys_addr,         0xe00698dd)
NHSTUB(set_canon_mmu_tables_to,             0xdffc7ccb)
NHSTUB(make_copy_of_canon_mmutables,        0xdffc7c55)
NHSTUB(icache_branchpr_invalidate,          0xe036bb4d)
NHSTUB(dcache_clean_and_invalidate_all,     0xe036bb09)

NHSTUB(EnterToCompensationEVF,              NULL_SUB) // TODO
NHSTUB(ExitFromCompensationEVF,             NULL_SUB) // TODO
NHSTUB(ExpCtrlTool_StartContiAE,            NULL_SUB) // TODO
NHSTUB(ExpCtrlTool_StopContiAE,             NULL_SUB) // TODO
NHSTUB(GetFocusLensSubjectDistanceFromLens, NULL_SUB) // TODO: GetFocusLensSubjectDistance, GetFocusLensSubjectDistanceNumber_FW, GetFocusLensSubjectDistance_FW
NHSTUB(MoveFocusLensToDistance,             NULL_SUB) // TODO: MoveFocusLensWithDistance_FW
NHSTUB(Restart,                             NULL_SUB) // TODO
NHSTUB(TurnOffBackLight,                    NULL_SUB) // TODO
NHSTUB(TurnOnBackLight,                     NULL_SUB) // TODO
