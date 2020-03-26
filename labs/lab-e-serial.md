# Mechatronics Microcontroller Project MXEN2002

### Laboratory E: Timers, interrupts and the LCD display

**Before the lab:**
- Review the use of harware interrupts.
- Research how to configure and use hardware **timers** (section 17 of the ATmega datasheet: http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf).
- Begin planning your program.

**Task: Design a simple stop-watch, using a serial monitor on PC to show the elapsed time.**
- You should set up a hardware timer (e.g TIMER1) to time a suitable interval (say 1 or 10msec), and program variables to maintain counts of milliseconds, seconds and minutes. You will need to calculate suitable values for the prescaler and for the timer compare register.
- Hardware interrupts should be used for button control.
- This lab task is described in fairly broad terms. It is up to you to determine the detailed scope.
- As a minimum, you should implement a toggle button which will “start” and “stop” the timer **(E1)**, and a second button which will “reset” your stopwatch **(E2)**. A debounce strategy will be needed for the toggle function to work properly.

<p align="center"> <img src="https://cdn.rawgit.com/mxeng/mcp-docs/58d989b29e79487f61872b26bb9f59bde3d672a8/labs/stopwatch.svg" alt="stopwatch with start/stop button and reset button" width="30%"> </p>

Some factors to consider:
- What precision will you record and display?
- Do you need to debounce one or more of the buttons?
- Is there any additional functionality which would be useful?

Your documentation should include:
- A clear specification of the scope of your task
- All relevant calculations, including prescaler and comparison values. **(E3)**
- All relevant circuit diagrams. **(E4)**
- Some pseudocode or flowcharts (preferred) showing the implementation of the logic. **(E5)**
- A description of any tests conducted to verify functionality. 

Marks E1 and E2 should be submitted as a short video if it is possible to show your display and can clearly see you pressing the toggle buttons and affecting the stopwatch appropriately. Otherwise submit a screenshot of serial monitor output, preferably adding lines of code that print across serial when buttons are pressed so we can clearly see your software has detected a button press and is reacting accordingly.

E3 to E5 should be submitted as photos or scans of your lab book with your student card either visible in photo or scanned in front of the page so it can be seen as one scanned image. This is necessary to show evidence that the documentation is your own work.

Example code below demonstrates how to use serial 0 to print messages to the computer. Note you will need to write an appropraite sprintf to store the correct message in stopwatch_string (as well as timer code, external interrupt code, and more). Serial 0 is connected to the USB connector, no additional wires are necessary to facilitate arduino to PC communication.
```c
//#includes not shown. dont delete them from your file

//ISR routines for anything handled via interrupt

int main( void )
  char stopwatch_string[10] = {0};
  serial0_init();
  
  //other code designed and written by you
  
  while(1)
  {
    //code that calculates what numbers to show on the stopwatch
    //use sprintf, same as creating a string as seen in the LCD lab
    //include \r (carriage return character) at the end of the string format
    
    //may want some code to slow the rate of communication. High likelihood of spam.
    serial0_print_string(stopwatch_string);
    
  }
  return 1;
}
 ```
  
