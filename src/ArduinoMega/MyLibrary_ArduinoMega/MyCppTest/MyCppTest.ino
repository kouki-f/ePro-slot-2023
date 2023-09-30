#include "MyCppTest.h"

MyCppTest led1(10);

void setup(){
Serial.begin(9600);
}

void loop() {
  led1.High();
  delay(300);
  led1.Low();
  delay(300);
}
