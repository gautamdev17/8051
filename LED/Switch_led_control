#include <reg51.h>
#include <delayheader.h>
sbit AL_LED1 = P1^0;
sbit AL_SWITCH1 = P2^0;

void main() {
    while (1) {
        AL_LED1 = (AL_SWITCH1 == 1)?1 : 0;
				delay(1000);
    }
}
