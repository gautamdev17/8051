#include"delayheader.h"
sfr P1=0x90;
sbit AL_LED=P1^0;// plugging in active low led to port 1 0th pin

void main()
{
while(1)
{
	AL_LED=0;//power-on active low Led
	delay(100);//wait for 100 milliseconds
	AL_LED=1;//power-off active low Led
	delay(100);//wait for 100 milliseconds
}
}
