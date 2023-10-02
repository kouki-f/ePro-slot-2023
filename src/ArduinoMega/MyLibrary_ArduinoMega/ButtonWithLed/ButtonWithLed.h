#pragma once

class ButtonWithLed
{
private:
  int m_ledPin;
  int m_bnPin;
public:
  ButtonWithLed(int bnPin, int ledPin);
  bool readButton();
  void turnOn();
  void turnOff();
};
