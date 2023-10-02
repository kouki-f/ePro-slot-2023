#include "ButtonWithLed.h"
#include "Arduino.h"

ButtonWithLed::ButtonWithLed(int bnPin, int ledPin){
  m_bnPin = bnPin;
  m_ledPin = ledPin;
  pinMode(m_bnPin, INPUT_PULL_UP);
  pinMode(m_ledPin, OUTPUT);
}

bool ButtonWithLed::readButton(){
  return !digitalRead(m_bnPin) == HIGH;  //PULL_UP => LOW is Push
}

void ButtonWithLed::turnOn(){
  digitalWrite(m_ledPin, HIGH);
}

void ButtonWithLed::turnOff(){
  digitalWrite(m_ledPin, LOW);
}