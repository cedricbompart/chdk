// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xe0020000
//   DRYOS R59 (DRYOS version 2.3, release #0059+p3) @ 0xe05e3640 ref @ 0xe05d70e0
//   Firmware Ver GM1.01A   // Found @ 0xe0431220, "GM1.01A" @ 0xe043122d
//   VMSA detected, probably digic >= 7

// Values for makefile.inc
//   PLATFORMOSVER = 59
//   DIGIC = 70
//   MEMISOSTART = 0x2b4138
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000#  Found @0xe03a51d4
// ARAM_HEAP_SIZE not found

// Detected address ranges:
// ROM      0xe0000000 - 0xe2000000 (33554432 bytes)
// RAM data 0x00008000 - 0x00068524 copied from 0xe115d544 ( 394532 bytes)
// RAM code 0x01900000 - 0x01901444 copied from 0xe11bda68 (   5188 bytes)
// TCM code 0xdffc4900 - 0xdffd9ba0 copied from 0xe11beeac (  86688 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff24d38 copied from 0xe0ff3cc8 (  19768 bytes)
// zico_1 0xbff00000 - 0xbff04260 copied from 0xe0ff8a08 (  16992 bytes)
// zico_2 0x80a00000 - 0x80adea20 copied from 0xe0ffcc70 ( 911904 bytes)

// Found DryOS versions:
// 0xe0019ae8 other "DRYOS version 2.3, release #0059+p3"
// 0xe05e3640 main  "DRYOS version 2.3, release #0059+p3"
// 0xe0d5a454 other "DRYOS version 2.3, release #0059+p3"
// 0xe0ffd510 other "DRYOS version 2.3, release #0059+p3"
// 0xe143fb40 other "DRYOS version 2.3, release #0059+p3"
// 0xe1e60390 other "DRYOS version 2.3, release #0054"

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
//#define CAM_ILC 1 // Camera is interchangeable lens
//#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xe01e8654
//#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
// Camera has an iris (CAM_HAS_IRIS_DIAPHRAGM default)

// physw_event_table 0xe05e4cd4 Found @0xe0070228
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x00000020 // Found @0xe05e4d0c, levent 0x30a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x20000000 // Found @0xe05e4e2c, levent 0x302
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x01000000 // Found @0xe05e4cf4, levent 0x305
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x00010000 // Found @0xe05e4dc4, levent 0x304
//#define HOTSHOE_IDX         2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Key name / function may vary! Values for unknown DryOS versions should not be trusted!
//KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xe05e4cdc, levent 0x101 (uses inverted logic in physw_status)
//    { 0, KEY_WIFI            ,0x00000004 }, // Found @0xe05e4ce4, levent 0x103 (uses inverted logic in physw_status)
//    { 1, KEY_MENU            ,0x00000080 }, // Found @0xe05e4d1c, levent 0x15
//    { 1, KEY_UP              ,0x00000100 }, // Found @0xe05e4d24, levent 0x06
//    { 1, KEY_DOWN            ,0x00000200 }, // Found @0xe05e4d2c, levent 0x07
//    { 1, KEY_RIGHT           ,0x00000400 }, // Found @0xe05e4d34, levent 0x09
//    { 1, KEY_LEFT            ,0x00000800 }, // Found @0xe05e4d3c, levent 0x08
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xe05e4d44, levent 0x0a
//    { 1, KEY_ERASE           ,0x00008000 }, // Found @0xe05e4d5c, levent 0x0b
//    { 2, KEY_VIDEO           ,0x00002000 }, // Found @0xe05e4db4, levent 0x02
//    { 0, 0, 0 }
//};

