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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_wiringpi.h"
#include "php_wiringpi_int.h"
#include "SAPI.h"
#include "wiringPi.h"

/* {{{ proto int wiringpi_setup()
	Init the wiringpi lib */
static PHP_FUNCTION(wiringpi_setup)
{
	int code;
	code = wiringPiSetup();
	RETURN_LONG(code);
}
/* }}} */

/* {{{ proto int wiring_pi_mode()
	Return the Wiring Pi Mode of library */
static PHP_FUNCTION(wiring_pi_mode)
{
	//wiringPiMode
	RETURN_LONG(-1);

}
/* }}} */


/* {{{ proto bool wiringpi_pin_mode(int $pin, int $mode)
	Set mode for one pin */
static PHP_FUNCTION(wiringpi_pin_mode)
{
	long pin;
	long mode;
	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &pin, &mode)) {
		RETURN_FALSE;
	}
	if (pin < 0) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "pin cannot be negative");
		RETURN_FALSE;
	}

	if (mode != OUTPUT && mode != INPUT) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Mode is not equal to WIRINGPI_INPUT or WIRINGPI_OUTPUT");
		RETURN_FALSE;
	}

	pinMode(pin, mode);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool wiringpi_pull_up_dn_control(int $pin, int $mode)
	Set mode for one pin */
static PHP_FUNCTION(wiringpi_pull_up_dn_control)
{
	long pin;
	long mode;
	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &pin, &mode)) {
		RETURN_FALSE;
	}
	if (pin < 0) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "pin cannot be negative");
		RETURN_FALSE;
	}

	if (mode != PUD_OFF && mode != PUD_DOWN && mode != PUD_UP) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Mode is not equal to WIRINGPI_PUD_OFF or WIRINGPI_PUD_DOWN or WIRINGPI_PUD_UP");
		RETURN_FALSE;
	}

	pullUpDnControl(pin, mode);
	RETURN_TRUE;
}
/* }}} */


/* {{{ proto bool win32_start_service_ctrl_dispatcher(string $name)
   Registers the script with the SCM, so that it can act as the service with the given name */
/*static PHP_FUNCTION(win32_start_service_ctrl_dispatcher)
{
	if (strcmp(sapi_module.name, "cli") != 0) {
		zend_error(E_ERROR, "This function work only when using the CLI SAPI and called into the service code.");
		RETURN_FALSE;
	}

	char *name;
	size_t name_len;

	if (SVCG(svc_thread)) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "service ctrl dispatcher already running");
		RETURN_FALSE;
	}

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len)) {
		RETURN_FALSE;
	}

	SVCG(service_name) = estrdup(name);

	SVCG(te)[0].lpServiceName = SVCG(service_name);
	SVCG(te)[0].lpServiceProc = service_main;
	SVCG(event) = CreateEvent(NULL, TRUE, FALSE, NULL);

	SVCG(svc_thread) = CreateThread(NULL, 0, svc_thread_proc, &SVCG(svc_thread), 0, &SVCG(svc_thread_id));

	if (SVCG(svc_thread) == NULL) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "failed to start dispatcher thread");
		RETURN_FALSE;
	}

	if (WAIT_OBJECT_0 == WaitForSingleObject(SVCG(event), 30000)) {
		if (SVCG(code) == NO_ERROR) {
			RETURN_TRUE;
		} else {
			RETURN_LONG(SVCG(code));
		}
	}

	RETURN_FALSE;
}*/
/* }}} */


/* {{{ arginfo */

ZEND_BEGIN_ARG_INFO_EX(arginfo_wiringpi_setup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wiring_pi_mode, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wiringpi_pin_mode, 0, 0, 2)
	ZEND_ARG_INFO(0, pin)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wiringpi_pull_up_dn_control, 0, 0, 2)
	ZEND_ARG_INFO(0, pin)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

/* }}} */

static zend_function_entry functions[] = {
	//PHP_FE(win32_start_service_ctrl_dispatcher, arginfo_win32_start_service_ctrl_dispatcher)
	PHP_FE(wiringpi_setup, arginfo_wiringpi_setup)
	PHP_FE(wiring_pi_mode, arginfo_wiring_pi_mode)
	PHP_FE(wiringpi_pin_mode, arginfo_wiringpi_pin_mode)
	PHP_FE(wiringpi_pull_up_dn_control, arginfo_wiringpi_pull_up_dn_control)
	PHP_FE_END
};

static void init_globals(zend_wiringpi_globals *g)
{
	memset(g, 0, sizeof(*g));
}

