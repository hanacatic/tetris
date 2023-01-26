#include <xc.h>
#include "max7219_driver.h"
#include "figure.h"

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF
#define _XTAL_FREQ 8000000

unsigned char matrix[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char matrix_row = 3;
unsigned char fig_bin_array[4] = {0,0,0,0};
unsigned char brojac =0;

void update_led(void){
    //Set LED states according to main matrix named 'matrix'.
    for(char i = 0; i<8; i++){
        MAX7219_send(8-i, matrix[4+i]);
        MAX7219_send(8-i, matrix[12+i]);
        MAX7219_update();
    }
}


void __interrupt() prekid(void){
    if(TMR0IF && TMR0IE){
        INTCONbits.TMR0IF = 0;
        TMR0 = 180;
        if (brojac == 100){
            if(can_go_further(matrix, &matrix_row)){
                go_down_1place(matrix, &matrix_row, fig_bin_array); update_led();
            }
            else{
                matrix_row = 3; prepare_new_figure(matrix, fig_bin_array);
            }
             brojac = 0;
        }
        brojac++;
        
    }
}

void tmr0_initialization(void){
    //setting TMR0 time to 5 ms.
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.TMR0CS = 0;
    TMR0 = 180;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
}
void main (void) {
    TRISD = 0b11100000;
    prepare_new_figure(matrix, fig_bin_array);
    MAX7219_initialization();
	tmr0_initialization();
    // main loop
    while (1);
    
    return;
}
