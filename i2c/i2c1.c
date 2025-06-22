#include <reg51.h>
#include <lcdheader.h>
#include <i2c.h>
#include <delayheader.h>

void main()
{
	lcd_init();
	lcd_str("i2c_EEPROM:");
	delay(500);
	i2c_slave_write(0xa0,0x00,'A');
	//lcd_cmd(0x01);  // Clear
	
	//lcd_int(i2c_slave_read(0xA0, 0x00)); // Show ASCII value (like 65)
	
	lcd_data(i2c_slave_read(0xa0,0x00));
	
	while(1);
}
