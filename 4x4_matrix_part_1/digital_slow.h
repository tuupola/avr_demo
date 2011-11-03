#ifndef DIGITAL_SLOW_H
#define DIGITAL_SLOW_H
#include <avr/pgmspace.h>

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1

#define PB 2
#define PC 3
#define PD 4

extern const uint8_t PROGMEM portmask_at_pin[];
extern const uint8_t PROGMEM port_at_pin[];
extern const uint16_t PROGMEM output_reg_at_port[];
extern const uint16_t PROGMEM direction_reg_at_port[];

void pin_mode(uint8_t pin, uint8_t mode);
void digital_write(uint8_t pin, uint8_t value);

#endif /* DIGITAL_SLOW_H */
