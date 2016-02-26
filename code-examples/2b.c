#include <stdbool.h>

//reading ports

static bool an_example_flag = false;
static uint8_t an_example_variable = 0;

//we want to make sure PORTA is in input mode (it is the default at boot though)
PORTA = 0x00;

//if you want to read from a port you need to use the PIN register
//the PORT register is the register that holds the outputs you have commanded previously

//think of a PORT register as your accelerator
//and a PIN register as your speedometer
//they are completely different things!!

//you don't look at the position of the accelerator pedal to see how fast you are going!
//that is the equivalent of reading from the PORT register to try and read the PIN input


//so to read in from the pins of PORTA
an_example_variable = PINA;

//remember PINA is the whole 8 bit port, to look at one pin we have to use bit masking (Google it!)
//if we have a switch attached on A3
//and we want to to "one thing" if the switch is high and "another thing" if the switch is low

an_example_flag = PINA & (1>>3);

if(an_example_flag): //if A3 is high
{
    //one thing
}
else: //if A3 is low
{
    //another thing
}

//we don't really need the variable though

if(PINA & (1>>3)): //if A3 is high
{
    //one thing
}
else: //if A3 is low
{
    //another thing
}
