- don't forget to initialise your serial subsystem:
```c
serial2_init();
```
- check the pin mapping (TX2/RX2)
- scale your data between 0 and 253:
```c
serial2_write_byte((uint32_t)adc_read(0)*253/1023);
```
