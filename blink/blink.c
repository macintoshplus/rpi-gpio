#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <unistd.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>

int main (void)
{
  int exit = 0;
  printf("Demarrage \n");
  wiringPiSetup();

  pinMode(0, OUTPUT);
  pinMode(2, INPUT);
  pullUpDnControl(2, PUD_UP);

  for(;;)
  {
    digitalWrite(0, HIGH) ; delay(500) ;
    digitalWrite(0, LOW) ; delay(500) ;
    if (digitalRead(2) == 0) {
	printf("Bouton\n");
	exit ++;
	if(exit > 2) {
          printf("Exit !\n");
	  return 0;
	}
    } else {
       exit = 0;
    }
  }
  return 0;
}
