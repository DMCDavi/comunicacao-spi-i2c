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
#include "spi.h"

#define _XTAL_FREQ 20000000

void main()
{
   SPI_Initialize_Master();
   
   while(1)
   {   
       SPI_Write(0X0A);
       SPI_Write(0X0F);
       SPI_Write(0X15);
       SPI_Write(0X54);
       SPI_Write(0X78);
       SPI_Write(0XF9);
       SPI_Write(0XAA);
       SPI_Write(0XE4);
         __delay_ms(100);
   }
}