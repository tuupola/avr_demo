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

void init(void) {
    
    /* Make PORTD2..7 PORTD0..1 (Arduino digital 3..11) input by clearing bits in DDR */
    DDRD &= ~(_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
    DDRB &= ~(_BV(PORTB0) | _BV(PORTB1));

    /* In input mode, when pull-up is enabled, default state of pin becomes ’1′. So even if */
    /* you don’t connect anything to pin and if you try to read it, it will read as 1. Now, */
    /* when you externally drive that pin to zero(i.e. connect to ground / or pull-down),   */
    /* only then it will be read as 0. */

    /* Enable pullups by setting bits in PORT. Default state is now high. */
    PORTD |= (_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
    PORTB |= (_BV(PORTB0) | _BV(PORTB1));
    
    /* Disable pullups by clearing bits in PORT. Default state is now low. */
    /*
    PORTD &= ~(_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
    PORTB &= ~(_BV(PORTB0) | _BV(PORTB1));
    */
    
    /* Make PORTB5 (Arduino digital 13) an output by setting bit in DDR. */
    DDRB |= _BV(PORTB5);
    
}

int digital_read(int input_register, int pin) {
    return bit_is_set(input_register, pin) != 0 ? 1 : 0;
}

/*
void digital_write(int input_register, int pin) {
    input_register |= _BV(pin);
}
*/

int main(void) {    
    
    init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    int  value;
    //char buffer[9];  
        
    while (1) {
        /* Blink led by toggling state of PORTB5 (Arduino digital 13). */
        PORTB ^= _BV(PORTB5);

        /*
        puts("PINB");
        value = PINB;
        itoa(value, buffer, 2);
        puts(buffer);
        */
        
        value = digital_read(PIND, PIND2);
        printf("%d", value);

        value = digital_read(PIND, PIND3);
        printf("%d", value);

        value = digital_read(PIND, PIND4);
        printf("%d", value);

        value = digital_read(PIND, PIND5);
        printf("%d", value);

        value = digital_read(PIND, PIND6);
        printf("%d", value);

        value = digital_read(PIND, PIND7);
        printf("%d", value);
        
        value = digital_read(PINB, PINB0);
        printf("%d", value);

        value = digital_read(PINB, PINB1);
        printf("%d\n", value);
        
        _delay_ms(500);    
    }
    
    return 0;
  
}