// canon_mode_list 0xe09d7ee8 Found @0xe003e7d0
// Check modemap values from 'platform/CAMERA/shooting.c':
// 32770  0x8002 In firmware but not in current modemap
// 32772  0x8004 In firmware but not in current modemap
// 32771  0x8003 In firmware but not in current modemap
// 32773  0x8005 In firmware but not in current modemap
// 33289  0x8209 In firmware but not in current modemap
// 16422  0x4026 In firmware but not in current modemap
// 16406  0x4016 In firmware but not in current modemap
// 16405  0x4015 In firmware but not in current modemap
// 16423  0x4027 In firmware but not in current modemap
// 16954  0x423a In firmware but not in current modemap
// 16425  0x4029 In firmware but not in current modemap
//  8776  0x2248 In firmware but not in current modemap
// 16461  0x404d In firmware but not in current modemap
//  8760  0x2238 In firmware but not in current modemap
//  8778  0x224a In firmware but not in current modemap
//  8777  0x2249 In firmware but not in current modemap
//  8761  0x2239 In firmware but not in current modemap
//  8764  0x223c In firmware but not in current modemap
//  8766  0x223e In firmware but not in current modemap
//  8779  0x224b In firmware but not in current modemap
// 16424  0x4028 In firmware but not in current modemap
// 16904  0x4208 In firmware but not in current modemap
// 33298  0x8212 In firmware but not in current modemap
// 32768  0x8000 In firmware but not in current modemap
//  2645  0x0a55 In firmware but not in current modemap
//  2653  0x0a5d In firmware but not in current modemap
//  2655  0x0a5f In firmware but not in current modemap
//  4175  0x104f In firmware but not in current modemap
//  4176  0x1050 In firmware but not in current modemap

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 40
// //      PROPCASE_DELTA_DIGITALGAIN 85
// #define PROPCASE_DELTA_SV 87
// //      PROPCASE_DELTA_ND 88
// //      PROPCASE_FELOCK 123
// #define PROPCASE_FLASH_ADJUST_MODE 130
// #define PROPCASE_FLASH_FIRE 131
// //      PROPCASE_HSCAPTURE 147
//         PROPCASE_EV_CORRECTION_2 not found
// #define PROPCASE_ORIENTATION_SENSOR 231
// #define PROPCASE_SV_MARKET 259
// //      PROPCASE_SVFIX 260
// #define PROPCASE_TV 276
// Guessed propset: uncertain (14 of 15 match), closest to 11
// Port's propset (12) may be set incorrectly

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_FIRMUP         3
// EXMEM_FIRMUP_INFLATE 4
// EXMEM_FIRMUP_PICTURESTYLE 5
// EXMEM_DVLPWORK       6
// EXMEM_GPS            7
// EXMEM_FACEAUTH       8
// EXMEM_OHYEARLOG      9
// EXMEM_WIFI           10
// EXMEM_MULTI_PLY      11
// EXMEM_FEP            12
// EXMEM_LENS_FIRMUP    13
// EXMEM_LENS_COMPENSATION 14
// EXMEM_FILESTORE      15
// EXMEM_MOVIE_REC      16
// EXMEM_MOVIE_PLY      17
// EXMEM_WIDE           18
// EXMEM_PIPELINE       19
// EXMEM_AUTO_GIS_MODE  20
// EXMEM_NP_GIS_MODE    21
// EXMEM_TRIPODHDR_MODE 22
// EXMEM_HSHQ_MODE      23
// EXMEM_CRAW_REC       24
// EXMEM_TIME_LAPSE_MOVIE 25

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xe05e3778) // Found @0xe006749c
DEF(physw_run                         ,0x00008334) // Found @0xe007a1aa
DEF(physw_sleep_delay                 ,0x0000833c) // (0x8334+0x8) Found @0xe007a1ae
DEF(physw_status                      ,0x0006a184) // Found @0xe007a4da
DEF(fileio_semaphore                  ,0x00010bac) // Found @0xe003a442
DEF(levent_table                      ,0xe06b81a4) // Found @0xe007ba58
DEF(FlashParamsTable                  ,0xe09d82c4) // Found @0xe003e7e4
DEF(playrec_mode                      ,0x0000b74c) // (0xb748+0x4) Found @0xe02ce292
DEF(jpeg_count_str                    ,0x00124ed8) // Found @0xe011e19a
// zoom_busy not found
// focus_busy not found
DEF(imager_active                     ,0x000086c4) // (0x86c0+0x4) Found @0xe01ccb12
DEF(canon_menu_active                 ,0x0000c740) // (0xc73c+0x4) Found @0xe035a48a
DEF(file_counter_var                  ,0x00010aa8) // Found @0xe03e3d2c
DEF(cameracon_state                   ,0x00008bbc) // (0x8ba4+0x18) Found @0xe0350a00
DEF(_nrflag                           ,0x000234bc) // (0x234b4+0x8) Found @0xe00f3e72
DEF(av_override_semaphore             ,0x0003d344) // Found @0xe03f4bc4
DEF(active_bitmap_buffer              ,0x0000c6f8) // (0xc6ac+0x4c) Found @0xe035e688
DEF(displaytype                       ,0x00009c28) // (0x9bc8+0x60) Found @0xe00e5578
DEF(bitmap_buffer                     ,0x0000c6fc) // (0xc6ac+0x50) Found @0xe035e68e
DEF(live_free_cluster_count           ,0x0012a948) // (0x12a910+0x38) Found @0xe002d066
// uiprop_count not found
DEF(exmem_alloc_table                 ,0x00073ba8) // Found @0xe0074062
DEF(exmem_types_table                 ,0xe1160da0) // Found @0xe0074066
DEF_CONST(exmem_type_count                  ,0x0000001a) // Found @0xe1160da0
DEF(debug_logging_ptr                 ,0x0002273c) // Found @0xe00879bc
DEF(debug_logging_flag                ,0x00022744) // Found @0xe00879b6
DEF(mzrm_sendmsg_ret_adr              ,0xe02ecc77)
DEF_CONST(fw_yuv_layer_buf                  ,0x4196a000) // Found @0xe007b710

