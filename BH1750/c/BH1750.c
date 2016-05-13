#include <wiringPiI2C.h>
#include <stdio.h>

#define BH1750_ADDR 0x23

//Delay getLux function
#define LUXDELAY 500

int getLux(int fd)
{
	wiringPiI2CWrite(fd,0x10);
	delay(LUXDELAY);
	int word = wiringPiI2CReadReg16(fd, 0x00);
	int lux=((word & 0xff00)>>8) | ((word & 0x00ff)<<8);
	return lux;
}

int main()
{
	int fd = wiringPiI2CSetup(BH1750_ADDR) ;
	printf("Lux:%d \n", getLux(fd));
	return 0 ;
}
