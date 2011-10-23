/*
 * digital.h
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

#ifndef DIGITAL_H
#define DIGITAL_H
#include "pins.h"

#define digital_read(pin)       EXPAND_WRAPPER(_D_READ, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )
#define digital_read_raw(pin)   EXPAND_WRAPPER(_D_READ_RAW, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )
#define digital_write(pin, val) D_WRITE_##val(pin)

#endif /* DIGITAL_H */