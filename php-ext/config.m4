dnl $Id$
dnl config.m4 for extension wiringpi

PHP_ARG_ENABLE(wiringpi, whether to enable wiringpi support,
[  --enable-wiringpi         Enable wiringpi support])

if test "$PHP_WIRINGPI" != "no"; then
	LDFLAGS="$LDFLAGS -lwiringPi"

	PHP_NEW_EXTENSION(wiringpi, wiringpi.c, $ext_shared);
fi
