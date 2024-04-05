#include <lpc214x.h>

#define RS 0 // rs => p0.0
#define RW 1 // rw => p0.1
#define EN 2 // en => p0.2

void pinWrite(unsigned int pin, unsigned int value) {
    if (value)
        IOSET0 |= (1 << pin);
    else
        IOCLR0 |= (1 << pin);
}

void portWrite(unsigned int data) {
    IO0PIN = data;
}

void delay() {
    unsigned int i;
    for (i = 0; i < 10000; i++); // Adjust the delay loop as needed
}

// Function declarations
void LCDcommand(unsigned char mycmd);
void LCDdata(unsigned char mydata);
void initLCD(void);

void main() {
    initLCD(); // Initialize the LCD

    // Display 'A' character
    LCDdata('A');

    while (1); // Infinite loop to keep the program running
}

void LCDcommand(unsigned char mycmd) {
    pinWrite(RS, 0); // RS will be selected for command mode
    pinWrite(RW, 0); // will be selected for write
    portWrite(mycmd);
    pinWrite(EN, 1);
    delay();
    pinWrite(EN, 0);
}

void LCDdata(unsigned char mydata) {
    pinWrite(RS, 1);
    pinWrite(RW, 0);
    portWrite(mydata);
    pinWrite(EN, 1);
    delay();
    pinWrite(EN, 0);
}

void initLCD(void) {
    LCDcommand(0x38); // 16*2 lcd
    LCDcommand(0x0C); // cursor off display on
    LCDcommand(0x06); // entry mode
    LCDcommand(0x01); // clear display
    LCDcommand(0x80); // to start from 1st row
}
