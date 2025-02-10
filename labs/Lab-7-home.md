# Mechatronic Microcontroller Project MXEN2003

## Laboratory 7 at home task:

This is an extension of lab 7 and will useful in future labs and your final project.

In this task you will use your knowledge of timers and analogue sensors to determine the frequency of a flashing light being detected by a photoresistor.

For this task you will need a photoresistor, a resistor to form a voltage divider and wires to connect them. You may find it useful to have a LED and resitor to use as a flashing light source.

**Task**

Determine the frequency a light is flashing which is being observed by a photoresistor. The suggested steps to use are outlined below.
  - Initialize a timer which will be used for sampling the ADCs at a specific interval
      - Suggest using CTC mode, using a timer interrupt with a frequency ~100 Hz (note this will mean the highest frequency signal that can be observed will be 50 Hz. See Nyquist Rate and Aliasing)
  - Use a static buffer array to store a number of adc samples (Use a index to store this position in this array and increment each time the sample is taken)
  - Create a function which uses the array and returns the frequency
      - Calculate the average of the ADC
      - Compare the value at each index to the average to determine if the signal is high or low
      - Count the number of edges
      - Convert the number of edges into frequency by using ADC sample frequency and duration
  - Run the function at a desired frequency and print the frequency

Tips
  - Minimize the processing in interrupts
  - Test using LED with known flashing frequencies
  - Start slow < 5Hz, some of the operations (especially if using floats) can be processing intense for the microcontroller)
  - Test at each stage (if it helps you can calculate the average separately or pass by reference or print in function)
