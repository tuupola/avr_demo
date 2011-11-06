/*
 * Exercise on Atmel analog to digital conversion by reading the values of
 * ADXL335 accelerometer sensor. 
 * 
 * There are lot of articles on how Atmel analog to digital conversion works.
 * Most of them don't really explain anything. Code is just copied from
 * other examples. Only after reading Protostack article I could understand
 * the inner workings. Another great source of information is source code
 * of ADC driver from Atmel.
 *
 * http://www.protostack.com/blog/2011/02/analogue-to-digital-conversion-on-an-atmega168/
 * http://www.google.com/search?q=atmel+adc_drv
 *
 * General information on using ADXL335.
 * 
 * http://bildr.org/2011/04/sensing-orientation-with-the-adxl335-arduino/
 * http://www.electronicsblog.net/simple-angle-meter-using-adxl335-accelerometer-arduino/
 * http://www.sparkfun.com/datasheets/Components/SMD/adxl335.pdf
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
#include <math.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

#include "main.h"
#include "uart.h"
#include "pins.h"
#include "analog.h"

#define X   0  /* Analog 0 */
#define Y   1  /* Analog 1 */
#define Z   2  /* Analog 2 */

#define RAD_TO_DEG 57.29578

static void init(void) {    
    pin_mode(X, INPUT);
    pin_mode(Y, INPUT);
    pin_mode(Z, INPUT); 
}

int64_t map(int64_t value, int64_t in_min, int64_t in_max, int64_t out_min, int64_t out_max) {
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t main(void) {    
    
    init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    uint16_t min = 265;
    uint16_t max = 413;
    
    while (1) {
        
        uint16_t x = analog_read(X); 
        uint16_t y = analog_read(Y);
        uint16_t z = analog_read(Z);
        
        int8_t x_ang = map(x, min, max, -90, 90);
        int8_t y_ang = map(y, min, max, -90, 90);
        int8_t z_ang = map(z, min, max, -90, 90);
        
        uint16_t x_deg = RAD_TO_DEG * (atan2(-y_ang, -z_ang) + M_PI);
        uint16_t y_deg = RAD_TO_DEG * (atan2(-x_ang, -z_ang) + M_PI);
        uint16_t z_deg = RAD_TO_DEG * (atan2(-y_ang, -x_ang) + M_PI);
        
        
        printf("word: %d %d %d angle: %d %d %d degrees: %d %d %d\n", x, y, z, x_ang, y_ang, z_ang, x_deg, y_deg, z_deg);
                
        /*
        uint16_t x2 = analog_read_byte(X);
        uint16_t y2 = analog_read_byte(Y);
        uint16_t z2 = analog_read_byte(Z); 
        printf("byte: %d %d %d\n", x2, y2, z2);
        */
        
        _delay_ms(200);
        
    }
    return 0;
  
}
