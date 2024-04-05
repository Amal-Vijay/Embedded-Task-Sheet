#include<LPC214X.h>
#include "HalfTimer.h"
#include "Half.h"

int main() {
    initUART();

    while (1) {
        
        printUART("Hello, world!\n");
			sendUART('\r');
        delayms(100);
        
        receiveUART();
			printReceivedData();
			delayms(100);
    }

    return 0;
}