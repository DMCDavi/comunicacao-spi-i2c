#line 1 "E:/davim/GitHub/comunicacao-spi-i2c/i2c/i2c.c"

void main()
{
 I2C1_Init(100000);


 I2C1_Start();
 I2C1_Wr(0xA0);

 I2C1_Wr(0x88);
 I2C1_Wr(0xFF);
 I2C1_Wr(0xF0);
 I2C1_Wr(0xF1);
 I2C1_Wr(0xF2);
 I2C1_Stop();
}
