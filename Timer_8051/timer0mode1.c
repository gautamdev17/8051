// 1ms delay using timer 0 mode 1
#include <reg51.h>

void main()
{
	TMOD = 0x01;
  //timer 0 mode 1 calls 16 bit timer mode, so for 1ms delay, we write in binary 65536-1000 to tl0 and th0
	TL0 = 0x18;
	TH0 = 0xFC;
	
	TR0 = 1;
	while(TF0==0);
	
	TR0 = 0;
	TF0 = 0;
}
