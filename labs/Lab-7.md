# Mechatronic Microcontroller Project MXEN2002

## Laboratory : Serial Communications

### Lab Briefing

Universal Synchronous and Asynchronous serial Receiver and Transmitter or USART is a flexible serial communication device. It is a 2 pin commmunication system using transmit, Tx, and Receive, Rx, pins for independant full duplex communication. In this lab we will be using it in asynchronous mode with each device having its own internal clock generation. For wireless communication you will be using XBee modules to connect Tx on one microcontroller to Rx on the other wirelessly.

The framework provided to you sets up USART for a baudrate of 9600 using 8 bit character sizes. It includes functions for initialising the serial communication and for writing a byte or string to serial, see serial.c.

A communication protocol defines how each device communicates accross its communication channel, in this case USART. You will need to define what is being sent/recieved by each device across the serial communication.

Some sample code is provided which you may use as a starting point for creating your communication protocol for communicating accross serial using a multi-byte protocol, see comms_example_interrupt.c

- A controller Arduino will be provided, equipped with an LCD display, two analogue joysticks and an XBee communication unit.  
  Schematic: https://github.com/mxeng/mcp-docs/blob/master/labs/controller_schematic.pdf

Below is an example of multibyte sending serial commmunication using the USART framework provided.

### Multibyte Sending:
```c
//main loop
	current_ms = milliseconds;
	
	//sending section
	if( (current_ms-last_send_ms) >= 100) //sending rate controlled here
	{
		last_send_ms = current_ms;
		serial2_write_byte(255); //send start byte
		serial2_write_byte(1); //send test value for first parameter
		serial2_write_byte(2); //send test value for second parameter
		serial2_write_byte(3); //send test value for third parameter
		serial2_write_byte(4); //send test value for fourth parameter
		serial2_write_byte(5); //send test value for fifth parameter
		serial2_write_byte(254); //send stop byte
	}
```

This will send 5 bytes of information with delimited by a start byte (255) and stop byte (254).

Then this is an example of multibyte receiving of information using the same structure.

### Multibyte Recieving:
```c
	serial_byte_in = UDR2; //move serial byte into variable
	
	switch(serial_fsm_state) //switch by the current state
	{
		case 0:
		//do nothing, if check after switch case will find start byte and set serial_fsm_state to 1
		break;
		case 1: //waiting for first parameter
		recvByte1 = serial_byte_in;
		serial_fsm_state++;
		break;
		case 2: //waiting for second parameter
		recvByte2 = serial_byte_in;
		serial_fsm_state++;
		break;
		case 3: //waiting for second parameter
		recvByte3 = serial_byte_in;
		serial_fsm_state++;
		break;
		case 4: //waiting for second parameter
		recvByte4 = serial_byte_in;
		serial_fsm_state++;
		break;
		case 5: //waiting for stop byte
		if(serial_byte_in == 0xFE) //stop byte
		{
			// now that the stop byte has been received, set a flag so that the
			// main loop can execute the results of the message
			dataByte1 = recvByte1;
			dataByte2 = recvByte2;
			dataByte3 = recvByte3;
			dataByte4 = recvByte4;
			
			new_message_received_flag=true;
		}
		// if the stop byte is not received, there is an error, so no commands are implemented
		serial_fsm_state = 0; //do nothing next time except check for start byte (below)
		break;
	}
	if(serial_byte_in == 0xFF) //if start byte is received, we go back to expecting the first data byte
	{
		serial_fsm_state=1;
	}
```

The above needs to be incorporated into either a polling or interrupt driven routine to control when information is taken out of the USART I/O Data Register (UDRn).

### Full Example:
The above code snippets can be found incorporated into a full interrupt driven script for comms at:
https://github.com/mxeng/mcp-docs/blob/master/code-examples/comms_sample_interrupt_controller.c

**TASK 1**

Your task is to achieve 2-way simultaneous communication between 2 microcontrollers. 
- Microcontroller one "*robot*" will read and transmit range sensor values, and control a servo motor from serial commands.
- Microcontroller two "*controller*" will read and transmit joystick values while outputting range sensor values from serial to an LCD screen.

### Before the lab
- Revise lab 2, 4 for joystick and range sensor reading
- Revise lab 6 for servo control
- Revise LCD printing
- Ensure you have read the lecture notes on serial communication
- Plan your communication protocol defining what is being sent and recieved by each device
- Read and familiarize with the USART documentation in the ATmega datasheet chapter 22
- Review the XBee datasheet

### Outcomes

1. Define the communication protocol for serial communication between the robot and controller microcontrollers.
	- Ensure it is clear how the instructions are structured and how they are delimited.
2. Discuss any considerations for ensuring adequate data flow: i.e ensuring that buffer overflows
do not occur, and that latency is minimised.
3. Demonstrate the use of serial for debugging code, show that if code enters erronomous states there is adaquate error states for debuggin
4. Demonstrate functional 1-way communication
5. Demonstrate functional 2-way communication


Note if using the code in that example for the Robot (i.e. programming in Robot.c), replace #include "Controller.h" with #include "Robot.h"
