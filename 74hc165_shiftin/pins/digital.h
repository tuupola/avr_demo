/*
 * digital.h
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
 * This file is part of Triple-A library:
 *   https://github.com/tuupola/triple-a
 *
 * Copyright (c) 2010-2011 Shikai Chen, Mika Tuupola
 *
 * Licensed under the LGPL 2.1 license:
 *   http://www.opensource.org/licenses/lgpl-2.1.php
 */

#ifndef DIGITAL_H
#define DIGITAL_H
#include "pins.h"

#define digital_read(pin)       EXPAND_WRAPPER(_DIGITAL_READ, PIN_TO_PORT(pin), PIN_TO_MASK(pin))
#define digital_read_raw(pin)   EXPAND_WRAPPER(_DIGITAL_READ_RAW, PIN_TO_PORT(pin), PIN_TO_MASK(pin))
#define digital_write(pin, val) DIGITAL_WRITE_##val(pin)
#define digital_toggle(pin)     EXPAND_WRAPPER(_DIGITAL_TOGGLE, PIN_TO_PORT(pin), PIN_TO_MASK(pin))

#endif /* DIGITAL_H */