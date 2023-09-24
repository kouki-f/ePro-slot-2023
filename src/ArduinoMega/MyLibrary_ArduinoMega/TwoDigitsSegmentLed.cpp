#include "TwoDigitsSegmentLed.h"
#include <Arduino.h>

TwoDigitsSegmentLed::TwoDigitsSegmentLed(int pinA1, int pinB1, int pinC1,
                      int pinD1, int pinE1, int pinF1,
                      int pinG1, int pinA2, int pinB2,
                      int pinC2, int pinD2, int pinE2,
                      int pinF2, int pinG2){

  m_pinA1 = pinA1; m_pinB1= pinB1; m_pinC1 = pinC1;
  m_pinD1 = pinD1; m_pinE1 = pinE1; m_pinF1 = pinF1;m_pinG1 = pinG1;
  m_pinA2 = pinA2; m_pinB2= pinB2; m_pinC2 = pinC2;
  m_pinD2 = pinD2; m_pinE2 = pinE2; m_pinF2 = pinF2;m_pinG2 = pinG2;

  pinMode(m_pinA1, OUTPUT);
  pinMode(m_pinB1, OUTPUT);
  pinMode(m_pinC1, OUTPUT);
  pinMode(m_pinD1, OUTPUT);
  pinMode(m_pinE1, OUTPUT);
  pinMode(m_pinF1, OUTPUT);
  pinMode(m_pinG1, OUTPUT);
  pinMode(m_pinA2, OUTPUT);
  pinMode(m_pinB2, OUTPUT);
  pinMode(m_pinC2, OUTPUT);
  pinMode(m_pinD2, OUTPUT);
  pinMode(m_pinE2, OUTPUT);
  pinMode(m_pinF2, OUTPUT);
  pinMode(m_pinG2, OUTPUT);
}

TwoDigitsSegmentLed::DisplayNumber(int n){
  m_num = n;
  m_tens = GetTensPlace(m_num);
  m_ones = GetOnesPlace(m_num);

  switch (m_tens)
  {
  case 0:
    displayZero(kTens_place);
    break;
  case 1:
    displayOne(kTens_place);
    break;
  case 2:
    displayTwo(kTens_place);
    break;
  case 3:
    displayThree(kTens_place);
    break;
  case 4:
    displayFour(kTens_place);
    break;
  case 5:
    displayFive(kTens_place);
    break;
  case 6:
    displaySix(kTens_place);
    break;
  case 7:
    displaySeven(kTens_place);
    break;
  case 8:
    displayEight(kTens_place);
    break;
  case 9:
    displayNine(kTens_place);
    break;
  default:
    println("ERR 0-9で指定してください。");
    break;
  }

  switch (m_ones)
  {
  case 0:
    displayZero(kOnes_place);
    break;
  case 1:
    displayOne(kOnes_place);
    break;
  case 2:
    displayTwo(kOnes_place);
    break;
  case 3:
    displayThree(kOnes_place);
    break;
  case 4:
    displayFour(kOnes_place);
    break;
  case 5:
    displayFive(kOnes_place);
    break;
  case 6:
    displaySix(kOnes_place);
    break;
  case 7:
    displaySeven(kOnes_place);
    break;
  case 8:
    displayEight(kOnes_place);
    break;
  case 9:
    displayNine(kOnes_place);
    break;
  default:
    println("ERR 0-9で指定してください。");
    break;
  }
}

int TwoDigitsSegmentLed::GetOnesPlace(int n){
  return n % 10;
}

int TwoDigitsSegmentLed::GetTensPlace(int n){
  return n / 10;
}

TwoDigitsSegmentLed::setHIGH(int pin){
  digitalWrite(pin, HIGH);
}

TwoDigitsSegmentLed::setLOW(int pin){
  digitalWrite(pin, LOW);
}

TwoDigitsSegmentLed::displayZero(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinB1);
    setHIGH(m_pinC1);
    setHIGH(m_pinD1);
    setHIGH(m_pinE1);
    setHIGH(m_pinF1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinB2);
    setHIGH(m_pinC2);
    setHIGH(m_pinD2);
    setHIGH(m_pinE2);
    setHIGH(m_pinF2);
  }
}

