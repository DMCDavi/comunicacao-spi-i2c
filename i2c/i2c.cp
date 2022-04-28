#line 1 "E:/davim/GitHub/comunicacao-spi-i2c/i2c/i2c.c"

int main()
{
 I2C1_Init(100000);
 while(1)
 {
 I2C1_Start();
 I2C1_Wr(0xFF);
 I2C1_Wr(0xD0);
 I2C1_Wr(0x88);
 I2C1_Stop();
 Delay_ms(100);
 }
}
