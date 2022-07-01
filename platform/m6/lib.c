#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

#define LED_PR 0xd20b0994 // green LED on the back

void shutdown_soft() {
	_PostLogicalEventForNotPowerType(0x1005, 0);
}

/**
 * @see main startup
 */
void shutdown() {
	while (1)
		_SleepTask(500);
}

/**
 * @header debug_led.h
 */
void debug_led(int state) {
	volatile long *p = (void*) LED_PR;
	*p = ((state) ? 0x4d0002 : 0x4c0003);
}

/**
 * Power Led = first entry in table (led 0).
 * AF Assist Lamp = second entry in table (led 1).
 *
 * @header debug_led.h
 */
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
	static char led_table[2] = { 0, 4 };
	_LEDDrive(led_table[led % sizeof(led_table)], state <= 1 ? !state : state);
}

/**
 * @header keyboard.h
 */
void JogDial_CW(void) {
	_PostLogicalEventToUI(0x872, 1); // RotateJogDialRight
}

/**
 * @header keyboard.h
 */
void JogDial_CCW(void) {
	_PostLogicalEventToUI(0x873, 1); // RotateJogDialLeft
}
