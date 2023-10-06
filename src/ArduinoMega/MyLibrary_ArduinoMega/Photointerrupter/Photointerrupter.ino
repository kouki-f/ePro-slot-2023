#include "Photointerrupter.h"

Photointerrupter photoSensor1(2);

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  if(photoSensor1.readPhoto()){
    digitalWrite(3, HIGH);
  }else{
    digitalWrite(3, LOW);
  }
}
