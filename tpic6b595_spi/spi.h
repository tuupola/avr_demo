/*
 * spi.h
 *
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

#define SPI_SS   10 /* Slave select. PORTB2 LATCH */
#define SPI_MOSI 11 /* Master out slave input. PORTB3 DATA*/
#define SPI_MISO 12 /* Master input slave output. PORTB4 */
#define SPI_SCK  13 /* Serial clock. PORTB5 CLOCK */

#define spi_set_lsb()   SPCR |= _BV(DORD)
#define spi_set_msb()   SPCR &= ~(_BV(DORD))

#define spi_set_master()    SPCR |= _BV(MSTR)
#define spi_set_slave()     SPCR &= ~(_BV(MSTR))

#define spi_enable()    SPCR |= _BV(SPE)
#define spi_disable()   SPCR &= ~(_BV(SPE));

uint8_t spi_transfer(volatile uint8_t data);
void spi_init(void);