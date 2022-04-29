
void main()
{
 I2C1_Init(100000);         // frequencia de clock do barramento I2C (CONSULTAR DATASHEET DO CHIP PARA SABER SUA FREQUENCIA MÁXIMA)
                           //esta função só precisa ser inicializada somente 1 unica vez no programa

 I2C1_Start();              // start no barramento i2c
 I2C1_Wr(0xA0);             // endereço da memória no barramento + comando de escrita(0)

 I2C1_Wr(0x88);             // endereço da eerprom onde será salvo o dado
 I2C1_Wr(0xFF);       // grava a variável A no endereço 00 da memória serial
 I2C1_Wr(0xF0);       // grava a variável B no endereço 01 da memória serial
 I2C1_Wr(0xF1);       // grava a variável C no endereço 02 da memória serial
 I2C1_Wr(0xF2);       // grava a variável D no endereço 03 da memória serial
 I2C1_Stop();               // condição de stop na comunicação i2c
}
