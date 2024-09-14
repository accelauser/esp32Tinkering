#include <Wire.h>
#include <Arduino.h>
// i2c adress 0x3C

void i2cScan() {
  // Leonardo: wait for serial port to connect
  while (!Serial) 
    {
    }
  delay(3000);
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin(11,10);
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

