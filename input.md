# Input
By reading the value of the ```PINy``` registries we can do input on the microcontroller. We can also use the ADC to read continuously variable voltages.

#### Putting a pin or a port into input mode
The microcontroller's ports default to high impedance output mode when it is reset or powered on (it's safer becuase the pins are protected from shorts), but we don't want to rely on this becuase previous code (either ours or a dodgey bootloader) might have put some pins into output mode.

We use the data direction register to do this:
```c
DDRA = 0x00; //whole of PORTA in high impedance input mode
DDRA &= ~((1<<DDA0)|(1<<DDA1); //just A0 and A1 in high impedance input mode
```


#### Wiring a switch
A switch needs to be wired so that it is in a defined state when it is pressed and also when it is not pressed. Usually either a pull up or pull down resistor is used for this task as seen in the schematic below.

<p align="center"> <img src="https://cdn.rawgit.com/mxeng/mcp-docs/1e6ea90f8f955fa6812864f90941af543fb00d82/schematics/input_and_adc.svg" alt="Schematic showing a switch wiring in a pull-up and pull-down configuration and a potentiometer wired to an ADC channel" width="90%"> </p>

The switch with the pull-up resistor connected to A0 will be active low and the switch connected to A1 in the pull-down configuration will be active high.

#### Enabling the internal pull-up

The pull-up configuration is more common and the Atmel microcontroller inludes a built in internal pull up. We can enable it by setting the corresponding ```PORTy:x``` bit after the ```DDRy:x``` bit has cleared (set to 0) to ensure the pin is in input mode!
```c
PORTA |= (1<<PA0); //enable the internal pull-up resistor on AO and leave the rest of PORTA alone
```

#### Using the switch in software
In order to do somethin based on the position of the switch we need to use the value of the input register (eg: ```PINA```) in our code. A common taske is to do one thing if a pin is high and another thing if the pin is low.

We need to use the input register, but we have to mask the result of the read from the ```PINy``` register so that we only consider the bit that the switch is connected to. We do this with the bitwise and operator - remember that ```x&0=0``` and ```x&1=x```.
```c
if(PINA & (1<<PINA0)) //if PINA0 is high
{
  //stuff to do if PINA0 is high
}
else //if PINA0 is low (when the button is pressed in the active low configuration)
{
  //stuff to do if PINA0 is low
}
```


#### Reading a voltage using the ADC
The Analogue to Digital Converter (ADC) allows us to measure a continuously variable (analogue) voltage (like the voltage coming from the potentiometer connected to ADC0 in the schematic above) and turn this into a number that we can use in our code. The result is proportional to the voltage and scaled so that ```AREF``` is the max. On our microcontrollers this means that 0 corresponds to 0V and 1023 corresponds to 5V.

To use the ADC using the basic ADC library provided, we must initialise it by putting this line at the top of our program where it should be run once (in our initialisation section):
```c
adc_init();
```
Then when we want to read from one of the ADC's 16 channels we just use the ```adc_read()``` function where the single parameter is the channel number.
```c
static uint16_t sixteen_bit_variable = 0; //declare and initialise a sixteen bit unsigned integer variable
sixteen_bit_variable = adc_read(2); //read the voltage on ADC2 and store the 10 bit result into a variable
```
We can put this function anywhere we want, just remember that it's a 10 bit result and sometimes we might need to modify that (like shifting it right twice before writing the eight most significant bit so a set of eight LED's).
```c
a = b*adc_read(0) + 2*adc_read(2);
PORTC = adc_read(0)>>2;
```
