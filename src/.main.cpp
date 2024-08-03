#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define redPin GPIO_NUM_15  //declarar assim faz funcionar o PWM
#define bluePin GPIO_NUM_17
#define greenPin GPIO_NUM_7



void rgbStrip(int redValue, int greenValue, int blueValue){
  //maior o valor menor a intensidade do LED
  int red = 255 - redValue;
  int green = 255 - greenValue;
  int blue = 255 - blueValue;
  if (redValue == 0){
    digitalWrite(redPin,HIGH);
  }
  else if (redValue == 255){
    digitalWrite(redPin, LOW);
  }
  else{
    analogWrite(redPin, red);
  }
  if (blueValue == 0){
    digitalWrite(bluePin,HIGH);
  }
  else if(blueValue == 255){
    digitalWrite(bluePin, LOW);
  }
  else{
  analogWrite(bluePin, blue);

  }
  if (greenValue == 0){
    digitalWrite(greenPin,HIGH);
  }
  else if(greenValue == 255){
    digitalWrite(greenPin, LOW);
  }
  else{
  analogWrite(greenPin, green);
  } 
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);    
  rgbStrip(0,0,0);
  pinMode(46, OUTPUT);
  ledcWrite(46, 300);

}

void loop() {

  for(int x = 0; x<256; x++){
    analogWrite(45, x);
  }

}
