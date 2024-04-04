#include <LPC214x.h>
#include "GPIO.h"
#include "LCD.h"
#include "keypad.h"
#include "Operation.h"

int main() {
    unsigned char mykey;
    char input[10]; // Array to store user input
    int num1 = 0, num2 = 0;
    char operation = ' ';

    initLCD();

    while (1) {
        mykey = getKeypad();

        if (mykey != 'x') {
            if (mykey == '=') {
                if (num2 != ' ' && num2 != 0) {
                    int result;

                    switch (operation) {
                        case '+':
                            result = Add(num1, num2);
                            break;
                        case '-':
                            result = Subtract(num1, num2);
                            break;
                        case '*':
                            result = Multiply(num1, num2);
                            break;
                        case '/':
                            result = Divide(num1, num2);
                            break;
                        default:
                            result = 0;             // invalid operation
                            break;
                    }

                    sprintf(input, "=%d", result); // Convert result to string
										LCDprint(input);
                    delay();
                    num1 = result;
                    num2 = 0;
                    operation = ' ';
										delay();
									
                }
            } else if (mykey >= '0' && mykey <= '9') {
                if (operation == ' ') {
                    num1 = atoi(&mykey);
                } else {
                     num2 = atoi(&mykey);
                }

                LCDdata(mykey);
                delay();
            } else if (mykey == '+' || mykey == '-' || mykey == '*' || mykey == '/') {
                operation = mykey;
                LCDdata(mykey);
                delay();
            }
        }
    }

    return 0;
}
