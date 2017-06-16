<?php
$exit = 0;
printf("Demarrage \n");

var_dump(wiringpi_already_setup());
wiringpi_setup();
var_dump(wiringpi_already_setup());

wiringpi_pin_mode(0, WIRINGPI_OUTPUT);
wiringpi_pin_mode(2, WIRINGPI_INPUT);
wiringpi_pull_up_dn_control(2, WIRINGPI_PUD_UP);

while(1)
  {
    wiringpi_digital_write(0, WIRINGPI_HIGH) ; usleep(500) ;
    wiringpi_digital_write(0, WIRINGPI_LOW) ; usleep(500) ;
    if (wiringpi_digital_read(2) == 0) {
	printf("Bouton\n");
	$exit ++;
	if($exit > 2) {
          printf("Exit !\n");
	  return 0;
	}
    } else {
       $exit = 0;
    }
  }
  return 0;
