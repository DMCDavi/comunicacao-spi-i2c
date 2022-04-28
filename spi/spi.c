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