#include<LPC214x.h>
#include"gpio.h"
#include "lcd.h"
int main()
{
int i;
unsigned char L1[15]="Hello World!";
unsigned char L2[15]="Technologics";
initLCD();
for(i=0;i<15;i++)
LCDdata(L1[i]);
LCDcommand(0xC0);
for(i=0;i<15;i++)
LCDdata(L2[i]);
while(1);
}
