#include <LPC214X.H>
#include <stdio.h>
#include <string.h>

#define LCD_DATA1 24
#define RS1 23
#define RW1 22
#define EN1 21

/*----- GPS Functions (UART1) -----*/
void init_uart1(void)  ;
void init_uart1int(void);
void sendserial1(unsigned char serdata);
void UART1_ISR(void)__irq;

/*----- LCD Functions -----*/
void display1(unsigned char *);
void command1(unsigned char );
void lcd_data_char1(unsigned char);
void delay (unsigned int );
void lcd_init(void);

char namegps[7], name1gps[7] = "GPRMC,",gpsdat[63];
char msggps , checkgps;
int h;
unsigned char f;

int main(void)
{
  
  IODIR1=0xfff00000;
  IODIR0=0x00ffBfff;
  VPBDIV=0x02;

  lcd_init();
  init_uart1int();

  command1(0x80);
  display1("LON:                ");
  command1(0xc0);
  display1("LAT:                ");
  
  while(1);

}


void UART1_ISR(void)__irq
{
  //U1IER=0X00;
  
  if((U1LSR & 1)!=0) {    // check for receive interrupt
    msggps=U1RBR;
    
    if(msggps=='$') {
      U1IER=0X00;

      for(f=0;f<=5;f++) {
        while(!(U1LSR & 0x01));
        namegps[f]=U1RBR;
      }
        checkgps=strcmp(namegps,name1gps);
         if(checkgps==0) {
           for(f=0;f<=62;f++) {
            while(!(U1LSR & 0x01)); 
            gpsdat[f]=U1RBR;      
        }

        command1(0x84);
        for(h=12;h<14;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        lcd_data_char1('.');
        for(h=14;h<16;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        for(h=17;h<19;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        lcd_data_char1(223);
        lcd_data_char1(' ');
        lcd_data_char1('N');

        command1(0xc4);
        for(h=26;h<28;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        lcd_data_char1('.');
        for(h=28;h<30;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        for(h=31;h<33;h++) {
          lcd_data_char1(gpsdat[h]);
        }
        lcd_data_char1(223);
        lcd_data_char1(' ');
        lcd_data_char1('E');
      }
      U1IER=0x01;
    }  
  }
    
  VICVectAddr=0x00000000;
}

void init_uart1(void)        // UART Initializing Function
{
  /* initializing UART1*/
  PINSEL0=PINSEL0 | 0x050000;    // Pin P0.8 and P0.9 for TxD1 and RxD1
  U1LCR= 0x83;        // 8 bits, no Parity, 1 Stop bit     
  U1DLL= 0xC2;        // DLAB = 1, 9600 Baud Rate @ 30MHz VPB Clock
  U1DLM = 0x00;               
  U1LCR=0x03;        // DLAB = 0
  
  return;
}

void init_uart1int(void)      // UART Initializing Function
{
  /* Initializing UART1 interrupt*/
  VICVectCntl6=0x027;      //  Set priority slot as 6 for UART1
  VICVectAddr6= (unsigned) UART1_ISR ;  // Set Address for UART1 ISR
  VICIntEnable= 0x0080;      // Enable UART1 Interrupt

  /* initializing UART1*/
  PINSEL0=PINSEL0 | 0x050000;    // Pin P0.8 and P0.9 for TxD1 and RxD1
  U1LCR= 0x83;        // 8 bits, no Parity, 1 Stop bit     
  U1DLL= 0xC2;        // DLAB = 1, 9600 Baud Rate @ 30MHz VPB Clock
  U1DLM = 0x00;               
  U1LCR=0x03;        // DLAB = 0
  U1IER=0x01;         // Enable RBR interrupt
  return;
}

void sendserial1(unsigned char serdata)
{
  U1THR = serdata;
  while(!(U1LSR & 0x20));
}

void display1(unsigned char *str)
{
  for(;*str!=NULL;str++) {
    lcd_data_char1(*str);
    delay(1);
  }
}

void command1(unsigned char command)
{
  IOCLR1  =  0xffe00000;          
  IOSET1  =  command<<LCD_DATA1;  
  delay(1);
  IOSET1  =  1<<EN1;
  delay(2);
  IOCLR1  =  1<<EN1;
}

void lcd_data_char1(unsigned char data)
{
  IOCLR1  =  0xffe00000;//<<LCD_DATA;
  IOSET1  =  1<<RS1;
  IOSET1  =  data<<LCD_DATA1;
  delay(1);
  IOSET1  =  1<<EN1;
  delay(5);
  IOCLR1  =  1<<EN1;
}

void delay (unsigned int t)
{
  unsigned int j=0;
  while(t-->0) {
    while(j++<10000);
    j=0;
  }
}

void lcd_init()
{
  unsigned char comm[]={0x38,0x0C,0x01,0x06,0x80};
  unsigned int i;
  IODIR1=0xfff00000;
  IODIR0=0x0000FF00;
  delay(1);

  for(i=0;i<=4;i++) {
    command1(comm[i]);
    delay(1);
  }
}