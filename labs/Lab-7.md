# Mechatronic Microcontroller Project MXEN2003

## Laboratory 7: Serial Communications, LCD printing and light following
### Lab Briefing

Universal Synchronous and Asynchronous serial Receiver and Transmitter or USART is a flexible serial communication device. It is a 2 pin commmunication system using transmit, Tx, and Receive, Rx, pins for independant full duplex communication. In this lab we will be using it in asynchronous mode with each device having its own internal clock generation. For wireless communication you will be using XBee modules to connect Tx on one microcontroller to Rx on the other wirelessly.

The framework provided to you sets up USART for a baudrate of 38400 using 8 bit character sizes. It includes functions for initialising the serial communication and for writing a byte, series of bytes of string to serial and functions to detect if new data is available, see serial.c and serial.h for descriptions of individual functions.

A communication protocol defines how each device communicates accross its communication channel, in this case USART. You will need to define what is being sent/recieved by each device across the serial communication. The *serial0_write_byte* function can be used for single byte communication and *serial#_write_bytes* for multibyte communication (and includes delimiting bytes. You will need to determine how many bytes to send and what data they will contain (with a maximum of 6 databytes per packet).

### Example of sending two bytes every 100ms;


```c
//main function initialization
serial2_init();
milliseconds_init();
uint8_t databyte1 = 0;
uint8_t databyte2 = 0;

while(1)
{
	//main loop
	current_ms = milliseconds_now();
	
	//sending section
	if( (current_ms-last_send_ms) >= 100) //sending rate controlled here
	{
		//Arbitrary process to update databytes
		databyte1++;
		databyte2+=2;
		
		//Function takes the number of bytes to send followed by the databytes as arguments
		serial2_write_bytes(2, databyte1, databyte2); 
		last_send_ms = current_ms;
	}
}
```
### Example of printing two bytes when available

```c
//main function initialization
serial2_init();
milliseconds_init();
uint8_t recievedData[2]; //recieved data array
char serial_string[60] = {0}; // String used for printing to terminal

while(1)
{
	//main loop
	current_ms = milliseconds_now();
	
	//sending section
	if(serial2_available()) //Returns true if new data available on serial buffer
	{
		//Function takes the array to return data to and the number of bytes to be read.
		serial2_get_data(recievedData,2); 
	        sprintf(serial_string,"\nData 1: %3u, Data2: %3u", recievedData[0],recievedData[1]); //Format string
	        serial0_print_string(serial_string); //Print string to usb serial
	}
}
```

- A controller Arduino will be provided, equipped with an LCD display, two analogue joysticks and an XBee communication unit.  
  Schematic: https://github.com/mxeng/mcp-docs/blob/master/labs/controller_schematic.pdf


### Alternate Example:
The above code uses a library for interrupt driven multibyte communication. If you find this limiting you can see the example below for how to build your own communication structure to enable more flexibility to communication.
https://github.com/mxeng/mcp-docs/blob/master/code-examples/comms_sample_interrupt_controller.c


### LCD printing

The controller arduino has an LCD display which you may use to display information as needed.  A tutorial with example of how to printo to the LCD is provided here https://github.com/mxeng/mcp-docs/blob/master/tutorials/LCD_example.c

### Light following

As part of the final task you will need to follow *beacons* which will be simplified as lights for this task. To do this you will need to use the light sensors you used previously to determine which direction the rover should turn of if it should stop.

**TASK 1**

Your task is to achieve 2-way simultaneous communication between 2 microcontrollers. 
- Microcontroller one "*robot*" will read and transmit sensor values (range sensors/ light sensors), and recieve commands to control a servo motor.
- Microcontroller two "*controller*" will read and transmit joystick values while printing relevant sensor values from serial to an LCD screen or terminal.
- You will need to interpret the signals and display on the *controller* if the robot should be stationary, moving forward, left or right based on light dependant resistor sensing.

### Before the lab
- Revise lab 2, 4 for joystick, light sensor and range sensor reading
- Revise lab 6 for servo control
- Read LCD printing tutorial
- Review string formatting
- Ensure you have read the lecture notes on serial communication
- Plan your communication protocol defining what is being sent and recieved by each device
	- Make a choice (with justification) for multibyte or single byte protocol
- Read and familiarize with the USART documentation in the ATmega datasheet chapter 22
- Review the XBee datasheet

### Outcomes

1. Define the communication protocol for serial communication between the robot and controller microcontrollers.
	- Ensure it is clear how the instructions are structured and how they are delimited.
	- Make it clear what information is sent in your communication protocol.
 		- Define this separately for each direction
2. Discuss design considerations for reliable commmunications:
   	- What is buffer overflow and why would it occur.
   	- What error detection exists in this communication. What could be added?
3. Demonstrate functional 1-way communication*
4. Demonstrate functional 2-way communication*
	- Including use of LCD screen
5. Demonstrate a functional interpretation of the sensor data
	- This must include some data transformation to make it readable, consider what might be useful for the final project.

*functional requires that it fulfills the requirements of the lab TASK
