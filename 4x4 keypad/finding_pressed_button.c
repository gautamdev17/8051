#include <reg51.h>
#include <lcdheader.h>

//declare rows and columns to Port3

sbit c0=P3^0;
sbit c1=P3^1;
sbit c2=P3^2;
sbit c3=P3^3;

sbit r0=P3^4;
sbit r1=P3^5;
sbit r2=P3^6;
sbit r3=P3^7;

// Define 2 dimensional array for displaying correspponding data based on key pressing
// Total 4 rows and 4 columns i.e 16 keys each key having one data

unsigned char key_lut[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int row_val,col_val;

void main()
{
	lcd_init();
	lcd_str("welcome to");
	lcd_cmd(0xc0);
	lcd_str("keypad ");
	delay(1000);
	lcd_cmd(0x01);
	
	while(1)
	{
		
		delay(300);
		
		r0=r1=r2=r3=0;// connect all rows to ground
		c0=c1=c2=c3=1;// all columns are high
		lcd_str("press any key");
		while(c0&c1&c2&c3);// check switch pressing or not
		lcd_cmd(0x01);
		/* row checking*/
		
		r0=0;// now let's check if any key in row 0 was clicked
		r1=r2=r3=1;
		
		if((c0&c1&c2&c3)==0)// IF CONDITION IS TRUE ZERO VALUE IS ASSIGNED TO ROW
		{
			row_val=0;
			goto col_check;
		}
		
		r1=0;// CHECK IN R0W1 ANY ONE OF KEY PRESSED OR NOT
		r0=r2=r3=1;
		if((c0&c1&c2&c3)==0)
		{
			row_val=1;
			goto col_check;
		}
		
		r2=0;// CHECK IN R0W2 ANY ONE OF KEY PRESSED OR NOT
		r0=r1=r3=1;
		if((c0&c1&c2&c3)==0)
		{
			row_val=2;
			goto col_check;
		}
		
		r3=0;// CHECK IN R0W3 ANY ONE OF KEY PRESSED OR NOT
		r0=r1=r2=1;
		if((c0&c1&c2&c3)==0)
		{
			row_val=3;
			goto col_check;
		}
		
			/* Column check*/
		col_check:
		if(c0==0)
			col_val=0;
		else if(c1==0)
			col_val=1;
		else if(c2==0)
			col_val=2;
		else if(c3==0)
			col_val=3;
		while((c0&c1&c2&c3)==0);//for key releasing
		lcd_int(key_lut[row_val] [col_val]);// assign key value to lcd to see the output
		lcd_str("   ");
		float_val(3.14); // just trying float_val function in lcd header for fun
		delay(5000);
		lcd_cmd(0x01);
	}
	
}
