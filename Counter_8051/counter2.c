//code to switch on led when count reaches 36
#include <reg51.h>
sbit LED P1^0
void main()
{
	int cnt = 0;
	TMOD = 0x04;// counter 0 mode 0
	TR0 = 1;// start counter
	
	while(cnt<36)
	{
		cnt = (TH0*32) + TL0;// since TL0 has 5 bits, and can maximum represent 31. so when count reaches 32, TH0 = 1 and TL0 = 0, then while loop ends at TH0 = 1 and TL0 = 4
	}
	LED = 0;//turning on active low led
	TR0 = 0;
}
