# MXEN2002 Mechatronic Microcontroller Project

### Laboratory 1:  Downloading to the microcontroller, driving LEDs

**Before the lab**
 - **This unit will involve programming a microcontroller in C, you will need to review programming notes and material and if unfamiliar with C language, and complete tutorials on the basics of C language.**
   - Some references: [C reference](http://en.cppreference.com/w/c), [GNU C reference](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
 - **The ATmega2560 is the microcontroller being used in this unit download the [datasheet](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf)**
   - The ATmega2560 is being used on an [Arduino Mega](http://arduino.cc/en/Main/ArduinoBoardMega), though you will not be using the Arduino IDE for development in this unit.
 - **In this unit you will be programming in Visual Studio Code you may wish to look at a [tutorial on the development environment](https://code.visualstudio.com/docs/introvideos/basics)**
 - **Read the code below and ensure you understand the functionality**
 - **A code framework is provided in the GitHub repository, https://github.com/mxeng/mcp, download this repository, install Visual Studio Code and setup the environment to enable uploading to the atmega board, see readme for instructions.**

```c

int main(void)
{
  DDRA = 0xFF;//put PORTA into output mode
  PORTA = 0; 
  while(1)//main loop
  {
    _delay_ms(500);     //500 millisecond delay
    PORTA |= (1<<PA3);  // note here PA3 is just an alias for the number 3
                        // this line is equivalent to PORTA = PORTA | 0b00001000   which writes a HIGH to pin 3 of PORTA
    _delay_ms(500); 
    PORTA &= ~(1<<PA3); // this line is equivalent to PORTA = PORTA & (0b11110111)  which writes a HIGH to pin 3 of PORTA
  }
  return(1);
}//end main 
```

### Lab Tasks

During this laboratory session you will set up and familiarise yourself with the development environment, modify and upload code to the microcontroller to drive some leds.

There is a code framework provided on GitHub which will form the foundation of your labwork throughout semester. It uses Visual Studio Code and platform.io to compile and upload code to your atmega2560 (arduinoMega) microcontroller. It contains libraries and two projects (in src), entitled "robot" and "controller": these simply enable you to program two microcontrollers from within the one code framework. At the end of semester, these two projects will be used to control the two microcontrollers: one mounted to your robot, and the other mounted on your controller. During the weekly labs, you will generally use just one of these projects.

For this lab, you can use the "robot" project, and all of the code you need to edit is contained in the file "robot.c". You may also wish to look at the header file "robot.h", but it shouldn't be necessary to edit it for this lab.

Your task is to demonstrate the ability to modify and upload code to the microcontroller to control a series of eight LEDs across multiple digital output registers. You will begin by connecting 8 LEDs and resistors to PORTA (arduino pins 22-29) using a breadboard. Check [ArduinoMega schematic](https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf) for correct pin locations, or the [pinmapping document](https://docs.arduino.cc/hacking/hardware/PinMapping2560).

**Outcomes**

1.  Calculate a series limiting resistor value to ensure current limit is not exceeded for an LED connected to PORTA.
    - Check the [atmega](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf) and [LED](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.farnell.com/datasheets/1498852.pdf) datasheets for their electrical characteristics, you may assume VCC is 5v.
    
2.  Describe how the written pins are specified. What is the purpose of the | and the & symbols, what would happen if they were removed? 
    - Check the Bit Manipulation tutorial https://github.com/mxeng/mcp-docs/blob/master/tutorials/bit_manipulation.md)
    
3.  Demonstrate two LEDs blinking alternately

4.  Demonstrate 8 LEDs blinking in sequence
    - Preferably use a for or while loop [reference](https://en.cppreference.com/w/c/language/for)
  
5.  Demonstrate the blinking sequence on a separate PORT
   
