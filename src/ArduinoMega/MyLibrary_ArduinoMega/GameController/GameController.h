#pragma once
#include "StepperMotor.h"
#include "OneDigitSegmentLed.h"
#include "TwoDigitsSegmentLed.h"
#include "SoundEffect.h"
#include "ButtonWithLed.h"
#include "CoinSelector.h"

class GameController{
private:
  StepperMotor motor1, motor2, motor3;
  OneDigitSegmentLed oneDigitSeg;
  TwoDigitsSegmentLed twoDigitsSeg;
  SoundEffect SE;
  ButtonWithLed startBN, stopBN1, stopBN2, stopBN3, betBN, payBN;
  CoinSelector coinSelector;
public:
  GameController(int* array);
};