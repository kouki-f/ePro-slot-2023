#include "CoinSelector.h"
#include "Arduino.h"

CoinSelector::CoinSelector(int pin)
{
  m_pin = pin;
  pinMode(m_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(m_pin), incrementPlayerCoinCount, RISING);
}

void CoinSelector::incrementPlayerCoinCount(){
  m_player_coin_count++;
}

int CoinSelector::nowPlayerCoinCount(){
  return m_player_coin_count;
}

void CoinSelector::updatePlayerCoinCount(int coin_num){
  m_player_coin_count -= coin_num;
}