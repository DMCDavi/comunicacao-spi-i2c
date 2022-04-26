#line 1 "E:/davim/GitHub/comunicacao-spi-i2c/spi/spi.c"
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = OFF
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF
#line 22 "E:/davim/GitHub/comunicacao-spi-i2c/spi/spi.c"
void SPI_Initialize_Master()
{
 TRISC5 = 0;
 SSPSTAT = 0b00000000;
 SSPCON = 0b00100000;
 TRISC3 = 0;
}

void SPI_Initialize_Slave()
{
 TRISC5 = 0;
 SSPSTAT = 0b00000000;
 SSPCON = 0b00100000;
 TRISC3 = 1;
}

void SPI_Write(char incoming)
{
 SSPBUF = incoming;
}

unsigned SPI_Ready2Read()
{
 if (SSPSTAT & 0b00000001)
 return 1;
 else
 return 0;
}

char SPI_Read()
{
 while ( !SSPSTATbits.BF );
 return(SSPBUF);
}

void main()
{
 SPI_Initialize_Master();

 while(1)
 {
 SPI_Write(0X0A);
 __delay_ms(100);
 SPI_Write(0X0F);
 __delay_ms(100);
 SPI_Write(0X15);
 __delay_ms(100);
 }
}
