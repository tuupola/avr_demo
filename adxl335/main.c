/*
 * Exercise on Atmel analog to digital conversion by reading the values of
 * ADXL335 accelerometer sensor. 
 * 
 * There are lot of articles on how Atmel analog to digital conversion works.
 * Most of them don't really explain anything. Code is just copied from
 * other examples. Only after reading Protostack article I could understand
 * the inner workings. Another great source of information is source code
 * of ADC driver from Atmel.
 *
 * http://www.protostack.com/blog/2011/02/analogue-to-digital-conversion-on-an-atmega168/
 * http://www.google.com/search?q=atmel+adc_drv
 *
 * General information on ADXL335.
 * 
 * http://bildr.org/2011/04/sensing-orientation-with-the-adxl335-arduino/
 * http://www.sparkfun.com/datasheets/Components/SMD/adxl335.pdf
 * 
 * To compile and upload run: make clean; make; make program;
 * 
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

#include "main.h"
#include "uart.h"
#include "pins.h"
#include "analog.h"

#define X   0  /* Analog 0 */
#define Y   1  /* Analog 1 */
#define Z   2  /* Analog 2 */

static void init(void) {    
    pin_mode(X, INPUT);
    pin_mode(Y, INPUT);
    pin_mode(Z, INPUT); 
}

int main(void) {    
    
    init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    while (1) {
        
        uint16_t x;
        uint16_t y;
        uint16_t z;
        x = analog_read(X);        
        y = analog_read(Y);        
        z = analog_read(Z);        
        printf("word: %d %d %d\n", x, y, z);
        
        uint16_t x2;
        uint16_t y2;
        uint16_t z2;
        x2 = analog_read_byte(X);        
        y2 = analog_read_byte(Y);        
        z2 = analog_read_byte(Z);        
        printf("byte: %d %d %d\n", x2, y2, z2);
        
        _delay_ms(200);
        
    }
    return 0;
  
}
