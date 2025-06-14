#include <reg51.h>
#include <delayheader.h>
#include <math.h>
#define LCD_D P2 // 8 data pins connected to port 2(D0 to D7)
sbit RS = P1^0;
sbit RW = P1^1;
sbit E = P1^2;

void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_str(char *);
void float_val(float ,int);
void lcd_num(int n);

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

void lcd_str(char * s)//this function recieves the string as a char pointer
{
	while(*s)//loop executes until null char is met
	{
		lcd_data(*s++);//pointer moves if not null
	}
}

void float_val(float f,int p)// function to print floating point numbers with precision 'p'
{
	float temp;
	int n;
	n=f;
	lcd_num(n);
	lcd_data('.');
	temp=(f-n)*pow(10,p);
	n=temp;
	lcd_num(n);
	
}



void lcd_num(int n)
{
	int arr[5],i=0;
	if(n==0)
		lcd_data('0');
	else
	{
		if(n<0)
		{
			lcd_data('-');
			n=-n;
		}
	
		while(n>0)
		{
			arr[i++]=n%10;
			n=n/10;
		}
	
		for(--i;i>=0;i--)
			lcd_data(arr[i]+48);
	}
	
}
