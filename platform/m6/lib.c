#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

#define LED_PR 0xd20b0994 // green LED on the back

void shutdown() {
    while(1)   _SleepTask(500);
}

void debug_led(int state) {
    volatile long *p = (void*)LED_PR;
    *p = ((state) ? 0x4d0002 : 0x4c0003);
}
