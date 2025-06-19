#include <reg51.h>

void uart_init();
void uart_tx(unsigned char);
void uart_rx();
void uart_str(unsigned char *);

void main()
{
	unsigned char ch;
	uart_init();
	while(1)
	{
		ch = uart_rx();
		uart_tx(ch);
	}
}

void uart_init()
{
	SCON = 0x50;// 8N1 frame is selected and REN is set
	TMOD = 0x20;// Timer 1 Mode 2
	TH1 = TL1 = 253;
	TR1 = 1;
}

void uart_tx(unsigned char d)
{
	SBUF = d;
	while(TI==0);
	TI=0;
}

unsigned char uart_rx()
{
	unsigned char rx_buf;
	while(RI==0);
	RI=0;
	rx_buf = SBUF;
	return rx_buf;
}

void uart_str(unsigned char *s)
{
	while(*s)
	{
		uart_tx(*s++);
	}
}
