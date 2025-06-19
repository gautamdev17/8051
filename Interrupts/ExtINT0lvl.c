#include <reg51.h>
sbit LED = P1^0;

void Ext_INT0_ISR(void) interrupt 0
{
    LED = 0;  // LED ON (active low)
}

void main()
{
    LED = 1;    // LED OFF initially
    EA = 1;     // Global interrupt enable
    EX0 = 1;    // Enable external interrupt 0
    IT0 = 0;    // Level-triggered mode (low level on P3.2)

    while(1);   // Infinite loop to keep microcontroller alive
}
