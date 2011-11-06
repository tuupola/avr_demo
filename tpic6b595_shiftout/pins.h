/*
 * pins.h
 *
 * Lightweight macro implementation of Arduino style pin numbering
 * for AVR microprocessors. Because only thing I want to use from
 * Arduino libraries is the pin numbering scheme.
 * 
 * This file taken 99% from the excellent ArduinoLite project by 
 * Shikai Chen <csk@live.com>. Some minor changes to suite my personal 
 * coding taste.
 *
 *   http://code.google.com/p/arduino-lite/
 *   http://www.csksoft.net/
 *
 * Copyright (c) 2010-2011 Shikai Chen
 *
 * Licensed under the LGPL 2.1 license:
 *   http://www.opensource.org/licenses/lgpl-2.1.php
 */

#ifndef PINS_H
#define PINS_H

#include <avr/sfr_defs.h>
#include <avr/io.h>

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define ENABLE 0x1
#define DISABLE 0x0

#define ARDUINOPIN_TO_TIMERID(x) TIMER_AT_PIN_##x
#define ARDUINOPIN_TO_TCCRID(x) TCCR_AT_PIN_##x

#define ARDUINOPIN_TO_PORTID(x) PORT_AT_PIN_##x
#define ARDUINOPIN_TO_PORTMSK(x) PORTMSK_AT_PIN_##x

#define PORTID_TO_DIR_REG(x) DIR_REG_AT_##x
#define PORTID_TO_OUTPUT_REG(x) OUTPUT_REG_AT_##x
#define PORTID_TO_INPUT_REG(x) INPUT_REG_AT_##x

#if defined(__AVR_ATmega1280__)

