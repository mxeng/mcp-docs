//Author: Tristan Davies
//Created: Jan 2024
//An example of LCD commands

//include this .c file's header file
#include "Controller.h"

//static function prototypes, functions only called in this file


int main(void)
{
	//variable declarations
	char lcd_string[33] = {0}; //declare and initialise string for LCD

	//initialisation section, runs once
	adc_init(); //initialse ADC
	lcd_init(); //initialise 

	_delay_ms(20);
	uint16_t variableToPrint;
	
	//main loop
	while(1)
	{	
		
    lcd_goto(0);      //Put cursor at position 0
    lcd_home();       // same as lcd_goto(0);
		lcd_puts( "This is the number 32" ); //Print string to LCD first line
		lcd_goto( 0x40 );     //Put cursor to first character on second line
		variableToPrint = 32;
		sprintf( lcd_string , "This is the number %u" , variableToPrint ); 
    //print to string, %u special character to be replaced by variables in later arguments
    lcd_puts( lcd_string ); //Print string to LCD second line, same as first line
    //%u for unsigned integers, %i,%d for signed integers
    //%lu for long unsigned ...
    lcd_clrscr();     //Clear everything on LCD
		variableToPrint = 111;
		sprintf( lcd_string , "%u" , variableToPrint );
		lcd_goto(0);     
    lcd_puts( lcd_string ); //Screen shows 111
		variableToPrint = 3;
		sprintf( lcd_string , "%u" , variableToPrint );
		lcd_puts( lcd_string ); // screen shows 311
		sprintf( lcd_string , "%3u" , variableToPrint );
		lcd_puts( lcd_string ); // screen now has 3
		//loop code goes here		
	}
	return(1);
} //end main
