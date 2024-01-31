# Mechatronic Microcontroller Project

## Laboratory 3: Driving a higher current load

### Lab Briefing

During this lab you will be driving higher power loads using transistors and darlington drivers. You will use push buttons configured with hardware interrupts and button debounce to switch outputs on and off.

The microcontroller has a limit of 40mA on an IO pin which means that any peripheral which needs more than this will need to have a external power supply. A transistor or darlington driver (built from transistors) can be used to provide a higher current to the load acting as an electrical switch. The lectures cover transistors and darlington drivers in more detail.

Hardware interrupts allow for functions to be executed by external voltage inputs and can be configured using the external interrupt control registers page 110 of the [datasheet](http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf)

When the push button is pressed an released the voltage does not transition from low to high in one step there is *bouncing* which occurs which makes it appear like the button is being pressed multiple times.

<p align="center"> <img src="https://github.com/MrTristanDavies/mcp-docs/blob/master/labs/button_bounce.png" alt="Button Bounce" width="30%"> </p>

To avoid the interrupts being triggered multiple times from a single button press a form of button debounce needs to be implemented, either in software or hardware.

**TASK 1**

Drive a 12 volt lamp using a transistor to blink it on and off a couple of times a second, without having any risk of damaging the microcontroller.

**TASK 2**

Drive a DC motor using a darlington driver, with flyback diode, turning it on and off using a push button connected to a hardware interrupt pin.

### Before the lab

- Read the ULN2803 Darlington driver and the 2N3904 NPN transistor specification sheets
- Calculate if a resistor would be needed and what size for a 12 volt (200mA or 300mA) lamp, based on expected gain from the NPN transistor
- Read up on button-bounce, and consider ways of eliminating this problem - information here http://www.ganssle.com/debouncing-pt2.htm.
- Learn how to configure and use interrupts in AVR GCC. These **tutorials** These tutorials are a good resource: http://www.fourwalledcubicle.com/AVRArticles.php
- Review flyback diodes and DC motors
- Draw a flow chart for planned program of task 2, separate flows for interrupts

### Outcomes

1. Draw relevant circuit diagrams: One diagram for an output driver circuit using the 2N3904 transistor controlling the 12 volt lamp, one diagram for the darlington driver and flyback diode controlling the motor.
2. Demonstrate a functional and safe circuit (see datasheets to ensure safe currents) which blinks a 12 volt lamp using a transistor.
3. Demonstrate a push button being used to toggle the state of the 12 volt lamp using an interrupt
4. Demonstrate a 12 volt DC motor being controlled via darlington driver, with a debounced interrupt driven push button.
   - Show the circuit to a lab demonstrator prior to powering the circuit.
5. Describe the function of the flyback diode in the darlington driver and motor circuit. Explain what happens to the current flow when the motor is switched off (with and without the flyback diode)
