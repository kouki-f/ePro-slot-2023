#include "OneDigitSegmentLed.h"
#include <Arduino.h>

OneDigitSegmentLed::OneDigitSegmentLed(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG)
{
  m_pinA = pinA; m_pinB= pinB; m_pinC = pinC; m_pinD = pinD; m_pinE = pinE; m_pinF = pinF; m_pinG = pinG;
  pinMode(m_pinA, OUTPUT);
  pinMode(m_pinB, OUTPUT);
  pinMode(m_pinC, OUTPUT);
  pinMode(m_pinD, OUTPUT);
  pinMode(m_pinE, OUTPUT);
  pinMode(m_pinF, OUTPUT);
  pinMode(m_pinG, OUTPUT);
}

void OneDigitSegmentLed::displayNumber(int n){
  m_num = n;
  switch (m_num)
  {
  case 0:
    displayZero();
    break;
  case 1:
    displayOne();
    break;
  case 2:
    displayTwo();
    break;
  case 3:
    displayThree();
    break;
  case 4:
    displayFour();
    break;
  case 5:
    displayFive();
    break;
  case 6:
    displaySix();
    break;
  case 7:
    displaySeven();
    break;
  case 8:
    displayEight();
    break;
  case 9:
    displayNine();
    break;
  default:
    //println("ERR 0-9で指定してください。");
    break;
  }
}

void OneDigitSegmentLed::setHIGH(int pin){
  digitalWrite(pin, HIGH);
}

void OneDigitSegmentLed::setLOW(int pin){
  digitalWrite(pin, LOW);
}

void OneDigitSegmentLed::displayZero(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
  setHIGH(m_pinE);
  setHIGH(m_pinF);
}

void OneDigitSegmentLed::displayOne(){
  turnOffAllLed();
  setHIGH(m_pinB);
  setHIGH(m_pinB);
}

void OneDigitSegmentLed::displayTwo(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinE);
  setHIGH(m_pinD);
}

void OneDigitSegmentLed::displayThree(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
}

void OneDigitSegmentLed::displayFour(){
  turnOffAllLed();
  setHIGH(m_pinF);
  setHIGH(m_pinG);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
}

void OneDigitSegmentLed::displayFive(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
}

void OneDigitSegmentLed::displaySix(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinE);
  setHIGH(m_pinG);
  setHIGH(m_pinD);
  setHIGH(m_pinC);
}

void OneDigitSegmentLed::displaySeven(){
  turnOffAllLed();
  setHIGH(m_pinF);
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
}

void OneDigitSegmentLed::displayEight(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
  setHIGH(m_pinE);
  setHIGH(m_pinF);
  setHIGH(m_pinG);
}

void OneDigitSegmentLed::displayNine(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
}

void OneDigitSegmentLed::turnOffAllLed(){
  setLOW(m_pinA);
  setLOW(m_pinB);
  setLOW(m_pinC);
  setLOW(m_pinD);
  setLOW(m_pinE);
  setLOW(m_pinF);
  setLOW(m_pinG);
}