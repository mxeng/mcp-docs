# Mechatronic Project 234

### Laboratory H: Motor Control

**Before the lab**:
- Ensure you have read the lecture notes on PWM, H-bridges and motors: https://lms.curtin.edu.au/bbcswebdav/pid-2158837-dt-content-rid-22938419_1/courses/308824-Ux-061-01-Sxx-x1/lecture_07%285%29.pdf
- Review the L293 H-bridge datasheet: http://www2.st.com/content/ccc/resource/technical/document/datasheet/04/ac/22/f9/20/5d/43/a1/CD00000059.pdf/files/CD00000059.pdf/jcr:content/translations/en.CD00000059.pdf
- Review the PWM section of the ATmega2560 datasheet (section 17, p133): http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf
- Plan your H-bridge configuration

Task:
- Configure the L293 H-bridge circuit to control two motors with variable speed, and in both directions. You may choose your own configuration (i.e how to drive the direction and inhibit lines).Include a schematic/circuit diagram in your lab book. (H1)
- Demonstrate the generation of two or four (as required) PWM signals with a calculated base frequency in the range 100-500Hz with duty cycle variable between 0 and 100%. Show on the
oscilloscope, then use to drive the left and right robot motors. (H2)
- Add motor control signals to your communication protocol for Lab G. Describe the full communication protocol in your lab book (H3).
- Show the calculations required to convert “forward” (0-1023) and “turnrate” (0-1023) joystick signals into suitable PWM comparison values for the left motor and right motor. (H4)
- Demonstrate a working wireless robot drive system (Joystick->Xbee->H-bridge). (H5)
