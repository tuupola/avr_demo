#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Make PORTB5 (Arduino pin 13) an output. */
    DDRB |= _BV(PORTB5);

    for(;;){
        /* Toggle state of PORTB5 (Arduino pin 13). */
        PORTB ^= _BV(PORTB5);
        _delay_ms(500);
    }
    
    /* Never reached. */
    return 0;
}