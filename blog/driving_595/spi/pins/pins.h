/*
 * pins.h
 * 
 * Lightweight macro implementation of AVR pin numbering for
 * accessing Atmel digital and analog pins.
 *
 * pin_mode(A1, OUTPUT);
 * digital_write(A1, HIGH);
 * pin_mode(A2, INPUT);
 * digital_read(A2);
 *
 * This file is based on the excellent ArduinoLite project by 
 * Shikai Chen <csk@live.com>. 
 *
 *   http://code.google.com/p/arduino-lite/
 *   http://www.csksoft.net/
 *
 * Copyright (c) 2010-2011 Shikai Chen, Mika Tuupola
 *
 * Licensed under the LGPL 2.1 license:
 *   http://www.opensource.org/licenses/lgpl-2.1.php
 */

#ifndef PINS_H
#define PINS_H

#include <avr/sfr_defs.h>
#include <avr/io.h>

#include "arduino.h"

#define HIGH 0x1
#define LOW  0x0

#define INPUT  0x0
#define OUTPUT 0x1

#define ENABLE  0x1
#define DISABLE 0x0

#define PIN_TO_PORT(x) PORT_AT_PIN_##x
#define PIN_TO_MASK(x) MASK_AT_PIN_##x

#define PORT_TO_DIRECTION_REGISTER(x) DIRECTION_REGISTER_AT_##x
#define PORT_TO_OUTPUT_REGISTER(x) OUTPUT_REGISTER_AT_##x
#define PORT_TO_INPUT_REGISTER(x) INPUT_REGISTER_AT_##x

#ifdef PORTA
#define DIRECTION_REGISTER_AT_PortA DDRA
#define OUTPUT_REGISTER_AT_PortA PORTA
#define INPUT_REGISTER_AT_PortA PINA

#define PORT_AT_PIN_A0  PortA
#define PORT_AT_PIN_A1  PortA
#define PORT_AT_PIN_A2  PortA
#define PORT_AT_PIN_A3  PortA
#define PORT_AT_PIN_A4  PortA
#define PORT_AT_PIN_A5  PortA
#define PORT_AT_PIN_A6  PortA
#define PORT_AT_PIN_A7  PortA

#define MASK_AT_PIN_A0  _BV(0)
#define MASK_AT_PIN_A1  _BV(1)
#define MASK_AT_PIN_A2  _BV(2)
#define MASK_AT_PIN_A3  _BV(3)
#define MASK_AT_PIN_A4  _BV(4)
#define MASK_AT_PIN_A5  _BV(5)
#define MASK_AT_PIN_A6  _BV(6)
#define MASK_AT_PIN_A7  _BV(7)
#endif

#ifdef PORTB
#define DIRECTION_REGISTER_AT_PortB DDRB
#define OUTPUT_REGISTER_AT_PortB PORTB
#define INPUT_REGISTER_AT_PortB PINB

#define PORT_AT_PIN_B0  PortB
#define PORT_AT_PIN_B1  PortB
#define PORT_AT_PIN_B2  PortB
#define PORT_AT_PIN_B3  PortB
#define PORT_AT_PIN_B4  PortB
#define PORT_AT_PIN_B5  PortB
#define PORT_AT_PIN_B6  PortB
#define PORT_AT_PIN_B7  PortB

#define MASK_AT_PIN_B0  _BV(0)
#define MASK_AT_PIN_B1  _BV(1)
#define MASK_AT_PIN_B2  _BV(2)
#define MASK_AT_PIN_B3  _BV(3)
#define MASK_AT_PIN_B4  _BV(4)
#define MASK_AT_PIN_B5  _BV(5)
#define MASK_AT_PIN_B6  _BV(6)
#define MASK_AT_PIN_B7  _BV(7)
#endif

#ifdef PORTC
#define DIRECTION_REGISTER_AT_PortC DDRC
#define OUTPUT_REGISTER_AT_PortC PORTC
#define INPUT_REGISTER_AT_PortC PINC

#define PORT_AT_PIN_C0  PortC
#define PORT_AT_PIN_C1  PortC
#define PORT_AT_PIN_C2  PortC
#define PORT_AT_PIN_C3  PortC
#define PORT_AT_PIN_C4  PortC
#define PORT_AT_PIN_C5  PortC
#define PORT_AT_PIN_C6  PortC
#define PORT_AT_PIN_C7  PortC

#define MASK_AT_PIN_C0  _BV(0)
#define MASK_AT_PIN_C1  _BV(1)
#define MASK_AT_PIN_C2  _BV(2)
#define MASK_AT_PIN_C3  _BV(3)
#define MASK_AT_PIN_C4  _BV(4)
#define MASK_AT_PIN_C5  _BV(5)
#define MASK_AT_PIN_C6  _BV(6)
#define MASK_AT_PIN_C7  _BV(7)
#endif

#ifdef PORTD
#define DIRECTION_REGISTER_AT_PortD DDRD
#define OUTPUT_REGISTER_AT_PortD PORTD
#define INPUT_REGISTER_AT_PortD PIND
#define PORT_AT_PIN_D0  PortD
#define PORT_AT_PIN_D1  PortD
#define PORT_AT_PIN_D2  PortD
#define PORT_AT_PIN_D3  PortD
#define PORT_AT_PIN_D4  PortD
#define PORT_AT_PIN_D5  PortD
#define PORT_AT_PIN_D6  PortD
#define PORT_AT_PIN_D7  PortD
#define MASK_AT_PIN_D0  _BV(0)
#define MASK_AT_PIN_D1  _BV(1)
#define MASK_AT_PIN_D2  _BV(2)
#define MASK_AT_PIN_D3  _BV(3)
#define MASK_AT_PIN_D4  _BV(4)
#define MASK_AT_PIN_D5  _BV(5)
#define MASK_AT_PIN_D6  _BV(6)
#define MASK_AT_PIN_D7  _BV(7)
#endif

