#pragma once
#include <Adafruit_NeoPixel.h>

class NanoLedTape{
private:
  Adafruit_NeoPixel pixels;
  const int m_kLED_COUNT = 60; // LEDの数

  enum{
    WAIT_FOR_START=0,
    WIN=1,
    COIN_INSERTED=2
  }
public:
  NanoLedTape();
  bool begin();
  void showLedPattern(int n);
};