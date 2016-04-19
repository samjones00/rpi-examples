#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Red: GPIO 0, aka pin 11
const int pinRed = 0;
// Red: GPIO 2, aka pin 13
const int pinGreen = 2;
// Red: GPIO 3, aka pin 15
const int pinBlue = 3; 

void color(int colorRed, int colorGreen, int colorBlue) 
{
	digitalWrite(pinRed, colorRed);
	digitalWrite(pinGreen, colorGreen);
	digitalWrite(pinBlue, colorBlue);
	//Wait for 1 second
	delay(1000);
}

int main()
{
  if (-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  // Set pin mode
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);

  for(;;) 
  {
    // Red
    color(1, 0, 0);
    // Green
    color(0, 1, 0);
    //Blue
    color(0, 0, 1);	
   }
   return 0;
}
