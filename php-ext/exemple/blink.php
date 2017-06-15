<?php
$exit = 0;
printf("Demarrage \n");
wiringPiSetup();

pinMode(0, WIRINGPI_OUTPUT);
pinMode(2, WIRINGPI_INPUT);
pullUpDnControl(2, WIRINGPI_PUD_UP);

while(1)
  {
    digitalWrite(0, WIRINGPI_HIGH) ; usleep(500) ;
    digitalWrite(0, WIRINGPI_LOW) ; usleep(500) ;
    if (digitalRead(2) == 0) {
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
