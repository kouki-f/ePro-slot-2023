#include "Photointerrupter.h"

Photointerrupter photoSensor1(2);

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(photoSensor1.readPhoto()==HIGH){
    digitalWrite(3, HIGH);
  }else{
    digitalWrite(3, LOW);
  }
}
