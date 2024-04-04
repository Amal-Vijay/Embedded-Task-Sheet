
// bitwise addition
int Add(int num1, int num2) {
    int Rem;
    while (num2 != 0) {
        Rem = num1 & num2;
        num1 = num1 ^ num2;
        num2 = Rem << 1;
    }
    return num1;
}

// bitwise subtraction
int Subtract(int num1, int num2) {
    while (num2 != 0) {
        int borrow = (~num1) & num2;
        num1 = num1 ^ num2;
        num2 = borrow << 1;
    }
    return num1;
}

// bitwise multiplication
int Multiply(int num1, int num2) {
    int result = 0;
    while (num2 != 0) {
        if (num2 & 1) {
            result = Add(result, num1);
        }
        num1 <<= 1;
        num2 >>= 1;
    }
    return result;
}

// bitwise division
int Divide(int num1, int num2) {
    int quotient = 0;
    while (num1 >= num2) {
        num1 = Subtract(num1, num2);
        quotient = Add(quotient, 1);
    }
    return quotient;
}
