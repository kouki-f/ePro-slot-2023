#pragma once

class LedTape{
private:
  int m_tx, m_rx;
public:
  LedTape(int tx, int rx);
  bool begin();
};