TwoDigitsSegmentLed::displayOne(int place){
  turnOffAllLed();
  if(place ==1){
    setHIGH(m_pinB1);
    setHIGH(m_pinB1);
  }else{
    setHIGH(m_pinB2);
    setHIGH(m_pinB2);
  }
}

TwoDigitsSegmentLed::displayTwo(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinB1);
    setHIGH(m_pinG1);
    setHIGH(m_pinE1);
    setHIGH(m_pinD1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinB2);
    setHIGH(m_pinG2);
    setHIGH(m_pinE2);
    setHIGH(m_pinD2);
  }
}

TwoDigitsSegmentLed::displayThree(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinB1);
    setHIGH(m_pinG1);
    setHIGH(m_pinC1);
    setHIGH(m_pinD1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinB2);
    setHIGH(m_pinG2);
    setHIGH(m_pinC2);
    setHIGH(m_pinD2);
  }
}

TwoDigitsSegmentLed::displayFour(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinF1);
    setHIGH(m_pinG1);
    setHIGH(m_pinB1);
    setHIGH(m_pinC1);
  }else{
    setHIGH(m_pinF2);
    setHIGH(m_pinG2);
    setHIGH(m_pinB2);
    setHIGH(m_pinC2);
  }
}

TwoDigitsSegmentLed::displayFive(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinF1);
    setHIGH(m_pinG1);
    setHIGH(m_pinC1);
    setHIGH(m_pinD1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinF2);
    setHIGH(m_pinG2);
    setHIGH(m_pinC2);
    setHIGH(m_pinD2);
  }
}

TwoDigitsSegmentLed::displaySix(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinF1);
    setHIGH(m_pinE1);
    setHIGH(m_pinG1);
    setHIGH(m_pinD1);
    setHIGH(m_pinC1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinF2);
    setHIGH(m_pinE2);
    setHIGH(m_pinG2);
    setHIGH(m_pinD2);
    setHIGH(m_pinC2);
  }
}

TwoDigitsSegmentLed::displaySeven(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinF1);
    setHIGH(m_pinA1);
    setHIGH(m_pinB1);
    setHIGH(m_pinC1);
  }else{
    setHIGH(m_pinF2);
    setHIGH(m_pinA2);
    setHIGH(m_pinB2);
    setHIGH(m_pinC2);
  }
}

TwoDigitsSegmentLed::displayEight(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinB1);
    setHIGH(m_pinC1);
    setHIGH(m_pinD1);
    setHIGH(m_pinE1);
    setHIGH(m_pinF1);
    setHIGH(m_pinG1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinB2);
    setHIGH(m_pinC2);
    setHIGH(m_pinD2);
    setHIGH(m_pinE2);
    setHIGH(m_pinF2);
    setHIGH(m_pinG2);
  }
}

TwoDigitsSegmentLed::displayNine(int place){
  turnOffAllLed();
  if(place == 1){
    setHIGH(m_pinA1);
    setHIGH(m_pinF1);
    setHIGH(m_pinB1);
    setHIGH(m_pinG1);
    setHIGH(m_pinC1);
  }else{
    setHIGH(m_pinA2);
    setHIGH(m_pinF2);
    setHIGH(m_pinB2);
    setHIGH(m_pinG2);
    setHIGH(m_pinC2);
  }
}

TwoDigitsSegmentLed::TurnOffAllLed(){
  setLOW(m_pinA1);
  setLOW(m_pinB1);
  setLOW(m_pinC1);
  setLOW(m_pinD1);
  setLOW(m_pinE1);
  setLOW(m_pinF1);
  setLOW(m_pinG1);

  setLOW(m_pinA2);
  setLOW(m_pinB2);
  setLOW(m_pinC2);
  setLOW(m_pinD2);
  setLOW(m_pinE2);
  setLOW(m_pinF2);
  setLOW(m_pinG2);
}