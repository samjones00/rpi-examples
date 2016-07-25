#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <softPwm.h>

const int speedMax = 100;

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

void close()
{
  motor1(LOW, LOW);
  motor2(LOW, LOW);
}

int main()
{
  if (-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!\n");
    return 1;
  }

  signal(SIGINT, close);

  // Set pin mode
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //Software PWM
  if (0 == softPwmCreate(motor1pin1, 0, speedMax))
  {
    printf("softPwmCreate ok for motor 1\n");
  }
  if (0 == softPwmCreate(motor2pin1, 0, speedMax))
  {
    printf("softPwmCreate ok for motor 2\n");
  }
  softPwmWrite(motor1pin1, 30);
  softPwmWrite(motor2pin1, 30);

  close();

  printf("Moving forward\n");

  motor1(HIGH, LOW);
  motor2(HIGH, LOW);

  sleep(3);

  /*printf("Moving backward\n");

  motor1(LOW, HIGH);
  motor2(LOW, HIGH);

  sleep(1);*/

  close();

  return 0;
}
