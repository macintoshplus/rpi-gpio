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


