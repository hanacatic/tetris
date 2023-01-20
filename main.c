#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF

#define _XTAL_FREQ 8000000

int a = 0;
unsigned char counter = 0;

const char figures[7][4] = {
    {1, 3, 5, 7}, // I
    {2, 4, 5, 7}, // 4
    {3, 5, 4, 6}, // N
    {3, 5, 4, 7}, // T
    {2, 3, 5, 7}, // L
    {3, 5, 7, 6}, // J
    {2, 3, 4, 5}, // O
};

struct Point{
    char x, y;
};

//moves figure in x axis depending on dx, dx > 0 RIGHT, dx < 0 LEFT
void moveFig(struct Point* figure, char dx){
    for(int i = 0; i < 4; i++){
        figure[i].x = figure[i].x + dx;
    }
}

//interrupt routine
void __interrupt() interr(){
    if(TMR0IE && TMR0IF){
        counter = counter + 1;
    }
    if (INTE && INTF){
        INTF =0;
        RD0 = 1 - RD0;
        RB1 = 1 - RB1;
        
    }
    
}

//interrupt initialisation
void interr_init(){
    //config of interrupt on change
    INTF=0;
    INTEDG=1;
    INTE=1;
    //configuration of TMR0 timer
    TMR0CS = 0;
    TMR0IF = 0;
    //using prescaler and setting TMR value to measure time in 1ms
    PSA = 0;
    PS0 = 1;
    PS1 = 0;
    PS2 = 1;
    TMR0 = 133;
    TMR0IE = 1;
    GIE = 1;
}
void port_init(void){
    TRISB=0xB1; // 1000 0001 
    ANSELB=0; 
    PORTB=0;
    TRISD = 0x00;
    PORTD = 0;
    ANSELD = 0;

}
void main(void) {
    interr_init();
    port_init();
    srand(5198);
 
    while(1){
        a = rand() % 7;
    }
}
