#include <Arduino.h> 
#include <led.h>
#include <i2cTest.h>
#include <Wire.h>


void setup(){
    ledSetup(); //led.h function not ledc lib function
    i2cScan();
}

void loop(){
    pulse(4, redChannel);
    pulse(4, blueChannel);
    pulse(4, greenChannel);
}