
void initUART(void);
void sendUART(unsigned char mydata);
void printUART(unsigned char mydata[]);
void receiveUART(void);
void printReceivedData(void);

unsigned char receivedData[50];
int dataIndex = 0;

void initUART(void) {
    // Initialize PLL and pin select
    initPLL();
    PINSEL0 = 0x05; // Configure UART0 TXD0 pin (P0.0) as TXD0

    // Configure UART0 for half-duplex
    U0LCR = 0x83; // DLAB=1, 8-bit UART
    U0DLL = 0x87; // 0x0187 for 9600 baud rate
    U0DLM = 0x01;
    U0LCR = 0x03; // DLAB=0, 8-bit UART
}

void sendUART(unsigned char mydata) {
    // Set direction for transmission (using P0.1 as direction control)
    IO0DIR |= (1 << 1); // Set P0.1 as output (for transmission)
    IO0SET = (1 << 1); // Set P0.1 high for transmission

    // Transmit data
    U0THR = mydata; 

    while (!(U0LSR & (0x01 << 5))); // THREmpty

    // Set direction for reception after transmission
    IO0CLR = (1 << 1); // Set P0.1 low for reception
}

void receiveUART(void) {
    // Check if data is available to read
    while (U0LSR & (1 << 0)) {
        char receivedChar = U0RBR;

        
        if (receivedChar == '\n') {
            receivedData[dataIndex] = '\0'; 
            dataIndex = 0; 
            return;
        }

        // Store received data in buffer
        receivedData[dataIndex++] = receivedChar;
    }
}

void printReceivedData(void) {
    printUART("\nReceived: \n"); 
    printUART(receivedData);
    printUART("\n"); 
}

void printUART(unsigned char mydata[]) {
    int i = 0;
    while (mydata[i] != '\0') {
        sendUART(mydata[i]);
        i++;
    }
}