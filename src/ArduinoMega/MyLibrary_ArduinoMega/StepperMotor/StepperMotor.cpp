#include "StepperMotor.h"
#include "Stepper.h"
#include "Arduino.h"

StepperMotor::StepperMotor(int speed, int pinA1, int pinA2, int pinB1, int pinB2):stepper(m_karound_step, pinA1, pinA2, pinB1, pinB2)
{
  m_speed = speed;
  m_pinA1 = pinA1; m_pinA2 = pinA2; m_pinB1 = pinB1; m_pinB2 = pinB2;
  stepper.setSpeed(speed);
}

void StepperMotor::setSpeed(int speed){
  stepper.setSpeed(speed);
}

void StepperMotor::rotateAngle(int angle){
  stepper.step(angle / (m_kangle_around_circle / m_karound_step));
}