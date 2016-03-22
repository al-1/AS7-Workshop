/*
Copyright (c) 2016, AL
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted
provided that the following conditions are met:

1.	Redistributions of source code must retain the above copyright notice, this list of conditions
and the following disclaimer.
2.	Redistributions in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or other materials provided
with the distribution.
3. 	Neither the name of the copyright holder nor the names of its contributors may be used to
endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <math.h>

uint8_t correction(uint8_t index)
{
	float temp=index;							// now is i as float in temp
	temp = temp/99	;							// temp=i/99
	temp = pow(temp, 2.2);						// (i/99)^2,2
	temp = round(255*temp);
	
	return (uint8_t)temp;						//typecast the result
}

int main(void)
{
	uint8_t  led_value=0;						// variable for the led brightness
	int8_t   led_increment=1;
	
	DDRD   |=   (1<<DDD6);						// set OC0A pin to output
	TCCR0A |= ( (1<<WGM01) | (1<<WGM00) );		// Set Mode 3 (fast PWM)
	TCCR0A |=   (1<<COM0A1);					// OCOA non inverting PWM output
	TCCR0B |=   (1<<CS00);						// prescaler=1 / use f_CPU
	OCR0A   = 0;								// set duty cycle to 0%
	
	while(1)
	{
		OCR0A =correction(led_value);			// set PWM value
		led_value = led_value+led_increment;
		if (led_value>=99)
			led_increment=-1;
		if (led_value==0)
			led_increment=1;
			
		_delay_ms(5);	
	}
}