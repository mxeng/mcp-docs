# Mechatronic Microcontroller Project MXEN2003

## Laboratory 8: Motor Control

### Lab Briefing

During this lab session you will assemble your cart, or use a pre-assembled cart and make modifications as you desire, and use PWM and a H-bridge circuit to control the motors which will drive the cart. At the end of this lab you should have a working wireless driving cart.

To achieve this you will need:
- Wireless control from the previous lab modified to send joystick commands to control the motors direction and speed.
- An algorithm for the conversion of joystick values to PWM duty cycle.
- 2 or 4 PWMs with an appropriate frequency to control the speed of the motors
- A H-bridge circuit built with appropriately placed flyback diodes (4 per motor)

An example of motor drive logic can be found here: https://github.com/mxeng/mcp-docs/blob/master/tutorials/motor_drive.md

**TASK1**

Assemble and demonstrate a working wireless robot drive system with intuitive controls*. (Joystick -> XBee -> H-bridge )

### Before the lab
- Ensure you have read the lecture notes on PWM, H-bridges and motors
- Review the L293 H-bridge datasheet: https://www.st.com/resource/en/datasheet/l293b.pdf
- Review the PWM section of the ATmega2560 datasheet (section 17, p133): http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf
- Plan your H-bridge configuration
- Review example for motor drive logic: https://github.com/mxeng/mcp-docs/blob/master/tutorials/motor_drive.md
- Plan code for motor drive, you may use snippets from the example code
- Plan your PWM configuration. **Be aware that you may be able to reuse your PWM config from your servos with some changes to top value and comparison value.**

### Outcomes
- Show the configuration of the L293 H-bridge used to control the two motor with variable speed and direction, including a circuit diagram.
- Show calculations / algorithm used to convert the joystick values into appropriate PWM comparison values and IO signals for motor control*.
  - This should include where the serial communication takes place.
- Demonstrate a PWM with appropriate frequency (**100-500Hz**) and duty cycle control on a oscilloscope.
- Demonstrate a appropriately wired circuit for motor control.
- Demonstrate a working wireless robot drive system with intuitive controls*.

*intuitive controls: consider how you would expect to control an RC car

<p align="center"> <img src="https://github.com/mxeng/mcp-docs/blob/master/labs/robot_drive.png" alt="stopwatch with start/stop button and reset button" width="80%"> </p>

Suggested circuit:
<p align="center"> <img src="https://github.com/mxeng/mcp-docs/blob/master/labs/hbridge_twomotor.png" alt="stopwatch with start/stop button and reset button" width="60%"> </p>
