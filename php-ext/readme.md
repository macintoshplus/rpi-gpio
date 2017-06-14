# Debug PHP

PHP 7.0 is build with this command

./configure --prefix=$HOME/bin/php-7.0-debug --enable-debug --enable-maintainer-zts

# Ext building

$HOME/bin/php-7.0-debug/bin/phpize

./configure --enable-wiringpi --with-php-config=$HOME/bin/php-7.0-debug/bin/phpconfig

# Execution

$HOME/bin/php-7.0-debug/bin/php -dextension=module/wiringpi.so -m