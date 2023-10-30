#include <Stepper.h>
#include "StepperMotor.h"
int speed = 50;
StepperMotor motor1(speed, 2, 3, 4, 5);

void setup() {
  //pinMode(10, INPUT_PULLUP);
}

void loop() {
  //delay(1000);
  motor1.step(1);
}