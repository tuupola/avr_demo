/*
 * Button with debouncing. Based on Lab Book Pages pseudocode.
 * 
 * http://www.labbookpages.co.uk/electronics/debounce.html
 * http://www.arduino.cc/en/Tutorial/Debounce
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
#include "timer.h"

void init(void) {
    
    /* Make PORTD2 (Arduino digital 2) input by clearing bit in DDR */
    DDRD &= ~(_BV(PORTD2));

    /* In input mode, when pull-up is enabled, default state of pin becomes ’1′. So even if */
    /* you don’t connect anything to pin and if you try to read it, it will read as 1. Now, */
    /* when you externally drive that pin to zero(i.e. connect to ground / or pull-down),   */
    /* only then it will be read as 0. */

    /* Enable pullups by setting bits in PORT. Default state is now high. */
    PORTD |= (_BV(PORTD2));
    
    /* Make PORTB5 (Arduino digital 13) an output by setting bit in DDR. */
    DDRB |= _BV(PORTB5);
    
}

uint8_t digital_read(int input_register, int pin) {
    return bit_is_set(input_register, pin) != 0 ? 1 : 0;
}

/* You could use cbi ie &= ~ or sbi ie |= but this makes code more readable. */
void digital_write(volatile uint8_t *data_port, uint8_t pin, uint8_t value) {
    if (0 == value) {
        *data_port &= ~(_BV(pin));
    } else {
        *data_port |= _BV(pin);
    }
}

int main(void) {    
    
    init();
    timer_init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    uint8_t current_reading;
    uint8_t current_state    = 0;
    uint8_t shift_register   = 0;
    
    /* Rest of the variables are used only for debugging output. */
    uint8_t previous_reading = 0;
    uint8_t previous_state   = 0;
    uint64_t last_toggle_time;

    while (1) {
        
        /* Shift the register towards the most significant bit. */
        shift_register = shift_register << 1;
        current_reading = digital_read(PIND, PIND2);
        
        /* Set least significant bit to current reading. */
        if (1 == current_reading) {
            shift_register |= _BV(0);
        } else {
            shift_register &= ~(_BV(0));
        }
        
        /* Used only for debugging purposes. */
        if (current_reading != previous_reading) {
            /* Note the time in millis of last change of button state. */
            last_toggle_time = timer_millis();
            printf("- Reading toggled %d (%d)\n", current_reading, last_toggle_time);
        }
        
        /* If shift register is 0b00000000 or 0b11111111 switch has been */
        /* high or low long enough to assume reading is not noise.       */
        if (0 == shift_register) {
            current_state = 0;
        } else if (255 == shift_register){
            current_state = 1;
        }
        
        /* Used only for debugging purposes. */
        if (current_state != previous_state) {
            printf("+ State toggled %d (%d)\n", current_state, last_toggle_time);
            previous_state = current_state;
        }
        
        previous_reading = current_reading;
        
    }
    return 0;
  
}