#define PORT_AT_PIN_0       PortE   // PE 0 ** 0 ** USART0_RX 
#define PORT_AT_PIN_1       PortE   // PE 1 ** 1 ** USART0_TX 
#define PORT_AT_PIN_2       PortE   // PE 4 ** 2 ** PWM2 
#define PORT_AT_PIN_3       PortE   // PE 5 ** 3 ** PWM3 
#define PORT_AT_PIN_4       PortG   // PG 5 ** 4 ** PWM4 
#define PORT_AT_PIN_5       PortE   // PE 3 ** 5 ** PWM5 
#define PORT_AT_PIN_6       PortH   // PH 3 ** 6 ** PWM6 
#define PORT_AT_PIN_7       PortH   // PH 4 ** 7 ** PWM7 
#define PORT_AT_PIN_8       PortH   // PH 5 ** 8 ** PWM8 
#define PORT_AT_PIN_9       PortH   // PH 6 ** 9 ** PWM9 
#define PORT_AT_PIN_10      PortB   // PB 4 ** 10 ** PWM10 
#define PORT_AT_PIN_11      PortB   // PB 5 ** 11 ** PWM11 
#define PORT_AT_PIN_12      PortB   // PB 6 ** 12 ** PWM12 
#define PORT_AT_PIN_13      PortB   // PB 7 ** 13 ** PWM13 
#define PORT_AT_PIN_14      PortJ   // PJ 1 ** 14 ** USART3_TX 
#define PORT_AT_PIN_15      PortJ   // PJ 0 ** 15 ** USART3_RX 
#define PORT_AT_PIN_16      PortH   // PH 1 ** 16 ** USART2_TX 
#define PORT_AT_PIN_17      PortH   // PH 0 ** 17 ** USART2_RX 
#define PORT_AT_PIN_18      PortD   // PD 3 ** 18 ** USART1_TX 
#define PORT_AT_PIN_19      PortD   // PD 2 ** 19 ** USART1_RX 
#define PORT_AT_PIN_20      PortD   // PD 1 ** 20 ** I2C_SDA 
#define PORT_AT_PIN_21      PortD   // PD 0 ** 21 ** I2C_SCL 
#define PORT_AT_PIN_22      PortA   // PA 0 ** 22 ** D22 
#define PORT_AT_PIN_23      PortA   // PA 1 ** 23 ** D23 
#define PORT_AT_PIN_24      PortA   // PA 2 ** 24 ** D24 
#define PORT_AT_PIN_25      PortA   // PA 3 ** 25 ** D25 
#define PORT_AT_PIN_26      PortA   // PA 4 ** 26 ** D26 
#define PORT_AT_PIN_27      PortA   // PA 5 ** 27 ** D27 
#define PORT_AT_PIN_28      PortA   // PA 6 ** 28 ** D28 
#define PORT_AT_PIN_29      PortA   // PA 7 ** 29 ** D29 
#define PORT_AT_PIN_30      PortC   // PC 7 ** 30 ** D30 
#define PORT_AT_PIN_31      PortC   // PC 6 ** 31 ** D31 
#define PORT_AT_PIN_32      PortC   // PC 5 ** 32 ** D32 
#define PORT_AT_PIN_33      PortC   // PC 4 ** 33 ** D33 
#define PORT_AT_PIN_34      PortC   // PC 3 ** 34 ** D34 
#define PORT_AT_PIN_35      PortC   // PC 2 ** 35 ** D35 
#define PORT_AT_PIN_36      PortC   // PC 1 ** 36 ** D36 
#define PORT_AT_PIN_37      PortC   // PC 0 ** 37 ** D37 
#define PORT_AT_PIN_38      PortD   // PD 7 ** 38 ** D38 
#define PORT_AT_PIN_39      PortG   // PG 2 ** 39 ** D39 
#define PORT_AT_PIN_40      PortG   // PG 1 ** 40 ** D40 
#define PORT_AT_PIN_41      PortG   // PG 0 ** 41 ** D41 
#define PORT_AT_PIN_42      PortL   // PL 7 ** 42 ** D42 
#define PORT_AT_PIN_43      PortL   // PL 6 ** 43 ** D43 
#define PORT_AT_PIN_44      PortL   // PL 5 ** 44 ** D44 
#define PORT_AT_PIN_45      PortL   // PL 4 ** 45 ** D45 
#define PORT_AT_PIN_46      PortL   // PL 3 ** 46 ** D46 
#define PORT_AT_PIN_47      PortL   // PL 2 ** 47 ** D47 
#define PORT_AT_PIN_48      PortL   // PL 1 ** 48 ** D48 
#define PORT_AT_PIN_49      PortL   // PL 0 ** 49 ** D49 
#define PORT_AT_PIN_50      PortB   // PB 3 ** 50 ** SPI_MISO 
#define PORT_AT_PIN_51      PortB   // PB 2 ** 51 ** SPI_MOSI 
#define PORT_AT_PIN_52      PortB   // PB 1 ** 52 ** SPI_SCK 
#define PORT_AT_PIN_53      PortB   // PB 0 ** 53 ** SPI_SS 
#define PORT_AT_PIN_54      PortF   // PF 0 ** 54 ** A0 
#define PORT_AT_PIN_55      PortF   // PF 1 ** 55 ** A1 
#define PORT_AT_PIN_56      PortF   // PF 2 ** 56 ** A2 
#define PORT_AT_PIN_57      PortF   // PF 3 ** 57 ** A3 
#define PORT_AT_PIN_58      PortF   // PF 4 ** 58 ** A4 
#define PORT_AT_PIN_59      PortF   // PF 5 ** 59 ** A5 
#define PORT_AT_PIN_60      PortF   // PF 6 ** 60 ** A6 
#define PORT_AT_PIN_61      PortF   // PF 7 ** 61 ** A7 
#define PORT_AT_PIN_62      PortK   // PK 0 ** 62 ** A8 
#define PORT_AT_PIN_63      PortK   // PK 1 ** 63 ** A9 
#define PORT_AT_PIN_64      PortK   // PK 2 ** 64 ** A10 
#define PORT_AT_PIN_65      PortK   // PK 3 ** 65 ** A11 
#define PORT_AT_PIN_66      PortK   // PK 4 ** 66 ** A12 
#define PORT_AT_PIN_67      PortK   // PK 5 ** 67 ** A13 
#define PORT_AT_PIN_68      PortK   // PK 6 ** 68 ** A14 
#define PORT_AT_PIN_69      PortK   // PK 7 ** 69 ** A15

