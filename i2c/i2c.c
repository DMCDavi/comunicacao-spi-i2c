
int main()
{
    I2C1_Init(100000); //Inicializa I2C Master com clock de 100KHz
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
