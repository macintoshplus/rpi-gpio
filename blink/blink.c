#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <unistd.h>
#include <string.h>
#include <time.h>

#include <wiringPi.h>
#include <lcd.h>
#include <wiringPiI2C.h>

#define TEMP_CONFIG   0xAC
#define TEMP_READ     0xAA
#define TEMP_DONE     0x80
#define TEMP_ONE_SHOT 0x01
#define TEMP_START_CONVERT 0xEE


int main (void)
{
  int fd;
  int currentD = 500;
  int minD = 100;
  int maxD = 900;
  int sens = 0;
  int exit = 0;
  char strVal[10] ;
  int tempi2c = -1;
  int temperature = -1;
  int temp_addr = 0x48;
  char strTemp[10];

  printf("Demarrage \n");
  wiringPiSetup();
  tempi2c = wiringPiI2CSetup(temp_addr);
  if (tempi2c < 0) {
     printf("Error %d\n", tempi2c);
  }
  int config = wiringPiI2CReadReg8(tempi2c, TEMP_CONFIG);
  printf("config %X\n", config);
  wiringPiI2CWriteReg8(tempi2c, TEMP_CONFIG, config | TEMP_ONE_SHOT);
  wiringPiI2CWriteReg8(tempi2c, TEMP_START_CONVERT, 0x01);
  int value;
  do {
	value = wiringPiI2CReadReg8(tempi2c, TEMP_CONFIG);
  } while ((value & 0x80) == 0);
  temperature = wiringPiI2CReadReg8(tempi2c, TEMP_READ);
  if(temperature > 127)
    value -= 256;
  sprintf(strTemp, "%d\0", temperature);
  printf("temps : %s\n", strTemp);
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
