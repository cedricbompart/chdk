#define LED 0xD20801E0

void sleep(int duration) {
	int i;
	for (i = 0; i < duration; i++) {
		asm volatile( "nop\n" );
	}
}

void blink() {
	volatile long *led = (long*) LED;

	while (1) {
		*led = 0x24D0002; /* on */
		sleep(10000000);
		*led = 0x24C0003; /* off */
		sleep(10000000);
	}
}

/**
 * @see main startup
 */
void __attribute__((naked,noinline)) boot() {
	blink();
}
