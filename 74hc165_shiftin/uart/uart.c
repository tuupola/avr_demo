/*
 * Copyright 2011 Mika Tuupola
 *
 * This file is part of Triple-A library:
 *   https://github.com/tuupola/triple-a
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
 
#include <avr/io.h>
#include <stdio.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

#if defined (UBRR0H)

#warning UART0
#define UBRRxH UBRR0H
#define UBRRxL UBRR0L
#define UCSRxA UCSR0A
#define U2Xx   U2X0
#define UCSRxC UCSR0C
#define UCSZx1 UCSZ01
#define UCSZx0 UCSZ00
#define UCSRxB UCSR0B
#define RXENx  RXEN0
#define TXENx  TXEN0
#define UDREx  UDRE0 
#define RXCx   RXC0
#define UDRx   UDR0
#define UDRIEx UDRIE0

#elif defined (UBRR1H)

#warning UART1
#define UBRRxH UBRR1H
#define UBRRxL UBRR1L
#define UCSRxA UCSR1A
#define U2Xx   U2X1 
#define UCSRxC UCSR1C
#define UCSZx1 UCSZ11
#define UCSZx0 UCSZ10
#define UCSRxB UCSR1B
#define RXENx  RXEN1
#define TXENx  TXEN1
#define UDREx  UDRE1 
#define RXCx   RXC1
#define UDRx   UDR1
#define UDRIEx UDRIE1

#else
#error No UART?
#endif

/* http://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html */

void uart_init(void) {
    UBRRxH = UBRRH_VALUE;
    UBRRxL = UBRRL_VALUE;
    
#if USE_2X
    UCSRxA |= _BV(U2Xx);
#else
    UCSRxA &= ~(_BV(U2Xx));
#endif

    UCSRxC = _BV(UCSZx1) | _BV(UCSZx0); /* 8-bit data */ 
    UCSRxB = _BV(RXENx) | _BV(TXENx);   /* Enable RX and TX */    
}

int uart_putchar(char c, FILE *stream) {
    if (c == '\n') {
        uart_putchar('\r', stream);
    }
    loop_until_bit_is_set(UCSRxA, UDREx);
    UDRx = c;
    
    return 0;
}

int uart_getchar(FILE *stream) {
    loop_until_bit_is_set(UCSRxA, RXCx);
    return UDRx;
}
