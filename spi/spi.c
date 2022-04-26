/*
 * File:   PIC_SPI.c
 * Author: Aswinth
 *
 * Created on 15 May, 2018, 1:46 PM
 */

// CONFIG
#pragma config FOSC = XT   // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits
#pragma config CP = OFF    // Flash Program Memory Code Protection bit

#include <xc.h>

#define _XTAL_FREQ 20000000

void SPI_Initialize_Master()
{
     TRISC5 = 0; //
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 0; // Definir como sa�da para o modo escravo
}

void SPI_Initialize_Slave()
{
     TRISC5 = 0; // O pino SDO deve ser declarado como sa�da
     SSPSTAT = 0b00000000; //pg 74/234
     SSPCON = 0b00100000; //pg 75/234
     TRISC3 = 1; // Definir como entrada para modo mestre
}

void SPI_Write(char incoming)
{
    SSPBUF = incoming; // Grava os dados fornecidos pelo usu�rio no buffer
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
    while ( !SSPSTATbits.BF ); // Segure at� que o bit BF seja definido, para garantir que todos os dados sejam lidos
    return(SSPBUF); // retorna os dados lidos
}

void main()
{
   SPI_Initialize_Master();

   while(1)
   {
       SPI_Write(0X0A);
         __delay_ms(100);
       SPI_Write(0X0F);
         __delay_ms(100);
       SPI_Write(0X15);
         __delay_ms(100);
   }
}