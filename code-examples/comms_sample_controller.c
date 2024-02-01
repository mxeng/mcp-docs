
//include this .c file's header file
#include "Controller.h"

//static function prototypes, functions only called in this file


//file scope variables
static char serial_string[200] = {0};

int main(void)
{
	// initialisation
	serial0_init(); 	// terminal communication with PC
	serial2_init();		// microcontroller communication to/from another Arduino 
				// or loopback communication to same Arduino
	
	milliseconds_init();
	
	uint8_t sendDataByte1=0, sendDataByte2=0;		// data bytes sent
	uint8_t recvDataByte1=0, recvDataByte2=0;		// data bytes received
	
	uint32_t current_ms=0, last_send_ms=0;			// used for timing the serial send
	
	uint8_t serial_byte_in=0, serial_fsm_state=0;	// used in the serial receive section
	
	while(1)
	{
		current_ms = milliseconds_now();
		//sending section
		if(current_ms-last_send_ms >= 100) //sending rate controlled here one message every 100ms (10Hz)
		{	
			// this is just incrementing variables to send for testing purposes
			// you will put the code here that puts the message you want to send into sendDataByte1 and sendDataByte2
			sendDataByte1++;
			sendDataByte2+=2;
			if (sendDataByte1>253)
				sendDataByte1 = 0;
			if (sendDataByte2>253)
				sendDataByte2 = 0;
			
			// you can add additional bytes to send in the message, 
			//but make sure the receiving code is expecting the right number of bytes
			
			last_send_ms = current_ms;
			serial2_write_byte(0xFF); 		//send start byte = 255
			serial2_write_byte(sendDataByte1); 	//send first data byte: must be scaled to the range 0-253
			serial2_write_byte(sendDataByte2); 	//send second parameter: must be scaled to the range 0-253
			serial2_write_byte(0xFE); 		//send stop byte = 254
		}

		//receiving section
		if(UCSR2A&(1<<RXC2)) //if new serial byte has arrived: refer to page 238 of datasheet. Single bit flag indicates a new byte is available
		{
			serial_byte_in = UDR2; //move serial byte into variable
			
			switch(serial_fsm_state) //switch by the current state
			{
				case 0:
				//do nothing, if check after switch case will find start byte and set serial_fsm_state to 1
				break;
				case 1: //waiting for first parameter
					recvDataByte1 = serial_byte_in;
					serial_fsm_state++;
				break;
				case 2: //waiting for second parameter
					recvDataByte2 = serial_byte_in;
					serial_fsm_state++;
				break;
				case 3: //waiting for stop byte
					if(serial_byte_in == 0xFE) //stop byte
					{
						// now that the stop byte has been received, we can process the whole message
						// the code in this section will implement the result of your message

						sprintf(serial_string, "received: 1:%4d, 2:%4d \n", recvDataByte1, recvDataByte2);
						serial0_print_string(serial_string);  // print the received bytes to the USB serial to make sure the right messages are received				
					} 
					// if the stop byte is not received, there is an error, so no commands are implemented
					serial_fsm_state = 0; //do nothing next time except check for start byte (below)
				break;
			}
			if(serial_byte_in == 0xFF) //if start byte is received, we go back to expecting the first data byte
			{
				serial_fsm_state=1;
			}
		}	
	}
	return(1);
} //end main
