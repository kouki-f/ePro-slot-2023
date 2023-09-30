#include "MyCppTest.h"
#include "Arduino.h"

MyCppTest::MyCppTest(int pin){
  m_pin = pin;
  pinMode(m_pin, OUTPUT);
}

void MyCppTest::High(){
  digitalWrite(m_pin, HIGH);
}

void MyCppTest::Low(){
  digitalWrite(m_pin, LOW);
}