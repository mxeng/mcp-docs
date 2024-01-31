# Mechatronic Microcontroller Project MXEN2003

## Laboratory 4:  Range sensor calibration and the LCD

### Lab Briefing

For this lab, you will be provided with two or more Sharp analog range sensors (2Y0A21, 2D120X), with ranges between 30 and 120cm.  You will devise a “range meter” using the sensors, an LCD display and one or more push buttons.  The LCD display will be used to display the range detected by the sensor, which is updated on a continuous basis.  The push buttons will be used to “freeze” or store range readings for later viewing, or for comparison to another distance.

You will need to determine the relationship between analog voltage and the sensor range. Does the sensor behave according to the datasheet?
  -  You should manually calibrate the relationship between the input voltage and the range.  You can then use a lookup table or a modelled mathematical relationship to determine the range corresponding to a given voltage.
  -  These sensors will be used for your final robot task, so the calibration you do here will be valuable later as long as it is done well.

<p align="center"> <img src="https://cdn.sparkfun.com//assets/parts/1/8/4/00242-1.jpg" alt="IR Distance Sensor" width="30%"> </p>

You will need to use a LCD screen to display the voltage and then distance being read by the range sensor. There is a library provided in the framework code for you the, *hd44780*, which provides functionality for writing to the LCD screen.

**TASK 1**

Use a LCD screen to display voltage (or ADC value) from the range sensor, with a push button being used to *freeze* the value.

**TASK 2**

Gather data to calibrate the range sensor and demonstrate a calibrated range sensor printing distance to an LCD screen. 

### Before the lab
- **Review the “hd44780” Library in your provided framework code and LCD [datasheet](https://pdf.datasheetcatalog.com/datasheet/vishay/016m002b.pdf)**
- **Review string formatting in c, suggest using sprintf [reference](https://en.cppreference.com/w/cpp/io/c/fprintf)**
- **Review analog input**
- **Draw a circuit diagram of the LCD screen and range sensor showing pin connections to the microcontroller**
- **Plan code using a flow diagram for the recording of sensor values**
- **Read range sensor datasheet for the [long](https://global.sharp/products/device/lineup/data/pdf/datasheet/gp2y0a21yk_e.pdf) and [short](https://www.digikey.com/htmldatasheets/production/9627/0/0/1/GP2D120-Datasheet.pdf) and plan testing to determine the relationship between analogue voltage and distance.**

### Outcomes
- Demonstrate a functional LCD display
- Sketch a circuit diagram of the LCD screen and range sensor showing pin connections
- Draw a flowchart showing the program logic, for calibrating range sensor (task 1)
- Demonstrate the range sensor reading on the LCD display, with push botton.
- Demonstrate a calibrated range sensor printing distance on the LCD screen
