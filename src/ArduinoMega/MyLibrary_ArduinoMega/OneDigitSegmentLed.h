#pragma once

class OneDigitSegmentLed
{
private:
  int m_pinA, m_pinB, m_pinC, m_pinD, m_pinE, m_pinF, m_pinG;
  int m_num;

  void displayZero();
  void displayOne();
  void displayTwo();
  void displayThree();
  void displayFour();
  void displayFive();
  void displaySix();
  void displaySeven();
  void displayEight();
  void displayNine();
  void turnOffAllLed();

  void setHIGH(int pin);
  void setLOW(int pin);
public:
  OneDigitSegmentLed(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG);
  void displayNumber(int n);
};
