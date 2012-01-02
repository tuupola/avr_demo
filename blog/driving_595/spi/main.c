/*
 * Code to write data to two daisychained TPIC6B595 SIPO shift registers.
 *
 * http://appelsiini.net/2011/driving-595-shift-registers
 * 
 * The TPIC6B595 is a monolithic, high-voltage, medium-current power 8-bit 
 * shift register designed for use in systems that require relatively high 
 * load power.
 *
 * This device contains an 8-bit serial-in, parallel-out shift register that 
 * feeds an 8-bit D-type storage register. Data transfers through both the 
 * shift and storage registers on the rising edge of the shift-register clock 
 * (SRCK) and the register clock (RCK), respectively. The storage register 
 * transfers data to the output buffer when shift-register clear (SRCLR) is 
 * high. When SRCLR is low, the input shift register is cleared. When output
 * enable (G) is held high, all data in the output buffers is held low and all 
 * drain outputs are off. When G is held low, data from the storage register 
 * is transparent to the output buffers. When data in the output buffers is 
 * low, the DMOS-transistor outputs are off. When data is high, the DMOS- 
 * transistor outputs have sink-current capability. The serial output (SER 
 * OUT) allows for cascading of the data from the shift register to additional 
 * devices.
 *
 * http://www.adafruit.com/datasheets/tpic6b595.pdf
 * 
 * To compile and upload run: make clean; make; make program;
 * 
 * Copyright 2012 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#include <util/delay.h>

#include "main.h"
#include "pins/digital.h"

#define SS   B0 
#define SCLK B1 
#define MOSI B2 
#define MISO B3

void spi_init(void) {
    pin_mode(SCLK, OUTPUT);
    pin_mode(MOSI, OUTPUT);
    pin_mode(SS, OUTPUT); /* Should be output in Master mode. */
    
    SPCR &= ~(_BV(DORD)); /* MSB first. */
    SPCR |= _BV(MSTR);    /* Act as master. */
    SPCR |= _BV(SPE);     /* Enable SPI. */
}

uint8_t spi_transfer(volatile uint8_t data) {
    SPDR = data;
    loop_until_bit_is_set(SPSR, SPIF);
    return SPDR;
}

int main(void) {    
    
    spi_init();
    
    for(uint16_t i = 0; i < 0xffff; i++) {

        /* Shift high byte first to shift registers. */
        spi_transfer(i >> 8); 
        spi_transfer(i & 0xff);

        /* Pulse latch to transfer data from shift registers */
        /* to storage registers. */
        digital_write(SS, LOW); 
        digital_write(SS, HIGH);

        _delay_ms(500);
    }
    return 0;
  
}
