#include <reg51.h>
sbit LED = P1^0;

void Ext_INT0_ISR(void) interrupt 0
{
    LED = ~LED; // Toggle LED on every falling edge trigger
}

void main()
{
    LED = 0;     // Start with LED OFF
    EA = 1;      // Enable global interrupts
    EX0 = 1;     // Enable external interrupt 0
    IT0 = 1;     // Set to falling edge triggered (edge-triggered mode)

    while(1);    // Infinite loop
}
