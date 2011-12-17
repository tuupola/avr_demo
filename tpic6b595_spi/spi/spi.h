/*
 * spi.h
 *
 * http://www.atmel.com/dyn/resources/prod_documents/doc2585.pdf
 *
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */


/* http://www.atmel.com/dyn/resources/prod_documents/doc8161.pdf */
#if defined(__AVR_ATmega168__)   \
 || defined(__AVR_ATmega168P__)  \
 || defined(__AVR_ATmega328__)   \
 || defined (__AVR_ATmega328P__)
#define SPI_SS   PB2 /* Slave Select. PORTB2 LATCH RCK*/
#define SPI_SCLK PB5 /* Serial clock. PORTB5 CLOCK */
#define SPI_MOSI PB3 /* Master Out Slave In. PORTB3 DATA*/
#define SPI_MISO PB4 /* Master In Slave Out PORTB4 */

/* http://www.pjrc.com/teensy/atmega32u4.pdf */
#elif defined (__AVR_ATmega32U4__)
#define SPI_SS   B0 
#define SPI_SCLK B1 
#define SPI_MOSI B2 
#define SPI_MISO B3
#endif

#define spi_set_lsb()   SPCR |= _BV(DORD)
#define spi_set_msb()   SPCR &= ~(_BV(DORD))

#define spi_set_master()    SPCR |= _BV(MSTR)
#define spi_set_slave()     SPCR &= ~(_BV(MSTR))

#define spi_enable()    SPCR |= _BV(SPE)
#define spi_disable()   SPCR &= ~(_BV(SPE));

uint8_t spi_transfer(volatile uint8_t data);
void spi_init(void);