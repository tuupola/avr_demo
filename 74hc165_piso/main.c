/*
 * Code to read in 8-bit data from 74HC165 PISO shift register.
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


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/sfr_defs.h>

#include "main.h"
#include "uart.h"

#define SHLD      PORTB0 
#define CLK       PORTB4 
#define QH        PORTB5 

#define PIN_QH    PINB /* This is the only input. */
 
#define DDR_SHLD  DDRB
#define DDR_CLK   DDRB
#define DDR_QH    DDRB

#define PORT_SHLD PORTB
#define PORT_CLK  PORTB
#define PORT_QH   PORTB

void init(void) {
    
    /* Make PORTD2 (Arduino digital 2) input by clearing bit in DDR */
    //DDRD &= ~(_BV(PORTD2));

    /* In input mode, when pull-up is enabled, default state of pin becomes ’1′. So even if */
    /* you don’t connect anything to pin and if you try to read it, it will read as 1. Now, */
    /* when you externally drive that pin to zero(i.e. connect to ground / or pull-down),   */
    /* only then it will be read as 0. */

    /* Enable pullups by setting bits in PORT. Default state is now high. */
    //PORTD |= (_BV(PORTD2));
    //PORT_SHLD |= (_BV(SHLD));
    //PORT_CLK |= (_BV(CLK));
    //PORT_QH |= (_BV(QH));
    
    /* Make PORTB5 (Arduino digital 13) an output by setting bit in DDR. */
    //DDRB |= _BV(PORTB5);

    DDR_SHLD |= (_BV(SHLD));  /* Output */
    DDR_CLK |= (_BV(CLK));  /* Output */
    DDR_QH &= ~(_BV(QH)); /* Input  */

}

uint8_t digital_read(int input_register, int pin) {
    return bit_is_set(input_register, pin) != 0 ? 1 : 0;
}

/* You could use cbi ie &= ~ or sbi ie |= but this makes code more readable. */
void digital_write(volatile uint8_t *data_port, uint8_t pin, uint8_t value) {
    if (0 == value) {
        *data_port &= ~(_BV(pin));
    } else {
        *data_port |= _BV(pin);
    }
}


int main(void) {    
    
    init();
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
    uint8_t i;
    uint8_t register_value;
    uint8_t pin_value;

    while (1) {
        
        /* Read in parallel input by setting SH/LD low. */
        digital_write(&PORT_SHLD, SHLD, 0); 
        //_delay_ms(5);
        
        /* Freeze data by setting SH/LD high. When SH/LD is high data enters */
        /* to reqisters from SER input and shifts one place to the right     */
        /* (Q0 -> Q1 -> Q2, etc.) with each positive-going clock transition. */
        digital_write(&PORT_SHLD, SHLD, 1);
        
        register_value = 0;

        for(i=0; i<8; i++) {
            pin_value = digital_read(PIN_QH, QH);  
            register_value |= (pin_value << ((8 - 1) - i));          

            printf("%d = %d \n", ((8 - 1) - i), pin_value);
            
            /* Pulse clock input (CP) LOW-HIGH to read next bit. */
            digital_write(&PORT_CLK, CLK, 0);
            //_delay_ms(5);
            digital_write(&PORT_CLK, CLK, 1);
        }
        printf("%d \n", register_value);
        
        _delay_ms(2000);
        
    }
    return 0;
  
}
