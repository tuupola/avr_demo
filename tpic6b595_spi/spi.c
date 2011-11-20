/*
 * spi.c
 *
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#include "digital.h"
#include "spi.h"

void spi_init(void) {
    pin_mode(SPI_SCK, OUTPUT);
    pin_mode(SPI_MOSI, OUTPUT);
    pin_mode(SPI_SS, OUTPUT); /* Must be output in Master mode. */
    spi_set_msb();
    spi_set_master();
    spi_enable();
}

uint8_t spi_transfer(volatile uint8_t data) {
    SPDR = data;
    loop_until_bit_is_set(SPSR, SPIF);
    return SPDR;
}