#define PORTMSK_AT_PIN_0     _BV( 0 )   // PE 0 ** 0 ** USART0_RX 
#define PORTMSK_AT_PIN_1     _BV( 1 )   // PE 1 ** 1 ** USART0_TX 
#define PORTMSK_AT_PIN_2     _BV( 4 )   // PE 4 ** 2 ** PWM2 
#define PORTMSK_AT_PIN_3     _BV( 5 )   // PE 5 ** 3 ** PWM3 
#define PORTMSK_AT_PIN_4     _BV( 5 )   // PG 5 ** 4 ** PWM4 
#define PORTMSK_AT_PIN_5     _BV( 3 )   // PE 3 ** 5 ** PWM5 
#define PORTMSK_AT_PIN_6     _BV( 3 )   // PH 3 ** 6 ** PWM6 
#define PORTMSK_AT_PIN_7     _BV( 4 )   // PH 4 ** 7 ** PWM7 
#define PORTMSK_AT_PIN_8     _BV( 5 )   // PH 5 ** 8 ** PWM8 
#define PORTMSK_AT_PIN_9     _BV( 6 )   // PH 6 ** 9 ** PWM9 
#define PORTMSK_AT_PIN_10    _BV( 4 )   // PB 4 ** 10 ** PWM10 
#define PORTMSK_AT_PIN_11    _BV( 5 )   // PB 5 ** 11 ** PWM11 
#define PORTMSK_AT_PIN_12    _BV( 6 )   // PB 6 ** 12 ** PWM12 
#define PORTMSK_AT_PIN_13    _BV( 7 )   // PB 7 ** 13 ** PWM13 
#define PORTMSK_AT_PIN_14    _BV( 1 )   // PJ 1 ** 14 ** USART3_TX 
#define PORTMSK_AT_PIN_15    _BV( 0 )   // PJ 0 ** 15 ** USART3_RX 
#define PORTMSK_AT_PIN_16    _BV( 1 )   // PH 1 ** 16 ** USART2_TX 
#define PORTMSK_AT_PIN_17    _BV( 0 )   // PH 0 ** 17 ** USART2_RX 
#define PORTMSK_AT_PIN_18    _BV( 3 )   // PD 3 ** 18 ** USART1_TX 
#define PORTMSK_AT_PIN_19    _BV( 2 )   // PD 2 ** 19 ** USART1_RX 
#define PORTMSK_AT_PIN_20    _BV( 1 )   // PD 1 ** 20 ** I2C_SDA 
#define PORTMSK_AT_PIN_21    _BV( 0 )   // PD 0 ** 21 ** I2C_SCL 
#define PORTMSK_AT_PIN_22    _BV( 0 )   // PA 0 ** 22 ** D22 
#define PORTMSK_AT_PIN_23    _BV( 1 )   // PA 1 ** 23 ** D23 
#define PORTMSK_AT_PIN_24    _BV( 2 )   // PA 2 ** 24 ** D24 
#define PORTMSK_AT_PIN_25    _BV( 3 )   // PA 3 ** 25 ** D25 
#define PORTMSK_AT_PIN_26    _BV( 4 )   // PA 4 ** 26 ** D26 
#define PORTMSK_AT_PIN_27    _BV( 5 )   // PA 5 ** 27 ** D27 
#define PORTMSK_AT_PIN_28    _BV( 6 )   // PA 6 ** 28 ** D28 
#define PORTMSK_AT_PIN_29    _BV( 7 )   // PA 7 ** 29 ** D29 
#define PORTMSK_AT_PIN_30    _BV( 7 )   // PC 7 ** 30 ** D30 
#define PORTMSK_AT_PIN_31    _BV( 6 )   // PC 6 ** 31 ** D31 
#define PORTMSK_AT_PIN_32    _BV( 5 )   // PC 5 ** 32 ** D32 
#define PORTMSK_AT_PIN_33    _BV( 4 )   // PC 4 ** 33 ** D33 
#define PORTMSK_AT_PIN_34    _BV( 3 )   // PC 3 ** 34 ** D34 
#define PORTMSK_AT_PIN_35    _BV( 2 )   // PC 2 ** 35 ** D35 
#define PORTMSK_AT_PIN_36    _BV( 1 )   // PC 1 ** 36 ** D36 
#define PORTMSK_AT_PIN_37    _BV( 0 )   // PC 0 ** 37 ** D37 
#define PORTMSK_AT_PIN_38    _BV( 7 )   // PD 7 ** 38 ** D38 
#define PORTMSK_AT_PIN_39    _BV( 2 )   // PG 2 ** 39 ** D39 
#define PORTMSK_AT_PIN_40    _BV( 1 )   // PG 1 ** 40 ** D40 
#define PORTMSK_AT_PIN_41    _BV( 0 )   // PG 0 ** 41 ** D41 
#define PORTMSK_AT_PIN_42    _BV( 7 )   // PL 7 ** 42 ** D42 
#define PORTMSK_AT_PIN_43    _BV( 6 )   // PL 6 ** 43 ** D43 
#define PORTMSK_AT_PIN_44    _BV( 5 )   // PL 5 ** 44 ** D44 
#define PORTMSK_AT_PIN_45    _BV( 4 )   // PL 4 ** 45 ** D45 
#define PORTMSK_AT_PIN_46    _BV( 3 )   // PL 3 ** 46 ** D46 
#define PORTMSK_AT_PIN_47    _BV( 2 )   // PL 2 ** 47 ** D47 
#define PORTMSK_AT_PIN_48    _BV( 1 )   // PL 1 ** 48 ** D48 
#define PORTMSK_AT_PIN_49    _BV( 0 )   // PL 0 ** 49 ** D49 
#define PORTMSK_AT_PIN_50    _BV( 3 )   // PB 3 ** 50 ** SPI_MISO 
#define PORTMSK_AT_PIN_51    _BV( 2 )   // PB 2 ** 51 ** SPI_MOSI 
#define PORTMSK_AT_PIN_52    _BV( 1 )   // PB 1 ** 52 ** SPI_SCK 
#define PORTMSK_AT_PIN_53    _BV( 0 )   // PB 0 ** 53 ** SPI_SS 
#define PORTMSK_AT_PIN_54    _BV( 0 )   // PF 0 ** 54 ** A0 
#define PORTMSK_AT_PIN_55    _BV( 1 )   // PF 1 ** 55 ** A1 
#define PORTMSK_AT_PIN_56    _BV( 2 )   // PF 2 ** 56 ** A2 
#define PORTMSK_AT_PIN_57    _BV( 3 )   // PF 3 ** 57 ** A3 
#define PORTMSK_AT_PIN_58    _BV( 4 )   // PF 4 ** 58 ** A4 
#define PORTMSK_AT_PIN_59    _BV( 5 )   // PF 5 ** 59 ** A5 
#define PORTMSK_AT_PIN_60    _BV( 6 )   // PF 6 ** 60 ** A6 
#define PORTMSK_AT_PIN_61    _BV( 7 )   // PF 7 ** 61 ** A7 
#define PORTMSK_AT_PIN_62    _BV( 0 )   // PK 0 ** 62 ** A8 
#define PORTMSK_AT_PIN_63    _BV( 1 )   // PK 1 ** 63 ** A9 
#define PORTMSK_AT_PIN_64    _BV( 2 )   // PK 2 ** 64 ** A10 
#define PORTMSK_AT_PIN_65    _BV( 3 )   // PK 3 ** 65 ** A11 
#define PORTMSK_AT_PIN_66    _BV( 4 )   // PK 4 ** 66 ** A12 
#define PORTMSK_AT_PIN_67    _BV( 5 )   // PK 5 ** 67 ** A13 
#define PORTMSK_AT_PIN_68    _BV( 6 )   // PK 6 ** 68 ** A14 
#define PORTMSK_AT_PIN_69    _BV( 7 )   // PK 7 ** 69 ** A15 

