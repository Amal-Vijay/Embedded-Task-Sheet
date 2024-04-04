#include <LPC214X.h>
int main() {
	unsigned int n=0;
    IODIR0 |= (0x01 << 7);        
	IODIR1 &= ~(0x01<<16);
	
	while(1){
	if((IOPIN1 &= (1 << 16))==0){
	if(n^=1){
		if(n){
	IOSET0 |= (0x01 << 7);
	}else{
	IOCLR0 |= (0x01 << 7);	
        }
			}
		}
	}
}