#pragma once

#include "LedTape.h"

class ArduinoNanoLedTape{
private:
  LedTape ledTape;
  int m_tx;
  int m_rx;
public:
  ArduinoNanoLedTape(int tx, int rx);
  bool begin();
  void test1();
};
