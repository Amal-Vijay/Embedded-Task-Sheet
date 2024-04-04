#include <LPC214X.h>
int main() {
    IODIR0 |= (0x01 << 7);        
	IODIR1 &= ~(0x01<<16);
	IODIR0 |= (0x01 << 10);        
	IODIR1 &= ~(0x01<<17);
	
	while(1){
	if ((IOPIN1 & 0x01 << 16)==0) {
            IOSET0 |= (0x01 << 7);
        } else {
            IOCLR0 |= (0x01 << 7);
	 }
		if ((IOPIN1 & 0x01 << 17)==0) {
            IOSET0 |= (0x01 << 10);
        } else {
            IOCLR0 |= (0x01 << 10);
	 }
        }
			}
