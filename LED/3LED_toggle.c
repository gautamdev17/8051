#include <reg51.h>
#include <delayheader.h>
sbit switch1 = P1^0;//active low

void main()
{
	int count = 0;
	while(1)
	{
		if(switch1==0){
			while(switch1==0){
				P2 = 0x01<<count;//leds are active high
				delay(1000);
			}
			count=(count+1)%3;
		}
		P2 = 0x00;
	}
}
