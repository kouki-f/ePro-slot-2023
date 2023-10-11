#pragma once
#include "StepperMotor.h"
#include "OneDigitSegmentLed.h"
#include "TwoDigitsSegmentLed.h"
#include "SoundEffect.h"
#include "ButtonWithLed.h"
#include "CoinSelector.h"
#include "Photointerrupter.h"
#include "Hopper.h"
#include "ArduinoNanoLedTape.h"
#include "ThreeDigitsSegmentLed.h"

class GameController{
private:
  StepperMotor          motor1, motor2, motor3;
  OneDigitSegmentLed    oneDigitSeg;
  TwoDigitsSegmentLed   twoDigitsSeg;
  ThreeDigitsSegmentLed threeDigitsSeg;
  SoundEffect           soundEffect;
  ButtonWithLed         startBN, stopBN1, stopBN2, stopBN3, betBN, payBN;
  CoinSelector          coinSelector;
  Photointerrupter      motorPhoto1, motorPhoto2, motorPhoto3;
  Hopper                hopper;
  ArduinoNanoLedTape    nanoLedTape, nanoMatrix; //仮

  class Reel{
  private:
    double big_probability[] = {0.037, 0.083, 0.385};  //1枚掛け、２枚掛け、3枚掛け
    double reg_probability[] = {0.037, 0.091, 0.333};
    double pierrot_probability[] = {0.006, 0.040, 0.092};
    double bell_probability[] = {0.006, 0.040, 0.092};
    double cherry_probability[] = {0.055, 1.50, 3.35};
    double grape_probability[] = {3.571, 8.00, 15.38};
    double replay_probability[] = {13.70, 13.70, 13.70};

    int lot(int bet);
    bool rand(double percent);  //return 当選結果
    void rotateMotor();
  public:
    Reel();
    int start();
  };
  
public:
  GameController(int* array);
};