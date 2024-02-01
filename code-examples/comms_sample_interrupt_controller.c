//include this .c file's header file
#include "Controller.h"

//static function prototypes, functions only called in this file


//file scope variables
static char serial_string[200] = {0};
volatile uint8_t dataByte1=0, dataByte2=0, dataByte3=0, dataByte4=0;		// data bytes received
volatile bool new_message_received_flag=false;


int main(void)
{
	// initialisation
	serial0_init(); 	// terminal communication with PC
	serial2_init();		// microcontroller communication to/from another Arduino
	// or loopback communication to same Arduino
	
	uint8_t sendDataByte1=0, sendDataByte2=0, sendDataByte3=0, sendDataByte4=0;		// data bytes sent
	
	uint32_t current_ms=0, last_send_ms=0;			// used for timing the serial send
	
	UCSR2B |= (1 << RXCIE2); // Enable the USART Receive Complete interrupt (USART_RXC)
	
	milliseconds_init();
	sei();
	
	while(1)
	{
		current_ms = milliseconds_now();
		//sending section
		if(current_ms-last_send_ms >= 100) //sending rate controlled here one message every 100ms (10Hz)
		{
			// this is just incrementing variables to send for testing purposes
			// you will put the code here that puts the message you want to send into sendDataByte1 and sendDataByte2
			sendDataByte1++; //increments byte 1 by 1 every send
			if (sendDataByte1>253) //Causes byte 1 to wrap back to 0 when exceeding 253
			sendDataByte1 = 0;
			
			sendDataByte2+=2; //increments byte 2 by 2 every send
			if (sendDataByte2>253)
			sendDataByte2 = 0;
			
			sendDataByte3+=3; //increments byte 3 by 3 every send
			if (sendDataByte3>253)
			sendDataByte3 = 0;
			
			sendDataByte4+=4; //increments byte 4 by 4 every send
			if (sendDataByte4>253)
			sendDataByte4 = 0;
			//You should replace the above data byte code with your own definitions
			//or calculations of what should be sent in the bytes
			
			// you can add additional bytes to send in the message,
			//but make sure the receiving code is expecting the right number of bytes
			
			last_send_ms = current_ms;
			serial2_write_byte(0xFF); 		//send start byte = 255
			serial2_write_byte(sendDataByte1); 	//send first data byte: must be scaled to the range 0-253
			serial2_write_byte(sendDataByte2); 	//send second parameter: must be scaled to the range 0-253
			serial2_write_byte(sendDataByte3); 	//send first data byte: must be scaled to the range 0-253
			serial2_write_byte(sendDataByte4); 	//send second parameter: must be scaled to the range 0-253
			serial2_write_byte(0xFE); 		//send stop byte = 254
		}

		//if a new byte has been received
		if(new_message_received_flag) 
		{
			// now that a full message has been received, we can process the whole message
			// the code in this section will implement the result of your message
			sprintf(serial_string, "received: 1:%4d, 2:%4d , 3:%4d , 4:%4d \n", dataByte1, dataByte2, dataByte3, dataByte4);
			serial0_print_string(serial_string);  // print the received bytes to the USB serial to make sure the right messages are received

			new_message_received_flag=false;	// set the flag back to false
		}
	}
	return(1);
} //end main


ISR(USART2_RX_vect)  // ISR executed whenever a new byte is available in the serial buffer
{
	static uint8_t recvByte1=0, recvByte2=0, recvByte3=0, recvByte4=0;		// data bytes received
	static uint8_t serial_fsm_state=0;									// used in the serial receive ISR
	uint8_t	serial_byte_in = UDR2; //move serial byte into variable
	
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
}
