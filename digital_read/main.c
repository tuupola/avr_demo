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

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/sfr_defs.h>

#include "main.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define BAUD 9600
#include <util/setbaud.h>

volatile uint8_t interrupts;
char buffer[1];

static void uart_init(void) {
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

static int uart_putchar(char c, FILE *stream) {
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}

static int uart_getchar(FILE *stream) {
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

void init(void) {
    
    /* Make PORTD3..7 PORTD0..1 (Arduino digital 3..9) input by clearing bits in DDR */
	DDRD &= ~(_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
	DDRB &= ~(_BV(PORTB0) | _BV(PORTB1));

	/* Disable pullups by clearing bits in PORT. Default state is now low. */
	/*
	PORTD &= ~(_BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
	PORTB &= ~(_BV(PORTB0) | _BV(PORTB1));
	*/
	
	/* Enable pullups by setting bits in PORT. Default state is now high. */
	PORTD |= (_BV(PORTD2) | _BV(PORTD3) | _BV(PORTD4) | _BV(PORTD5) | _BV(PORTD6) | _BV(PORTD7));
	PORTB |= (_BV(PORTB0) | _BV(PORTB1));    
    
    /* Make PORTB5 (Arduino digital 13) an output by setting bit in DDR. */
    DDRB |= _BV(PORTB5);
    
}

int main(void) {	
	
    init();
	uart_init();
    stdout = &output;
	stdin  = &input;
	    
    uint8_t value;
    char buffer[9];  
	    
	while (1) {
        /* Blink led by toggling state of PORTB5 (Arduino digital 13). */
        PORTB ^= _BV(PORTB5);
        
        /* Take 8bit value from PORTD3..7 PORTD0..1 */      
        value = (PIND >> 2) + (PINB << 6);

        itoa(value, buffer, 2);
        puts(buffer);
        
        _delay_ms(500);    
    }
    
    return 0;
  
}
