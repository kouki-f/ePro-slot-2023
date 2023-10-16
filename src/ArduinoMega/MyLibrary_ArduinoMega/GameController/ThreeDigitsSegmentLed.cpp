#include "ThreeDigitsSegmentLed.h"
#include <Arduino.h>

ThreeDigitsSegmentLed::ThreeDigitsSegmentLed(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int pin1, int pin2, int pin3){
  m_pinA = pinA; m_pinB= pinB; m_pinC = pinC; m_pinD = pinD; m_pinE = pinE;
  m_pinF = pinF; m_pinG = pinG; m_pin1 = pin1; m_pin2 = pin2; m_pin3 = pin3;

  pinMode(m_pinA, OUTPUT);
  pinMode(m_pinB, OUTPUT);
  pinMode(m_pinC, OUTPUT);
  pinMode(m_pinD, OUTPUT);
  pinMode(m_pinE, OUTPUT);
  pinMode(m_pinF, OUTPUT);
  pinMode(m_pinG, OUTPUT);
  pinMode(m_pin1, OUTPUT);
  pinMode(m_pin2, OUTPUT);
  pinMode(m_pin3, OUTPUT);
}

void ThreeDigitsSegmentLed::displayNumber(int n){  //ループ無し
  m_num = n;
  m_hundred_num = GetHundredPlace(m_num);
  m_ten_num = GetTensPlace(m_num);
  m_one_num = GetOnesPlace(m_num);

  CaseOfDisplayNum(m_hundred_num);
  setHIGH(m_pin1);
  CaseOfDisplayNum(m_ten_num);
  SegDelay();
  setLOW(m_pin1);
  setHIGH(m_pin2);
  CaseOfDisplayNum(m_one_num);
  SegDelay();
  setLOW(m_pin2);
  setHIGH(m_pin3);
  SegDelay();
  setLOW(m_pin3);
}

void ThreeDigitsSegmentLed::CaseOfDisplayNum(int n){
  switch (n)
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
    break;
  }
}

void ThreeDigitsSegmentLed::SegDelay(){
  delay(10);
}

int ThreeDigitsSegmentLed::GetOnesPlace(int n){
  return n % 10;
}

int ThreeDigitsSegmentLed::GetTensPlace(int n){
  return (n % 100) - GetOnesPlace(n);
}

int ThreeDigitsSegmentLed::GetHundredPlace(int n){
  return n / 100;
}

void ThreeDigitsSegmentLed::setHIGH(int pin){
  digitalWrite(pin, HIGH);
}

void ThreeDigitsSegmentLed::setLOW(int pin){
  digitalWrite(pin, LOW);
}

void ThreeDigitsSegmentLed::displayZero(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
  setHIGH(m_pinE);
  setHIGH(m_pinF);
}

void ThreeDigitsSegmentLed::displayOne(){
  turnOffAllLed();
  setHIGH(m_pinB);
  setHIGH(m_pinB);
}

void ThreeDigitsSegmentLed::displayTwo(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinE);
  setHIGH(m_pinD);
}

void ThreeDigitsSegmentLed::displayThree(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
}

void ThreeDigitsSegmentLed::displayFour(){
  turnOffAllLed();
  setHIGH(m_pinF);
  setHIGH(m_pinG);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
}

void ThreeDigitsSegmentLed::displayFive(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
}

void ThreeDigitsSegmentLed::displaySix(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinE);
  setHIGH(m_pinG);
  setHIGH(m_pinD);
  setHIGH(m_pinC);
}

void ThreeDigitsSegmentLed::displaySeven(){
  turnOffAllLed();
  setHIGH(m_pinF);
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
}

void ThreeDigitsSegmentLed::displayEight(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinB);
  setHIGH(m_pinC);
  setHIGH(m_pinD);
  setHIGH(m_pinE);
  setHIGH(m_pinF);
  setHIGH(m_pinG);
}

void ThreeDigitsSegmentLed::displayNine(){
  turnOffAllLed();
  setHIGH(m_pinA);
  setHIGH(m_pinF);
  setHIGH(m_pinB);
  setHIGH(m_pinG);
  setHIGH(m_pinC);
}

void ThreeDigitsSegmentLed::turnOffAllLed(){
  setLOW(m_pinA);
  setLOW(m_pinB);
  setLOW(m_pinC);
  setLOW(m_pinD);
  setLOW(m_pinE);
  setLOW(m_pinF);
  setLOW(m_pinG);
}