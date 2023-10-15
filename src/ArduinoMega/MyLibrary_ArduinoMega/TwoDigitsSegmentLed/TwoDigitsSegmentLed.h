#pragma once

class TwoDigitsSegmentLed{
  private:
    static int m_pinA1, m_pinB1, m_pinC1,
               m_pinD1, m_pinE1, m_pinF1,
               m_pinG1, m_pinA2, m_pinB2,
               m_pinC2, m_pinD2, m_pinE2,
               m_pinF2, m_pinG2;

    static int m_num;
    static int m_tens, m_ones;
    static const int kOnes_place = 1;
    static const int kTens_place = 2;

    static int GetTensPlace(int n);  //十の位の数字を取得
    static int GetOnesPlace(int n);  //一の位の数字を取得
    static void displayZero(int place);
    static void displayOne(int place);
    static void displayTwo(int place);
    static void displayThree(int place);
    static void displayFour(int place);
    static void displayFive(int place);
    static void displaySix(int place);
    static void displaySeven(int place);
    static void displayEight(int place);
    static void displayNine(int place);
    static void setHIGH(int pin);
    static void setLOW(int pin);
    static void displayOnesPlace(int ones);
    static void displayTensPlace(int tens);
  public:
    TwoDigitsSegmentLed(int pinA1, int pinB1, int pinC1,
                        int pinD1, int pinE1, int pinF1,
                        int pinG1, int pinA2, int pinB2,
                        int pinC2, int pinD2, int pinE2,
                        int pinF2, int pinG2);

    static void displayNumber(int n);
    static void turnOffAllLed();
};