void initPLL(void);
void delayms(unsigned int milliseconds); // Added semicolon
void delayus(unsigned int microseconds); // Added semicolon

void initPLL(void)
{
    PLL0CON = 0x01 ;
    PLL0CFG = 0x24 ;
    // Enable PLL
    // Set Up PLL for CClk = 60MHz
    PLL0FEED = 0xAA; PLL0FEED = 0x55; //
    // Apply Feed Sequence
    while( (PLL0STAT & (0x01 << 10)) == 0 ); // Added parentheses

    PLL0CON = 0x03;
    // Enable & Connect PLL
    PLL0FEED = 0xAA; PLL0FEED = 0x55; //
    // Apply Feed Sequence

    VPBDIV = 0x01; // Pclk is same as Cclk (60 MHz)
}

void delayms(unsigned int milliseconds)
{
    // Using Timer0
    T0CTCR = 0x00 ; // configure T0 as Timer
    T0PR = 60000-1 ;
    T0TC = 0; // Reset Timer
    T0TCR = 0x01; // Enable timer
    while(T0TC < milliseconds);
    // Wait until timer reaches the desired delay
    T0TCR = 0x00; // Disable timer
}

void delayus(unsigned int microseconds)
{
    // Using Timer0
    T0CTCR = 0x00 ; // configure T0 as Timer
    T0PR = 60-1 ;
    T0TC = 0; // Reset Timer
    T0TCR = 0x01; // Enable timer
    while(T0TC < microseconds);
    // Wait until timer reaches the desired delay
    T0TCR = 0x00; // Disable timer
}