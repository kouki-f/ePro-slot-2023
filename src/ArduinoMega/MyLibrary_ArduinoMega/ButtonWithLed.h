#pragma once

class ButtonWithLed
{
private:
  int m_ledPin;
  int m_bnPin;
  //bool m_isBnPressed;
public:
  ButtonWithLed(int bn_pin, int led_pin);
  bool readButton();
  void ledOn();
  void ledOff();
};
