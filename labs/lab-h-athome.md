# Mechatronic Microcontroller Project MXEN2002

### Laboratory H: Differential drive and communications (at home version)

**Before the lab**:
- Ensure you have read the lecture notes on PWM, H-bridges, motors and communication
- Review the L293 H-bridge datasheet: http://www.micropik.com/PDF/l293b.pdf
- Review the PWM section of the ATmega2560 datasheet (section 17, p133): http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf
- Review the communication sample provided at https://github.com/mxeng/mcp-docs/blob/master/code-examples/comms_sample_controller.c


Task:
- Compile and upload the communication sample file as controller.c, verify that the communication works as expected using the serial terminal. **(H1)**
- Change your communication protocol to send the two joystick channels in the two message bytes. Note that the values will need to be scaled, as the ADC will give you a 10 bit number (0-1023) while the communication protocol requires a value from 0-253. Explain the communication protocol in your lab book. **(H2)**
- Verify you can read these values correctly on the serial terminal. **(H3)**
- Mix the joystick values to produce a differential drive: 
-- joystick forward should result in left motor forward and right motor forward
-- joystick back should result in left motor back and right motor back
-- joystick left should result in left motor back and right motor forward
-- joystid right should result in left motor forward and right motor back
- Show the calculations required to convert the two joystick signals into suitable PWM comparison and direction values for the left motor and right motor. **(H4)**
- Demonstrate a working differential drive system with smooth control of both motors (with one motor, demonstrate both sides of the H bridge chip. **(H5)**

<p align="center"> <img src="https://github.com/mxeng/mcp-docs/blob/master/labs/robot_drive.png" alt="robot drive diagram" width="80%"> </p>
