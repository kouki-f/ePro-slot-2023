#include "ButtonWithLed.h"
#include "Arduino.h"

ButtonWithLed::ButtonWithLed(int bn_pin, int led_pin){
  pinMode(bn_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);

  m_bnPin = bn_pin;
  m_ledPin = led_pin;
  //m_isBnPressed = false;
}

bool ButtonWithLed::readButton(){
  return digitalRead(m_bnPin) == HIGH;
}

void ButtonWithLed::ledOn(){
  digitalWrite(m_ledPin, HIGH);
}

void ButtonWithLed::ledOff(){
  digitalWrite(m_ledPin, LOW);
}