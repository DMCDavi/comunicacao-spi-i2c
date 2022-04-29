void SPI_Initialize_Master()
{
     TRISC5 = 0; //
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 0; // Definir como saída para o modo escravo
}

void SPI_Initialize_Slave()
{
     TRISC5 = 0; // O pino SDO deve ser declarado como saída
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 1; // Definir como entrada para modo mestre
}

void SPI_Write(char incoming)
{
    SSPBUF = incoming; // Grava os dados fornecidos pelo usuário no buffer
}

unsigned SPI_Ready2Read()
{
    if (SSPSTAT & 0b00000001)
        return 1;
    else
        return 0;
}

char SPI_Read() // Leia os dados recebidos
{
    while ( !SSPSTATbits.BF ); // Segure até que o bit BF seja definido, para garantir que todos os dados sejam lidos
    return(SSPBUF); // retorna os dados lidos
}