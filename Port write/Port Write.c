#include<LPC214X.h>       
void Portwrite(int blockNo,int blockValue);      
	int main(){
Portwrite(0,0xFF);
}
	void Portwrite(int blockNo,int blockValue){
		
	if(blockNo<10){
		
	IODIR0 |= blockValue << (blockNo*8);
		
		if(blockValue){
		IOSET0 |= blockValue << (blockNo*8);
		}
		else{
		IOCLR0 |=0xFF << (blockNo*8);
		}
	}
	else{
	blockNo -=10;
		IODIR1 |=0x01 << (blockNo*8);
		if(blockValue){
		IOSET1 |= blockValue << (blockNo*8);
		}
		else{
		IOCLR1 |=0xFF << (blockNo);
		}
	}
}