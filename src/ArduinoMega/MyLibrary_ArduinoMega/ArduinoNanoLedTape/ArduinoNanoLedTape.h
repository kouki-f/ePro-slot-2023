#pragma once

class ArduinoNanoLedTape{
private:
  LedTape ledTape;
  int m_tx;
  int m_rx;
public:
  ArduinoNanoLedTape();
  bool begin();
  void test1();
};
