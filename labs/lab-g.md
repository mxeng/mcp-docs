# Mechatronic Project 234

### Laboratory G: PWM for servo control

**Before the lab**:
- Ensure you have read the lecture notes on serial communication, PWM and servomotors
- Review the instructions given in the Lecture session
- Review the Atmega datasheet on timers and PWM
- Review the XBee datasheet


Task:
- A controller Arduino will be provided, equipped with an LCD display, two analogue joysticks and an XBee communication unit. A schematic for the controller is provided on Blackboard.
- You should establish wireless communication between two the controller unit and your robot Arduino unit equipped with a second XBee.
- Transmit instructions for two servos (as per lab F) from the control unit to the robot unit. **(G1)**
- Transmit sensor readings back from the robot unit to the control unit. **(G2)**
- Signal transmission should be simultaneous, smooth, and with little latency or delay.

<p align="center"> <img src=https://itp.nyu.edu/archive/physcomp-spring2014/uploads/XbeeCommunication.png" alt="XBee serial bridge" width="30%"> </p>


Note:
- Show the design of your communication protocol in your lab book **(G3)**. Make it clear how
your instructions are structured, and how the instructions are delimited.
- Discuss any considerations for ensuring adequate data flow: i.e ensuring that buffer overflows
do not occur, and that latency is minimised. **(G4)**
- Include schematics for both of your circuits in your lab book. **(G5)**
