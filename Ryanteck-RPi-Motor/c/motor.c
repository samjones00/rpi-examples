#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>

const int speedMax = 200;

// Motor 1 1st: GPIO 0, aka pin 11
const int motor1pin1 = 0;
// Motor 1 2nd: GPIO 1, aka pin 12
const int motor1pin2 = 1;

// Motor 2 1st: GPIO 3, aka pin 15
const int motor2pin1 = 3;
// Motor 2 2nd: GPIO 4, aka pin 16
const int motor2pin2 = 4;

void motor1(int pin1, int pin2)
{
  digitalWrite(motor1pin1, pin1);
  digitalWrite(motor1pin2, pin2);
}

void motor2(int pin1, int pin2)
{
  digitalWrite(motor2pin1, pin1);
  digitalWrite(motor2pin2, pin2);
}

void brake()
{
  softPwmWrite(motor1pin1, 0);
  softPwmWrite(motor1pin2, 0);
  softPwmWrite(motor2pin1, 0);
  softPwmWrite(motor2pin2, 0);
  motor1(LOW, LOW);
  motor2(LOW, LOW);
}

void enablePWM(pin, speed)
{
  if (0 != softPwmCreate(pin, 0, speed))
  {
    printf("ERROR: Cannot enable software PWM for pin %d", pin);
  }
}

int main()
{
  if (-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  signal(SIGINT, brake);

  // Set pin mode
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //Software PWM
  enablePWM(motor1pin1, speedMax);
  enablePWM(motor1pin2, speedMax);
  enablePWM(motor2pin1, speedMax);
  enablePWM(motor2pin2, speedMax);

  brake();

  printf("Moving forward\n");

  softPwmWrite(motor1pin1, 90);
  softPwmWrite(motor2pin1, 90);

  motor1(HIGH, LOW);
  motor2(HIGH, LOW);

  sleep(3);

  printf("Stop\n");

  brake();
  sleep(5);

  printf("Moving backward\n");

  softPwmWrite(motor1pin2, 70);
  softPwmWrite(motor2pin2, 70);

  motor1(LOW, HIGH);
  motor2(LOW, HIGH);

  sleep(3);

  brake();

  return 0;
}
