#pragma once

class ArduinoNanoLedTape{
private:
  int m_tx;
  int m_rx;
public:
  ArduinoNanoLedTape();
  bool begin();
  void test1();
};