////////////Arduino pin to Timer Regs mapping
#define TIMER_AT_PIN_2   3B
#define TCCR_AT_PIN_2    TCCR3A

#define TIMER_AT_PIN_3   3C
#define TCCR_AT_PIN_3    TCCR3A

#define TIMER_AT_PIN_4   0B
#define TCCR_AT_PIN_4    TCCR0A

#define TIMER_AT_PIN_5   3A 
#define TCCR_AT_PIN_5    TCCR3A

#define TIMER_AT_PIN_6   4A 
#define TCCR_AT_PIN_6    TCCR4A

#define TIMER_AT_PIN_7   4B
#define TCCR_AT_PIN_7    TCCR4A

#define TIMER_AT_PIN_8   4C
#define TCCR_AT_PIN_8    TCCR4A

#define TIMER_AT_PIN_9   2B
#define TCCR_AT_PIN_9    TCCR2A

#define TIMER_AT_PIN_10  2A
#define TCCR_AT_PIN_10   TCCR2A

#define TIMER_AT_PIN_11  1A
#define TCCR_AT_PIN_11   TCCR1A

#define TIMER_AT_PIN_12  1B
#define TCCR_AT_PIN_12   TCCR1A

#define TIMER_AT_PIN_13  0A
#define TCCR_AT_PIN_13   TCCR0A