NHSTUB(AllocateUncacheableMemory              ,0xe01e8625) //  0
NHSTUB(Close                                  ,0xe035f377) //  0
NHSTUB(CreateBinarySemaphore                  ,0xdffccf7d) //  0
NHSTUB(CreateTask                             ,0xdffc93a3) //  0
NHSTUB(DebugAssert                            ,0xdffc96e5) //  0
//NHSTUB(DeleteDirectory_Fut                  ,0x00000000) //  0            == 0x00000000
//NHSTUB(DeleteFile_Fut                       ,0x00000000) //  0            == 0x00000000
NHSTUB(DeleteSemaphore                        ,0xdffcd005) //  0
NHSTUB(DoAELock                               ,0xe027a70f) //  0
NHSTUB(DoAFLock                               ,0xe027a2c1) //  0
//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0            == 0x00000000
NHSTUB2(ExecuteEventProcedure                  ,0xe03366f3) //  0
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0            == 0x00000000
NHSTUB(ExitTask                               ,0xdffc9597) //  0
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0            == 0x00000000
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0            == 0x00000000
NHSTUB(Fclose_Fut                             ,0xe033503f) //  0
//NHSTUB(Feof_Fut                             ,0x00000000) //  0            == 0x00000000
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0            == 0x00000000
NHSTUB(Fgets_Fut                              ,0xe0335123) //  0
NHSTUB(Fopen_Fut                              ,0xe0335017) //  0
NHSTUB(Fread_Fut                              ,0xe03350b3) //  0
NHSTUB(FreeUncacheableMemory                  ,0xe01e8651) //  0
NHSTUB(Fseek_Fut                              ,0xe0335155) //  0
NHSTUB(Fwrite_Fut                             ,0xe03350eb) //  0
NHSTUB(GetBatteryTemperature                  ,0xe01e5c3b) //  0
NHSTUB(GetCCDTemperature                      ,0xe01e5c91) //  0
NHSTUB(GetCurrentAvValue                      ,0xe0305b45) //  0
NHSTUB(GetCurrentShutterSpeed                 ,0xe02ed889) //  0
NHSTUB(GetUsableMaxAv                         ,0xe03a4375) //  0
NHSTUB(GetUsableMinAv                         ,0xe03a4363) //  0
NHSTUB(get_current_deltasv                    ,0xe01cfc8f) //  0
NHSTUB(GetCurrentDriveBaseSvValue             ,0xe02fafb1) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xe036076b) //  0
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0            == 0x00000000
NHSTUB(GetFocusLensSubjectDistance            ,0xe035ee73) //  0
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0            == 0x00000000
NHSTUB(GetKbdState                            ,0xe00703b7) //  0
NHSTUB(GetMemInfo                             ,0xe0424f59) //  0
NHSTUB(GetOpticalTemperature                  ,0xe01e5bc7) //  0
NHSTUB(GetParameterData                       ,0xe025e52f) //  0
NHSTUB(GetPropertyCase                        ,0xe036b15b) //  0
NHSTUB(GetSystemTime                          ,0xe01819fb) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xe03676c1) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xe03676c9) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xe02181a9) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xe021815d) //  0
NHSTUB(GiveSemaphore                          ,0xdffcd0f1) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xe00756ef) //  0
NHSTUB(LEDDrive                               ,0xe03c2bcd) //  0
NHSTUB(LocalTime                              ,0xdffcd883) //  0
NHSTUB(LockMainPower                          ,0xe0088d49) //  0
NHSTUB(MakeDirectory_Fut                      ,0xe035f6df) //  0
//NHSTUB(MoveFocusLensToDistance              ,0x00000000) //  0            == 0x00000000
NHSTUB(MoveIrisWithAv                         ,0xe03f4bb1) //  0
NHSTUB(Open                                   ,0xe035f33b) //  0
NHSTUB(PB2Rec                                 ,0xe03513d9) //  0
NHSTUB(PT_PlaySound                           ,0xe036b7bf) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xe0362bbb) //  0
NHSTUB(PostLogicalEventToUI                   ,0xe0362bef) //  0
NHSTUB(Read                                   ,0xe044cd97) //  0
NHSTUB(ReadFastDir                            ,0xe03ba959) //  0
NHSTUB(Rec2PB                                 ,0xe0351433) //  0
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0            == 0x00000000
//NHSTUB(Restart                              ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xe035dd93) //  0
NHSTUB(ScreenUnlock                           ,0xe035dea7) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xe040eac1) //  0
NHSTUB(SetAutoShutdownTime                    ,0xe0088d99) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xe0369f1f) //  0
NHSTUB(SetDate                                ,0xe041004d) //  0
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0            == 0x00000000
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0            == 0x00000000
NHSTUB(SetLogicalEventActive                  ,0xe03578af) //  0
NHSTUB(SetParameterData                       ,0xe025e443) //  0
NHSTUB(SetPropertyCase                        ,0xe036b00d) //  0
NHSTUB(SetScriptMode                          ,0xe03578e7) //  0
NHSTUB(SleepTask                              ,0xdffc9253) //  0
NHSTUB(TakeSemaphore                          ,0xdffcd077) //  0
//NHSTUB(TurnOffBackLight                     ,0x00000000) //  0            == 0x00000000
//NHSTUB(TurnOnBackLight                      ,0x00000000) //  0            == 0x00000000
NHSTUB(TurnOnDisplay                          ,0xe00cb739) //  0
NHSTUB(TurnOffDisplay                         ,0xe00e55b5) //  0
NHSTUB(UnlockAE                               ,0xe027a72d) //  0
NHSTUB(UnlockAF                               ,0xe027a2f1) //  0
NHSTUB(UnlockMainPower                        ,0xe0088cdb) //  0
NHSTUB(VbattGet                               ,0xe0072c69) //  0
NHSTUB(Write                                  ,0xe035f2fd) //  0
//NHSTUB(WriteSDCard                          ,0x00000000) //  0            == 0x00000000
NHSTUB(_log                                   ,0xdffd52c9) //  0
NHSTUB(_log10                                 ,0xdffd5621) //  0
NHSTUB(_pow                                   ,0xdffd5705) //  0
//NHSTUB(_sqrt                                ,0x00000000) //  0            == 0x00000000
NHSTUB(add_ptp_handler                        ,0xe02d5567) //  0
//NHSTUB(apex2us                              ,0x00000000) //  0            == 0x00000000
NHSTUB(close                                  ,0xe044cc93) //  0
//NHSTUB(exmem_ualloc                         ,0x00000000) //  0            == 0x00000000
//NHSTUB(exmem_ufree                          ,0x00000000) //  0            == 0x00000000
NHSTUB(free                                   ,0xe03a0b7b) //  0
NHSTUB(kbd_p1_f                               ,0xe007a4d3) //  0
NHSTUB(kbd_p1_f_cont                          ,0xe007a4db) //  0
NHSTUB(kbd_p2_f                               ,0xe0079efd) //  0
NHSTUB(kbd_read_keys                          ,0xe007a49d) //  0
NHSTUB(kbd_read_keys_r2                       ,0xe007021f) //  0
NHSTUB(lseek                                  ,0xe035f549) //  0
NHSTUB(malloc                                 ,0xe03a0b43) //  0
NHSTUB(memcmp                                 ,0xe03fa605) //  0
NHSTUB(memcpy                                 ,0xe0200051) //  0
NHSTUB(memset                                 ,0xe0201b8d) //  0
NHSTUB(mktime_ext                             ,0xe01b6461) //  0
NHSTUB(open                                   ,0xe044cc21) //  0
NHSTUB(OpenFastDir                            ,0xe03ba8bb) //  0
NHSTUB(closedir                               ,0xe03ba883) //  0
NHSTUB(get_fstype                             ,0xe0360705) //  0
NHSTUB(qsort                                  ,0xe049c7af) //  0
NHSTUB(rand                                   ,0xe04fb4a7) //  0
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0            == 0x00000000
NHSTUB(set_control_event                      ,0xe0357619) //  0
NHSTUB(srand                                  ,0xe04fb4a1) //  0
NHSTUB(stat                                   ,0xe035f57d) //  0
NHSTUB(strcat                                 ,0xe0439d77) //  0
NHSTUB(strchr                                 ,0xe0230051) //  0
NHSTUB(strcmp                                 ,0xe0362e89) //  0
NHSTUB(strcpy                                 ,0xe036bbc1) //  0
NHSTUB(strftime                               ,0xe035dd93) //  0
NHSTUB(strlen                                 ,0xe036bbe3) //  0
NHSTUB(strncmp                                ,0xe0471aad) //  0
NHSTUB(strncpy                                ,0xe04c0f3d) //  0
NHSTUB(strrchr                                ,0xe04c0f61) //  0
NHSTUB(strtol                                 ,0xe03c1133) //  0
NHSTUB(strtolx                                ,0xe03c0fd9) //  0
   DEF(task_CaptSeq                           ,0xe00384d9) //  0
   DEF(task_DvlpSeqTask                       ,0xe00531f7) //  0
   DEF(task_ExpDrv                            ,0xe02a2ca3) //  0
   DEF(task_InitFileModules                   ,0xe00fdd05) //  0
   DEF(task_MovieRecord                       ,0xe00dec29) //  0
   DEF(task_PhySw                             ,0xe007a1a9) //  0
   DEF(task_TouchPanel                        ,0xe01f43a3) //  0
   DEF(task_TricInitTask                      ,0xe03be2f3) //  0
   DEF(hook_CreateTask                        ,0xdffc93a2) //  0
