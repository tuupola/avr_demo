/*
 * shift.c
 *
 * This file is part of Triple-A library:
 *   https://github.com/tuupola/triple-a
 *
 * Copyright 2011-2012 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
 
#include "pins/digital.h"
#include "shift/shift.h"

/* Assumes MSB first. */
uint8_t shift_in(void) {
    uint8_t byte = 0;
    uint8_t pin_value;
    
    for(int i=0; i<8; i++) {
        pin_value = digital_read(SHIFT_IN_DATA);  
        byte |= (pin_value << ((8 - 1) - i));
        
        #ifdef DEBUG
        printf("%d = %d \n", ((8 - 1) - i), pin_value);
        #endif
        
        /* Pulse clock to write next bit. */
        digital_write(SHIFT_IN_CLOCK, LOW);
        digital_write(SHIFT_IN_CLOCK, HIGH);
    }
    return byte;
}

void shift_in_latch(void) {
    digital_write(SHIFT_IN_LATCH, LOW); 
    digital_write(SHIFT_IN_LATCH, HIGH);
}


void shift_in_init(void) {
    pin_mode(SHIFT_OUT_LATCH, OUTPUT);
    pin_mode(SHIFT_OUT_CLOCK, OUTPUT);
    pin_mode(SHIFT_OUT_DATA,  INPUT);
}

/* Assumes MSB first. */
void shift_out(uint8_t data) {
    for(uint8_t i = 0; i < 8; i++) {
        /* Write bit to data port. */
        if (0 == (data & _BV(7 - i))) {
            digital_write(SHIFT_OUT_DATA, LOW);            
        } else {
            digital_write(SHIFT_OUT_DATA, HIGH);
        }
        
        /* Pulse clock to write next bit. */
        digital_write(SHIFT_OUT_CLOCK, LOW);
        digital_write(SHIFT_OUT_CLOCK, HIGH);
    }
}

void shift_out_latch(void) {
    digital_write(SHIFT_OUT_LATCH, LOW); 
    digital_write(SHIFT_OUT_LATCH, HIGH);
}

void shift_out_init(void) {
    pin_mode(SHIFT_OUT_LATCH, OUTPUT);
    pin_mode(SHIFT_OUT_CLOCK, OUTPUT);
    pin_mode(SHIFT_OUT_DATA,  OUTPUT);
}