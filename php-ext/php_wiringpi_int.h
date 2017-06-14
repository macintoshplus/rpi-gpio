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
  | Author: Jean-Baptiste Nahan <jb@nahan.fr>                            |
  +----------------------------------------------------------------------+
*/

/* $Id: php_wiringpi.h 309260 2017-06-14 07:39:37Z jbnahan $ */

#ifndef PHP_WIRINGPI_INT_H
#define PHP_WIRINGPI_INT_H

#ifdef ZTS
# include "TSRM.h"
# define SVCG(v)	TSRMG(wiringpi_globals_id, zend_wiringpi_globals *, v)
#else
# define SVCG(v)	(wiringpi_globals.v)
#endif

ZEND_BEGIN_MODULE_GLOBALS(wiringpi)
	char *service_name;
ZEND_END_MODULE_GLOBALS(wiringpi)

ZEND_DECLARE_MODULE_GLOBALS(wiringpi);
#endif

