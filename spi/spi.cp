#line 1 "E:/davim/GitHub/comunicacao-spi-i2c/spi/spi.c"
#line 1 "e:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdio.h"
#line 1 "e:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdlib.h"







 typedef struct divstruct {
 int quot;
 int rem;
 } div_t;

 typedef struct ldivstruct {
 long quot;
 long rem;
 } ldiv_t;

 typedef struct uldivstruct {
 unsigned long quot;
 unsigned long rem;
 } uldiv_t;

int abs(int a);
float atof(char * s);
int atoi(char * s);
long atol(char * s);
div_t div(int number, int denom);
ldiv_t ldiv(long number, long denom);
uldiv_t uldiv(unsigned long number, unsigned long denom);
long labs(long x);
int max(int a, int b);
int min(int a, int b);
void srand(unsigned x);
int rand();
int xtoi(char * s);
#line 39 "E:/davim/GitHub/comunicacao-spi-i2c/spi/spi.c"
void main()
{
 SPI1_Init();

 while(1)
 {
 SPI1_Write(0X0A);
 Delay_ms(100);
 SPI_Write(0X0F);
 Delay_ms(100);
 SPI_Write(0X15);
 Delay_ms(100);
 }
}
