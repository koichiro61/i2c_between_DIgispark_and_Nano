// i2c master sender rumning on Digispark
//
// modified from sample program in the below library 
// https://github.com/lucullusTheOnly/TinyWire

#include <TinyWire.h>

#define button_pin 3
#define led_pin 1

byte slave_address = 10;


void setup() {
	// config button_pin als INPUT for a connected button (normally open; connects to GND)
	pinMode( button_pin, INPUT_PULLUP);
	// config led_pin as OUTPUT for a connected LED
	pinMode( led_pin, OUTPUT);
	
	// config TinyWire library for I2C master functionality
	TinyWire.begin();
}

void loop() {
	// check, if the button was pressed
	if(digitalRead(button_pin) == LOW) {
  //if (true) {
		// begin a master transmission with the slave's address as parameter
		TinyWire.beginTransmission(slave_address);
		// fill the send buffer with bytes
		TinyWire.send('c');
		// endTransmission sends the bytes in the buffer to the slave and returns 0 if there was no error
		// (otherwise you can find the different error code definitions in TinyWire.h)
		if(TinyWire.endTransmission() != 0){
			// turn LED on, to indicate an error
			digitalWrite(led_pin, HIGH);
		}
		delay(300);
		// reset LED after a little delay
		digitalWrite(led_pin, LOW);
	}
}
