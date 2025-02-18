# Mechatronic Microcontroller Project MXEN2003

## Laboratory 4: Driving higher loads and IR range sensor

### Lab Briefing

During this lab you will be driving higher power loads using transistors and darlington drivers. 

The microcontroller has a limit of 40mA on an IO pin which means that any peripheral which needs more than this will need to have a external power supply. A transistor or darlington driver (built from transistors) can be used to provide a higher current to the load acting as an electrical switch. The lectures cover transistors and darlington drivers in more detail.

For this lab, you will be provided with two or more Sharp analog range sensors (2Y0A21, 2D120X), with ranges between 30 and 120cm.  You will calibrate a range sensor and use it to control a DC motor.  

The serial terminal will be used to display the range detected by the sensor, which is updated on a continuous basis.  You may want to use a push button to to “freeze” or store range readings to help with calibration.

You will need to determine the relationship between analog voltage and the sensor range. Does the sensor behave according to the datasheet?
  -  You should manually calibrate the relationship between the input voltage and the range.  You can then use a lookup table or a modelled mathematical relationship to determine the range corresponding to a given voltage.
  -  These sensors will be used for your final robot task, so the calibration you do here will be valuable later as long as it is done well.

<p align="center"> <img src="https://cdn.sparkfun.com//assets/parts/1/8/4/00242-1.jpg" alt="IR Distance Sensor" width="30%"> </p>

**TASK 1**

Drive a 12 volt lamp using a transistor to blink it on and off a couple of times a second, without having any risk of damaging the microcontroller.

**TASK 2**

Use the range sensor to control the DC motor, turning on the DC motor if there is an object within 10cm.

**TASK 3**

Gather data to calibrate the range sensor and demonstrate a calibrated range sensor printing distance to an serial. 



### Before the lab
- **Review string formatting in c, suggest using sprintf [reference](https://en.cppreference.com/w/cpp/io/c/fprintf)**
- **Review analog input**
- **Draw a circuit diagram of the range sensor, 2N3904 NPN transistor and darlington driver showing pin connections to the microcontroller**
- **Plan code using a flow diagram for the recording of sensor values**
- **Read range sensor datasheet for the [long](https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a21yk_e.pdf) and [short](https://www.digikey.com/htmldatasheets/production/9627/0/0/1/GP2D120-Datasheet.pdf) and plan testing to determine the relationship between analogue voltage and distance.**
- **Investigate flyback protection and why we might need it when controlling DC motors or Electromagnets**

### Outcomes
- Demonstrate a load (12 volt lamp) being driven using a transistor ensure this is safe for all components.
- Demonstrate an inductive load being driven using a darlington driver including flyback diode for protection.
- Demonstrate a DC motor being triggered by range sensor.
- Show range sensor calibration plan and how you will use the results
  - You may need some form of data linearization
- Describe the function of the flyback diode in the darlington driver and motor circuit.
  - Explain what happens to the current flow when the motor is switched off (with and without the flyback diode)
  - Include a circuit diagram
