# Mechatronic Microcontroller Project MXEN2002

### Laboratory G: Serial Communications

**Before the lab**:
- Ensure you have read the lecture notes on serial communication, PWM and servomotors
- Review the instructions given in the Lecture session
- Review the Atmega datasheet on timers and PWM
- Review the XBee datasheet


Task:
- A controller Arduino will be provided, equipped with an LCD display, two analogue joysticks and an XBee communication unit.  
  Schematic: https://github.com/mxeng/mcp-docs/blob/master/labs/controller_schematic.pdf
- You should establish wireless communication between two the controller unit and your robot Arduino unit equipped with a second XBee.
- Transmit instructions for two servos (as per lab F) from the control unit to the robot unit. **(G1)**
- Transmit sensor readings back from the robot unit to the control unit. **(G2)**
- Signal transmission should be simultaneous, smooth, and with little latency or delay.


Note:
- Show the design of your communication protocol in your lab book **(G3)**. Make it clear how
your instructions are structured, and how the instructions are delimited.
- Discuss any considerations for ensuring adequate data flow: i.e ensuring that buffer overflows
do not occur, and that latency is minimised. **(G4)**
- Include schematics for both of your circuits in your lab book. **(G5)**

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

### Full Example:
The above code snippets can be found incorporated into a full interrupt driven script for comms at:
https://github.com/mxeng/mcp-docs/blob/master/code-examples/comms_sample_interrupt_controller.c

Note if using the code in that example for the Robot (i.e. programming in Robot.c), replace #include "Controller.h" with #include "Robot.h"
