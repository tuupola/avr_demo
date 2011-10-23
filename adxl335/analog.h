/*
 * analog.h
 *
 * Lightweight macro implementation of Arduino style pin numbering
 * for AVR microprocessors. Because only thing I want to use from
 * Arduino libraries is the pin numbering scheme.
 * 
 * This file taken 60% from the excellent ArduinoLite project by 
 * Shikai Chen <csk@live.com>. Part of the code from Teensy examples
 * by PJRC.COM, LLC. Some minor additions to suite my personal coding 
 * taste.
 *
 *   http://code.google.com/p/arduino-lite/
 *   http://www.csksoft.net/
 *
 * Copyright (c) 2010-2011 Shikai Chen, PJRC.COM LLC, Mika Tuupola
 *
 * Licensed under the LGPL 2.1 license:
 *   http://www.opensource.org/licenses/lgpl-2.1.php
 */

#ifndef ANALOG_H
#define ANALOG_H
#include "pins.h"

#define PWM_ENABLE(pin)         EXPAND_WRAPPER(_PWM_ENABLE ,ARDUINOPIN_TO_TCCRID(pin) , ARDUINOPIN_TO_TIMERID(pin) )
#define PWM_DISABLE(pin)        EXPAND_WRAPPER(_PWM_DISABLE ,ARDUINOPIN_TO_TCCRID(pin) , ARDUINOPIN_TO_TIMERID(pin) ) 
#define PWM_SET(pin, val)       EXPAND_WRAPPER(_PWM_SET, ARDUINOPIN_TO_TIMERID(pin), val )

#define analog_write( pin, val )  \
    do{                          \
         PWM_ENABLE(pin);        \
         PWM_SET(pin,val);       \
    }                            \
    while(0)                   
    
#define PWM_SET_SAFE(pin, val)  \
    do{                         \
        if (val) {PIN_MODE(pin,OUTPUT);PWM_SET(pin, val);} \
        else PIN_MODE(pin, INPUT); \
    }while(0)


uint16_t analog_read(uint8_t pin);
uint8_t analog_read_byte(uint8_t pin);

#define ADC_REF_VCC      (1<<REFS0)                /* Power supply. Usually 5V */
#define ADC_REF_INTERNAL ((1<<REFS1) | (1<<REFS0)) /* Internal 2.56V */
#define ADC_REF_EXTERNAL (0)

/* Taken from Teensy example code: http://www.pjrc.com/teensy/adc.html */

#if F_CPU == 16000000L
#define ADC_PRESCALER ((1<<ADPS2) | (1<<ADPS1))
#elif F_CPU == 8000000L
#define ADC_PRESCALER ((1<<ADPS2) | (1<<ADPS0))
#elif F_CPU == 4000000L
#define ADC_PRESCALER ((1<<ADPS2))
#elif F_CPU == 2000000L
#define ADC_PRESCALER ((1<<ADPS1) | (1<<ADPS0))
#elif F_CPU == 1000000L
#define ADC_PRESCALER ((1<<ADPS1))
#else
#define ADC_PRESCALER ((1<<ADPS0))
#endif


#ifndef ADHSM
#define ADHSM (7)
#endif

#endif /* ANALOG_H */