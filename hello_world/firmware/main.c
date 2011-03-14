/*
 * Hello world of AVR. Blink led PORTB5 (Arduino digital 13).
 *
 * To compile and upload run: make clean; make; make program;
 *
 * Copyright 2009-2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
 
#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{
    /* Make PORTB5 (Arduino pin 13) an output. */
    DDRB |= _BV(PORTB5);

    for(;;){
        /* Toggle state of PORTB5 (Arduino pin 13). */
        PORTB ^= _BV(PORTB5);
        _delay_ms(500);
    }
    
    /* Never reached. */
    return 0;
}