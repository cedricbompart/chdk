#define CAM_DRYOS         1
#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
#define CAM_DRYOS_2_3_R59 1 // Defined for cameras with DryOS version R59 or higher
#define CAM_ILC 1 // Camera is interchangeable lens
#define CAM_HAS_WIFI 1 // Firmware has wifi support (only define if camera has hardware)
#undef  CAM_UNCACHED_BIT
#define CAM_UNCACHED_BIT  0x40000000 // Found @0xe01e8654
#undef CAM_HAS_ND_FILTER // Camera does not have an ND filter
