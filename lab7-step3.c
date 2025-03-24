/*
 * lab7-step3.c
 *
 * Created: 3/24/2025 1:19:05 PM
 * Author: Alexander D'Alesio
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU = 1000000UL // 1MHz clock frequency

int main(void)
{
	DDRA=0xFF;
	DDRD=0;

	// Variable declaration
	int count;
	
	// Initialize count
	count = 0;
	
	do
	{
		// Only execute test sequencey if Pin 7 is HIGH
		if (PIND & (1 << PD7))
		{
            		// Count down 9-0
			count++;
						
           		 // Reset counter once it reaches 11 (so it counts from 0-10)
			if (count == 11)
				count = 0;
		}
	        // Turn off all segments if Pin 7 is LOW
		else if (!(PIND & (1 << PD7)))
		{
			count = 10;
		}

		
		// Logic for turning on segments
		switch (count)
		{
			case 0:
				PORTA = 0x01;
				_delay_ms(250.0);
				break;

			case 1:
				PORTA = 0x02;
				_delay_ms(250.0);
				break;
			
			case 2:
				PORTA = 0x04;
				_delay_ms(250.0);
				break;

			case 3:
				PORTA = 0x08;
				_delay_ms(250.0);
				break;
			
			case 4:
				PORTA = 0x10;
				_delay_ms(250.0);
				break;

			case 5:
				PORTA = 0x20;
				_delay_ms(250.0);
				break;
			
			case 6:
				PORTA = 0x40;
				_delay_ms(250.0);
				break;

			case 7:
				PORTA = 0x7F;
				_delay_ms(500.0);
				break;
			
			case 8:
				PORTA = 0x00;
				_delay_ms(500.0);
				break;

			case 9:
				PORTA = 0x7F;
				_delay_ms(500.0);
				break;

           		case 10:
				PORTA = 0x00;
				_delay_ms(500.0);
				break;
		}
	}
	while(1);
	
	return 0;
}
