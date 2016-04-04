```c
sprintf(lcd_string, "%d:%d.%d   ", minutes, seconds, hundredths); //build LCD string displaying time
lcd_goto(0x00); //send cursor to top left
lcd_puts(lcd_string); //write LCD string at cursor location
```
