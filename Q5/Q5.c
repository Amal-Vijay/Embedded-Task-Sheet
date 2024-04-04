#include <LPC214X.h>

void delay() {
    unsigned int i = 0;
    while (i < 200000) {
        i++;
    }
}

int main() {
    int n = 0;
    IODIR0 |= ((0x01 << 7) | (0x01 << 10) | (0x01 << 11) | (0x01 << 14) | (0x01 << 15) | (0x01 << 17) | (0x01 << 18) | (0x01 << 20));

    while (1) {
        
        if (n & 0x01) {
            IOSET0 |= (0x01 << 7);
        } else {
            IOCLR0 |= (0x01 << 7);
        }
        if (n & 0x02) {
            IOSET0 |= (0x01 << 10);
        } else {
            IOCLR0 |= (0x01 << 10);
        }
        if (n & 0x04) {
            IOSET0 |= (0x01 << 11);
        } else {
            IOCLR0 |= (0x01 << 11);
        }
        if (n & 0x08) {
            IOSET0 |= (0x01 << 14);
        } 
				else {
            IOCLR0 |= (0x01 << 14);
        }
				if (n & 0x10) {
            IOSET0 |= (0x01 << 15);
        } 
				else {
            IOCLR0 |= (0x01 << 15);
        }
				if (n & 0x20) {
            IOSET0 |= (0x01 << 17);
        } 
				else {
            IOCLR0 |= (0x01 << 17);
        }
				if (n & 0x40) {
            IOSET0 |= (0x01 << 18);
        } 
				else {
            IOCLR0 |= (0x01 << 18);
        }
				if (n & 0x80) {
            IOSET0 |= (0x01 << 20);
        } 
				else {
            IOCLR0 |= (0x01 << 20);
        }

        delay();

        n++;
				
        if (n == 256) {
            n = 0;
        }
    }
}
