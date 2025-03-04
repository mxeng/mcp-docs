# Mechatronic Microcontroller Project MXEN2003

## Laboratory 2:  Digital and analogue inputs and the ADC

### Lab Briefing

During this lab you will use analogue and digital inputs to read the state of a joystick and thermister and display their value on the LEDs setup during the previous lab.

ADC stands for Analogue to Digital Converter.  It is an interface which converts an analogue voltage (e.g 0-5V) into a digital signal (e.g an 8-bit or 10-bit number).  An ADC is essential if you wish to be able to process analogue signals with your Microcontroller.

The ATmega can read up to 16 different analogue voltages (using the Port F & Port K pins).

In addition, the ADC requires two reference voltages.  AREF is the maximum measured voltage (that is, the voltage which will return the largest digital output), while AGND is the minimum measured voltage (often 0V, connected to the GND pin on the ATmega2560).  AVCC is the ADC power supply, and will usually be simply the same 5V power supply as the VCC pin.

The ADC on the ATmega2560 is manipulated using specific ADC registers, which are described in the ATmega2560 datasheet. 
Some framework code has been provided for you (in the files adc.c and adc.h), to make dealing with the ADC a simpler, however you may wish to examine adc.c and the datasheet to see exactly how this works. This framework initialises AREF to 5V (VCC).

You will need to firstly ensure the header file adc.h is #included in your project header file (probably in Robot.h): The example code provided below shows the syntax for initialising and reading from an ADC using the framework.
```c
#include "../adc.h" //minimal adc lib

adc_init(); //initialse ADC
_delay_ms(20); //it's a good idea to wait a bit after your init section

adc_read(3); //read the voltage at ADC3
```
You will be using an analogue joystick which consists of two potentiometers and a push button. When the joystick is connected to power and ground, the two analog output pins will deliver voltages proportional to the stick position in the horizontal and vertical directions. The push-button is configured active-low (meaning the output  on the SEL line is low when pressed and open otherwise).

You will also be using a thermistor which will vary in resistance as its temperature is changed. To use an ADC to measure the changing resistance you will need to calculate and make a voltage divider circuit to support the circuit. 

**TASK 1**

Tasks one is to wire a circuit to read joystick position and push button state and write code to light up a series of eight led's based on the position of a joystick and use the push button to determine which channel of the joystick is being read.

**TASK 2**

Task two is to light up a series of eight led's based on the ammount of light being recieved by a photoresistor.

### Before the lab

  - **Read up on analogue joysticks and sketch a circuit diagram of the internals of the analogue joystick and what it is connected to on your microcontroller.**

  - **Read up on reading digital using ```PINx``` registers (e.g ```PINA``` for Port A etc) to read digital inputs, and how to either configure an internal pull-up resistor for the select line or wire an external pull-up resistor. See [input.md](https://github.com/mxeng/mcp-docs/blob/master/tutorials/input.md) for a brief tutorial.**

  - **Familiarise with the ADC pin locations and functionality through the ATmega2560 datasheet**

  - **Draw a flowchart describing the functionality of your program**


### Outcomes

1. Sketch a circuit diagram which shows how the potentiometers and buttons are configured (joystick internals), including the pull-up resistor, and showing all Arduino/microcontroller input/output pins.

2. Draw a flowchart describing the program for task 1 in your workbook.

3. Demonstrate a functional mechatronic system which reads the input voltage from one channel of the joystick and displays the result on eight LEDs (using the circuit from Lab A).

4. Demonstrate a functional mechatronic system which uses a push button to switch the display between the input channels displaying the result on the LEDs.

5. Find a way to represent the light intensity received by the photoresistor using the eight LEDs (convert from binary).  You will need to adjust the range in software to maximize the range of input.

   - You will need to determine the size of a suitable fixed resistor to use in a voltage devider circuit (sketch circuit).
   - Use a multimeter to estimate the range of resistances from ambient light to dark ensure you take note of the resistance range and predicted voltage range in your notes.
