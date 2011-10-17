/*
 * Digital read 8bit data from PORTD3..7 PORTD0..1 (Arduino digital ports 3..9)
 * and output it as binary string (10001101) to serial. Floating state is high. 
 * Connect pin to ground to set it low.
 * 
 * Led at Arduino digital 13 (PORTB5). Cause we all love blinken leds!
 *
 * To compile and upload run: make clean; make; make program;
 *
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/sfr_defs.h>

#include "main.h"
#include "uart.h"
#include "digital.h"

void init(void) {
    
    /* Switch inputs. */
    pin_mode(2, INPUT);
    pin_mode(3, INPUT);
    pin_mode(4, INPUT);
    pin_mode(5, INPUT);
    pin_mode(6, INPUT);
    pin_mode(7, INPUT);
    pin_mode(8, INPUT);
    pin_mode(9, INPUT);

    /* In input mode, when pull-up is enabled, default state of pin becomes ’1′. So even if */
    /* you don’t connect anything to pin and if you try to read it, it will read as 1. Now, */
    /* when you externally drive that pin to zero(i.e. connect to ground / or pull-down),   */
    /* only then it will be read as 0. */
    
    pin_pullup(2, DISABLE);
    pin_pullup(3, DISABLE);
    pin_pullup(4, DISABLE);
    pin_pullup(5, DISABLE);
    pin_pullup(6, DISABLE);
    pin_pullup(7, DISABLE);
    pin_pullup(8, DISABLE);
    pin_pullup(9, DISABLE);
    
    /* Blinken led. */
    pin_mode(13, OUTPUT);
    
}

int main(void) {    
    
    init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    int  value;
        
    while (1) {
        
        /* Blink led by toggling state of PORTB5 (Arduino digital 13). */
        PORTB ^= _BV(PORTB5);
        
        value = digital_read(2);
        printf("%d", value);

        value = digital_read(3);
        printf("%d", value);

        value = digital_read(4);
        printf("%d", value);

        value = digital_read(5);
        printf("%d", value);

        value = digital_read(6);
        printf("%d", value);

        value = digital_read(7);
        printf("%d", value);
        
        value = digital_read(8);
        printf("%d", value);

        value = digital_read(9);
        printf("%d\n", value);
        
        _delay_ms(500);    
    }
    
    return 0;
  
}
