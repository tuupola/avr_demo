/*
 * Button with debouncing. Based on the Arduino example but without
 * Arduino libraries.
 * 
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
    uint8_t previous_reading = 0;
    uint8_t current_state    = 0;
    uint8_t previous_state   = 0;
    
    uint64_t last_toggle_time;

    while (1) {
        
        current_reading = digital_read(PIND, PIND2);
        if (current_reading != previous_reading) {
            /* Note the time in millis of last change of button state. */
            last_toggle_time = timer_millis();
            printf("- Reading toggled %d (%d)\n", current_reading, last_toggle_time);
        }

        /* If there has been more than 10 millis since last toggling  */
        /* of button state, assume it is real and not bouncing noise. */
        if ((timer_millis() - last_toggle_time) > 10) {
            current_state = current_reading;
        }
        
        /* Just for debugging purposes. */
        if (current_state != previous_state) {
            printf("+ State toggled %d (%d)\n", current_state, last_toggle_time);
            previous_state = current_state;
        }
        
        previous_reading = current_reading;
    }
    
    return 0;
  
}
