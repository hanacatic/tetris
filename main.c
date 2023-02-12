#include <xc.h>
#include "max7219_driver.h"
#include "figure.h"

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF
#define _XTAL_FREQ 8000000

char matrix[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char matrix_row = 3;
char matrix_col = 2;
char fig_bin_array[4] = {0,0,0,0};
char brojac =0;
char debouncing_counter = 11;
__bit start_game = 0;
char randomizer = 1;

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
        randomizer++;
        if(start_game == 1){
        if (brojac == 100){
            debouncing_counter++;
            if(can_go_further(matrix, &matrix_row, fig_bin_array)){
                go_down_1place(matrix, &matrix_row, fig_bin_array); update_led();
            }
            else{
                remove_full_rows(matrix); update_led();
                matrix_row = 3; prepare_new_figure(matrix, fig_bin_array, randomizer);
            }
             brojac = 0;
        }
        brojac++;
        }
    }
    
    if(IOCBN0&&IOCBF0){
        
        IOCBF0 = 0;
        IOCIF=0;
        if(debouncing_counter>1){
        debouncing_counter = 0;
        }
        //do something to start the game
        
    }
    if(IOCBN1&&IOCBF1){
        
        IOCBF1 = 0;
        IOCIF=0;
        if(start_game == 0){
            start_game = 1;            
        }else{
        if(debouncing_counter>1){
        PORTDbits.RD7 = !PORTDbits.RD7;
        go_left(matrix, &matrix_row, &matrix_col, fig_bin_array);
        debouncing_counter = 0;
        }
     }
    }
                
    if(IOCBN2&&IOCBF2){
        IOCBF2 = 0;
        IOCIF=0;
        if(debouncing_counter>1){
        PORTDbits.RD7 = !PORTDbits.RD7;
        go_right(matrix, &matrix_row, &matrix_col, fig_bin_array);
        debouncing_counter = 0;
        }
        
                
    }
    if(IOCBN3&&IOCBF3){
        IOCBF3 = 0;
        IOCIF=0;
        if(debouncing_counter>1){
        go_down_1place(matrix, &matrix_row, fig_bin_array);    
        debouncing_counter = 0;
        }
    }
    if(IOCBN4&&IOCBF4){
        IOCBF4 = 0;
        IOCIF=0;
        if(debouncing_counter>1){
        PORTDbits.RD7 = !PORTDbits.RD7;
        rotate(matrix, &matrix_row, &matrix_col, fig_bin_array); 
        debouncing_counter = 0;
        }
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
    prepare_new_figure(matrix, fig_bin_array, randomizer);
    MAX7219_initialization();
    
    // main loop
    while (1);
    
    return;
}
