/*
 * Loops through 0-F and displays it on TIL311. Pure C version.
 *
 * TIL311 pin 12 -> Arduino Digital 2 (PORTD2)
 * TIL311 pin 13 -> Arduino Digital 3 (PORTD3)
 * TIL311 pin 2  -> Arduino Digital 4 (PORTD4)
 * TIL311 pin 3  -> Arduino Digital 5 (PORTD5)
 * 
 * TIL311 pin 8  -> Arduino Digital 5 (PORTD6)
 * 
 * Led at Arduino Digital 13 (PORTB5)
 *
 * To compile and upload run: make clean; make; make flash;
 *
 * Copyright 2009-2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#include <avr/io.h>
#include <util/delay.h>

#define BIT_AT(value, bit) (value & (1 << bit))

int main(void) {
    
    /* Make PORTB5 (Arduino 13) and PORTD0-PORTD3 (Arduino 2-6) as an output. */
    DDRB |= _BV(PORTB5);
    DDRD |= _BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD7);
    
    for(;;) {
        
        PORTD |= _BV(PORTD7);
        

        /* Reset displayed value. */
        int value = 0;
        while (value < 16) {
            
            /* Toggle led at PORTB5 */
            PORTB ^= _BV(PORTB5);
            
            /* Short way would be to directly write the value to PORTD. */
            /* Shift by 2 because first TIL311 port is PORTD2. However  */
            /* This would zero PORTD0, PORTD1, PORTD6 and PORTD7.       */
            /* PORTD = value << 2; */
            
            /* TIL311 pin 3, latch data input A (1). */
            if (0 == BIT_AT(value, 0)) {
                PORTD &= ~_BV(PORTD2); 
            } else {
                PORTD |= _BV(PORTD2);
            }

            /* TIL311 pin 2, latch data input B (2). */
            if (0 == BIT_AT(value, 1)) {
                PORTD &= ~_BV(PORTD3);
            } else {
                PORTD |= _BV(PORTD3);
            }

            /* TIL311 pin 13, latch data input C (4). */
            if (0 == BIT_AT(value, 2)) {
                PORTD &= ~_BV(PORTD4);
            } else {
                PORTD |= _BV(PORTD4);
            }

            /* TIL311 pin 12, latch data input D (8). */
            if (0 == BIT_AT(value, 3)) {
                PORTD &= ~_BV(PORTD5);
            } else {
                PORTD |= _BV(PORTD5);
            }
                    
            value++;
            _delay_ms(500);    
        }
                
    }
    
    /* This is never reached. */
    return 0;
}


