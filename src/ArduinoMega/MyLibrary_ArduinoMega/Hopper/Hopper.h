#pragma once
#include "Photointerrupter.h"

class Hopper{
private:
  Photointerrupter hopperPhoto;
  int m_payOutCoin;
  int m_motor_pin;
  void rotateMotor();
  void motorStop();
public:
  Hopper(int motor_pin, int dinPin);
  void payOutCoin(int n);
};