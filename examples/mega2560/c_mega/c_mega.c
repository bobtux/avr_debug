/*
 * main.c
 *
 *
 *  Example for debugging with avr8-stub.c in plain C language,
 *  without Arduino libraries.
 *  For instructions on use please see doc\avr_debug.pdf
 *
 *  Author: Jan Dolinay
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "avr8-stub.h"

/* pin PB7 is the onboard LED on Arduino Mega (Arduino pin 13) */
#define	LED_PIN	(7)

uint16_t cnt = 0;
uint16_t result;
uint16_t function(uint16_t a);

int main(void)
{
    debug_init();
    DDRB |= _BV(LED_PIN);
    sei();			/* enable interrupts */
    breakpoint();
    while(1)
    {
    	PORTB |= _BV(LED_PIN);	/* LED on */
    	cnt++;
    	result = function(cnt);
    	PORTB &= ~_BV(LED_PIN);	/* LED off */
    	result++;
    }
    return 0;
}

uint16_t function(uint16_t a)
{
	uint16_t n;
	n = 2*a;
	return n;
}




