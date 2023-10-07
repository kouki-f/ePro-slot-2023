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
  SoundEffect           SE;
  ButtonWithLed         startBN, stopBN1, stopBN2, stopBN3, betBN, payBN;
  CoinSelector          coinSelector;
  Photointerrupter      motorPhoto1, motorPhoto2, motorPhoto3;
  Hopper                hopper;
  ArduinoNanoLedTape    nanoLedTape, nanoMatrix; //仮
public:
  GameController(int* array);
};