# MXEN2002 Mechatronic Microcontroller Project

### Laboratory A:  Downloading to the microcontroller, driving LEDs

Preliminary reading and reference material:
- Review previous programming notes and material, particularly C language
- The Arduino Mega page at http://arduino.cc/en/Main/ArduinoBoardMega
- GNU C reference: http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html
- C reference: http://en.cppreference.com/w/c
- You may wish to look at the Atmel ATmega2560 Datasheet: http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf, but be warned it is large
- In this unit you will be programming in Visual Studio Code you may wish to look at a tutorial on the development environment, https://code.visualstudio.com/docs/introvideos/basics

The aim of this laboratory session is to familiarise yourselves with the equipment and software that we will be using for the rest of semester.  By the end of the session, you should have confirmed that the Microcontroller, kit board and development environment are all working correctly, and you should have practiced modifying, compiling, and downloading code to the ATMEGA in order to drive some output LEDs.

To begin, you should download the "mcp-master" code framework from the GitHub repository: https://github.com/mxeng/mcp

This code framework is the foundation of your labwork throughout semester. It uses Visual Studio Code and platform.io to compile and upload code to your atmega2560 (arduinoMega) microcontroller. It contains libraries and two projects (in scr), entitled "robot" and "controller": these simply enable you to program two microcontrollers from within the one code framework. At the end of semester, these two projects will be used to control the two microcontrollers: one mounted to your robot, and the other mounted on your controller. During the weekly labs, you will generally use just one of these projects.

For this lab, you can use the "robot" project, and all of the code you need to edit is contained in the file "robot.c". You may also wish to look at the header file "robot.h", but it shouldn't be necessary to edit it for this lab.

Below is some basic code to blink and LED on PORTA pin 3 (PA3).

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

1. Calculate the requirements of the current limiting resistor that is required in series with an LED to be certain that the current from the microcontroller and through the LED is within the limits of the devices. Check the atmega and LED datasheets for their electrical characteristics, you may assume VCC is 5v. **(A1)**

2. Open the provided Visual Studio Code project, replace the "int main(void)" function with the above code, compile the program, and download it to your board.
    - See the readme for instructions.
3. Use hookup wire to connect PortA (arduino pins 22-29) to eight LEDs on the breadboard, using the appropriate current-limiting resistors.
   Refer to the ArduinoMega schematic to check the correct pin locations, https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf, or the pinmapping reference, https://docs.arduino.cc/hacking/hardware/PinMapping2560.

4. Power up the board, and observe the results.

5. Describe the program functionality in your logbook. How is the written pin specified? What would happen if the | symbol was omitted in "PORTA |= (1<<PA3)"? What would happen if the & symbol was ommitted in "PORTA &= ~(1<<PA3)"? (hint: try it!) Why are the | and & symbols used (check bit manipulation tutorial https://github.com/mxeng/mcp-docs/blob/master/tutorials/bit_manipulation.md) **(A2)**

6. Modify your program so that pins 2 and 5 of PORTA (digital pins 24 and 27 respectively) are blinked in sequence. **(A3)**

7. Modify your program so that the LEDs are lit one at a time in sequence from PA0 to PA7 and then back again. **(A4)**
     -  Try using a for loop, https://en.cppreference.com/w/c/language/for, remember PA0 to PA7 are constants 0 to 7.

8. Locate the pins on the Arduino that correspond to Ports A,B,C,K,L (all digital pins)

9. Test the program on at least one other port. This will involve changing both the circuit and the program.  **(A5)**

10. Ensure that all of your work is comprehensively documented in your logbook, including pseudocode or flowcharts where necessary.  You should be able to use the logbook to reproduce the lab session work very quickly if required later. Show your logbook to a demonstator.
