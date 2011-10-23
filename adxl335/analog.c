/*
 * Analog to digital conversion routines for Atmel.
 * 
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
 
#ifndef ADC_REF
#define ADC_REF          ADC_REF_VCC
#endif

#include <avr/io.h>
#include "analog.h"

uint16_t analog_read(uint8_t pin) {
	
	/* Enable ADC and set prescaler. */
	ADCSRA = _BV(ADEN) | ADC_PRESCALER;
	
	/* Set high speed mode. */
    ADCSRB |=  _BV(ADHSM);
	
	/* Set adc reference and select mux. */
	ADMUX = ADC_REF | (pin & 0b00011111);
	
	/* Start conversion. */
    ADCSRA |= _BV(ADSC);
    
    /* Wait until adc has result ready. */
    loop_until_bit_is_clear(ADCSRA, ADSC);

	/* Word! */
	return ADCW;
}

uint8_t analog_read_byte(uint8_t pin) {
	
	/* Enable ADC and set prescaler. */
	ADCSRA = _BV(ADEN) | ADC_PRESCALER;
	
	/* Set high speed mode. */
    ADCSRB |=  _BV(ADHSM);
	
	/* Set adc reference and select mux. */
	ADMUX = ADC_REF | (pin & 0b00011111);
	
	/* Left adjust the 10 bit result. */
    ADMUX  |=  (1<<ADLAR);
	
	/* Start conversion. */
    ADCSRA |= _BV(ADSC);
    
    /* Wait until adc has result ready. */
    loop_until_bit_is_clear(ADCSRA, ADSC);

	/* Hight byte. */
	return ADCH;
}
