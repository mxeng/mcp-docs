# Mechatronic Microcontroller Project MXEN2002

### Laboratory G: Motor Control (based on the usual Lab H)

**Before the lab**:
- Ensure you have read the lecture notes on PWM, H-bridges and motors: https://lms.curtin.edu.au/bbcswebdav/pid-2158837-dt-content-rid-22938419_1/courses/308824-Ux-061-01-Sxx-x1/lecture_07%285%29.pdf
- Review the L293 H-bridge datasheet: http://www.micropik.com/PDF/l293b.pdf
- Review the PWM section of the ATmega2560 datasheet (section 17, p133): http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf
- Plan your H-bridge configuration
- **Be aware that you may be able to reuse your PWM configurations from your servos with a suitable modification to the top value (to set a suitable base frequency) and to the comparison values to set a suitable full range of duty cycle (from 0 to 100%).**

Task:
- Configure the L293 H-bridge circuit to control two motors with variable speed, and in both directions. You may choose your own configuration (i.e how to drive the direction and inhibit lines). As a minimum, you will need two PWM signals (these can be generated using one timer) and four digital outputs. You will also need eight protection diodes for flyback. Include a schematic/circuit diagram in your lab book. **(G1)**
- Demonstrate the generation of two or four (as required) PWM signals with a calculated base **frequency in the range 500Hz-20kHz** with duty cycle variable between 0 and 100%. Note that some frequencies may produce an audible tone from the motor: a change in frequency will usually fix this. Use a loop with delay to step through your motor control in direction and speed. You should test the signals with a multimeter if possible before connecting the motor. Use your motor to test both sides of the H bridge (so that the H bridge is ready to control two motors). **(G2)**
- Use the two channels of your joystick (horizontal and vertical) to drive the speed and direction of the motor control on each side of the H bridge (e.g vertical channel controls speed and direction of motor A and horizontal channel controls speed and direction of motor B). **(G3)**
- Show the calculations for the base frequency of the motor, and for converting joystick digital value into suitable direction and comparison values. **(G4)**
- Show a well structured and commented C program. **(G5)**

<p align="center"> <img src="https://github.com/mxeng/mcp-docs/blob/master/labs/robot_drive.png" alt="stopwatch with start/stop button and reset button" width="80%"> </p>
