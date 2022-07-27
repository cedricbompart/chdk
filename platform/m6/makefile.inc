THUMB_FW=1
ARMV7A=1

PLATFORMID=12997 # from lsusb
PLATFORMOS=dryos
PLATFORMOSVER=59
DIGIC = 70

MEMBASEADDR=0x8000
ROMBASEADDR=0xE0000000

override OPT_FI2=

MAXRAMADDR = 0x3fffffff

NEED_ENCODED_DISKBOOT=19
KEYSYS=d4k // TODO
FI2FLAGS=W

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xe1f20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=5
# BLINK_LED_GPIO=0xD20801E0
