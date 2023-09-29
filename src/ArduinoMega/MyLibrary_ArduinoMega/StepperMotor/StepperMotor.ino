#include <Stepper.h>

int around_step = 200;  //1回転ステップ数
int step = 10;
int speed = 50;  //50rpm
int motor_pin1 = 10;
int motor_pin2 = 11;

Stepper myStepper(around_step, motor_pin1, motor_pin2);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(100);
  delay(500);
  myStepper.step(-100);
  delay(500);
}
