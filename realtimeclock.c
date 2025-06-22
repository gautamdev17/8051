#include<reg51.h>
#include"lcdheader.h"
#include "i2c.h"

void func(unsigned char bcd)
{
	//to convert bcd input of rtc to lcd writable
	//if rtc gives 0x51, its 51. but lcd_data(i2cslaveread) will print ascii of 0x51=81='Q'
	lcd_data((bcd >> 4) + '0');//5 will get printed
	lcd_data((bcd & 0x0F) + '0');//1 will get printed
}

void main()
{
	lcd_init();
	lcd_str("i2c_RTC:");
	delay(500);
	while(1)
	{
		func(i2c_slave_read(0xd0,0x02));
		lcd_str(":");
		func(i2c_slave_read(0xd0,0x01));
		lcd_str(":");
		func(i2c_slave_read(0xd0,0x00));
		delay(1000);
		lcd_cmd(0x01);
    lcd_cmd(0x80);
	}
	
}
