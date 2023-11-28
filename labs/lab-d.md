# Mechatronic Microcontroller Project

## Laboratory D: Driving a higher current load

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

Before the lab:
- Read the ULN2803 Darlington driver and the 2N3904 NPN transistor specification sheets
- Read up on button-bounce, and consider ways of eliminating this problem.
- Learn how to configure and use interrupts in AVR GCC. These tutorials are a good resource: http://www.fourwalledcubicle.com/AVRArticles.php
- Review driving higher current loads, transistor amplifiers, Darlington
drivers, flyback diodes and hardware interrupts (covered in the lectures)

### Outcomes

1. Draw relevant circuit diagrams: One diagram for the 2N3904 transistor controlling the 12 volt lamp, one diagram for the darlington driver and flyback diode controlling the motor.
2. Demonstrate a functional and safe circuit (see datasheets to ensure safe currents) for controlling a 12 volt lamp using a transistor.
3. Demonstrate a push button being used to toggle the state of the 12 volt lamp of motor using an interrupt
4. Demonstrate a 12 volt DC motor being controlled via darlington driver, with a debounced interrupt driven push button.
5. Describe the function of the flyback diode in the darlington driver and motor circuit. Explain what happens to the current flow when the motor is switched off (with and without the flyback diode)

END

6. Design an output driver circuit which will power a 12V, lamp using the 2N3904 transistor, check the lamp for its current draw. Draw a circuit diagram, and verify that the current at the Microcontroller terminals are safe (referring to the transistor and Atmega datasheets). **(D1)**
7. Write a program to blink the lamp on and off approximately twice per second.
8. Implement your design and demonstrate that is works. **(D2)**
9. Modify your output circuit to use the Darlington driver instead of the transistor.
10. Modify your program to toggle the lamp on and off using a push button (or the select button on your joystick) connected to one of the hardware interrupt pins on the microcontroller **(D3)**, include a method of button debounce. **(D4)**
11. Modify your output circuit so it can power a 12V motor on your robot chassis using either the transistor or Darlington driver, including an appropriately oriented flyback diode. Draw a circuit diagram, and explain in your lab book what will happen to current flow when the motor is switched off. **(D5)**
12. Implement your design, ensuring that a demonstrator checks your circuit before power is applied.

