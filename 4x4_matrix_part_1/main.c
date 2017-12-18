/*
 * 
 * To compile and upload run: make clean; make; make program;
 * 
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#include <stdint.h>
#include <util/delay.h>

#include "main.h"
#include "digital_slow.h"

uint8_t column_pins[4] = {2, 3, 4, 5};
uint8_t row_pins[4]    = {11, 10, 9, 8};
uint8_t pattern[4][4]  = {{1,0,0,1},
                          {0,1,0,0},
                          {0,0,1,0},
                          {1,0,0,1}};
     
static void init(void) {

    /* Turn all columns off by setting then low. */
    for (uint8_t x=0; x<4; x++) { 
        pin_mode(column_pins[x], OUTPUT);
        digital_write(column_pins[x], LOW);
    }
    
    /* Turn all rows off by setting then high. */
    for (uint8_t y=0; y<4; y++) { 
        pin_mode(row_pins[y], OUTPUT);
        digital_write(row_pins[y], HIGH);
    }

}

void draw(uint8_t buffer[4][4], uint8_t delay) {
    
    for (uint8_t row=0; row<4; ++row) {
        /* Connect or disconnect columns as needed. */
        for (uint8_t column=0; column<4; ++column) {
            digital_write(column_pins[column], buffer[row][column]);                    
        }
        
        /* Turn on whole row. */
        digital_write(row_pins[row], LOW);

        _delay_ms(delay);

        /* Turn off whole row. */
        digital_write(row_pins[row], HIGH);
    }
}

int main(void) {    
    
    init();
    
    /* With 100ms delay eye can see updating row by row. */
    for (uint8_t i=0; i<10; i++) { 
        draw(pattern, 100);
    }

    /* With 10ms delay pattern appears but flickers. */
    for (uint16_t i=0; i<100; i++) { 
        draw(pattern, 10);
    }
    
    /* Withoud delay solid pattern appears. */
    while (1) {
        draw(pattern, 1);        
    }
    
    return 0;
}
