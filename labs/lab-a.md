# MXEN2002 Mechatronic Microcontroller Project

### Laboratory A:  Downloading to the microcontroller, driving LEDs

**Before the lab**
 - **This unit will involve programming a microcontroller in C, you will need to review programming notes and material and if unfamiliar with C language, and complete tutorials on the basics of C language.**
   - Some references: [C reference](http://en.cppreference.com/w/c), [GNU C reference](http://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
 - **The ATmega2560 is the microcontroller being used in this unit download the [datasheet](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf)**
   - The ATmega2560 is being used on an [Arduino Mega](http://arduino.cc/en/Main/ArduinoBoardMega), though you will not be using the Arduino IDE for development in this unit.
 - **In this unit you will be programming in Visual Studio Code you may wish to look at a [tutorial on the development environment](https://code.visualstudio.com/docs/introvideos/basics)
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

### Task

During this laboratory session you will set up and familiarise yourself with the development environment, modify and upload code to the microcontroller to drive some leds.

There is a code framework provided on GitHub which will form the foundation of your labwork throughout semester. It uses Visual Studio Code and platform.io to compile and upload code to your atmega2560 (arduinoMega) microcontroller. It contains libraries and two projects (in scr), entitled "robot" and "controller": these simply enable you to program two microcontrollers from within the one code framework. At the end of semester, these two projects will be used to control the two microcontrollers: one mounted to your robot, and the other mounted on your controller. During the weekly labs, you will generally use just one of these projects.

For this lab, you can use the "robot" project, and all of the code you need to edit is contained in the file "robot.c". You may also wish to look at the header file "robot.h", but it shouldn't be necessary to edit it for this lab.

Your task is to demonstrate the ability to modify and upload code to the microcontroller to control a series of eight LEDs across multiple digital output registers.
**Outcomes**
  -  Task 1

1. Calculate the requirements of the current limiting resistor that is required in series with an LED to be certain that the current from the microcontroller and through the LED is within the limits of the devices. Check the [atmega](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf) and [LED](chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.farnell.com/datasheets/1498852.pdf) datasheets for their electrical characteristics, you may assume VCC is 5v. **(A1)**

2. Open the provided Visual Studio Code project, replace the "int main(void)" function with the above code, compile the program, and download it to your board.
    - See the readme for instructions.
3. Use hookup wire to connect PortA (arduino pins 22-29) to eight LEDs on the breadboard, using the appropriate current-limiting resistors.
   Refer to the [ArduinoMega schematic](https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf) to check the correct pin locations, , or the [pinmapping reference](https://docs.arduino.cc/hacking/hardware/PinMapping2560).

4. Power up the board, and observe the results.

5. Describe the program functionality in your logbook. How is the written pin specified? What would happen if the | symbol was omitted in "PORTA |= (1<<PA3)"? What would happen if the & symbol was ommitted in "PORTA &= ~(1<<PA3)"? (hint: try it!) Why are the | and & symbols used (check bit manipulation tutorial https://github.com/mxeng/mcp-docs/blob/master/tutorials/bit_manipulation.md) **(A2)**

6. Modify your program so that pins 2 and 5 of PORTA (digital pins 24 and 27 respectively) are blinked in sequence. **(A3)**

7. Modify your program so that the LEDs are lit one at a time in sequence from PA0 to PA7 and then back again. **(A4)**
     -  Try using a for loop, [reference](https://en.cppreference.com/w/c/language/for), remember PA0 to PA7 are constants 0 to 7.

8. Locate the pins on the Arduino that correspond to Ports A,B,C,K,L (all digital pins)

9. Test the program on at least one other port. This will involve changing both the circuit and the program.  **(A5)**

10. Ensure that all of your work is comprehensively documented in your logbook, including pseudocode or flowcharts where necessary.  You should be able to use the logbook to reproduce the lab session work very quickly if required later. Show your logbook to a demonstator.
