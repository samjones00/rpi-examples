#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>

// Pin for controlling the LED strip: GPIO 11, aka pin 11
const int pinCtrl = 0;

void close()
{
	digitalWrite(pinCtrl, 0);
	exit(0);
}

void enablePWM(int pin, int speed)
{
	if (0 != softPwmCreate(pin, 0, speed))
	{
		printf("ERROR: Cannot enable software PWM for pin %d", pin);
	}
}

int main()
{
	signal(SIGINT, close);

	if (-1 == wiringPiSetup())
	{
		printf("setup wiringPi failed!\n");
		return 1;
	}

	// Set pin mode
	pinMode(pinCtrl, OUTPUT);
	enablePWM(pinCtrl, 255);

	digitalWrite(pinCtrl, 1);
	for(;;) 
	{
		softPwmWrite(pinCtrl, 255);
		//digitalWrite(pinCtrl, 1);
		delay(1000);
		softPwmWrite(pinCtrl, 10);
		//digitalWrite(pinCtrl, 0);
		delay(1000);
	}
	return 0;
}
