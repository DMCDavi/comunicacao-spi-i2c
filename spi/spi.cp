#line 1 "E:/davim/GitHub/comunicacao-spi-i2c/spi/spi.c"
void main()
{
 SPI1_Init();
 while(1)
 {
 SPI1_Write(0X0A);
 SPI_Write(0X0F);
 SPI_Write(0X15);
 Delay_ms(1000);
 }
}
