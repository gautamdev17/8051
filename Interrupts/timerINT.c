#include <reg51.h>
sbit LED = P2^0;

void timer_ISR() interrupt 1
{
	TR0 = 0;//stop timer 0
	LED = ~LED;
	//reload the timer
	TL0 = 0xf0;
	TH0 = 0xd8;
	TR0 = 1;
}
//10000 millisecond delay : 65536 - 10000 = 55536 = d8f0(hex)
void main()
{
	TMOD = 0x01;
	//set the timer
	TL0 = 0xf0;
	TH0 = 0xd8;
	//enable timer 0 interrupt
	EA = 1;
	ET0 = 1;
	TR0 = 1;//start timer 0
	while(1);
}
