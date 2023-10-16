#pragma once

class ThreeDigitsSegmentLed{
  private:
    int m_pinA, m_pinB, m_pinC, m_pinD, m_pinE, m_pinF, m_pinG, m_pin1, m_pin2, m_pin3;
    int m_num;
    int m_hundred_num, m_ten_num, m_one_num;

    void displayZero();
    void displayOne();
    void displayTwo();
    void displayThree();
    void displayFour();
    void displayFive();
    void displaySix();
    void displaySeven();
    void displayEight();
    void displayNine();
    void setHIGH(int pin);
    void setLOW(int pin);
    int GetHundredPlace(int n);  //百の位の数字を取得
    int GetTensPlace(int n);  //十の位の数字を取得
    int GetOnesPlace(int n);  //一の位の数字を取得
    void CaseOfDisplayNum(int n);
    void SegDelay();
  public:
    ThreeDigitsSegmentLed(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int pin1, int pin2, int pin3);
    void displayNumber(int n);
    void turnOffAllLed();
};
