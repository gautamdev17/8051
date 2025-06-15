//this code makes char 'A' blink in an 16x2 LCD (initalizing the lcd clears it and it writes char A, this goes on a loop forever)

#include <reg51.h>
#include <delayheader.h>
#define LCD_D P2 // 8 data pins connected to port 2(D0 to D7)
sbit RS = P1^0;
sbit RW = P1^1;
sbit E = P1^2;

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

void main()
{
	lcd_init();//initializes the lcd
	lcd_data('A');// this line sends char 'A' to the 8 data pins
}

void lcd_init(void)
{
	lcd_cmd(0x01);//to clear display
	lcd_cmd(0x02);//return cursor to home position
	lcd_cmd(0x0c);//display on cursor off
	lcd_cmd(0x38);//8 bit interfacing mode with both lines
	lcd_cmd(0x80);//select the starting address of DDRAM
}

void lcd_cmd(unsigned char cmd)
{
	LCD_D = cmd;// Assigning command to the data pins
	RS = 0;// selects command register
	RW = 0;// write operation
	E = 1;// latch the data to the LCD
	delay(2);// LCD is in internal operation mode
	E = 0;// To re-latch the next byte
}

void lcd_data(unsigned char d)
{
	LCD_D = d;// Assigning data to the data pins
	RS = 1;// selects data register
	RW = 0;// write operation
	E = 1;// latch the data to the LCD
	delay(2);// LCD is in internal operation mode
	E = 0;// To re-latch the next byte
}
