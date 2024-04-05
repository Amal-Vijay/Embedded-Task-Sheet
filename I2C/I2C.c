#include <lpc214x.h>

void Uart0Init (void){
PINSEL0 = 0x00000005;
U0LCR = 0x83;
U0DLL = 97;
U0LCR = 0x03;
}
void Uart0PutCh (unsigned char ch) // Write character to Serial Port
{
U0THR = ch; while (!(U0LSR & 0x20));
}
unsigned char Uart0GetCh (void) // Read character from Serial Port
{
while (!(U0LSR & 0x01));
return (U0RBR);
}

int main()
{
unsigned char a;
Uart0Init();
while(1){
a=Uart0GetCh();
Uart0PutCh(a);
}
}