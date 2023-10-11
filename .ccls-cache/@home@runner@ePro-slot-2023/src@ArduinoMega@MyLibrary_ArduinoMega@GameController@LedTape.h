#pragma once

class LedTape{
private:
  int m_tx, m_rx;
public:
  int m_serialNum;
  LedTape();
  void serialSendData(int n);
};