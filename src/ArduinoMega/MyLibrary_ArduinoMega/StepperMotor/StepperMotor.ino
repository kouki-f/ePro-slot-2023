//#include <Stepper.h>
#include "StepperMotor.h"
int speed = 80;
StepperMotor motor1(speed, 4, 5, 6, 7);

void setup() {
  motor1.rotateAngle(90);
  delay(500);
  motor1.rotateAngle(90);
  delay(500);
  motor1.rotateAngle(90);
  delay(500);
  motor1.rotateAngle(90);
  delay(500);

  motor1.rotateAngle(-90);
  delay(500);
  motor1.rotateAngle(-90);
  delay(500);
  motor1.rotateAngle(-90);
  delay(500);
  motor1.rotateAngle(-90);
  delay(500);
}

void loop() {
  
}