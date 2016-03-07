# Bit Manipulation
[(Summary)](bit_manipulation.md#summary)
Bit manipulation is used to set up configuration registers and change the state of output pins to control devices connected to the microcontroller. The register we write to and the bits we change determint the functionality (refer to the datasheet for your chip, eg: [Atmega2560 Datasheet](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf).


#### Writing a register at once
Setting a group of bits using hex notation
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
