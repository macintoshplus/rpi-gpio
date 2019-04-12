/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Jean-Baptiste Nahan <jbnahan@php.net>                        |
  +----------------------------------------------------------------------+
*/

/* $Id: php_wiringpi.h 309260 2017-06-14 07:39:37Z jbnahan $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_wiringpi.h"
#include "php_wiringpi_int.h"
#include "wiringPi.h"

/* {{{ proto int wiringpi_setup()
	Setup the wiringpi lib in default mode */
static PHP_FUNCTION(wiringpi_setup)
{
	if (SVCG(is_setup) == 1) {
		RETURN_FALSE;
	}
	int code;
	code = wiringPiSetup();
	if (code == 0) {
		SVCG(is_setup) = 1;
	}
	RETURN_LONG(code);
}
/* }}} */

/* {{{ proto bool wiringpi_already_setup()
	Return true if the setup is already called */
static PHP_FUNCTION(wiringpi_already_setup)
{
	if (SVCG(is_setup) == 1) {
		RETURN_TRUE;
	}
	RETURN_FALSE;
}
/* }}} */


ZEND_BEGIN_ARG_INFO_EX(arginfo_wiringpi_setup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wiringpi_already_setup, 0, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry wiring_setup_functions[] = {
	PHP_FE(wiringpi_setup, arginfo_wiringpi_setup)
	PHP_FE(wiringpi_already_setup, arginfo_wiringpi_already_setup)
	PHP_FE_END
};

PHP_MINIT_FUNCTION(wiring_setup) {
    return SUCCESS;
}
