#pragma once

class MyCppTest{
private:
  int m_pin;
public:
  MyCppTest(int pin);
  void High();
  void Low();
};