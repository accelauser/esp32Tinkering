#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
    Wire.begin(11,10);
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    // Display static text

}

void loop(){
    for (int i = 0; i < 10; i++){
        display.printf("%d ",i);
        display.display();
        delay(100);
    }
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Hello, world!");
    display.display(); 
}