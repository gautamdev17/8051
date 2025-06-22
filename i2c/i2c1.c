/*Write an ECP to write 'A' into EEPROM(AT24C08) and read 
the data from EEPROM and display it on LCD using 8051*/
#include<reg51.h>
#include"lcdheader.h"
#include "i2c.h"

void main()
{
	lcd_init();
	lcd_str("i2c_EEPROM:");
	delay(500);
	i2c_slave_write(0xa0,0x00,'A');
	lcd_data(i2c_slave_read(0xa0,0x00));
	while(1);
	
}
