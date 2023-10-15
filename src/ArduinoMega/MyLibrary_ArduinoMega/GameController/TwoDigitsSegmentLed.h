#pragma once

class TwoDigitsSegmentLed{
  private:
    int m_pinA1, m_pinB1, m_pinC1,
        m_pinD1, m_pinE1, m_pinF1,
        m_pinG1, m_pinA2, m_pinB2,
        m_pinC2, m_pinD2, m_pinE2,
        m_pinF2, m_pinG2;
        
    int m_num;
    int m_tens, m_ones;
    const int kOnes_place = 1;
    const int kTens_place = 2;

    int GetTensPlace(int n);  //十の位の数字を取得
    int GetOnesPlace(int n);  //一の位の数字を取得
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
    void setHIGH(int pin);
    void setLOW(int pin);
    void displayOnesPlace(int ones);
    void displayTensPlace(int tens);
  public:
    TwoDigitsSegmentLed(int pinA1, int pinB1, int pinC1,
                        int pinD1, int pinE1, int pinF1,
                        int pinG1, int pinA2, int pinB2,
                        int pinC2, int pinD2, int pinE2,
                        int pinF2, int pinG2);

    static void displayNumber(int n);
    void turnOffAllLed();
};