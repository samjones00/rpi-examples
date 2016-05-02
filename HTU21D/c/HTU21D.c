#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "wiringPi.h"
#include "wiringPiI2C.h"

#define   ADDR   0x40

// cTemp:
//   Convert sensor reading into temperature.
//   See page 14 of the datasheet

double cTemp (int sensorTemp)
{
  double tSensorTemp = sensorTemp / 65536.0;
  return -46.85 + (175.72 * tSensorTemp);
}

// cHumid:
//   Convert sensor reading into humidity.
//   See page 15 of the datasheet

double cHumid (int sensorHumid)
{
  double tSensorHumid = sensorHumid / 65536.0;
  return -6.0 + (125.0 * tSensorHumid);
}

int main (void)
{
  int fd;
  unsigned int x;
  unsigned char buf [4];
  unsigned int temp, humid;

  wiringPiSetup () ;

  if ((fd = wiringPiI2CSetup (ADDR)) < 0)
  {
    fprintf (stderr, "Unable to open I2C device: %s\n", strerror (errno));
    exit (-1);
  }

  // Temperature
  wiringPiI2CWrite (fd, 0xF3);
  delay (100);
  x = read (fd, buf, 3);

  if (x != 3)
    printf ("%d: %02X %02X %02X\n", x, buf[0], buf[1], buf[2]);

  temp = (buf [0] << 8 | buf [1]) & 0xFFFC;

  printf("%5.2fC\n", cTemp(temp));

  // Humidity

  wiringPiI2CWrite(fd, 0xF5);
  delay(100);
  x = read(fd, buf, 3);

  if (x != 3)
    printf ("%d: %02X %02X %02X\n", x, buf[0], buf[1], buf[2]);

  humid = (buf [0] << 8 | buf [1]) & 0xFFFC;

  printf("%5.2f%%rh\n", cHumid(humid));

  return 0;
}
