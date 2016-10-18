ifneq ($V,1)
Q ?= @
endif

DEBUG   = -O3
CC      = gcc
INCLUDE = -I/usr/local/include
CFLAGS  = $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS = -L/usr/local/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm

all:
	$(CC) -o lcd lcd.c  $(LDFLAGS) $(LDLIBS)
