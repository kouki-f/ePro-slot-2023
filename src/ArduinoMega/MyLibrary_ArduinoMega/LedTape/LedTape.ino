#include "LedTape.h"

LedTape ledTape(18, 19);

void setup() {
  // put your setup code here, to run once:
  ledTape.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  ledTape.test1();
  delay(1000);
  ledTape.test2();
  delay(1000);
}
