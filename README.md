# rpi-examples
Raspberry Pi examples

## Buzzer

Video: https://www.youtube.com/watch?v=j8HnKM58QXk

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