static PHP_MINIT_FUNCTION(wiringpi)
{

	ZEND_INIT_MODULE_GLOBALS(wiringpi, init_globals, NULL);
	// wiringPi modes

	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_PINS", WPI_MODE_PINS, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_GPIO", WPI_MODE_GPIO, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_GPIO_SYS", WPI_MODE_GPIO_SYS, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_PHYS", WPI_MODE_PHYS, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_PIFACE", WPI_MODE_PIFACE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_WPI_MODE_UNINITIALISED", WPI_MODE_UNINITIALISED, CONST_CS | CONST_PERSISTENT);

// Pin modes

	REGISTER_LONG_CONSTANT("WIRINGPI_INPUT", INPUT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_OUTPUT", OUTPUT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PWM_OUTPUT", PWM_OUTPUT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_GPIO_CLOCK", GPIO_CLOCK, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_SOFT_PWM_OUTPUT", SOFT_PWM_OUTPUT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_SOFT_TONE_OUTPUT", SOFT_TONE_OUTPUT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PWM_TONE_OUTPUT", PWM_TONE_OUTPUT, CONST_CS | CONST_PERSISTENT);

	/*  Pin State */
	REGISTER_LONG_CONSTANT("WIRINGPI_LOW", LOW, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_HIGH", HIGH, CONST_CS | CONST_PERSISTENT);


// Pull up/down/none

	REGISTER_LONG_CONSTANT("WIRINGPI_PUD_OFF", PUD_OFF, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PUD_DOWN", PUD_DOWN, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PUD_UP", PUD_UP, CONST_CS|CONST_PERSISTENT);

// PWM

	REGISTER_LONG_CONSTANT("WIRINGPI_PWM_MODE_MS", PWM_MODE_MS, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PWM_MODE_BAL", PWM_MODE_BAL, CONST_CS|CONST_PERSISTENT);

// Interrupt levels

	REGISTER_LONG_CONSTANT("WIRINGPI_INT_EDGE_SETUP", INT_EDGE_SETUP, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_INT_EDGE_FALLING", INT_EDGE_FALLING, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_INT_EDGE_RISING", INT_EDGE_RISING, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_INT_EDGE_BOTH", INT_EDGE_BOTH, CONST_CS|CONST_PERSISTENT);

// Pi model types and version numbers
//	Intended for the GPIO program Use at your own risk.

	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_A", PI_MODEL_A, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_B", PI_MODEL_B, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_AP", PI_MODEL_AP, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_BP", PI_MODEL_BP, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_2", PI_MODEL_2, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_ALPHA", PI_ALPHA, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_CM", PI_MODEL_CM, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_07", PI_MODEL_07, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_3", PI_MODEL_3, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_ZERO", PI_MODEL_ZERO, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_CM3", PI_MODEL_CM3, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MODEL_ZERO_W", PI_MODEL_ZERO_W, CONST_CS|CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("WIRINGPI_PI_VERSION_1", PI_VERSION_1, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_VERSION_1_1", PI_VERSION_1_1, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_VERSION_1_2", PI_VERSION_1_2, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_VERSION_2", PI_VERSION_2, CONST_CS|CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MAKER_SONY", PI_MAKER_SONY, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MAKER_EGOMAN", PI_MAKER_EGOMAN, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MAKER_EMBEST", PI_MAKER_EMBEST, CONST_CS|CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("WIRINGPI_PI_MAKER_UNKNOWN", PI_MAKER_UNKNOWN, CONST_CS|CONST_PERSISTENT);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(wiringpi)
{
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(wiringpi)
{
	int major;
	int minor;
	char *piVersion;
	wiringPiVersion(&major, &minor);
	php_sprintf(piVersion, "%ld.%ld", major, minor)
	php_info_print_table_start();
	php_info_print_table_row(2, "WiringPi", "enabled");
	php_info_print_table_row(2, "Version", PHP_WIRINGPI_VERSION);
	php_info_print_table_row(2, "libwiringPi version", piVersion);
	php_info_print_table_end();
}

zend_module_entry wiringpi_module_entry = {
	STANDARD_MODULE_HEADER,
	"wiringpi",
	functions,
	PHP_MINIT(wiringpi),
	NULL,
	NULL,
	PHP_RSHUTDOWN(wiringpi),
	PHP_MINFO(wiringpi),
	PHP_WIRINGPI_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_WIRINGPI
ZEND_GET_MODULE(wiringpi)
#endif