#define TIMER_AT_PIN_44  5C
#define TCCR_AT_PIN_44   TCCR5A

#define TIMER_AT_PIN_45  5B
#define TCCR_AT_PIN_45   TCCR5A

#define TIMER_AT_PIN_46  5A
#define TCCR_AT_PIN_46   TCCR5A


////////////PORT to DDRX mapping
#define DIR_REG_AT_PortA DDRA
#define DIR_REG_AT_PortB DDRB
#define DIR_REG_AT_PortC DDRC
#define DIR_REG_AT_PortD DDRD
#define DIR_REG_AT_PortE DDRE
#define DIR_REG_AT_PortF DDRF
#define DIR_REG_AT_PortG DDRG
#define DIR_REG_AT_PortH DDRH

#define DIR_REG_AT_PortJ DDRJ
#define DIR_REG_AT_PortK DDRK
#define DIR_REG_AT_PortL DDRL

////////////PORT to PORTX mapping
#define OUTPUT_REG_AT_PortA PORTA
#define OUTPUT_REG_AT_PortB PORTB
#define OUTPUT_REG_AT_PortC PORTC
#define OUTPUT_REG_AT_PortD PORTD
#define OUTPUT_REG_AT_PortE PORTE
#define OUTPUT_REG_AT_PortF PORTF
#define OUTPUT_REG_AT_PortG PORTG
#define OUTPUT_REG_AT_PortH PORTH

#define OUTPUT_REG_AT_PortJ PORTJ
#define OUTPUT_REG_AT_PortK PORTK
#define OUTPUT_REG_AT_PortL PORTL

////////////PORT to PINX(input regs) mapping
#define INPUT_REG_AT_PortA PINA
#define INPUT_REG_AT_PortB PINB
#define INPUT_REG_AT_PortC PINC
#define INPUT_REG_AT_PortD PIND
#define INPUT_REG_AT_PortE PINE
#define INPUT_REG_AT_PortF PINF
#define INPUT_REG_AT_PortG PING
#define INPUT_REG_AT_PortH PINH

#define INPUT_REG_AT_PortJ PINJ
#define INPUT_REG_AT_PortK PINK
#define INPUT_REG_AT_PortL PINL

#else            /* not __AVR_ATmega1280__ */

#if defined(__AVR_ATtiny2313__)  
//no PortC on tiny2313
//Pin[0-6] -> PortD[0-6]
#define PORT_AT_PIN_0         PortD  /* 0 */
#define PORT_AT_PIN_1         PortD 
#define PORT_AT_PIN_2         PortD 
#define PORT_AT_PIN_3         PortD 
#define PORT_AT_PIN_4         PortD 
#define PORT_AT_PIN_5         PortD 
#define PORT_AT_PIN_6         PortD  

