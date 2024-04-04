#include<LPC214x.h>
#include"GPIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "TIMER.h"
int main()
{
initPLL();
while(1)
{
pinWrite(16,1);
delayms(1000);
pinWrite(16,0);
delayms(1000);
}
}
// (1 sec Delay)
