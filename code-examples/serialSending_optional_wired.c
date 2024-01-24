void serial_sending_S(uint8_t numBytes, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6);

if(current_ms-last_send_ms>15) // 20Hz clocked loop
{
	last_send_ms = current_ms;
	serial_sending_S(5, byte,byte,byte,byte,byte,byte);
}

void serial_sending_S(uint8_t numBytes, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6)
{
	
	static uint8_t serial_send_state = 0;
	static uint8_t  sByte1,  sByte2,  sByte3,  sByte4,  sByte5, sByte6;
	
	switch(serial_send_state) //switch by the current state
	{
		case 0:
		serial2_write_byte(255); //send start byte
		sByte1 = byte1;
		sByte2 = byte2;
		sByte3 = byte3;
		sByte4 = byte4;
		sByte5 = byte5;
		sByte6 = byte6;
		serial_send_state++;
		break;
		case 1:
		serial2_write_byte(sByte1);//send byte1
		serial_send_state++;
		break;
		case 2:
		serial2_write_byte(sByte2);//send byte1
		serial_send_state++;
		break;
		case 3:
		serial2_write_byte(sByte3);//send byte1
		serial_send_state++;
		break;
		case 4:
		serial2_write_byte(sByte4);//send byte1
		serial_send_state++;
		break;
		case 5:
		serial2_write_byte(sByte5);//send byte1
		serial_send_state++;
		break;
		case 6:
		serial2_write_byte(sByte6);//send byte1
		serial_send_state++;
		break;
		case 7:
		serial2_write_byte(254); //send end byte
		serial_send_state = 0;
		break;
	}
	if(serial_send_state==(numBytes+1))
	{
		serial_send_state = 7;
	}
}
