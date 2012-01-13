/*
 * Copyright 2011 Mika Tuupola
 *
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */

/* Based on Atmel Application Note AVR 306 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE 64
#endif

#ifndef UART_TX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE 64
#endif

#if defined (UBRR0H)

#warning Using UART0
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

#define USARTx_RX_vect   USART_RX_vect
#define USARTx_UDRE_vect USART_UDRE_vect
#elif defined (UBRR1H)

#warning Using UART1
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

#define USARTx_RX_vect   USART1_RX_vect
#define USARTx_UDRE_vect USART1_UDRE_vect

#else
#error No UART?
#endif

struct tx_ring {
    int buffer[UART_TX_BUFFER_SIZE];
    int start;
    int end;
};

struct rx_ring {
    int buffer[UART_RX_BUFFER_SIZE];
    int start;
    int end;
};

static struct tx_ring tx_buffer;
static struct rx_ring rx_buffer;

/* http://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html */

void uart_init(void) {
    
    tx_buffer.start = 0;
    tx_buffer.end   = 0;

    rx_buffer.start = 0;
    rx_buffer.end   = 0;
    
    UBRRxH = UBRRH_VALUE;
    UBRRxL = UBRRL_VALUE;

    UCSRxC = _BV(UCSZx1) | _BV(UCSZx0); /* 8-bit data */ 
    UCSRxB = _BV(RXENx) | _BV(TXENx);   /* Enable RX and TX */  
    
    sei();  
}

int uart_putchar(char c, FILE *stream) {
    if (c == '\n') {
        uart_putchar('\r', stream);
    }
    
    int write_pointer = (tx_buffer.end + 1) % UART_TX_BUFFER_SIZE;
    
    if (write_pointer != tx_buffer.start){
        tx_buffer.buffer[tx_buffer.end] = c;
        tx_buffer.end = write_pointer;
        
        /* Data available. Enable the transmit interrupt for serial port 0. */
        UCSRxB |= _BV(UDRIEx);  
    }
    
    return 0;
}

int uart_getchar(FILE *stream) {
    int read_pointer = (rx_buffer.start + 1) % UART_RX_BUFFER_SIZE;
    
    rx_buffer.start = read_pointer;
    return rx_buffer.buffer[read_pointer];
}

ISR(USARTx_RX_vect) {
    int write_pointer = (rx_buffer.end + 1) % UART_RX_BUFFER_SIZE;

    /* Add next byte to ringbuffer if it has space available. */
    if (write_pointer != rx_buffer.start){
        rx_buffer.buffer[rx_buffer.end] = UDRx;
        rx_buffer.end = write_pointer;
    }
}

ISR(USARTx_UDRE_vect){
    int read_pointer = (tx_buffer.start + 1) % UART_TX_BUFFER_SIZE;
    
    /* Transmit next byte if data available in ringbuffer. */
    if (read_pointer != tx_buffer.end) {
        UDRx = tx_buffer.buffer[read_pointer];
        tx_buffer.start = read_pointer;
    } else {
        /* Nothing to send. Disable the transmit interrupt for serial port x. */
        UCSRxB &= ~_BV(UDRIEx);
    }
}


