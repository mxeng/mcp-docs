#include "adc.h" //minimal adc lib



int main(void)
{
    //variable declarations
    
    //a 16 bit variable is required becuase 
    //an 8 bit variable isn't big enough 
    //to hold the ADC's 10 bit output
    static uint16_t adc_value = 0;
    
    //initialisation section, runs once
    adc_init(); //initialse ADC
    _delay_ms(20); //probably a good idea to let the ADC start running
    
    DDRA=0xFF; //put PORTA in high impedance output mode for driving LEDs
    
    //main loop
    while(1)
    {
        //read voltage from ADC0 and store value in the adc_value variable
        adc_value = adc_read(0); 
        
        //read voltage from ADC1 and output value on PORTA
        PORTA = adc_read(1);
        //keep in mind that you're putting a 16 variable in an 8 bit port
        //what will this do? what's a better way to do it?
        
        _delay_ms(100); //no reason to do it more than 10 times a second
    }
}//end main
