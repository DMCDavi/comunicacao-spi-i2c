
void main()
{
 I2C1_Init(100000);         // frequencia de clock do barramento I2C (CONSULTAR DATASHEET DO CHIP PARA SABER SUA FREQUENCIA M�XIMA)
                           //esta fun��o s� precisa ser inicializada somente 1 unica vez no programa

 I2C1_Start();              // start no barramento i2c
 I2C1_Wr(0xA0);             // endere�o da mem�ria no barramento + comando de escrita(0)

 I2C1_Wr(0x88);             // endere�o da eerprom onde ser� salvo o dado
 I2C1_Wr(0xFF);       // grava a vari�vel A no endere�o 00 da mem�ria serial
 I2C1_Wr(0xF0);       // grava a vari�vel B no endere�o 01 da mem�ria serial
 I2C1_Wr(0xF1);       // grava a vari�vel C no endere�o 02 da mem�ria serial
 I2C1_Wr(0xF2);       // grava a vari�vel D no endere�o 03 da mem�ria serial
 I2C1_Stop();               // condi��o de stop na comunica��o i2c
}
