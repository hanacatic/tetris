/*
 * File:   max_7219_driver.c
 * Author: gaztu
 *
 * Created on January 17, 2023, 2:19 PM
 */


#include <xc.h>
#include "max7219_driver.h"

//default brightness
unsigned char brt = 15;

#define DATA RD6
#define LOAD RD5
#define CLK  RD4


void MAX7219_initialization(void){
    
    MAX7219_send(MAX7219_MODE_SCANLIMIT, 7);
	MAX7219_send(MAX7219_MODE_SCANLIMIT, 7);
    MAX7219_update();
    
    MAX7219_send(MAX7219_MODE_DECODE, MAX7219_NO_DECODE);
	MAX7219_send(MAX7219_MODE_DECODE, MAX7219_NO_DECODE);
    MAX7219_update();
    
    MAX7219_send(MAX7219_MODE_INTENSITY, 15);
	MAX7219_send(MAX7219_MODE_INTENSITY, 15);
    MAX7219_update();
    
    MAX7219_send(MAX7219_MODE_SHUTDOWN, 1);
	MAX7219_send(MAX7219_MODE_SHUTDOWN, 1);
    MAX7219_update();

    MAX7219_send(1, 0); MAX7219_send(1, 0);  MAX7219_update();
    MAX7219_send(2, 0); MAX7219_send(2, 0);  MAX7219_update();
    MAX7219_send(3, 0); MAX7219_send(3, 0);  MAX7219_update();
    MAX7219_send(4, 0); MAX7219_send(4, 0);  MAX7219_update();
    MAX7219_send(5, 0); MAX7219_send(5, 0);  MAX7219_update();
    MAX7219_send(6, 0); MAX7219_send(6, 0);  MAX7219_update();
    MAX7219_send(7, 0); MAX7219_send(7, 0);  MAX7219_update();
    MAX7219_send(8, 0); MAX7219_send(8, 0);  MAX7219_update();
    
}
void MAX7219_send (unsigned char a, unsigned char d) {

	// send out address byte, start with most significant bit and work backwards
    for (int i=7; i>=0; i--) {
        DATA = (a >> i) & 1;
        CLK = 1;
        CLK = 0;
    }
	
	// send out data byte, start with most significant bit and work backwards
    for (int i=7; i>=0; i--) {
        DATA = (d >> i) & 1;
        CLK = 1;
        CLK = 0;
    }
	
	// reset the data pin back to zero
	// (so that it is not left ON if the last sent bit was a 1)
    DATA = 0;

}

void MAX7219_update (void) {
	
    LOAD = 1;
    LOAD = 0;
	
}

