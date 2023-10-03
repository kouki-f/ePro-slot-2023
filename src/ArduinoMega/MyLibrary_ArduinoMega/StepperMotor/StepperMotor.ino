//#include <Stepper.h>
#include "StepperMotor.h"
int speed = 80;
StepperMotor motor1(speed, 4, 5, 6, 7);

void setup() {
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  while(digitalRead(10)){
    motor1.rotateAngle(5);
  }
  while(1){}
}