# mandatory for DIGIC 6 and later
THUMB_FW=1
# update build rules for Digic 7 ARM changes
ARMV7A=1

PLATFORMID=12997

PLATFORMOS=dryos

PLATFORMOSVER=59

DIGIC = 70

# mandatory for DIGIC 6
MEMBASEADDR=0x8000

# start of firmware
ROMBASEADDR=0xE0000000

# end of RAM
MAXRAMADDR = 0x3fffffff

# force FI2 off - does not work
#override OPT_FI2=

# TODO
NEED_ENCODED_DISKBOOT=18
KEYSYS=d4k
FI2FLAGS=W

# next line is for the compatibility check, as comment
# PLATFORMID @ 0xe1f20270
# below 2 commented lines are used by tools/compatbuilder.sh
# BLINK_LED_CONTROL=5
# BLINK_LED_GPIO=0xD20801E0
