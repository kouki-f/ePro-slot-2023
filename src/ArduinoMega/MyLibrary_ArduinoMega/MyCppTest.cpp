#include "MyCppTest.h"
#include <Arduino.h>

MyCppTest::MyCppTest(int pin){
  m_pin = pin;
  pinMode(m_pin, OUTPUT);
}

MyCppTest::High(){
  digitalWrite(m_pin, HIGH);
}

MyCppTest::Low(){
  digitalWrite(m_pin, LOW);
}