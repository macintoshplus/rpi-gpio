#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <unistd.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>
#include <lcd.h>
#include <wiringPiI2C.h>


int main (void)
{
  int fd;
  int currentD = 500;
  int minD = 100;
  int maxD = 900;
  int sens = 0;
  int exit = 0;
  char strVal[10] ;

  printf("Demarrage \n");
  wiringPiSetup();
  fd = lcdInit(4, 20, 4, 28, 29, 21, 22, 23, 24, 0, 0, 0, 0);
  delay(1);
  lcdClear(fd);
  delay(1);
  lcdHome(fd);
  delay(1);
  lcdPosition(fd, 0, 0);
  lcdPuts(fd, "LED");
  lcdPosition(fd, 6, 0);
  lcdPuts(fd, "Bouton");
  lcdPosition(fd, 0, 1);
  lcdPuts(fd, "Delay");

 // lcdPosition(fd, 0, 0);
 // lcdPuts(fd, "Salut Jean-Baptiste!");

  lcdPosition(fd, 0, 3);
  lcdPuts(fd, "Temp");
  lcdPosition(fd, 6, 3);
  lcdPuts(fd, strTemp);

  pinMode(0, OUTPUT);
  pinMode(2, INPUT);
  pullUpDnControl(2, PUD_UP);

  for(;;)
  {
    lcdPosition(fd, 4, 0);
    lcdPuts(fd, "1");
    digitalWrite(0, HIGH) ; delay(currentD) ;
    lcdPosition(fd, 4, 0);
    lcdPuts(fd, "0");
    digitalWrite(0, LOW) ; delay(currentD) ;
    if (digitalRead(2) == 0) {
        lcdPosition(fd, 13, 0);
	lcdPuts(fd, "1");
	printf("Bouton\n");
        if( sens == 0) {
          currentD -= 100;
          if(currentD == minD) {
           sens = 1;
          }
        } else {
          currentD += 100;
          if(currentD == maxD) {
           sens = 0;
          }
        }
	exit ++;
	if(exit > 2) {
          lcdClear(fd);
          lcdPosition(fd, 0, 0);
          lcdPuts(fd, "Au revoir !!!");
          delay(5000);
          printf("Exit !\n");
	  lcdClear(fd);
	  return 0;
	}
    } else {
       exit = 0;
       lcdPosition(fd, 13, 0);
       lcdPuts(fd, "0");
    }
    lcdPosition(fd, 6, 1);
    sprintf(strVal, "%d\0", currentD);
    //printf("%s\n", strVal);
    lcdPuts(fd, strVal);
  }
  return 0;
}