#ifdef PORTE
#define DIRECTION_REGISTER_AT_PortE DDRE
#define OUTPUT_REGISTER_AT_PortE PORTE
#define INPUT_REGISTER_AT_PortE PINE

#define PORT_AT_PIN_E0  PortE
#define PORT_AT_PIN_E1  PortE
#define PORT_AT_PIN_E2  PortE
#define PORT_AT_PIN_E3  PortE
#define PORT_AT_PIN_E4  PortE
#define PORT_AT_PIN_E5  PortE
#define PORT_AT_PIN_E6  PortE
#define PORT_AT_PIN_E7  PortE

#define MASK_AT_PIN_E0  _BV(0)
#define MASK_AT_PIN_E1  _BV(1)
#define MASK_AT_PIN_E2  _BV(2)
#define MASK_AT_PIN_E3  _BV(3)
#define MASK_AT_PIN_E4  _BV(4)
#define MASK_AT_PIN_E5  _BV(5)
#define MASK_AT_PIN_E6  _BV(6)
#define MASK_AT_PIN_E7  _BV(7)
#endif

#ifdef PORTF
#define DIRECTION_REGISTER_AT_PortF DDRF
#define OUTPUT_REGISTER_AT_PortF PORTF
#define INPUT_REGISTER_AT_PortF PINF

#define PORT_AT_PIN_F0  PortF
#define PORT_AT_PIN_F1  PortF
#define PORT_AT_PIN_F2  PortF
#define PORT_AT_PIN_F3  PortF
#define PORT_AT_PIN_F4  PortF
#define PORT_AT_PIN_F5  PortF
#define PORT_AT_PIN_F6  PortF
#define PORT_AT_PIN_F7  PortF

#define MASK_AT_PIN_F0  _BV(0)
#define MASK_AT_PIN_F1  _BV(1)
#define MASK_AT_PIN_F2  _BV(2)
#define MASK_AT_PIN_F3  _BV(3)
#define MASK_AT_PIN_F4  _BV(4)
#define MASK_AT_PIN_F5  _BV(5)
#define MASK_AT_PIN_F6  _BV(6)
#define MASK_AT_PIN_F7  _BV(7)
#endif

#define MERGE_TO_FUNC(prefix, id)   prefix##_##id
#define EXPAND_WRAPPER(NEXTLEVEL, ...)  NEXTLEVEL(__VA_ARGS__)

#define _SET_OUTPUT(port_id, msk) PORT_TO_DIRECTION_REGISTER(port_id) |= (msk)
#define _SET_INPUT(port_id, msk)  PORT_TO_DIRECTION_REGISTER(port_id) &= ~(msk)

#define _DIGITAL_WRITE_HIGH(port_id, msk) PORT_TO_OUTPUT_REGISTER(port_id) |= (msk)
#define _DIGITAL_WRITE_LOW(port_id, msk)  PORT_TO_OUTPUT_REGISTER(port_id) &= ~(msk)

#define _DIGITAL_READ_RAW(port_id, msk) ((PORT_TO_INPUT_REGISTER(port_id)) & (msk))
#define _DIGITAL_READ(port_id, msk)     (((PORT_TO_INPUT_REGISTER(port_id)) & (msk)) != 0 ? 1 : 0)

#define _DIGITAL_TOGGLE(port_id, msk) PORT_TO_OUTPUT_REGISTER(port_id) ^= (msk)

#define SET_1(pin) SET_OUTPUT(pin)
#define SET_0(pin) SET_INPUT(pin)

#define SET_0x1(pin) SET_OUTPUT(pin)
#define SET_0x0(pin) SET_INPUT(pin)

#define DIGITAL_WRITE_HIGH(pin) EXPAND_WRAPPER(_DIGITAL_WRITE_HIGH, PIN_TO_PORT(pin), PIN_TO_MASK(pin))
#define DIGITAL_WRITE_LOW(pin)  EXPAND_WRAPPER(_DIGITAL_WRITE_LOW, PIN_TO_PORT(pin), PIN_TO_MASK(pin))

#define DIGITAL_WRITE_1(pin) DIGITAL_WRITE_HIGH(pin) 
#define DIGITAL_WRITE_0(pin) DIGITAL_WRITE_LOW(pin)

#define DIGITAL_WRITE_0x1(pin) DIGITAL_WRITE_HIGH(pin) 
#define DIGITAL_WRITE_0x0(pin) DIGITAL_WRITE_LOW(pin)

#define DIGITAL_WRITE_ENABLE(pin)  DIGITAL_WRITE_HIGH(pin) 
#define DIGITAL_WRITE_DISABLE(pin) DIGITAL_WRITE_LOW(pin)

#define SET_OUTPUT(pin) EXPAND_WRAPPER(_SET_OUTPUT, PIN_TO_PORT(pin), PIN_TO_MASK(pin))
#define SET_INPUT(pin)  EXPAND_WRAPPER(_SET_INPUT, PIN_TO_PORT(pin), PIN_TO_MASK(pin))

#define pin_mode(pin, mode)  SET_##mode(pin)
#define pin_pullup(pin, val) DIGITAL_WRITE_##val(pin)

#endif /* PINS_H */
