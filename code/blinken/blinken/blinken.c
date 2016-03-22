/*
 * blinken.c
 *
 * Created: dd.mm.2016 hh:mm:ss
 * Author : AL

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
 

#define F_CPU 16000000UL		// needed for delay.h
#include <util/delay.h>			// get some delay functions
#include <avr/io.h>

//some basic blink program for PD3
int main(void)
{
DDRD |= (1<<DDD3) | (1<<DDD4) | (1<<DDD5) | (1<<DDD6);	
// PD3..PD6 are now output
	
    while (1) 
    {
		PORTD |=    (1<<PORTD3) | (1<<PORTD4);		// PD3/PD4 -> HIGH
		PORTD &= ~( (1<<PORTD5) | (1<<PORTD6) );	// PD5/PD6 -> LOW
		_delay_ms(500);								// wait for 500ms
		PORTD |=    (1<<PORTD5) | (1<<PORTD6);		// PD5/PD6 -> HIGH	
		PORTD &= ~( (1<<PORTD3) | (1<<PORTD4) );	// PD3/PD4 -> LOW	
		_delay_ms(500);								// wait for 500ms
    }
}
