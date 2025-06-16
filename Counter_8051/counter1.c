//to switch on LED when count reaches to 5
#include <reg51.h>
sbit LED = P1^0;

void main()
{
	LED = 1;
	TMOD = 0x04;// counter 0 mode 0
	TR0 = 1;// counter 0 starts
	while(TL0<5);//wait until count reaches 5, it's connected at P3^4
	LED = 0;//power on active-low led
	TR0 = 0;
}
