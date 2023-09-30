#include <Stepper.h>

int around_step = 200;  // 1回転ステップ数
int step = 10;
int speed =80;   // 回転スピード(rpm）

Stepper stepper(around_step, 4,5,6,7);

void setup() {
  stepper.setSpeed(speed);
}

void loop() {
  stepper.step(step);
}