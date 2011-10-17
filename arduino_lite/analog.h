/*
 * analog.h
 *
 * Lightweight macro implementation of Arduino style pin numbering
 * for AVR microprocessors. Because only thing I want to use from
 * Arduino libraries is the pin numbering scheme.
 * 
 * This file taken 99% from the excellent ArduinoLite project by 
 * Shikai Chen <csk@live.com>. Some minor changes to suite my personal 
 * coding taste.
 *
 *   http://code.google.com/p/arduino-lite/
 *   http://www.csksoft.net/
 *
 * Copyright (c) 2010-2011 Shikai Chen
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


#endif /* ANALOG_H */