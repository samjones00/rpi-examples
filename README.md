# rpi-examples
Raspberry Pi examples

# Videos

Buzzer: https://www.youtube.com/watch?v=j8HnKM58QXk
LM75A: https://www.youtube.com/watch?v=pyg27uj0Xns
HTU21D: https://www.youtube.com/watch?v=A_yruJtYUwE

# Notes

If you are interested in running any of the examples for I2C written in C/C++ as a regular user (not root) perform the following steps:
* Remove line "wiringPiSetup();" in "HTU21D_test.c"
* Add your user in "i2c" group

## Buzzer

### C

#### Beep

Simple application to test if a piezo buzzer attached to pin 11 is working.

Install [wiringPi](http://wiringpi.com/download-and-install/) and after that execute the following command to build the application:

```
cd buzzer/c/
gcc beep.c -o beep -lwiringPi -std=c99
```

Execute the following command to run the application:
```
sudo ./beep
```

#### Star Wars

Implementation of the Imperial March from Star Wars.

Install [wiringPi](http://wiringpi.com/download-and-install/) and after that execute the following command to build the application:

```
cd buzzer/c/
gcc starwars.c -o starwars -lwiringPi -std=c99
```

Execute the following command to play the Imperial March:
```
sudo ./starwars
```

#### TSL2561

Install i2c tools:
```
sudo apt-get install i2c-tools

```

Enable i2c on Raspberry Pi with Raspian GNU/Linux distribution:
```
sudo raspi-config
```

Go to Advanced Options > A7 I2C and reboot the board

Verify that TSL2561 is detected on i2c address 39 on bus 1:
```
pi@raspberrypi:~ $ i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- 39 -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --
```

Build and run the source code
```
cd TSL2561/c/
make
./TSL2561_test
```
