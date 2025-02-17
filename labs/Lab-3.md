# Mechatronic Microcontroller Project

## Laboratory 3: Serial Printing, Interrupts and Button Debounce

### Lab Briefing

During this lab you will be using interrupts to read button presses and print to serial how many have been detected.

To transmit data from the microcontroller to the computer a communication protocol needs to be initiated. Provided in the MCP repo is a serial library which communicates using USART on channel 0 with BAUD 9600.

The *serial0_print_string()* function prints a string to serial which can be viewed using VScodes inbuilt serial monitor. String literals can be sent accross using this function. To send variables using this command they must first be formatted into strings, see *springf*

In the previous lab we used digital input using the *PINx* register which holds the current value of the input pins. To use this to trigger some code the register must be constantly polled, another method of triggering code is to use an interrupt instead.

Hardware interrupts allow for functions to be executed by external voltage inputs and can be configured using the external interrupt control registers page 110 of the [datasheet](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf)

When the push button is pressed and released the voltage does not transition from low to high in one step, instead there is *bouncing* which occurs which makes it appear like the button is being pressed multiple times.

<p align="center"> <img src="https://github.com/mxeng/mcp-docs/blob/master/labs/button_bounce.png" alt="Button Bounce" width="30%"> </p>

To avoid the interrupts being triggered multiple times from a single button press a form of button debounce needs to be implemented. This can be achieved either in software or hardware.

**TASK 1**

Display the light level of a photoresistor on the serial monitor using a interrupt driven push button. 

**TASK 2**

Display on the serial monitor the number of rising or falling edges detected when a push button in pressed. Then eliminate button bounce using software and hardware solutions.

### Before the lab

- **Review string formatting in c, suggest using sprintf [reference](https://en.cppreference.com/w/cpp/io/c/fprintf)**
- **Read up on button-bounce, and consider ways of eliminating this problem - information here http://www.ganssle.com/debouncing-pt2.htm.**
- **Learn how to configure and use interrupts in AVR GCC. These **tutorials** These tutorials are a good resource: http://www.fourwalledcubicle.com/AVRArticles.php**
- **Calculate and appropriate sized RC circuit to debounce the push button, aiming for a time constant between 20-50ms.**
- **Review lab 2 and ensure your photoresistor light detection circuit is functional.**

### Outcomes

1. Demonstrate display of formatted voltage to serial terminal.
2. Demonstrate using an interrupt to update display value
3. Demonstrate a system which measures the number of falling or rising edges within the last second.
4. Calculate and implement an RC filter on the interrupt pin to minimize the effect of button bounce.
5. Implement a software solution to the button bounce problem, discuss why each method of button debounce would be used.

**Tips**

Note on volatile variable type.

The compiler optimizes code when a variables value isn't expected to change, using volatile ensurea the variables memory is read when it is used.
For variables modified in interrupts since this modification is not visible variable access within the main function their value will not be updated.
Declaring a variable as volatile tells the compiler that the variables value is prone to change externally and to always read the variable to check its value.


