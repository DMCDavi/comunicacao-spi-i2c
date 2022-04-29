#define _XTAL_FREQ 20000000

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
void I2C_Initialize(const unsigned long feq_K) //Comece IIC como mestre
{
  TRISC3 = 1;  
  TRISC4 = 1;  //Defina os pinos SDA e SCL como pinos de entrada
  SSPCON  = 0b00101000;    //pg84/234
  SSPCON2 = 0b00000000;    //pg85/234
  SSPADD = (_XTAL_FREQ/(4*feq_K*100))-1; //Configurando a velocidade do relógio pg99 / 234
  SSPSTAT = 0b00000000;    //pg83/234
}

void I2C_Hold()
{
    while (   (SSPCON2 & 0b00011111)  ||  (SSPSTAT & 0b00000100)   ) ; //verifique isso nos registros para ter certeza de que o IIC não está em andamento
}

void I2C_Begin()
{
  I2C_Hold();  //Segure o programa se I2C está ocupado
  SEN = 1;     //Comece IIC pg85/234
}
void I2C_End()
{
  I2C_Hold(); //Segure o programa se I2C está ocupado
  PEN = 1;    //Fim da IIC pg85/234
}


void I2C_Write(unsigned data)
{
  I2C_Hold();      //Segure o programa se I2C está ocupado
  SSPBUF = data;   //pg82/234
}


unsigned short I2C_Read(unsigned short ack)
{
  unsigned short incoming;
  I2C_Hold();
  RCEN = 1;
  I2C_Hold();
  incoming = SSPBUF;      //obtém os dados salvos em SSPBUF
  I2C_Hold();
  ACKDT = (ack)?0:1;    //verifique se o bit de confirmação foi recebido
  ACKEN = 1;            //pg 85/234
  return incoming;
}