#pragma once

class CoinSelector{
private:
  int m_pin;
  static volatile int m_player_coin_count;
  static void incrementPlayerCoinCount();
  gameController* gameController;
public:
  CoinSelector(int pin, GameController* gameController);
  int nowPlayerCoinCount();
  void updatePlayerCoinCount(int coin_num);
};