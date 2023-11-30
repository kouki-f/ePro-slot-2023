#pragma once
#include "Stepper.h"

class StepperMotor{
private:
  int m_pinA1, m_pinA2, m_pinB1, m_pinB2;
  int m_speed;
  const double m_kangle_around_circle = 360.0;
  const double m_karound_step = 200.0;
  Stepper stepper;
  
public:
  StepperMotor(int speed, int pinA1, int pinA2, int pinB1, int pinB2);
  void setSpeed(int speed);
  void rotateAngle(double angle);
  void step(int step);
};