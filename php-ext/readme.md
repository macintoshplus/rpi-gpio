This Extension is an wrapper for the WiringPi library written in C.

For use, you can build your PHP version or use the [deb.sury.org](https://deb.sury.org) pre-compiled PHP 7.0.

If you use the sury version, install the `php7.0-dev` package.

This project don't have automated test because, the ARM architecture is not available on travis or another. If you know one service can build and run tests on ARM, please create an issue.

# Debug PHP

PHP 7.0 is build with this command

./configure --prefix=$HOME/bin/php-7.0-debug --enable-debug --enable-maintainer-zts

# Ext building

$HOME/bin/php-7.0-debug/bin/phpize

./configure --enable-wiringpi --with-php-config=$HOME/bin/php-7.0-debug/bin/phpconfig

# Execution

$HOME/bin/php-7.0-debug/bin/php -dextension=module/wiringpi.so -m

Result:

```
[...]
wiringpi
[...]
```

$HOME/bin/php-7.0-debug/bin/php -dextension=module/wiringpi.so --ri wiringpi

```
wiringpi

WiringPi => enabled
Version => 0.1.0
libwiringPi version => 2.44
Model => 2
Revision => 1.1
Maker => Sony
```