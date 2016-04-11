# Mechatronic Microcontroller Project

### Laboratory F: PWM for servo control

**Before the lab:**
- Ensure you have read the lecture notes on timers, PWM and servomotors
- Review the Atmega datasheet on timers and PWM
- Calculate prescaler values and comparison ranges suitable for the servo control task: the base period of the servomotor: a base period in the range 15-25ms is recommended

### Task:
- Establish control over two servos, using two independent PWM signals produced by one or two of the microcontroller timers.
- Control servo 1 by position smoothly through the maximum horizontal range. The position of the servo should be in response to position of the analog joystick. **(F1)**
- Control servo 2 by velocity smoothly through the maximum horizontal range. The speed of the servo should be in response to the position of the analog joystick. **(F2)**


<p align="center"> <img src="https://cdn.sparkfun.com//assets/parts/8/3/0/8/11884-07.jpg" alt="RC Servo" width="30%"> </p>

### Note:
- Show the calculations for the PWM base frequency and duty cycle in your lab book **(F3)**
- Explain how the timer control registers are configured in order to achieve your desired base period and range of movement. State clearly the safe operating range for your comparison register values. **(F4)**
- Use a flowchart to outline the logic of your program **(F5)**
- Show the PWM signals to a demonstrator on a CRO before applying it to any servo, making sure you have carefully checked the waveform frequency and pulse durations so that the servos cannot be damaged
