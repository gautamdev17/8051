// delay 1ms using timer 0 mode 0, using 12MHz clock
#include <reg51.h>
#include <delayheader.h>

void main()
{
	TMOD = 0x00;
	// we want to generate 1ms delay in mode 0. tl0 has 5 bits and th0 has 8 bits.
  // 8192 is total count of timer 0 mode 0. we write 8192-1000 to tl0 and th0 in binary.
	TL0 = 0x18;
	TH0 = 0xE0;
	
	TR0 = 1;
	
	while(TF0==0);
	
	TR0 = 0;
	
	TF0 = 0;
}
