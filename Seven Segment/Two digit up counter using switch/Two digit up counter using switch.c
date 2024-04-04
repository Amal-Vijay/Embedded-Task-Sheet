#include<lpc214X.h>

void delay() {
    unsigned int i = 0;
    while (i < 70000) {
        i++;
    }
}

int main() {
    int n = 1;
    IODIR0 |= ((0x01 << 0) | (0x01 << 1) | (0x01 << 2) | (0x01 << 3) | (0x01 << 4)  | (0x01 << 5) | (0x01 << 6));
    IODIR0 |= ((0x01 << 9) | (0x01 << 10) | (0x01 << 11) | (0x01 << 12) | (0x01 << 13)  | (0x01 << 14) | (0x01 << 15));
	if ((IOPIN1 & 0x01 << 16)==0) {
		while(1){
	while (1) {
		        IOSET0 |= (0x01 << 9);
		        IOSET0 |= (0x01 << 14);          //0
						IOSET0 |= (0x01 << 13);
		        IOSET0 |= (0x01 << 10);
						IOSET0 |= (0x01 << 11);
		        IOSET0 |= (0x01 << 12);
		        IOCLR0 |= (0x01 << 15);
				  delay();
		
		        IOCLR0 |= (0x01 << 9);
		        IOCLR0 |= (0x01 << 12);
		        IOCLR0 |= (0x01 << 13);
		        IOCLR0 |= (0x01 << 14);        //1
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
						IOSET0 |= (0x01 << 12);
				 delay();
				 
				 if((IOSET0 |= (0x01 << 9)|(0x01 << 10)|(0x01 << 11)|(0x01 << 12)|(0x01 << 13)|(0x01 << 14)==1)){
				
    if(n==0){
		        IOSET0 |= (0x01 << 0);
		        IOSET0 |= (0x01 << 1);
		        IOSET0 |= (0x01 << 2);
		        IOSET0 |= (0x01 << 3);        //0
			      IOSET0 |= (0x01 << 4);
			      IOSET0 |= (0x01 << 5);
			      IOCLR0 |= (0x01 << 6);
		}
		
		if(n==1){
		        IOCLR0 |= (0x01 << 0);
		        IOCLR0 |= (0x01 << 3);
		        IOCLR0 |= (0x01 << 4);
		        IOCLR0 |= (0x01 << 5);        //1
			      IOSET0 |= (0x01 << 2);
			      IOSET0 |= (0x01 << 1);
		}
     if(n==2){   
					  IOCLR0 |= (0x01 << 2);
            IOSET0 |= (0x01 << 0);         //2
					  IOSET0 |= (0x01 << 3);
			      IOSET0 |= (0x01 << 1);
					  IOSET0 |= (0x01 << 4);
			      IOSET0 |= (0x01 << 6);
		 }
       if(n==3){ 
            IOSET0 |= (0x01 << 2);         //3
					  IOCLR0 |= (0x01 << 4);
				    
			 }
       if(n==4){  
					  IOCLR0 |= (0x01 << 0);          //4
            IOCLR0 |= (0x01 << 3);
				    IOCLR0 |= (0x01 << 4);
				    IOSET0 |= (0x01 << 5);
			 }
			if(n==5){ 	 
				    IOSET0 |= (0x01 << 0);
						IOSET0 |= (0x01 << 3);         //5
						IOCLR0 |= (0x01 << 1);
			}
			if(n==6){ 	
            IOSET0 |= (0x01 << 4);         //6
			}
			if(n==7){ 	 
				    IOSET0 |= (0x01 << 1);
						IOCLR0 |= (0x01 << 5);
						IOCLR0 |= (0x01 << 6);
						IOCLR0 |= (0x01 << 3);
						IOCLR0 |= (0x01 << 4);          //7
			}
      if(n==8){       
						IOSET0 |= (0x01 << 6);
						IOSET0 |= (0x01 << 5);
						IOSET0 |= (0x01 << 4);          //8
						IOSET0 |= (0x01 << 3);
			}
			if(n==9){ 	 
				    IOCLR0 |= (0x01 << 4);          //9
						IOSET0 |= (0x01 << 3);
			}
        }
				 n++;
				if(n==10){
	n = 0 ;
	}
			}
	
		}
	}
}