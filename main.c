#include <xc.h>
#include "max7219_driver.h"
#include "figure.h"

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF
#define _XTAL_FREQ 8000000

char matrix[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char matrix_row = 3;
char matrix_col = 3;
char fig_bin_array[4] = {0,0,0,0};
char brojac =0;

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
            if(can_go_further(matrix, &matrix_row, fig_bin_array)){
                go_down_1place(matrix, &matrix_row, fig_bin_array); update_led();
            }
            else{
                matrix_row = 3; prepare_new_figure(matrix, fig_bin_array);
            }
             brojac = 0;
        }
        brojac++;
    }
    
    if(IOCBN0&&IOCBF0){        
        IOCBF0 = 0;
        IOCIF=0;
        //do something to start the game
        
    }
    if(IOCBN1&&IOCBF1){
        IOCBF1 = 0;
        IOCIF=0;
        PORTDbits.RD7 = !PORTDbits.RD7;
        go_left(matrix, &matrix_row, &matrix_col, fig_bin_array);
                
    }
    if(IOCBN2&&IOCBF2){
        IOCBF2 = 0;
        IOCIF=0;
        PORTDbits.RD7 = !PORTDbits.RD7;
        go_right(matrix, &matrix_row, &matrix_col, fig_bin_array);
                
    }
    if(IOCBN3&&IOCBF3){
        IOCBF3 = 0;
        IOCIF=0;
        go_down_1place(matrix, &matrix_row, fig_bin_array);                        
    }
    if(IOCBN4&&IOCBF4){
        IOCBF4 = 0;
        IOCIF=0;
        PORTDbits.RD7 = !PORTDbits.RD7;
        rotate(matrix, &matrix_row, &matrix_col, fig_bin_array);                        
    }
    if(INTE && INTF){
        PORTDbits.RD7 = !PORTDbits.RD7;
        INTF = 0;
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
    //INTCONbits.GIE = 1;
}
void ioc_initialization(void){
 IOCBN0=1; // Omogucavanje prekida na rastucu ivicu na RB0 - Start
 IOCBF0=0;
 IOCBN1=1; // Omogucavanje prekida na rastucu ivicu na RB1 - Left
 IOCBF1=0;
 IOCBN2=1; // Omogucavanje prekida na rastucu ivicu na RB2 - Right
 IOCBF2=0;
 IOCBN3=1; //Omogucavanje prekida na rastucu ivicu na RB3 - drop down
 IOCBF3=0;
 IOCBN4=1; //Omogucavanje prekida na rastucu ivicu na RB4 - rotate
 IOCBF4=0; 
 IOCIF=0;
 IOCIE=1;
 GIE=1;
}

void main (void) {
    
    TRISB = 0xFF;
    PORTB = 0x00;
    TRISD = 0b00000000;
    PORTD = 0x00;
    ANSELD = 0x00;
    ANSELB = 0x00;
    PORTDbits.RD7 = 1;
    tmr0_initialization();
    ioc_initialization();
    prepare_new_figure(matrix, fig_bin_array);
    MAX7219_initialization();
    
	
    // main loop
    while (1);
    
    return;
}
