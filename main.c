#include <xc.h>
#include "max7219_driver.h"
#include "figure.h"

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF
#define _XTAL_FREQ 8000000

char matrix[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char matrix_row = 3;
char fig_bin_array[4] = {0,0,0,0};
char brojac =0;
char debouncing_counter = 80;
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
    if(TMR0IF && TMR0IE){ //interrupt on timer 0
        INTCONbits.TMR0IF = 0;
        TMR0 = 180;
        randomizer++; //changing randomizer value every time interrupt routine is done
        if(start_game == 1){ //game starts only after start button was pressed
        if (brojac == 100){ //after every 5ms game updates
            
            if(can_go_further(matrix, &matrix_row, fig_bin_array)){
                go_down_1place(matrix, &matrix_row, fig_bin_array); update_led(); //if a figure can go down a place it does
            }
            else{
                remove_full_rows(matrix); update_led(); //after figure has been dropped we check for any full rows
                matrix_row = 3; prepare_new_figure(matrix, fig_bin_array, randomizer); //deploy new figure
            }
             brojac = 0;
        }
        brojac++; //counter for timer
        debouncing_counter++;
        }
    }
    
   
    if(IOCBN1&&IOCBF1){
        
        IOCBF1 = 0;
        IOCIF=0;
        //first press initalizes the game
        if(start_game == 0){
            start_game = 1; 
            prepare_new_figure(matrix, fig_bin_array, randomizer);
            //randomizer is used so every time the game starts it has a different sequence -
            //which is calculated from time between starting the system and pressing the start button
        }else{
        if(debouncing_counter>70){
            //debouncing counter is made so only 1 press of butten within 3.5ms is recognized
        go_left(matrix, &matrix_row, fig_bin_array); //after first press - button for moving left
        debouncing_counter = 0;
        }
     }
    }
                
    if(IOCBN2&&IOCBF2){
        IOCBF2 = 0;
        IOCIF=0;
        if(debouncing_counter>70){
            //debouncing counter is made so only 1 press of butten within 3.5ms is recognized
        go_right(matrix, &matrix_row, fig_bin_array); //button for moving right
        debouncing_counter = 0;
        }
        
                
    }
    if(IOCBN3&&IOCBF3){
        //this button drops the figure as much as possible
        IOCBF3 = 0;
        IOCIF=0;
        char x = 1;
        if(debouncing_counter>70){
            //debouncing counter is made so only 1 press of butten within 3.5ms is recognized
        while(can_go_further(matrix, &matrix_row,fig_bin_array) && x < 20){go_down_1place(matrix, &matrix_row, fig_bin_array);x++;}
        update_led();
        debouncing_counter = 0;
        }
    }
    if(IOCBN4&&IOCBF4){
        //this button rotates the figure
        IOCBF4 = 0;
        IOCIF=0;
        if(debouncing_counter>70){
            //debouncing counter is made so only 1 press of butten within 3.5ms is recognized
        rotate(matrix, &matrix_row, fig_bin_array); 
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
 IOCBN1=1; // enables interrupt on change on rb1 - left
 IOCBF1=0;
 IOCBN2=1; // enables interrupt on change on rb2 - right
 IOCBF2=0;
 IOCBN3=1; // enables interrupt on change on rb3 - drop down
 IOCBF3=0;
 IOCBN4=1;  // enables interrupt on change on rb4 - rotate
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
    //prepare_new_figure(matrix, fig_bin_array, randomizer);
    MAX7219_initialization();
    
    // main loop
    while (1);
    
    return;
}