NHSTUB(time                                   ,0xdffcd4c1) //  0
NHSTUB(vsprintf                               ,0xe0383ad3) //  0
//NHSTUB(EngDrvRead                           ,0x00000000) //  0            == 0x00000000
NHSTUB(PTM_GetCurrentItem                     ,0xe035940f) //  0
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0            == 0x00000000
//NHSTUB(SetHPTimerAfterNow                   ,0x00000000) //  0            == 0x00000000
NHSTUB(SetEventFlag                           ,0xdffcca49) //  0
NHSTUB(transfer_src_overlay                   ,0xe035da6b) //  0
NHSTUB(bzero                                  ,0xdffd415d) //  0
NHSTUB(memset32                               ,0xdffd4161) //  0
NHSTUB(get_dial_hw_position                   ,0xe024ec59) //  0
NHSTUB(PT_MFOn                                ,0xe027b743) //  0
NHSTUB(PT_MFOff                               ,0xe027b777) //  0
NHSTUB(GetAdChValue                           ,0xe01d78ef) //  0
NHSTUB(EnableHDMIPower                        ,0xe01b6355) //  0
NHSTUB(DisableHDMIPower                       ,0xe01b6385) //  0
NHSTUB(SetVideoOutType                        ,0xe040f03f) //  0
NHSTUB(GetVideoOutType                        ,0xe040efcb) //  0
NHSTUB(IsWirelessConnect                      ,0xe0349b01) //  0
