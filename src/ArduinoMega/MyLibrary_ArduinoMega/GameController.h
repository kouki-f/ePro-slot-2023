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
class GameController{
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
    GameController* gameController;
    double big_probability[3] = {0.037, 0.083, 0.385};  //1枚掛け、２枚掛け、3枚掛け
    double reg_probability[3] = {0.037, 0.091, 0.333};
    double pierrot_probability[3] = {0.006, 0.040, 0.092};
    double bell_probability[3] = {0.006, 0.040, 0.092};
    double cherry_probability[3] = {0.055, 1.50, 3.35};
    double grape_probability[3] = {3.571, 8.00, 15.38};
    double replay_probability[3] = {13.70, 13.70, 13.70};
    int ND = -1;  //no_data
    int seven_position[3][2] = {{10, 20}, {20, ND}, {20, ND}};  //リール番号
    int bar_position[3][2] = {{4, 15}, {4, 12}, {19, ND}};
    int pierrot_position[3][4] = {{9, ND, ND, ND}, {1, ND, ND, ND}, {3, 7, 11, 15}};
    int bell_position[3][5] = {{21, ND, ND, ND, ND}, {8, 16, ND, ND, ND}, {2, 6, 10, 14, 18}};
    int cherry_position[3][5] = {{5, 14, ND, ND, ND}, {2, 6, 10, 14, 18}, {ND, ND, ND, ND, ND}};
    int grape_position[3][8] = {{1, 3, 6, 8, 11, 13, 16, 18}, {3, 7, 11, 15, 19, ND, ND, ND}, {4, 8, 12, 16, 21, ND, ND, ND}};
    int replay_position[3][5] = {{2, 7, 12, 17, 19}, {5, 9, 13, 17, 21}, {1, 5, 9, 13, 17}};
    double reel_result_position[3];  //角度
    double now_posi_num;
    double now_position[3] = {0, 0, 0};  //Deg
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
    void reelPosition(int result);
    double getNearPosition(int reel_num, int pattern);
    void setReelResultPosition(int result);
    int searchNearNum(int reel_num, int for_i);
  public:
    int slot_result;
    Reel(GameController* gameController);
    void start2Stop(int bet);
    void rotate1Step(int reel_num);
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
  void payOutCoins(int result, int bet);
  void launch();  //起動音など
  void waitForPushedStartBN();
  void showNum(int digit, int num);
public:
  GameController(int* array);
  void start();  //システムのメイン関数
};