#pragma once
#include <Adafruit_NeoPixel.h>

class NanoLedTape{
private:
  Adafruit_NeoPixel pixels;
  const int m_kLED_COUNT = 120; // LEDの数

  enum{
    WAIT_FOR_START=0,
    WIN=1,
    COIN_INSERTED=2,
    LOSE=3,
    PLAYING=4
  }
public:
  NanoLedTape();
  bool begin();
  void showLedPattern(int n);
};