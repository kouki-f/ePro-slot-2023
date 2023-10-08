#include "CoinSelector.h"
#include "Arduino.h"

volatile int CoinSelector::m_player_coin_count = 0;

CoinSelector::CoinSelector(int pin)
{
  m_pin = pin;
  pinMode(m_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(m_pin), incrementPlayerCoinCount, RISING);
}

static void CoinSelector::incrementPlayerCoinCount(){
  m_player_coin_count += 1;
}

int CoinSelector::nowPlayerCoinCount(){
  return m_player_coin_count;
}

void CoinSelector::updatePlayerCoinCount(int coin_num){
  m_player_coin_count -= coin_num;
}