#pragma once

class CoinSelector{
private:
  int m_pin;
  static volatile int m_player_coin_count;
  static void incrementPlayerCoinCount();
public:
  CoinSelector(int pin);
  int nowPlayerCoinCount();
  void updatePlayerCoinCount(int coin_num);
};