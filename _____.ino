#include "LedControl.h"
LedControl lc=LedControl(12,11,10,1);

byte great[8]={B10000001,
               B01000010,
               B00100100,
               B00011000,
               B00011000,
               B00100100,
               B01000010,
               B10000001};
byte good[8] = {};

byte soSO[8] = {};

byte bad [8] = {};

unsigned long delaytime=100;
void writeOnmatrix(byte emoticonArray[]);

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
   lc.shutdown(0,false);
/* Set the brightness toa medium values */
lc.setIntensity (0,8);
/*and clear the display */
lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
writeOnMatrix(great);
}

void writeOnMatrix(byte emoticonArray[])
{
  for(int i=0;i<8;i++)
    lc.setRow(0,i,emoticonArray[i]);
  delay(delaytime);
}

