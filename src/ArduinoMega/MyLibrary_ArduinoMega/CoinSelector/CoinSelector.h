#pragma once

class CoinSelector{
private:
  int m_player_coin_count = 0;
  int m_pin;
  void incrementPlayerCoinCount();
  
public:
  CoinSelector(int pin);
  int nowPlayerCoinCount();
  void updatePlayerCoinCount(int coin_num);
};