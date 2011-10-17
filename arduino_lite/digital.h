#ifndef DIGITAL_H
#define DIGITAL_H
#include "pins.h"

#define digital_read(pin)       EXPAND_WRAPPER(_D_READ, ARDUINOPIN_TO_PORTID(pin), ARDUINOPIN_TO_PORTMSK(pin) )
#define digital_write(pin, val) D_WRITE_##val(pin)

#endif /* DIGITAL_H */