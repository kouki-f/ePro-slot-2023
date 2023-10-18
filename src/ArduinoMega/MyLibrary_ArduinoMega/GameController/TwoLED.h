#pragma once
//#include "Arduino.h"

extern int m_two_pinA1; extern int m_two_pinB1; extern int m_two_pinC1;
extern int m_two_pinD1; extern int m_two_pinE1; extern int m_two_pinF1;
extern int m_two_pinG1;
extern int m_two_pinA2; extern int m_two_pinB2; extern int m_two_pinC2;
extern int m_two_pinD2; extern int m_two_pinE2; extern int m_two_pinF2;
extern int m_two_pinG2;

void TwoLED_begin();

void displayNumber(int n);
void displayOnesPlace(int ones);
void displayTensPlace(int tens);
int GetOnesPlace(int n);
int GetTensPlace(int n);
void setHIGH(int pin);
void setLOW(int pin);
void displayZero(int place);
void displayOne(int place);
void displayTwo(int place);
void displayThree(int place);
void displayFour(int place);
void displayFive(int place);
void displaySix(int place);
void displaySeven(int place);
void displayEight(int place);
void displayNine(int place);
void turnOffAllLed();