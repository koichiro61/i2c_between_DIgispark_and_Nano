# i2c_between_Digispark_and_Nano

Since USB serial is not available on Digispark when PB3 and/or PB4 are connected to devices,
you cannot debug sketches by checking values of variables in the sketch with serial monitor
on your PC in this case.
The sketches in this repositry realizes i2c connection between Digispark and Arduino
so that values of variables or state of pins can be seen from Arduino and be displayed on serial monitor
on your PC via USB serial connection betweeb Arduino and the PC.

These codes are partial modification and porting to Nano based on the ones published
at https://github.com/lucullusTheOnly/TinyWire .
Many thanks to the author.
