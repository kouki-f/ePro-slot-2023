#include "TwoLED.h"
#include "Arduino.h"

int m_two_pinA1 = A0; int m_two_pinB1 = A1; int m_two_pinC1 = A2;
int m_two_pinD1 = A3; int m_two_pinE1 = A4; int m_two_pinF1 = A5;
int m_two_pinG1 = A6;
int m_two_pinA2 = A7; int m_two_pinB2 = A8; int m_two_pinC2 = A9;
int m_two_pinD2 = A10; int m_two_pinE2 = A11; int m_two_pinF2 = A12;
int m_two_pinG2 = A13;

void TwoLED_begin(){
  pinMode(m_two_pinA1, OUTPUT);
  pinMode(m_two_pinB1, OUTPUT);
  pinMode(m_two_pinC1, OUTPUT);
  pinMode(m_two_pinD1, OUTPUT);
  pinMode(m_two_pinE1, OUTPUT);
  pinMode(m_two_pinF1, OUTPUT);
  pinMode(m_two_pinG1, OUTPUT);
  pinMode(m_two_pinA2, OUTPUT);
  pinMode(m_two_pinB2, OUTPUT);
  pinMode(m_two_pinC2, OUTPUT);
  pinMode(m_two_pinD2, OUTPUT);
  pinMode(m_two_pinE2, OUTPUT);
  pinMode(m_two_pinF2, OUTPUT);
  pinMode(m_two_pinG2, OUTPUT);
}

void displayNumber(int n){
  int m_num = n;
  int m_ones = GetOnesPlace(m_num);
  int m_tens = GetTensPlace(m_num);

  turnOffAllLed();
  displayOnesPlace(m_ones);
  displayTensPlace(m_tens);
}

void displayOnesPlace(int ones){
  int kOnes_place = 1;

  switch (ones)
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
    break;
  }
}

void displayTensPlace(int tens){
  int kTens_place = 2;

  switch (tens)
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
    break;
  }
}

int GetOnesPlace(int n){
  return n % 10;
}

int GetTensPlace(int n){
  return n / 10;
}

void setHIGH(int pin){
  digitalWrite(pin, HIGH);
}

void setLOW(int pin){
  digitalWrite(pin, LOW);
}

void displayZero(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinC1);
    setHIGH(m_two_pinD1);
    setHIGH(m_two_pinE1);
    setHIGH(m_two_pinF1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinC2);
    setHIGH(m_two_pinD2);
    setHIGH(m_two_pinE2);
    setHIGH(m_two_pinF2);
  }
}

void displayOne(int place){
  if(place == 1){
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinC1);
  }else{
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinC2);
  }
}

void displayTwo(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinE1);
    setHIGH(m_two_pinD1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinE2);
    setHIGH(m_two_pinD2);
  }
}

void displayThree(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinC1);
    setHIGH(m_two_pinD1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinC2);
    setHIGH(m_two_pinD2);
  }
}

void displayFour(int place){
  if(place == 1){
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinC1);
  }else{
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinC2);
  }
}

void displayFive(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinC1);
    setHIGH(m_two_pinD1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinC2);
    setHIGH(m_two_pinD2);
  }
}

void displaySix(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinE1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinD1);
    setHIGH(m_two_pinC1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinE2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinD2);
    setHIGH(m_two_pinC2);
  }
}

void displaySeven(int place){
  if(place == 1){
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinC1);
  }else{
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinC2);
  }
}

void displayEight(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinC1);
    setHIGH(m_two_pinD1);
    setHIGH(m_two_pinE1);
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinG1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinC2);
    setHIGH(m_two_pinD2);
    setHIGH(m_two_pinE2);
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinG2);
  }
}

void displayNine(int place){
  if(place == 1){
    setHIGH(m_two_pinA1);
    setHIGH(m_two_pinF1);
    setHIGH(m_two_pinB1);
    setHIGH(m_two_pinG1);
    setHIGH(m_two_pinC1);
  }else{
    setHIGH(m_two_pinA2);
    setHIGH(m_two_pinF2);
    setHIGH(m_two_pinB2);
    setHIGH(m_two_pinG2);
    setHIGH(m_two_pinC2);
  }
}

void turnOffAllLed(){
  setLOW(m_two_pinA1);
  setLOW(m_two_pinB1);
  setLOW(m_two_pinC1);
  setLOW(m_two_pinD1);
  setLOW(m_two_pinE1);
  setLOW(m_two_pinF1);
  setLOW(m_two_pinG1);

  setLOW(m_two_pinA2);
  setLOW(m_two_pinB2);
  setLOW(m_two_pinC2);
  setLOW(m_two_pinD2);
  setLOW(m_two_pinE2);
  setLOW(m_two_pinF2);
  setLOW(m_two_pinG2);
}