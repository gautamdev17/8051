void delay(unsigned int dly)// include this header file in your programs
{
	unsigned char i;
	for(;dly>0;dly--)// controls number of millisecond delay
	{
	//i=250, register copy costs 1 MC
	for(i=250;i>0;i--);// this uses 250x2 machine cycles(DJNZ costs 2 MC)
	//i=247, register copy costs 1 MC
	for(i=247;i>0;i--);// this uses 247x2 machine cycle
	
	}
}
/* function call and return take up  2+2, 4 more machine cycles
if we use 12MHz crystal, this comes up to be 1000us or 1 millisecond delay
 1 + 250x2 + 1 + 247x2 + 4= 1000*/
