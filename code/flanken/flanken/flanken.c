/*
 * flanken.c
 *
 * Created: 20.03.2016 13:21:39
 * Author : alex
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    DDRD  |= (1<<DDD2);		// PD2 output
	PORTD |= (1<<PORTD3);	// enable pullup on PD3
	
	uint8_t oldIn=1;		// variable for old input state
	uint8_t newIn;			// variable for new input state 
	uint8_t led=0;			// variable for LED state
	
    while (1) 
    {
		newIn = PIND & (1<<PIND3);	// read new input
		if (newIn && !(oldIn) )		// if newIn==1 and oldIn==0
		{
			if (led==0)					// if led is off 
			{
				led=1;
				PORTD |=(1<<PORTD2);	// led on
			}
			else
			{
				led=0;
				PORTD &= ~(1<<PORTD2);	// led off
			}
		}
		oldIn=newIn;
		_delay_ms(10);					// some delay
    }
}

