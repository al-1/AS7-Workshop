#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRD   |= (1<<DDD7);				// LED pin output
	TCCR0B |= ((1<<CS02) | (1<<CS00));	// prescaler: 1024
	TIMSK0 |= (1<<TOIE0);				// enable overflow interrupt	
	sei();								// enable interrupts
	
	while (1)
	{
		;								// nothing to do (yet)
	}
}

ISR(TIMER0_OVF_vect)					// timer0 overflow interrupt service routine
{
	PORTD ^= (1<<PORTD7);	//troggel LED
}