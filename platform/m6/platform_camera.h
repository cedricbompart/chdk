/**
 * Camera - M6 - platform_camera.h
 *
 * This file contains the various settings values specific to the EOS M6 camera.
 * This file is referenced via the 'include/camera.h' file and should not be loaded directly.
 *
 * If adding a new settings value put a suitable default in 'include/camera.h',
 * along with documentation on what the setting does and how to determine the correct value.
 * If the setting should not have a default value then add it in 'include/camera.h'
 * using the '#undef' directive along with appropriate documentation.
 *
 * Override any default values with your camera specific values in this file. Try and avoid
 * having override values that are the same as the default value.
 *
 * When overriding a setting value there are two cases:
 *   1. If removing the value, because it does not apply to your camera, use the '#undef' directive.
 *   2. If changing the value it is best to use an '#undef' directive to remove the default value
 * followed by a '#define' to set the new value.
 *
 * When porting CHDK to a new camera, check the documentation in 'include/camera.h'
 * for information on each setting. If the default values are correct for your camera then
 * don't override them again in here.
 */

// from signature finder
#define CAM_DRYOS                         1
#define CAM_DRYOS_2_3_R39                 1 // Defined for cameras with DryOS version R39 or higher
#define CAM_DRYOS_2_3_R47                 1 // Defined for cameras with DryOS version R47 or higher
#define CAM_DRYOS_2_3_R59                 1 // Defined for cameras with DryOS version R59 or higher
#define CAM_ILC                           1 // Camera has interchangeable lens
#define CAM_HAS_WIFI                      1 // Firmware has wifi support
#undef  CAM_UNCACHED_BIT
#define CAM_UNCACHED_BIT                  0x40000000 // Found @0xe01e8654
#undef  CAM_HAS_ND_FILTER                 // Camera does not have an ND filter

// handwritten
#define CAM_PROPSET                       12
#define CAM_HAS_CMOS                      1

#define CAM_RAW_ROWPIX                    6112
#define CAM_RAW_ROWS                      4060
#define CAM_JPEG_WIDTH                    6000
#define CAM_JPEG_HEIGHT                   4000
#define CAM_ACTIVE_AREA_X1                84
#define CAM_ACTIVE_AREA_Y1                46
#define CAM_ACTIVE_AREA_X2                6084
#define CAM_ACTIVE_AREA_Y2                4046
#undef  CAM_SENSOR_BITS_PER_PIXEL
#define CAM_SENSOR_BITS_PER_PIXEL         14
#define CAM_DNG_LENS_INFO                 { 180,10,550,10,35,10,56,10 } // 18-55mm
#define cam_CFAPattern                    0x02010100
#define cam_CalibrationIlluminant1        17 // Standard light A
#define cam_CalibrationIlluminant2        21 // D65

#define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1
#undef  CAM_BITMAP_WIDTH
#undef  CAM_BITMAP_HEIGHT
#undef  CAM_SCREEN_WIDTH
#undef  CAM_SCREEN_HEIGHT
#define CAM_BITMAP_WIDTH                  736
#define CAM_BITMAP_HEIGHT                 480
#define CAM_SCREEN_WIDTH                  720
#define CAM_SCREEN_HEIGHT                 480

#define CAM_HAS_CANON_RAW                 1
#define CAM_ADJUSTABLE_ALT_BUTTON         1
#define CAM_ALT_BUTTON_NAMES              { "Playback", "WiFi" }
#define CAM_ALT_BUTTON_OPTIONS            { KEY_PLAYBACK, KEY_WIFI }
#define CAM_HAS_VIDEO_BUTTON              1
#undef  CAM_HAS_ERASE_BUTTON
#undef  CAM_USE_ZOOM_FOR_MF

#undef  CAM_KEY_PRESS_DELAY
#define CAM_KEY_PRESS_DELAY               60

#define CAM_3ARG_DebugAssert              1
#define CAM_FILE_COUNTER_IS_VAR           1
#define PARAM_CAMERA_NAME                 2
#define CAM_DATE_FOLDER_NAMING            0x80
#define CAM_QUALITY_OVERRIDE              1
#define CAM_CALC_BLACK_LEVEL              1
#define CAM_SHOW_OSD_IN_SHOOT_MENU        1
#define CAM_AV_OVERRIDE_IRIS_FIX          1
#define CAM_DRIVE_MODE_FROM_TIMER_MODE    1

#undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
#undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
#undef  CAM_VIDEO_CONTROL
#define CAM_SIMPLE_MOVIE_STATUS           1
#define CAM_IS_VID_REC_WORKS              1

#undef  CAM_AF_LED
#define CAM_AF_LED                        1

#undef  CAM_CIRCLE_OF_CONFUSION
#define CAM_CIRCLE_OF_CONFUSION           19 // APSC - CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

#define CAM_SD_OVER_IN_AF                 1
#define CAM_SD_OVER_IN_MF                 1

#undef  CAM_USB_EVENTID
#define CAM_USB_EVENTID                   0x302 // Levent ID for USB control
