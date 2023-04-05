#include <Arduino.h>
#include <Servo.h>
#include <JC_Button.h>

const int servoPin = 9;
const int button1Pin = 7;
const int button2Pin = 6;
const int button3Pin = 5;

Servo Servo1;
Button button1(button1Pin);
Button button2(button2Pin);
Button button3(button3Pin);

int blindsOpen = 180;
int blindsClosed = 0;
int blindsCenter = 90;

void setup() {
  button1.begin();
  button2.begin();
  button3.begin();
  Servo1.attach(servoPin);
  Servo1.write(blindsCenter);
  delay(500);
  Servo1.detach();
}

void OpenBlinds(){

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
  button1.read();
  button2.read();
  button3.read();

  if (button1.wasPressed()){
    CloseBlinds();
  } 
  if (button2.wasPressed()){
    MiddleBlinds();
  } 
  if (button3.wasPressed()){
    OpenBlinds();
  }
}
