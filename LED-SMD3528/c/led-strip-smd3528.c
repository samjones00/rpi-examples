#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Pin for controlling the LED strip: GPIO 11, aka pin 11
const int pinCtrl = 0;

int main()
{
	if (-1 == wiringPiSetup())
	{
		printf("setup wiringPi failed!\n");
		return 1;
	}

	// Set pin mode
	pinMode(pinCtrl, OUTPUT);

	for(;;) 
	{
		digitalWrite(pinCtrl, 1);
		delay(1000);
		digitalWrite(pinCtrl, 0);
		delay(1000);
	}
	return 0;
}
