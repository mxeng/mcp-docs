# Mechatronic Project 234

###Laboratory C:  Range sensor calibration and the LCD

**Before the lab:**
- **Review the “LiquidCrystal” Library in the Arduino Reference**
- **Review analog input**
- **Begin coding your program**

### Task:
For this lab, you will be provided with two or more Sharp analog range sensors (2Y0A21, 2D120X), with ranges between 30 and 120cm.  You will devise a “range meter” using the sensors, an LCD display and one or more push buttons.  The LCD display will be used to display the range detected by the sensor, which is updated on a continuous basis.  The push buttons will be used to “freeze” or store range readings for later viewing, or for comparison to another distance.

Some factors to consider:
- What is the relationship between analog voltage and the sensor range?  Does your sensor behave according to the datasheet?
- For best results, you should manually calibrate the relationship between the input voltage and the range.  You can then use a lookup table or a modelled mathematical relationship to determine the range corresponding to a given voltage.
- These sensors will be used for your final robot task, so the calibration you do here will be valuable later as long as it is done well.

<p align="center"> <img src="https://cdn.sparkfun.com//assets/parts/1/8/4/00242-1.jpg" alt="IR Distance Sensor" width="30%"> </p>

### Your documentation should include:
- A clear specification of the objective and scope of your task **(C1)**
- All circuit diagrams **(C2)**
- Flowcharts showing the program logic **(C3)**
- A clear summary of all calibration tests and resulting model to be used in code. **(C4)**
- A graph showing the results of your calibration **(C5)**
