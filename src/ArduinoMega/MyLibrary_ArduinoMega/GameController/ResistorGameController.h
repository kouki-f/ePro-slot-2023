#pragma once

#include "StepperMotor.h"
#include "OneDigitSegmentLed.h"
//#include "TwoDigitsSegmentLed.h"
#include "SoundEffect.h"
#include "ButtonWithLed.h"
#include "CoinSelector.h"
#include "Photointerrupter.h"
#include "Hopper.h"
#include "ArduinoNanoLedTape.h"
#include "ThreeDigitsSegmentLed.h"
class ResistorGameController{
private:
  StepperMotor          motor1, motor2, motor3;
  OneDigitSegmentLed    oneDigitSeg;
  //TwoDigitsSegmentLed   twoDigitsSeg;
  ThreeDigitsSegmentLed threeDigitsSeg;
  SoundEffect           soundEffect;
  ButtonWithLed         startBN, stopBN1, stopBN2, stopBN3, betBN, payBN;
  CoinSelector          coinSelector;
  Photointerrupter      motorPhoto1, motorPhoto2, motorPhoto3;
  Hopper                hopper;
  ArduinoNanoLedTape    nanoLedTape, nanoMatrix; //仮

  class Reel{
  private:
    ResistorGameController* gameController;
    // double big_probability[3] = {0.037, 0.083, 0.385};  //1枚掛け、２枚掛け、3枚掛け
    // double reg_probability[3] = {0.037, 0.091, 0.333};
    // double pierrot_probability[3] = {0.006, 0.040, 0.092};
    // double bell_probability[3] = {0.006, 0.040, 0.092};
    // double cherry_probability[3] = {0.055, 1.50, 3.35};
    // double grape_probability[3] = {3.571, 8.00, 15.38};
    // double replay_probability[3] = {13.70, 13.70, 13.70};
    enum{
      BLACK = 0,
      BROWN = 1,
      RED = 2,
      ORANGE = 3,
      YELLOW = 4,
      GREEN = 5,
      BLUE = 6,
      VIOLET = 7,
      GRAY = 8,
      WHITE = 9
    };

    int reel_result_position[3];  //step
    double now_posi_num;
    const double BETWEEN_DEG = 17.142;
    enum{
      LOSE = 0,
      BIG = 1,
      REG = 2,
      SEVEN = 1,
      BAR = 2,
      PIERROT = 3,
      BELL = 4,
      CHERRY = 5,
      GRAPE = 6,
      REPLAY = 7
    };

    int lot(int bet);
    bool rand(double percent);  //return 当選結果
  public:
    double left_reel[20] = {BROWN, WHITE, RED, BLUE, ORANGE, GREEN, BROWN, VIOLET, RED, YELLOW,
                            BROWN, VIOLET, RED, ORANGE, GRAY, BROWN, GREEN, YELLOW, BLUE, RED};
    double center_reel[20] = {BROWN, BLACK, VIOLET, RED, ORANGE, BLACK, BLUE, YELLOW, GREEN, BROWN,
                              WHITE, BLACK, RED, GREEN, BLUE, ORANGE, YELLOW, BROWN, BLACK, GRAY};
    double right_reel[20] = {ORANGE, BROWN, GRAY, BLACK, GREEN, RED, BLUE, BLACK, YELLOW, BROWN,
                             VIOLET, BLACK, GREEN, YELLOW, RED, ORANGE, BROWN, WHITE, BLACK, RED};
    int now_step_position[3] = {0, 0, 0};  //step
    int slot_result;
    Reel(ResistorGameController* gameController);
    void start2Stop();
    void start2StopDark();
    void rotate10Step(int reel_num);
  };

  enum{
      LOSE = 0,
      BIG = 1,
      REG = 2,
      SEVEN = 1,
      BAR = 2,
      PIERROT = 3,
      BELL = 4,
      CHERRY = 5,
      GRAPE = 6,
      REPLAY = 7,

      BET7SEG = 1,
      PLAYERCOIN7SEG = 2,
      PAYOUT7SEG = 3
  };

  Reel reel;
  int bet = 1;
  int m_payout_coin_cnt;
  void payOutCoins();
  void launch();  //起動音など
  void waitForPushedStartBN();
  void showNum(int digit, int num);
public:
  ResistorGameController(int* array);
  void startLightSide();  //システムのメイン関数
  void startDarkSide();
};