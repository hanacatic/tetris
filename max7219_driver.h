
#ifndef MAX7219_DRIVER_HEADER_H
#define	MAX7219_DRIVER_HEADER_H

#include <xc.h> // include processor files - each processor file is guarded.  

// define MAX7219 register addresses (for convenience)
#define MAX7219_MODE_NOP       0b00000000
#define MAX7219_MODE_DECODE    0b00001001
#define MAX7219_MODE_INTENSITY 0b00001010
#define MAX7219_MODE_SCANLIMIT 0b00001011
#define MAX7219_MODE_SHUTDOWN  0b00001100
#define MAX7219_MODE_TEST      0b00001111

// define MAX7219 commands (for convenience)
#define MAX7219_NO_DECODE      0b00000000
#define MAX7219_7SEG_DECODE    0b11111111




/**
    <p><b>Function prototype:</b>void MAX7219_send (unsigned char a, unsigned char d);</p>
  
    <p><b>Summary:</b>Sending data to LED matrix display</p>

    <p><b>Description:</b>This function sends out the address byte "a" and the data byte "d" in the MAX7219 format.</p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b>'a' - unsigned char, 'd' - unsigned char</p>

    <p><b>Returns:</b>No return (void)</p>

    <p><b>Example:</b></p>
    <code>

    </code>

    <p><b>Remarks:</b>Sequence of bits is a7-a6-a5-a4-a3-a2-a1-a0-d7-d6-d5-d4-d3-d2-d1-d0.</p>
 */
void MAX7219_send (unsigned char a, unsigned char d);


/**
    <p><b>Function prototype:</b>void MAX7219_update (void);</p>
  
    <p><b>Summary:</b>Displaying sent information</p>

    <p><b>Description:</b>This function pulls the LOAD pin high and then back to zero, so that the transmitted data appears in the MAX7219's output stage</p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b>No parameters (void)</p>

    <p><b>Returns:</b>No return (void)</p>

    <p><b>Example:</b></p>
    <code>

    </code>

    <p><b>Remarks:</b></p>
 */
void MAX7219_update (void);


/**
    <p><b>Function prototype:</b>void MAX7219_initialization(void);</p>

    <p><b>Summary:</b>Initializing MAX7219 driver</p>

    <p><b>Description:</b>1.) Scan all 16 rows. 2.) Set MAX7219 to no-decoding mode. 3.) Set brightness. 4.) Turn on. 5.) Clear all dots on LED matrix display.</p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b>No parameters (void)</p>

    <p><b>Returns:</b>No return (void)</p>

    <p><b>Example:</b></p>
    <code>

    </code>

    <p><b>Remarks:</b></p>
 */
void MAX7219_initialization(void);





#endif
