#include<lpc214X.h>

void delay() {
    unsigned int i = 0;
    while (i < 200000) {
        i++;
    }
}

int main() {
    int n = 0;
    IODIR0 |= ((0x01 << 9) | (0x01 << 10) | (0x01 << 11) | (0x01 << 12) | (0x01 << 13)  | (0x01 << 14) | (0x01 << 15));
 while (1) {
            IOCLR0 |= (0x01 << 9);
	          IOCLR0 |= (0x01 << 12);
	          IOCLR0 |= (0x01 << 13);
	          IOCLR0 |= (0x01 << 14);
            IOSET0 |= (0x01 << 10);
					  IOSET0 |= (0x01 << 11);        //1
        delay();
        
					  IOCLR0 |= (0x01 << 11);
            IOSET0 |= (0x01 << 9);         //2
					  IOSET0 |= (0x01 << 12);
					  IOSET0 |= (0x01 << 13);
					  IOSET0 |= (0x01 << 15);
        delay();
       
            IOSET0 |= (0x01 << 11);         //3
					  IOCLR0 |= (0x01 << 13);
	      delay();
        
					  IOCLR0 |= (0x01 << 9);          //4
            IOCLR0 |= (0x01 << 12);
				    IOCLR0 |= (0x01 << 13);
				    IOSET0 |= (0x01 << 14);
         delay();
				 
				    IOSET0 |= (0x01 << 9);
						IOSET0 |= (0x01 << 12);         //5
						IOCLR0 |= (0x01 << 10);
				 delay();
				
            IOSET0 |= (0x01 << 13);         //6
         delay();
				 
				    IOSET0 |= (0x01 << 10);
						IOCLR0 |= (0x01 << 14);
						IOCLR0 |= (0x01 << 15);
						IOCLR0 |= (0x01 << 12);
						IOCLR0 |= (0x01 << 13);          //7
         delay();
            
						IOSET0 |= (0x01 << 15);
						IOSET0 |= (0x01 << 14);
						IOSET0 |= (0x01 << 13);          //8
						IOSET0 |= (0x01 << 12);
				 delay();
				 
				    IOCLR0 |= (0x01 << 13);          //9
						IOCLR0 |= (0x01 << 12);
				 delay();
				 
				    IOCLR0 |= (0x01 << 15);
						IOSET0 |= (0x01 << 13);         //0
						IOSET0 |= (0x01 << 12);
				 delay();		
        }
			}