#include "Photointerrupter.h"

Photointerrupter photoSensor1(53);

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  if(photoSensor1.readPhoto()){
    //digitalWrite(3, HIGH);
    Serial.println("HIGH!");
  }else{
    // digitalWrite(3, LOW);
    Serial.println("LOW!");
  }
}
