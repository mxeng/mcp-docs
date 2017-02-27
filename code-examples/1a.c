//includes should actually be in a separate header file
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(void)
{
	// initialisation code goes in this section
	DDRA = 0xFF;	//put PORTA into output mode
  	PORTA = 0; 	// what does this line do?
	
	
  	while(1)//main loop, any repeated instructions go here
  	{
    		_delay_ms(500);     //500 millisecond delay
    		PORTA |= (1<<PA3);  // note here PA3 is just an alias for the number 3
                        // this line is equivalent to PORTA = PORTA | 0b00001000   which writes a HIGH to pin 3 of PORTA
    		_delay_ms(500); 
    		PORTA &= ~(1<<PA3); // this line is equivalent to PORTA = PORTA & (0b11110111)  which writes a LOW to pin 3 of PORTA
  	}
  	return(1);
}//end main 
