/* 
 * File:   device_config.c
 * Author: Mohamed Ahmed
 * Created on July, 2023
 */

#include "device_config.h"

// PIC18F4620 Configuration Bit Settings

// Oscillator Selection bits (HS oscillator)
#pragma config OSC = HS

// Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config FCMEN = OFF

// Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)
#pragma config IESO = OFF

// Power-up Timer Enable bit (PWRT disabled)
#pragma config PWRT = OFF

// Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BOREN = OFF

// Brown Out Reset Voltage bits ()
#pragma config BORV = 1

// Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDT = OFF

// Watchdog Timer Postscale Select bits (1:32768)
#pragma config WDTPS = 512

// CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config CCP2MX = PORTC

// PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config PBADEN = OFF

// Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config LPT1OSC = OFF

// MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config MCLRE = ON

// Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config STVREN = ON

// Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config LVP = OFF

// Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))
#pragma config XINST = OFF

// Code Protection bits (Block 0 (000800-003FFFh) not code-protected)
#pragma config CP0 = OFF

// Code Protection bits (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP1 = OFF

// Code Protection bits (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP2 = OFF

// Code Protection bits (Block 3 (00C000-00FFFFh) not code-protected)
#pragma config CP3 = OFF

// Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPB = OFF

// Data EEPROM Code Protection bit (Data EEPROM not code-protected)
#pragma config CPD = OFF

// Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
#pragma config WRT0 = OFF

// Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT1 = OFF

// Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT2 = OFF

// Write Protection bit (Block 3 (00C000-00FFFFh) not write-protected)
#pragma config WRT3 = OFF

// Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTC = OFF

// Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTB = OFF

// Data EEPROM Write Protection bit (Data EEPROM not write-protected)
#pragma config WRTD = OFF

// Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR0 = OFF

// Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF

// Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF

// Table Read Protection bit (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF

// Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)
#pragma config EBTRB = OFF

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
