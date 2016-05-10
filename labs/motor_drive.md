If you think of the up axis on the joystick as the forwards component ```fc``` and the sideways axis as the turn right component ```rc```.

We can turn this into motor speeds to drive the robot. Declare two 16 bit signed variables for the motor speeds ```lm``` and ```rm```:

```c
static int16_t lm = 0;
static int16_t rm = 0;
```

When lm is positive the left motor will be driving forwards, and when lm is negative the left motor will be driving in reverse (same for ```rm``` and the right motor).

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

Now, since we want the robot to stop moving when the joystick is centred we need to offset ```fc``` by ```253/2```. ```126``` is close enough:
```c
lm = (fc-126);
rm = (fc-126);
```
