/*
 * arduino.h
 *
 * Lightweight macro implementation of Arduino style pin numbering 
 * for accessing Atmel digital and analog pins.
 *
 * pin_mode(1, OUTPUT);
 * digital_write(1, HIGH);
 * pin_mode(2, INPUT);
 * digital_read(2);
 *
 * This file is based on Arduino project.
 *   https://github.com/arduino/Arduino/
 *
 * Copyright (c) 2007-2011 David A. Mellis, Mika tuupola
 *
 * Licensed under the LGPL 2.1 license:
 *   http://www.opensource.org/licenses/lgpl-2.1.php
 */

#ifndef ARDUINO_H
#define ARDUINO_H

/* atmega328 */
#define PORT_AT_PIN_0         PortD  
#define PORT_AT_PIN_1         PortD 
#define PORT_AT_PIN_2         PortD 
#define PORT_AT_PIN_3         PortD 
#define PORT_AT_PIN_4         PortD 
#define PORT_AT_PIN_5         PortD 
#define PORT_AT_PIN_6         PortD 
#define PORT_AT_PIN_7         PortD 
#define PORT_AT_PIN_8         PortB  
#define PORT_AT_PIN_9         PortB 
#define PORT_AT_PIN_10        PortB 
#define PORT_AT_PIN_11        PortB 
#define PORT_AT_PIN_12        PortB 
#define PORT_AT_PIN_13        PortB 
#define PORT_AT_PIN_14        PortC
#define PORT_AT_PIN_15        PortC 
#define PORT_AT_PIN_16        PortC 
#define PORT_AT_PIN_17        PortC 
#define PORT_AT_PIN_18        PortC 
#define PORT_AT_PIN_19        PortC 

#define PORT_AT_PIN_20        PortB
#define PORT_AT_PIN_21        PortB

#define MASK_AT_PIN_0      _BV(0)  
#define MASK_AT_PIN_1      _BV(1) 
#define MASK_AT_PIN_2      _BV(2) 
#define MASK_AT_PIN_3      _BV(3) 
#define MASK_AT_PIN_4      _BV(4) 
#define MASK_AT_PIN_5      _BV(5) 
#define MASK_AT_PIN_6      _BV(6) 
#define MASK_AT_PIN_7      _BV(7) 
#define MASK_AT_PIN_8      _BV(0)  
#define MASK_AT_PIN_9      _BV(1) 
#define MASK_AT_PIN_10     _BV(2) 
#define MASK_AT_PIN_11     _BV(3) 
#define MASK_AT_PIN_12     _BV(4) 
#define MASK_AT_PIN_13     _BV(5) 
#define MASK_AT_PIN_14     _BV(0) 
#define MASK_AT_PIN_15     _BV(1) 
#define MASK_AT_PIN_16     _BV(2) 
#define MASK_AT_PIN_17     _BV(3) 
#define MASK_AT_PIN_18     _BV(4) 
#define MASK_AT_PIN_19     _BV(5) 

#define MASK_AT_PIN_20     _BV(6) 
#define MASK_AT_PIN_21     _BV(7)

#endif /* ARDUINO_H */
