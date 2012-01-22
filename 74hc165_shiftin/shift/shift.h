/*
 * shift.h
 *
 * This file is part of Triple-A library:
 *   https://github.com/tuupola/triple-a
 *
 * Copyright 2011-2012 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
#ifndef SHIFT_H
#define SHIFT_H

/* Configure ports here. */
#define SHIFT_IN_LATCH   B0
#define SHIFT_IN_DATA    B2
#define SHIFT_IN_CLOCK   B1

#define SHIFT_OUT_LATCH  B0
#define SHIFT_OUT_DATA   B2
#define SHIFT_OUT_CLOCK  B1

uint8_t shift_in(void);
void shift_in_latch(void);
void shift_in_init(void);
void shift_out(uint8_t data);
void shift_out_latch(void);
void shift_out_init(void);

#endif /* SHIFT_H */