//Pin[7-14] -> PortB[0-7]
#define PORT_AT_PIN_7         PortB 
#define PORT_AT_PIN_8         PortB  /* 8 */
#define PORT_AT_PIN_9         PortB 
#define PORT_AT_PIN_10        PortB 
#define PORT_AT_PIN_11        PortB 
#define PORT_AT_PIN_12        PortB 
#define PORT_AT_PIN_13        PortB 
#define PORT_AT_PIN_14        PortB 

#elif  defined(__AVR_ATtiny26__)

//Pin[0-6] -> PortD[0-6]
#define PORT_AT_PIN_0         PortB  /* 0 */
#define PORT_AT_PIN_1         PortB 
#define PORT_AT_PIN_2         PortB 
#define PORT_AT_PIN_3         PortB 
#define PORT_AT_PIN_4         PortB 
#define PORT_AT_PIN_5         PortB 
#define PORT_AT_PIN_6         PortB  


//D[7-13] and A[0-9] share the same pins on Attiny26
#define PORT_AT_PIN_7         PortA  /* 0 */
#define PORT_AT_PIN_8         PortA 
#define PORT_AT_PIN_9         PortA 
#define PORT_AT_PIN_10        PortA 
#define PORT_AT_PIN_11        PortA 
#define PORT_AT_PIN_12        PortA 
#define PORT_AT_PIN_13        PortA

#else // Atmega8 / Atmegax8
#define PORT_AT_PIN_0         PortD  /* 0 */
#define PORT_AT_PIN_1         PortD 
#define PORT_AT_PIN_2         PortD 
#define PORT_AT_PIN_3         PortD 
#define PORT_AT_PIN_4         PortD 
#define PORT_AT_PIN_5         PortD 
#define PORT_AT_PIN_6         PortD 
#define PORT_AT_PIN_7         PortD 
#define PORT_AT_PIN_8         PortB  /* 8 */
#define PORT_AT_PIN_9         PortB 
#define PORT_AT_PIN_10        PortB 
#define PORT_AT_PIN_11        PortB 
#define PORT_AT_PIN_12        PortB 
#define PORT_AT_PIN_13        PortB 
#define PORT_AT_PIN_14        PortC  /* 14 */
#define PORT_AT_PIN_15        PortC 
#define PORT_AT_PIN_16        PortC 
#define PORT_AT_PIN_17        PortC 
#define PORT_AT_PIN_18        PortC 
#define PORT_AT_PIN_19        PortC 

#define PORT_AT_PIN_20        PortB
#define PORT_AT_PIN_21        PortB 
#endif


#if defined(__AVR_ATtiny2313__)  
#define PORTMSK_AT_PIN_0      _BV(0)  
#define PORTMSK_AT_PIN_1      _BV(1) 
#define PORTMSK_AT_PIN_2      _BV(2) 
#define PORTMSK_AT_PIN_3      _BV(3) 
#define PORTMSK_AT_PIN_4      _BV(4) 
#define PORTMSK_AT_PIN_5      _BV(5) 
#define PORTMSK_AT_PIN_6      _BV(6) 
#define PORTMSK_AT_PIN_7      _BV(0) 
#define PORTMSK_AT_PIN_8      _BV(1)  
#define PORTMSK_AT_PIN_9      _BV(2) 
#define PORTMSK_AT_PIN_10     _BV(3) 
#define PORTMSK_AT_PIN_11     _BV(4) 
#define PORTMSK_AT_PIN_12     _BV(5) 
#define PORTMSK_AT_PIN_13     _BV(6) 
#define PORTMSK_AT_PIN_14     _BV(7)

#elif  defined(__AVR_ATtiny26__)

#define PORTMSK_AT_PIN_0      _BV(0)  
#define PORTMSK_AT_PIN_1      _BV(1) 
#define PORTMSK_AT_PIN_2      _BV(2) 
#define PORTMSK_AT_PIN_3      _BV(3) 
#define PORTMSK_AT_PIN_4      _BV(4) 
#define PORTMSK_AT_PIN_5      _BV(5) 
#define PORTMSK_AT_PIN_6      _BV(6) 
#define PORTMSK_AT_PIN_7      _BV(0) 
#define PORTMSK_AT_PIN_8      _BV(1)  
#define PORTMSK_AT_PIN_9      _BV(2) 
#define PORTMSK_AT_PIN_10     _BV(3) 
#define PORTMSK_AT_PIN_11     _BV(4) 
#define PORTMSK_AT_PIN_12     _BV(5) 
#define PORTMSK_AT_PIN_13     _BV(6) 

