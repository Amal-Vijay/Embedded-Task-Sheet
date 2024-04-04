#include <LPC214X.h>

void delay() {
    unsigned int i = 0;
    while (i < 200000) {
        i++;
    }
}

int main() {
    int n = 0;
    IODIR0 |= ((0x01 << 7) | (0x01 << 10) | (0x01 << 11) | (0x01 << 14));

    while (1) {
        
        if (n & 0x08) {
            IOSET0 |= (0x01 << 7);
        } else {
            IOCLR0 |= (0x01 << 7);
        }
        if (n & 0x04) {
            IOSET0 |= (0x01 << 10);
        } else {
            IOCLR0 |= (0x01 << 10);
        }
        if (n & 0x02) {
            IOSET0 |= (0x01 << 11);
        } else {
            IOCLR0 |= (0x01 << 11);
        }
        if (n & 0x01) {
            IOSET0 |= (0x01 << 14);
        } 
				else {
            IOCLR0 |= (0x01 << 14);
        }

        delay();
  
        n*=2;
				if(n==0){
				n++;
				}
        if (n == 16) {
            n = 0;
        }
    }
}
