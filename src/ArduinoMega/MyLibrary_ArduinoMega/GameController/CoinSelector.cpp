#include "CoinSelector.h"
#include "Arduino.h"

volatile int CoinSelector::m_player_coin_count = 0;

CoinSelector::CoinSelector(int pin, GameController* gameController)
{
  m_pin = pin;
  pinMode(m_pin, INPUT);
  gameController = gameController;
  attachInterrupt(digitalPinToInterrupt(m_pin), incrementPlayerCoinCount, RISING);
}

static void CoinSelector::incrementPlayerCoinCount(){
  m_player_coin_count += 1;
  gameController->twoDigitsSeg.displayNumber(m_player_coin_count);
}

int CoinSelector::nowPlayerCoinCount(){
  return m_player_coin_count;
}

void CoinSelector::updatePlayerCoinCount(int coin_num){
  m_player_coin_count -= coin_num;
  gameController->twoDigitsSeg.displayNumber(m_player_coin_count);
}