//we have to use hex as binary format is nonstandard

//upper nibble of PORTA in low impedance output mode
//lower nibble in high impedance input mode
DDRA = 0xF0;
//PORTK in low impedance output mode
DDRK = 0xFF;

//if we want put only one pin into output mode
//(as we should to be safe if only using one pin as output)

//pin A3 as output mode, rest remains in default input mode
//PORTC: IIII OIII (C7...C0)
DDRC = 0x08;

//but then we have to convert to hex (too much effort and easy to make mistakes)
//lets use a trick so we can just type in the pin we want to put into output mode

//pin A3 as output mode, using the simpler bit shifting method
DDRC |= (1<<3);
//lets do the same for C4
DDRC |= (1<<4);


//now lets do C5 and C6 in one go!
DDRC |= (1<<5)|(1<<6);

//it looks complicated at first, but it's actually much easier this way
//it's also easier to debug so it will save you from silly mistakes (hopefully)
//this method can also be used for turning outputs on

//drive C5 high
PORTC |= (1<<5);

//driving pins low is a bit more complicated
//we'll explain this in more detail later, but here's an example if you want


//drive C5 low again
PORTC &= ~(1<<5);
//don't worry if this is a bit confusing at the moment, you'll understand it pretty soon! :)
