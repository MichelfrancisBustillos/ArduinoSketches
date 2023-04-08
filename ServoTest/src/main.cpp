#include <Arduino.h>
#include <Servo.h>

const int servoPin = 9;
const int servoDelay = 700;
String userInput = "";
Servo Servo1;

void setup() {
  Serial.begin(9600);
  delay(5000);

  Servo1.attach(servoPin);
  Servo1.write(0);
  delay(servoDelay);
  Servo1.detach();

  Serial.println("Ready...");
}

int rangeConversion(int dimmer){
  int servoPosition = 0;
  int servoMin = 0;
  int servoMax = 180;
  int dimmerMin = 0;
  int dimmerMax = 100;
  int servoRange = (servoMax - servoMin);
  int dimmerRange = (dimmerMax - dimmerMin);

  servoPosition = (((dimmer - dimmerMin) * servoRange) / dimmerRange) + servoMin;

  return servoPosition;
}

void loop() {
  if(Serial.available()){
    userInput = Serial.readStringUntil('\n');
    int dimmer = userInput.toInt();
    int servoPosition = rangeConversion(dimmer); //Convert dimmer percentage input into servo steps
    //int servoPosition = dimmer; //Bypass rangeConversion for debugging
    Serial.println("Servo to ");
    Serial.print(servoPosition);
    Servo1.attach(servoPin);
    Servo1.write(servoPosition);
    delay(servoDelay);
    Servo1.detach();
  }
}