#else //Atmega8/ Atmegax8
#define PORTMSK_AT_PIN_0      _BV(0)  /* 0  port D */
#define PORTMSK_AT_PIN_1      _BV(1) 
#define PORTMSK_AT_PIN_2      _BV(2) 
#define PORTMSK_AT_PIN_3      _BV(3) 
#define PORTMSK_AT_PIN_4      _BV(4) 
#define PORTMSK_AT_PIN_5      _BV(5) 
#define PORTMSK_AT_PIN_6      _BV(6) 
#define PORTMSK_AT_PIN_7      _BV(7) 
#define PORTMSK_AT_PIN_8      _BV(0)  /* 8  port B */
#define PORTMSK_AT_PIN_9      _BV(1) 
#define PORTMSK_AT_PIN_10     _BV(2) 
#define PORTMSK_AT_PIN_11     _BV(3) 
#define PORTMSK_AT_PIN_12     _BV(4) 
#define PORTMSK_AT_PIN_13     _BV(5) 
#define PORTMSK_AT_PIN_14     _BV(0)  /* 14  port C */
#define PORTMSK_AT_PIN_15     _BV(1) 
#define PORTMSK_AT_PIN_16     _BV(2) 
#define PORTMSK_AT_PIN_17     _BV(3) 
#define PORTMSK_AT_PIN_18     _BV(4) 
#define PORTMSK_AT_PIN_19     _BV(5) 

#define PORTMSK_AT_PIN_20     _BV(6) 
#define PORTMSK_AT_PIN_21     _BV(7) 
#endif 
////////////PORT to DDRX mapping
#define DIR_REG_AT_PortA DDRA

#define DIR_REG_AT_PortB DDRB

#if defined(__AVR_ATtiny2313__)  
//no PortC on tiny2313
#else
#define DIR_REG_AT_PortC DDRC
#endif

#define DIR_REG_AT_PortD DDRD

////////////PORT to PORTX mapping
#define OUTPUT_REG_AT_PortA PORTA
#define OUTPUT_REG_AT_PortB PORTB

#if defined(__AVR_ATtiny2313__)  
//no PortC on tiny2313
#else
#define OUTPUT_REG_AT_PortC PORTC
#endif

#define OUTPUT_REG_AT_PortD PORTD

////////////PORT to PINX(input regs) mapping
#define INPUT_REG_AT_PortA PINA

#define INPUT_REG_AT_PortB PINB

#if defined(__AVR_ATtiny2313__)  
//no PortC on tiny2313
#else
#define INPUT_REG_AT_PortC PINC
#endif

#define INPUT_REG_AT_PortD PIND


#if defined(__AVR_ATtiny2313__) 

#define TIMER_AT_PIN_5   0B
#define TCCR_AT_PIN_5    TCCR0A

#define TIMER_AT_PIN_9   0A
#define TCCR_AT_PIN_9    TCCR0A

#define TIMER_AT_PIN_10  1A
#define TCCR_AT_PIN_10   TCCR1A

#define TIMER_AT_PIN_11  1B
#define TCCR_AT_PIN_11   TCCR1A

#elif  defined(__AVR_ATtiny26__)
/*
#define TIMER_AT_PIN_0   1A
#define TCCR_AT_PIN_0    TCCR1A
*/
#define TIMER_AT_PIN_1   1A
#define TCCR_AT_PIN_1    TCCR1A
/*
#define TIMER_AT_PIN_2   1B
#define TCCR_AT_PIN_2    TCCR1A
*/
#define TIMER_AT_PIN_3   1B
#define TCCR_AT_PIN_3    TCCR1A

#else

