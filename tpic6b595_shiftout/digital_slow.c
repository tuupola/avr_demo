#include <stdint.h>
#include "digital_slow.h"

const uint8_t PROGMEM portmask_at_pin[] = {
	_BV(0), /* 0, port D */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7),
	_BV(0), /* 8, port B */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(0), /* 14, port C */
	_BV(1),
	_BV(2),
	_BV(3),
	_BV(4),
	_BV(5),
	_BV(6),
	_BV(7)
};

const uint8_t PROGMEM port_at_pin[] = {
	PD, /* 0 */
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PD,
	PB, /* 8 */
	PB,
	PB,
	PB,
	PB,
	PB,
	PC, /* 14 */
	PC,
	PC,
	PC,
	PC,
	PC,
	PB, /* 20 */
	PB
};
 
const uint16_t PROGMEM output_reg_at_port[] = {
	0,
	0,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD
};




const uint16_t PROGMEM direction_reg_at_port[] = {
	0,
	0,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD
};

void pin_mode(uint8_t pin, uint8_t mode) {
    
	uint8_t port_mask = pgm_read_byte(portmask_at_pin + pin);
	uint8_t port = pgm_read_byte(port_at_pin + pin);
    
    volatile uint8_t *direction_register = pgm_read_byte(direction_reg_at_port + port);;

	if (mode == INPUT) { 
		*direction_register &= ~port_mask;
	} else {
		*direction_register |= port_mask;
	}
}

void digital_write(uint8_t pin, uint8_t value) {
	volatile uint8_t *out;

    uint8_t port_mask = pgm_read_byte(portmask_at_pin + pin);
    uint8_t port = pgm_read_byte(port_at_pin + pin);
    uint8_t *output_register = pgm_read_byte(output_reg_at_port + port);

	if (0 == value) {
		*output_register &= ~port_mask;
	} else {
		*output_register |= port_mask;
	}
}
