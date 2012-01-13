/*
 * Test on how to create a digital_write() function. Leds at PORTD2..6 
 * (Arduino digital 2..6) with 220 ohm resistors on positive leg.
 * 
 * Led at Arduino digital 13 (PORTB5). Cause we all love blinken leds!
 *
 * To compile and upload run: make clean; make; make program
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
//#include "uart.h"

void init(void) {
    
    /* Make PORTD2..6 (Arduino digital 2..6) output by setting bits in DDR */
    DDRD |= (_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6));
    
    /* Make PORTB5 (Arduino digital 13) an output by setting bit in DDR. */
    DDRB |= _BV(PORTB5);
    
}

int digital_read(int input_register, int pin) {
    return bit_is_set(input_register, pin) != 0 ? 1 : 0;
}

/* You could use cbi ie &= ~ or sbi ie |= but this makes code more readable. */
void digital_write(volatile int *data_port, int pin, int value) {
    if (0 == value) {
        *data_port &= ~(_BV(pin));
    } else {
        *data_port |= _BV(pin);
    }
}

int main(void) {    
    
    init();
    //uart_init();
    //stdout = &uart_output;
    //stdin  = &uart_input;
        
    while (1) {
        /* Blink led by toggling state of PORTB5 (Arduino digital 13). */
        PORTB ^= _BV(PORTB5);

        puts("Light PIND2");
        /*PORTD &= ~(_BV(PORTD6));
        PORTD |= _BV(PORTD2);*/
        digital_write(&PORTD, PORTD6, 0);
        digital_write(&PORTD, PORTD2, 1);
        _delay_ms(100);    
        
        puts("Light PIND3");
        /*PORTD &= ~(_BV(PORTD2));
        PORTD |= _BV(PORTD3);*/
        digital_write(&PORTD, PORTD2, 0);
        digital_write(&PORTD, PORTD3, 1);
        _delay_ms(100);    

        puts("Light PIND4");
        /*PORTD &= ~(_BV(PORTD3));        
        PORTD |= _BV(PORTD4);*/
        digital_write(&PORTD, PORTD3, 0);
        digital_write(&PORTD, PORTD4, 1);
        _delay_ms(100);
        
        puts("Light PIND5");
        /*PORTD &= ~(_BV(PORTD4));
        PORTD |= _BV(PORTD5);*/
        digital_write(&PORTD, PORTD4, 0);
        digital_write(&PORTD, PORTD5, 1);
        _delay_ms(100);    

        puts("Light PIND6");
        /*PORTD &= ~(_BV(PORTD5));
        PORTD |= _BV(PORTD6);*/
        digital_write(&PORTD, PORTD5, 0);
        digital_write(&PORTD, PORTD6, 1);
        _delay_ms(100);    
    }
    
    return 0;
  
}
