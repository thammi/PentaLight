#include <stdint.h>
#include <stdlib.h>

#include "main.h"

void tick(void);

#if defined(__AVR__)
void init(void) __attribute__ ((naked, used, section (".init8")));
#warning compiling for AVR
#else
void init(void) __attribute__((constructor));
#warning compiling for SIM
#endif

void init(void)
{
    void (*fp)(void);
	fp=tick;
        
	registerAnimation(fp,4);
}
            


void tick() {
	uint8_t x, y;

	for(x = 0; x < LED_WIDTH; x++) {
		for(y = 0; y < LED_HEIGHT; y++) {
			setLedXY(x, y, rand()&3);
		}
	}
}
