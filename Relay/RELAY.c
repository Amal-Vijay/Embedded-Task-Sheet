#include<lpc214x.h>
#define bit(x) (1<<x)
#define delay for(i=0;i<60000;i++)

unsigned int i;

int main()
{
    IO0DIR=0xff;
    IO0PIN=0;

    while(1) {
        IO0SET=bit(0);              //Relay ON
        delay;
        IO0CLR=bit(0);              //Relay OFF
        delay;
    }
}
