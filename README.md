# rpi-gpio
Use the Raspberry Pi GPIO port with C

# Global considerations

In all example, the library used is [WiringPi](https://projects.drogon.net/raspberry-pi/wiringpi/). This library can work on 3 modes.
By default, the mode is by default.

I used this page for [GPIO pin number](http://deusyss.developpez.com/tutoriels/RaspberryPi/PythonEtLeGpio/#LII-D).

## Blink

Connect one DEL on the pin 11 (GPIO17) with protect resistor.

build the programm

```
$ make
$ chmod +x blink
```

execute 

```
$ sudo ./blink
```

Use Ctrl+C for exit or connect the pin 13 (GPIO27) to ground with an button.


## Lcd

Connect the LCD on the GPIO.

E : pin 40 (GPIO21)

R/S : pin 38 (GPIO20)

D4 : pin 29 (GPIO5)

D5 : pin 31 (GPIO6)

D6 : pin 33 (GPIO13)

D7 : pin 35 (GPIO19)

build the programm

```
$ make
$ chmod +x lcd
```

execute 

```
$ sudo ./lcd
```

Use Ctrl+C for exit or connect the pin 13 (GPIO27) to ground with an button.

## i2c

[source](http://connect.ed-diamond.com/GNU-Linux-Magazine/GLMFHS-075/Communiquer-en-i2c-avec-un-capteur-de-temperature)

I used an DS1631+ (work with DS1321) and use the GPIO default I2C Bus.

SDA : pin 3

SDL : pin 5

build the programm

```
$ make
$ chmod +x i2c
```

execute 

```
$ sudo ./i2c
```

Use Ctrl+C for exit or connect the pin 13 (GPIO27) to ground with an button.

