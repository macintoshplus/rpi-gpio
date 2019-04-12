This Extension is an wrapper for the [WiringPi](http://wiringpi.com) library written in C.

For use, you can build your PHP version or use the [deb.sury.org](https://deb.sury.org) pre-compiled PHP 7.x.

If you use the sury version, install the `php7.x-dev` package.

This project don't have automated test because, the ARM architecture is not available on travis or another. If you know one service can build and run tests on ARM, please create an issue.

> This extension has been writen for PHP 7.0


# Debug PHP

PHP 7.0 is build with this command

```bash
./configure --prefix=$HOME/bin/php-7.0-debug --enable-debug --enable-maintainer-zts
```

# Ext building

```bash
$HOME/bin/php-7.0-debug/bin/phpize

./configure --enable-wiringpi --with-php-config=$HOME/bin/php-7.0-debug/bin/phpconfig
```


# Running

```bash
$HOME/bin/php-7.0-debug/bin/php -dextension=module/wiringpi.so -m
```

Result:

```
[...]
wiringpi
[...]
```

Display the module infomations:

```bash
$HOME/bin/php-7.0-debug/bin/php -dextension=module/wiringpi.so --ri wiringpi
```

Result:

```
wiringpi

WiringPi => enabled
Version => 0.1.0
libwiringPi version => 2.44
Model => 2
Revision => 1.1
Maker => Sony
```
