# Mechatronic Microcontroller Project

###Laboratory D: Driving a higher current load

This lab requires some preparation. In order to complete the lab within the session some work beforehand is required.

Before the lab:
- Read the ULN2803 Darlington driver and the 2N3904 NPN transistor specification sheets
- Read up on button-bounce, and consider ways of eliminating this problem.
- Learn how to configure and use interrupts in AVR GCC. These tutorials are a good resource: http://www.fourwalledcubicle.com/AVRArticles.php
- Review driving higher current loads, transistor amplifiers, Darlington
drivers, flyback diodes and hardware interrupts (covered in the lectures)

The objective of this lab is to drive high current outputs without any risk to the
microcontroller. We will use a 12V lamp and a 12V DC motor as output loads.

Lab tasks:

1. Design an output driver circuit which will power a 12V, 300mA lamp using the 2N3904 transistor. Draw a circuit diagram, and verify that the current at the Microcontroller terminals are safe. **(D1)**
2. Write a program to blink the lamp on and off approximately twice per second.
3. Collect a 12V lamp, and implement your design. **(D2)**
4. Modify your output circuit to use the Darlington driver instead of the transistor. **(D3)**
5. Modify your program to toggle the lamp on and off using a push button (or the select button on your joystick) connected to one of the hardware interrupt pins on the microcontroller **(D4)**
6. Modify your output circuit so it can power a 12V motor on your robot chassis using either the transistor or Darlington driver, including an appropriately oriented flyback diode. Draw a circuit diagram, and explain in your lab book what will happen to current flow when the motor is switched off. **(D5)**
7. Implement your design, ensuring that a demonstrator checks your circuit before power is
applied.

