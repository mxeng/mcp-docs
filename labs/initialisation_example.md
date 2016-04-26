Your init section on your robot might end up looking something like this (once you're doing two way communication):

```c
int main(void)
{
	//variable declarations
	static uint32_t current_ms = 0;
	static uint8_t serial_fsm_state = 0;
	static uint8_t serial_byte_in = 0;
	
	static uint8_t parameter_in_1 = 0;
	static uint8_t parameter_in_2 = 0;
	static uint8_t parameter_in_3 = 0;
	static uint8_t parameter_in_4 = 0;
	static uint8_t parameter_in_5 = 0;
	
	static uint8_t temp_parameter_in_1 = 0;
	static uint8_t temp_parameter_in_2 = 0;
	static uint8_t temp_parameter_in_3 = 0;
	static uint8_t temp_parameter_in_4 = 0;
	static uint8_t temp_parameter_in_5 = 0;
	
	static uint8_t parameter_out_1 = 0;
	static uint8_t parameter_out_2 = 0;
	static uint8_t parameter_out_3 = 0;
	
	//initialisation section, runs once
	serial0_init(); //initialise serial0 subsystem
	serial1_init(); //initialise serial1 subsystem
	adc_init(); //initialse ADC
	milliseconds_init(); //initialise timer one to track milliseconds
	motors_init(); //initialise motors, DDRs & PWM
	_delay_ms(10); //short delay
```
