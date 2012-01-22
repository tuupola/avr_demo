/*
 * Code to read in data from two daisychained 74HC165 PISO shift registers.
 * 
 * The SN74HC165 is an 8-bit parallel-load shift register that, when clocked, 
 * shift the data toward a serial (QH) output. Parallel-in access to each 
 * stage is provided by eight individual direct data (A−H) inputs that are 
 * enabled by a low level at the shift/load (SH/LD) input. The SN74HC165 also 
 * features a clock-inhibit (CLK INH) function and a complementary serial (QH) 
 * output.
 *
 * Clocking is accomplished by a low-to-high transition of the clock (CLK) 
 * input while SH/LD is held high and CLK INH is held low. The functions of 
 * CLK and CLK  INH are interchangeable. Since a low CLK and a low-to-high 
 * transition of CLK  INH also accomplish clocking, CLK INH should be changed 
 * to the high level only while CLK is high. Parallel loading is inhibited 
 * when SH/LD is held high. While SH/LD is low, the parallel inputs to the
 * register are enabled independently of the levels of the CLK, CLK INH, or 
 * serial (SER) input
 *
 * http://www.datasheetcatalog.org/datasheet2/8/0ue9fx650zw5716zs9zch6ks5uwy.pdf
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
#include "uart/uart.h"
#include "pins/digital.h"

static void init(void) {     
}

int main(void) {    
    
    shift_in_init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    uint8_t register_value;

    while (1) {
        
        /* Read in parallel input by setting SH/LD low. */
        //digital_write(LATCH, LOW); 
        //_delay_ms(10);
        
        /* Freeze data by setting SH/LD high. When SH/LD is high data enters */
        /* to reqisters from SER input and shifts one place to the right     */
        /* (Q0 -> Q1 -> Q2, etc.) with each positive-going clock transition. */
        //digital_write(LATCH, HIGH);        

        shift_in_latch();
        
        /* Read in first 74HC165 data. */
        register_value = shift_in();        
        printf("%d \n", register_value);
        
        /* Read in second 74HC165 data. */
        register_value = shift_in();
        printf("%d \n", register_value);
        
        _delay_ms(2000);
        
    }
    return 0;
  
}
