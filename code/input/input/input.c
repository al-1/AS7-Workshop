/*
 * input.c
 *
 * Created: 20.03.2016 12:07:04
 * Author : alex
 */ 

#include <avr/io.h>


int main(void)
{
	uint8_t myInput;
	DDRD  |= (1<<DDD2);				// output pin for LED
	PORTD |= (1<<PORTD3);			// enable internal pullup
   
    while (1) 
    {
		myInput = PIND & (1<<PIND3); // read input pin and write value to variable
		if (myInput)				// input==HIGH
		{
			PORTD &= ~(1<<PORTD2);	// LED off
		}
		else
		{
			PORTD |= (1<<PORTD2);	// LED on
		}
    }
}

