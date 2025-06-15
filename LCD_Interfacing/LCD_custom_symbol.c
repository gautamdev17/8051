#include <reg51.h>
#include <lcdheader.h>//including the lcd header file(check my 'header files' folder)

void cgram_write(void);
/*developers plz look into this for better understanding of cgram and how i defined custom symbols on the lcd:
The lcd controller provides 
64 bytes of cgram for user defined custom chars
Each custom char is:
- 8 bytes long (1 byte = 1 row of 5x8 matrix)
- Max 8 characters (8 x 8 = 64 bytes)
To define and use a custom character:
1. Set CGRAM address (0x40, 0x48, ..., 0x78):
    lcd_cmd(0x40);  // 0x40 = CGRAM address for symbol 0
2️. Send 8 bytes (each row pattern of 5x8 symbol):
    lcd_data(0x1F); // Example row: all 5 pixels ON
3️.To display the symbol, use:
    lcd_data(0);    // 0 to 7 corresponds to CGRAM symbols
 CGRAM Address Mapping:
    Symbol 0: 0x40
    Symbol 1: 0x48
    Symbol 2: 0x50
    ...
    Symbol 7: 0x78
*/
unsigned char cgram_lut[] = {0x17,0x14,0x14,0x1f,0x05,0x05,0x1d};
	
void main()
{
	lcd_init();
	cgram_write();
	while(1)
	{
		lcd_cmd(0x80);
		lcd_data(0);
	}
}

void cgram_write()
{
	unsigned char k;
	lcd_cmd(0x40); // starting address of cgram
	for(k=0;k<8;k++)
		lcd_data(cgram_lut[k]);
}
