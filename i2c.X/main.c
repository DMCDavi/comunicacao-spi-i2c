/*
 * File:   main.c
 * Author: Davi Costa
 *
 * Created on 28 de Abril de 2022, 22:56
 */
#pragma config FOSC = HS // Bits de sele��o do oscilador (oscilador HS)
#pragma config WDTE = OFF // Bit de ativa��o do temporizador de watchdog (WDT desativado)
#pragma config PWRTE = ON // Bit de ativa��o do temporizador de inicializa��o (PWRT ativado)
#pragma config BOREN = ON // Bit de habilita��o de redefini��o de Brown-out (BOR habilitado)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 � digital I / O, HV em MCLR deve ser usado para programa��o)
#pragma config CPD = OFF // Bit de prote��o de c�digo de mem�ria EEPROM de dados (prote��o de c�digo EEPROM de dados desativada)
#pragma config WRT = OFF // Bits de habilita��o de grava��o da mem�ria do programa Flash (prote��o contra grava��o desligada; toda a mem�ria do programa pode ser gravada pelo controle EECON)
#pragma config CP = OFF // Bit de prote��o de c�digo de mem�ria de programa Flash (prote��o de c�digo desativada)
#define _XTAL_FREQ 20000000

#include <xc.h>
#include "i2c.h"

void main(void) {
    I2C_Initialize(100); //Inicializa I2C Master com clock de 100KHz

    while(1)
  {
   I2C_Begin();
   I2C_Write(0xD0);
   I2C_Write(0x88);
   I2C_Write(0xFF);
   I2C_End();
   __delay_ms(100);
  }
    return;
}
