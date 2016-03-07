# Input
[(Summary)](bit_manipulation.md#summary)
By reading the value of the ```PINx``` registries we can do input on the microcontroller.


#### Wiring a switch
A switch needs to be wired so that it is in a defined state when it is pressed and also when it is not pressed. Usually either a pull up or pull down resistor is used for this task.
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
