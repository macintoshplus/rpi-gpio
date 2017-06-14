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

#ifndef PHP_WIRINGPI_H
#define PHP_WIRINGPI_H

extern zend_module_entry wiringpi_module_entry;
#define phpext_wiringpi_ptr	&wiringpi_module_entry

#define PHP_WIRINGPI_VERSION "0.1.0"

#ifdef PHP_WIN32
# error This extension is for linux only
#endif

#if PHP_MAJOR_VERSION < 7
# error This extension is for PHP 7+ only
#endif

#endif


