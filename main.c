
#include <xc.h>
#include "max7219_driver.h"
#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF
#define _XTAL_FREQ 8000000


void main (void) {

    TRISD = 0b11100000;
	
    // main loop
    while (1) {
		
        MAX7219_send(8, 0b00001111); MAX7219_send(8, 0b00000111); MAX7219_update();
        MAX7219_send(7, 0b00001111); MAX7219_send(7, 0b00000111); MAX7219_update();
		MAX7219_send(6, 0b00001111); MAX7219_send(6, 0b00000111); MAX7219_update();
		MAX7219_send(5, 0b00001111); MAX7219_send(5, 0b00000111); MAX7219_update();
		MAX7219_send(4, 0b00001111); MAX7219_send(4, 0b00000111); MAX7219_update();
		MAX7219_send(3, 0b00001111); MAX7219_send(3, 0b00000111); MAX7219_update();
		MAX7219_send(2, 0b00001111); MAX7219_send(2, 0b00000111); MAX7219_update();
        MAX7219_send(1, 0b00001111); MAX7219_send(1, 0b00000111); MAX7219_update();
        
    }
    
    return;
    
}
