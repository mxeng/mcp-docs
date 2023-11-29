# Mechatronic Microcontroller Project MXEN2002

## Laboratory F: PWM for servo control

### Lab Briefing

During this laboratory you will be using the hardware timer/counters to generate a PWM to control the position of a servo motor. The servo motors support are position controlled via a 40-60Hz PWM (recommend 50Hz). The HIGH period determines the position of the servo where ~1ms is maximum negative direction and 2ms maximum positive direction and 1.5ms is central position.

You will need to configure a timer/counter to generate a PWM as this control signal and determine what is safe operating range is. The microcontroller has a limited power output from its internal 5 volt regulator and you may need to use an external regulator if this is insufficient see [LM7805](https://www.st.com/resource/en/datasheet/l78.pdf)

**TASK 1**

Establish control over two servos, using two independent PWM signals produced by one or two of the microcontroller timers.
  
### Before the lab
- Ensure you have read the lecture notes on timers, PWM and servomotors
- Review the Atmega datasheet on timers and PWM
- Calculate prescaler values and comparison ranges suitable for the servo control task: the base period of the servomotor: a base period in the range 15-25ms is recommended

### Outcomes
1. Show calculations for PWM base frequency and duty cycle, state clearly the sage operating range for comparison values
2. Explain how the timer/counter registers are configured to achieve the desired PWM
3. Demonstrate an appropriate PWM on an oscilloscope
   - Demonstrate this prior to connecting to a servo motor, an incorrect waveform can damage the servo motors
4. Demonstrate *smooth* control of a servo motor
5. Demonstrate simultaneous independent control of two servo motors
   - This may require a 5 volt regulator if the power requirements for the servo motors is too large

<p align="center"> <img src="https://upload.wikimedia.org/wikipedia/commons/3/30/Two_hobby_servo_motors.jpg" alt="RC Servos" width="30%"> </p>
