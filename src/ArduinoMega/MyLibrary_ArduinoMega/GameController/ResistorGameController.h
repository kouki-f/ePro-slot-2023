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
  int bet = 0;
  int m_payout_coin_cnt;
  void payOutCoins();
  void launch();  //起動音など
  void launchDark();
  void waitForPushedStartBN();
  void waitForPushedStartBNDark();
  void showNum(int digit, int num);
  void payOutCoinsDark();
public:
  ResistorGameController(int* array);
  void startLightMode();  //システムのメイン関数
  void startDarkMode();
};