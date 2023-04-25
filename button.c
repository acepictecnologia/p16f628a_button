/*
 * File:   button.c
 * Author: SANDRINI
 *
 * Created on 13 de Abril de 2023, 08:51
 */


// PIC16F628A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define _XTAL_FREQ 8000000

void main(void) {
    
    TRISAbits.TRISA4 = 1;       //Direciona o pino 4 da porta A como entrada
    TRISBbits.TRISB0 = 1;       //Direciona o pino 0 da porta B como entrada
    TRISBbits.TRISB6 = 0;       //Direciona o pino 6 da porta B como saída
    TRISBbits.TRISB7 = 0;       //Direciona o pino 7 da porta B como saída
    
    PORTBbits.RB6 = 0;          //Atribui nível lógico 0 (0V) ao pino 6 da porta B
    PORTBbits.RB7 = 0;          //Atribui nível lógico 0 (0V) ao pino 7 da porta B
    
    while(1)
    {
        if (PORTAbits.RA4 == 1)
        {
            PORTBbits.RB6 = 1;
            __delay_ms(3000);
        }     
        
        if (PORTBbits.RB0 == 1)
        {
            PORTBbits.RB7 = 1;
            __delay_ms(3000);
        }       
        
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 0;
    }
        
}
