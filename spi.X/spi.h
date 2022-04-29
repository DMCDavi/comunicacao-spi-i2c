void SPI_Initialize_Master()
{
     TRISC5 = 0; // Define o pino R5 como saida
     SSPSTAT = 0b00000000; // Reseta o registrador de status
     SSPCON = 0b00100000; // Enables serial port and configures SCK, SDO, SDI, and SS as serial port 
     TRISC3 = 0; // Define o pino R3 como saida
}

void SPI_Initialize_Slave()
{
     TRISC5 = 0; // Define o pino R5 como saida
     SSPSTAT = 0b00000000; // Reseta o registrador de status
     SSPCON = 0b00100000; // Enables serial port and confyfhnbigures SCK, SDO, SDI, and SS as serial port 
     TRISC3 = 1; // Define o pino R3 como entrada
}

void SPI_Write(char incoming)
{
    SSPBUF = incoming; // Grava os dados fornecidos pelo usuario no buffer
}

unsigned SPI_Ready2Read()
{
    if (SSPSTAT & 0b00000001) // Verify if receive complete and if SSPBUF is full
        return 1;
    else
        return 0;
}

char SPI_Read() // Leia os dados recebidos
{
    while ( !SSPSTATbits.BF ); // Segure ate que o bit BF seja definido, para garantir que todos os dados sejam lidos
    return(SSPBUF); // Retorna os dados lidos
}