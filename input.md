# Input
[(Summary)](bit_manipulation.md#summary)
By reading the value of the ```PINx``` registries we can do input on the microcontroller.

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
if(PINA & (1<<PINA0) //if PINA0 is high
{
  //stuff to do if PINA0 is high
}
else //if PINA0 is low (when the button is pressed in the active low configuration)
{
  //stuff to do if PINA0 is low
}
```


```c
REGISTER = 0xFF; //all high
REGISTER = 0xF0; //upper nibble high, lower nibble low
REGISTER = 0x00; //all low
REGISTER = 0xCA; //HHLL HLHL, 8+4=12=0xC, 8+2=10=A
```
Setting one bit high
```c
REGISTER = 0x01; //R0 high, all other bits low, 0000 0001, LLLL LLLH
REGISTER = 0x04; //R2 high, all other bits low  0000 0100, LLLL LHLL
```
