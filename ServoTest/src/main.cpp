#include <Arduino.h>
#include <Servo.h>
#include <JC_Button.h>

const int servoPin = 9;
const int buttonPin = 7;

Servo Servo1;
Button button(buttonPin);

int blindsOpen = 180;
int blindsClosed = 0;
int blindsCenter = 90;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Servo1.attach(servoPin);
  Servo1.write(blindsCenter);
  delay(500);
  Servo1.detach();
}

void OpenBlinds(){
  button.begin();
  Servo1.attach(servoPin);
  Servo1.write(blindsOpen);
  delay(500);
  Servo1.detach();
}

void CloseBlinds(){
  Servo1.attach(servoPin);
  Servo1.write(blindsClosed);
  delay(500);
  Servo1.detach();
}

void MiddleBlinds(){
  Servo1.attach(servoPin);
  Servo1.write(blindsCenter);
  delay(500);
  Servo1.detach();
}

void loop() {
  //static bool blindsState;
  button.read();

  if (button.wasPressed()){
    CloseBlinds();
  } 
}
