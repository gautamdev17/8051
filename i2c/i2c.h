#include <intrins.h>
#include <delayheader.h>
sbit scl = P3^0;
sbit sda = P3^1;

void i2c_start()
{
	scl = 1;
	sda = 1;
	sda = 0;
}

void i2c_stop()
{
	sda = 0;
	scl = 1;
	sda = 1;
}

void i2c_bytewrite(unsigned char d)
{
	unsigned char j;
	for(j=0;j<8;j++)
	{
		scl = 0;
		sda = d&(0x80>>j);//d&(0x80>>j)?1:0;
		scl = 1;
	}
}

void i2c_ack()
{
	scl=0;
	sda=1;
	scl=1;
	while(sda==1);
	scl=0;
}

void i2c_noack(void)
{
	scl=0;
	sda=1;
	scl=1;
	scl=0;
		
}

unsigned char i2c_byteread()
{
	unsigned char j,buf1=0;
	for(j=0;j<8;j++)
	{
		scl = 0;
		_nop_();// due to clock stretching
		scl = 1;
		if(sda)
			buf1|=(0x80>>j);
	}
	return buf1;
}

void i2c_slave_write(unsigned char sa,unsigned char r_addr,unsigned char dat)
{
	i2c_start();
	i2c_bytewrite(sa);// selecting slave
	i2c_ack();
	i2c_bytewrite(r_addr);// selecting reg address to write inside the slave
	i2c_ack();
	i2c_bytewrite(dat);// writing the address
	i2c_ack();
	i2c_stop();
	delay(100);
}

unsigned char i2c_slave_read(unsigned char sa,unsigned char r_addr)
{
	unsigned char buf;
	i2c_start();
	i2c_bytewrite(sa);// selecting slave
	i2c_ack();
	i2c_bytewrite(r_addr);// selecting reg address to read inside the slave
	i2c_ack();
	i2c_start();
	i2c_bytewrite(sa|1);// we do this to select read mode, ex: 10100000 | 00000001 = 10100001
	buf = i2c_byteread();      // ? store the byte read
	i2c_noack(); 
	i2c_stop();
	delay(100);
	return buf;
}