#if !defined(__AVR_ATmega8__)    //for Atmega48/88/168/328
#define TIMER_AT_PIN_3   2B
#define TCCR_AT_PIN_3    TCCR2A

#define TIMER_AT_PIN_5   0B
#define TCCR_AT_PIN_5    TCCR0A

#define TIMER_AT_PIN_6   0A
#define TCCR_AT_PIN_6    TCCR0A
#endif

#define TIMER_AT_PIN_9   1A
#define TCCR_AT_PIN_9    TCCR1A

#define TIMER_AT_PIN_10  1B
#define TCCR_AT_PIN_10   TCCR1A

#if defined(__AVR_ATmega8__)    
#define TIMER_AT_PIN_11  2
#define TCCR_AT_PIN_11   TCCR2
#else                            //for Atmega48/88/168/328
#define TIMER_AT_PIN_11  2A
#define TCCR_AT_PIN_11   TCCR2A
#endif

#endif

#endif          



#define MERGE_TO_FUNC(prefix, id)   prefix##_##id
#define EXPAND_WRAPPER( NEXTLEVEL, ...)  NEXTLEVEL( __VA_ARGS__ )



#define _PWM_SET(id, val)   \
    do{                     \
        OCR##id = val;      \
    }                       \
    while(0)            

#define _PWM_ENABLE(TCCR, id)  sbi(TCCR, COM##id##1)
#define _PWM_DISABLE(TCCR, id) cbi(TCCR, COM##id##1)

#define _SET_OUTPUT(port_id, msk)  PORTID_TO_DIR_REG(port_id) |= (msk)
#define _SET_INTPUT(port_id, msk)  PORTID_TO_DIR_REG(port_id) &= ~(msk)

#define _D_WRITE_HIGH(port_id, msk) PORTID_TO_OUTPUT_REG(port_id) |= (msk)
#define _D_WRITE_LOW(port_id, msk)  PORTID_TO_OUTPUT_REG(port_id) &= ~(msk)

#define _D_READ_RAW(port_id, msk)   ((PORTID_TO_INPUT_REG(port_id)) & (msk))
#define _D_READ(port_id, msk)       (((PORTID_TO_INPUT_REG(port_id)) & (msk)) != 0 ? 1 : 0)

#define _D_TOGGLE(port_id, msk)   PORTID_TO_OUTPUT_REG(port_id) ^= (msk)
/*
 *
 *  NOTICE: for pins at timer0A/0B, 
 *          if the duty cycle to be set equals to zero, using the following code:
 *            DIGITAL_WRITE(pin, LOW);
 *             -- or --
 *            digitalWrite(pin, LOW);
 *  The caller should make sure the current pin has been set to OUTPUT mode first
 */

#define SET_1(pin)              SET_OUTPUT(pin)
#define SET_0(pin)              SET_INPUT(pin)

#define SET_0x1(pin)            SET_OUTPUT(pin)
#define SET_0x0(pin)            SET_INPUT(pin)

#define D_WRITE_HIGH(pin)       EXPAND_WRAPPER(_D_WRITE_HIGH, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )
#define D_WRITE_LOW(pin)        EXPAND_WRAPPER(_D_WRITE_LOW, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )

#define D_WRITE_1(pin)          D_WRITE_HIGH(pin) 
#define D_WRITE_0(pin)          D_WRITE_LOW(pin)

#define D_WRITE_0x1(pin)        D_WRITE_HIGH(pin) 
#define D_WRITE_0x0(pin)        D_WRITE_LOW(pin)

#define D_WRITE_ENABLE(pin)     D_WRITE_HIGH(pin) 
#define D_WRITE_DISABLE(pin)    D_WRITE_LOW(pin)

#define SET_OUTPUT(pin)         EXPAND_WRAPPER(_SET_OUTPUT, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )
#define SET_INPUT(pin)          EXPAND_WRAPPER(_SET_INTPUT, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )

#define pin_mode(pin, mode)     SET_##mode(pin)
#define pin_pullup(pin, val)    D_WRITE_##val(pin)
#define pin_toggle(pin)         EXPAND_WRAPPER(_D_TOGGLE, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )


#endif /* PINS_H */
