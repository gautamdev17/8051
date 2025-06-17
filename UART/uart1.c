#include <reg51.h>
sbit LED = P1^0;
void uart_init(void);
void uart_tx(unsigned char);

void main()
{
	uart_init();
	uart_tx('A');
}

void uart_init()
{
	SCON = 0x40; /* 8N1 frame is selected
	(Start Bit (0) | 8 Data Bits | No Parity | 1 Stop Bit (1))*/
	TMOD = 0x20; // Timer 1 Mode 2
	TH1 = TL1 = 253;
	TR1 = 1;// Timer 1 starts to run
}

void uart_tx(unsigned char d)
{
	SBUF = d;// Serial transimission has started
	while(TI==0);// Waiting until the data has been transmitted
	LED = 0;// turning on active-low led
	TI = 0; // clear the TI flag
}
