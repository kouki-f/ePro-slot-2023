#include "Photointerrupter.h"
#include "Arduino.h"

Photointerrupter::Photointerrupter(int photoPin)
{
  m_photoPin = photoPin;
  pinMode(m_photoPin, INPUT);
}

bool Photointerrupter::readPhoto(){
  return digitalRead(m_photoPin)==LOW;
}