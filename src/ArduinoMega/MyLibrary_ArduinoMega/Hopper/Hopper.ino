#include "Hopper.h"

int motor_pin = 2;
int motor_photo = 3;

Hopper hopper(motor_pin, motor_photo);

void setup() {
  Serial.begin(9600);
  hopper.payOutCoin(5);
}

void loop() {
}
