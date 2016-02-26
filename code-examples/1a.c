//includes should actually be in a separate header file
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(void)
{
	//variable declarations
	static uint8_t leds = 0;
	
	//initialisation section, runs once
	DDRA = 0xFF; //configure PORTA as output
	leds = 0;
    PORTA = leds;
    
	//main loop
	while(1)
	{
		leds = leds + 1; //increment the value of the leds variable by one
        PORTA = leds; //write the value in the leds variable to PORTA, changing the state of the LEDs
        _delay_ms(500); //500ms delay, make sure F_CPU is set
	}
}//end main
