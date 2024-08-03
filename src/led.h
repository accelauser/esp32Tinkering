#include <driver/ledc.h> //https://docs.espressif.com/projects/arduino-esp32/en/latest/api/ledc.html

#define redPin 15
#define greenPin 16
#define bluePin 17
#define redChannel 2
#define blueChannel 3
#define greenChannel 4
#define MAX_DUTY_CYCLE 255 //valor máximo que pode mandar para um LED

void pulse (int delayTime, int channel){
    for(int dutyCycle = 0; dutyCycle <= MAX_DUTY_CYCLE; dutyCycle++){   
        ledcWrite(channel, dutyCycle);
        delay(delayTime);
    }
    for(int dutyCycle = MAX_DUTY_CYCLE; dutyCycle >= 0; dutyCycle--){
        ledcWrite(channel, dutyCycle);   
        delay(delayTime);
    }
}

void rgbStripe(int rValue, int gValue, int bValue){
    ledcWrite(greenChannel, 255 - gValue); //desliga os leds 255 é o valor onde tem 0 cor no led
    ledcWrite(redChannel, 255 - rValue); 
    ledcWrite(blueChannel, 255 - bValue);
}

bool ledSetup(void){
    ledcSetup(redChannel, 500, 8); //cria os canais baseados em um número, define a frequência e o número de bytes
    ledcSetup(blueChannel, 500, 8);
    ledcSetup(greenChannel, 500, 8);
    ledcAttachPin(redPin, redChannel); //atribui os pinos aos canais 
    ledcAttachPin(bluePin, blueChannel);
    ledcAttachPin(greenPin, greenChannel);
    ledcWrite(greenChannel, 255); //desliga os leds 255 é o valor onde tem 0 cor no led
    ledcWrite(redChannel, 255); 
    ledcWrite(blueChannel, 255);
    rgbStripe(50,0,255);
    return true;
}
