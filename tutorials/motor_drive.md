If you think of the up axis on the joystick as the forwards component ```fc``` and the sideways axis as the turn right component ```rc```.

<p align="center"> <img src="fc-rc.png" alt="forwards component and right component" width="30%"> </p>

We can turn this into motor speeds to drive the robot. Declare two 16 bit signed variables for the motor speeds ```lm``` and ```rm```.
```c
static int16_t lm = 0;
static int16_t rm = 0;
```
The variables must be signed because they will sometimes be positive and sometimes be negative. When lm is positive the left motor will be driving forwards, and when lm is negative the left motor will be driving in reverse (same for ```rm``` and the right motor).



When we push up on the joystick, ```fc``` will increase and we want both motors to go forwards, so ```lm``` and ```rm``` will depend on ```fc```.
Something like this:

```c
lm = fc;
rm = fc;
```

What about turning? Well, if we push the joystick to the right ```rc``` will increase, and we want the left motor to speed up and the right motor to slow down.
So our motor speeds will be something like this:
```c
lm = fc + rc;
rm = fc - rc;
```

Now, since we want the robot to stop moving when the joystick is centred we need to offset ```fc``` by ```253/2```. ```126``` is close enough. We do the same for ```rc``` and our equations look like:
```c
lm = (fc-126) + (rc-126);
rm = (fc-126) - (rc-126);
```

The math simplifies a bit, so you can implement it like this if you want:
```c
lm = fc + rc - 253;
rm = fc - rc;
```

The speed of the motors is equal to the absolute value (```abs()```) of ```lm``` and ```rm``` and the direction is equal to the sign.

If we wire our H-bridge up so that the PWM goes to the enable lines and the direction lines are connected to any GPIO pins we can control our robot quite easily. PWM mode 8 is reccomended.

For the following wiring:
```
EnA: OC3A
In1: A0
In2: A1
EnB: OCRB
In3: A2
In4: A3
Out1, Out2: left motor
Out3, Out4: right motor
```
and assuming a top value of 10000. We can set the speed and direction like this:
```c
OCR3A = (int32_t)abs(lm)*10000/126; //lm speed from magnitude of lm
OC3RB = (int32_t)abs(rm)*10000/126; //lm speed from magnitude of rm

if(lm>=0) //if lm is positive
{
  //set direction forwards
  PORTA |= (1<<PA0);
  PORTB &= ~(1<<PA1);
}
else
{
  //set direction reverse
  PORTA &= ~(1<<PA0);
  PORTA |= (1<<PA1);
}

if(rm>=0) //if rm is positive
{
  //set direction forwards
  PORTA |= (1<<PA2);
  PORTA &= ~(1<<PA3);
}
else
{
  //set direction reverse
  PORTA &= ~(1<<PA2);
  PORTA |= (1<<PA3);
}
````
Note that the values in OCR1A and OCR1B will exceed the TOP value. This will work in PWM mode 8 but won't work in mode 10.

You will also need to set the DDR bits for the direction control lines:
```c
DDRA |= (1<<DDA0)|(1<<DDA1)|(1<<DDA2)|(1<<DDA3); //put A0-A3 into low impedance output mode
```
