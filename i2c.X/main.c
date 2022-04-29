/*
 * File:   main.c
 * Author: Davi Costa
 *
 * Created on 28 de Abril de 2022, 22:56
 */
#pragma config FOSC = HS // Bits de seleção do oscilador (oscilador HS)
#pragma config WDTE = OFF // Bit de ativação do temporizador de watchdog (WDT desativado)
#pragma config PWRTE = ON // Bit de ativação do temporizador de inicialização (PWRT ativado)
#pragma config BOREN = ON // Bit de habilitação de redefinição de Brown-out (BOR habilitado)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 é digital I / O, HV em MCLR deve ser usado para programação)
#pragma config CPD = OFF // Bit de proteção de código de memória EEPROM de dados (proteção de código EEPROM de dados desativada)
#pragma config WRT = OFF // Bits de habilitação de gravação da memória do programa Flash (proteção contra gravação desligada; toda a memória do programa pode ser gravada pelo controle EECON)
#pragma config CP = OFF // Bit de proteção de código de memória de programa Flash (proteção de código desativada)
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
