// Ported from Tinywire Libarry
// https://github.com/lucullusTheOnly/TinyWire

#include <Wire.h>

#define led_pin 13  // for nano

byte own_address = 10;

volatile char vc ='x';
volatile int count = 0;

void setup() {
	// config led_pin as Output for driving an LED
	pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin,HIGH);
	
	// config TinyWire library for I2C slave functionality
	Wire.begin( own_address );
	// sets callback for the event of a slave receive
	Wire.onReceive( onI2CReceive );

 Serial.begin(9600);
}

void loop() {
  Serial.println(count);
  delay(500);
}

/*
I2C Slave Receive Callback:
Note that this function is called from an interrupt routine and shouldn't take long to execute
*/
void onI2CReceive(int howMany){
	// loops, until all received bytes are read
 count++;
	while(Wire.available()>0){
		// toggles the led everytime, when an 'a' is received
    vc = Wire.read();
		if(vc =='c') {
		  digitalWrite(led_pin, !digitalRead(led_pin));
		}
	}
}
