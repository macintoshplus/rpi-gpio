dnl $Id$
dnl config.m4 for extension wiringpi

PHP_ARG_ENABLE(wiringpi, whether to enable wiringpi support,
dnl Make sure that the comment is aligned:
[  --enable-wiringpi           Enable wiringpi support])

if test "$PHP_WIRINGPI" != "no"; then
	PHP_NEW_EXTENSION(wiringpi, wiringpi.c, $ext_shared);
fi
