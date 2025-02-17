# Mechatronics Microcontroller Project MXEN2003

## Laboratory 5: Timers, interrupts and the LCD display

### Lab Briefing

The ATmega 2560 has 6 timer/counters available with variable modes of operation. Timer/Counter 0 and 2 are 8 bit timers and are configured a little differently to timers 1,3,4 and 5. It is suggested that you use one of timers 1,3 or 4 for your stopwatch, and later PWM generation.

In this lab you will be configuring a timer in Clear Timer on Compare (CTC) mode in order to create a stop watch. Information on setting this mode and its function is available in the datasheet on page 145.

You will be displaying your stopwatch on an LCD screen for which a library is provided to you (HD44780, [reference](http://community.atmel.com/projects/hd44780-library.))

Previously digital inputs were read using PINx registers which read the current state of an IO pin. In this lab you will need to use hardware interrupts configured to execute when a digital inputs state is changed (eg a button pressed or released) as was used in lab 3.

Some factors to consider:
- What precision will you record and display?
- Do you need to debounce one or more of the buttons?
- Is there any additional functionality which would be useful?

**TASK 1**

Develop a simple stop watch using an LCD to show the elapsed time, this is a broad scope but some requirements are outlined below.
  - You will need to set up a hardware to a suitable interval (0.1, 1 or 10 ms), and write a program to keep count of milliseconds, seconds and minutes.
  - You will need to calculate a prescaler and choose register configurations
  - As a minimum the stopwatch needs to have a start/stop button, a reset button and display time in a readable format.

<p align="center"> <img src="https://cdn.rawgit.com/mxeng/mcp-docs/58d989b29e79487f61872b26bb9f59bde3d672a8/labs/stopwatch.svg" alt="stopwatch with start/stop button and reset button" width="30%"> </p>

### Before the lab

- Review the use of the LCD using the HD44780 Library if necessary: http://community.atmel.com/projects/hd44780-library.
- Review the use of hardware interrupts.
  - Plan configuration of hardware registers (EICRnA/B, EIMSK)
- Research how to configure and use hardware timers (section 17 of the ATmega datasheet: http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf).
  - Calculate a suitable prescaler and register configuration (TCCRnA/B, TIMSKn, OCRnA/B/C, ICRn)
- Plan your program using a flowchart to describe its functionality
- Review C variables - volatile for variables which change in interrupts
- Review button debounce

### Outcomes

1. Show calculations and register configuration for the setup of the timer.
2. Draw a flowchart describing the logic of the stopwatch (using separate flows for the interrupts)
3. Demonstrate a working timer (using timer interrupts)
4. **Demonstrate a functional stopwatch which meets the requirements - 2 marks**
