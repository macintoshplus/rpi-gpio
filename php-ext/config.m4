dnl $Id$
dnl config.m4 for extension wiringpi

PHP_ARG_ENABLE(wiringpi, whether to enable wiringpi support,
[  --enable-wiringpi         Enable wiringpi support])

if test "$PHP_WIRINGPI" != "no"; then
	for i in /usr /usr/local
	do
        if test -f $i/include/wiringPi.h
        then
            WIRINGPI_DIR=$i
            AC_MSG_RESULT(wiringPi.h found in $WIRINGPI_DIR/include)
        fi
    done
    
    if test -z "$WIRINGPI_DIR"
    then
        AC_MSG_ERROR(Cannot find libwiringPi: please install it)
    fi
    AC_MSG_RESULT([wiringPi found in $WIRINGPI_DIR])
    
    PHP_ADD_INCLUDE($WIRINGPI_DIR/include)
    PHP_ADD_LIBRARY_WITH_PATH(wiringpi, $WIRINGPI_DIR/lib, WIRINGPI_SHARED_LIBADD)
    AC_DEFINE(HAVE_WIRINGPI, 1, [Have wiringPi library])
    
    dnl Pour que le linker lie à la bibliothèque
    LDFLAGS="$LDFLAGS -lwiringPi -L$WIRINGPI_DIR/lib"

	PHP_NEW_EXTENSION(wiringpi, wiringpi.c, $ext_shared);
    PHP_SUBST(WIRINGPI_SHARED_LIBADD)
fi
