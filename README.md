# rpi-examples
Raspberry Pi examples

## Buzzer

### C

#### Beer

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
