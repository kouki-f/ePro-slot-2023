#include "CoinSelector.h"
#include "TwoLED.h"
#include "Arduino.h"

// static メンバ変数の初期化
volatile int CoinSelector::m_player_coin_count = 0;

CoinSelector::CoinSelector(int pin)
{
  TwoLED_begin();
  m_pin = pin;
  m_player_coin_count = 0;
  pinMode(m_pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(m_pin), incrementPlayerCoinCount, RISING);
}

static void CoinSelector::incrementPlayerCoinCount(){
  m_player_coin_count += 1;
  displayNumber(m_player_coin_count);
}

int CoinSelector::nowPlayerCoinCount(){
  return m_player_coin_count;
}

void CoinSelector::updatePlayerCoinCount(int coin_num){
  CoinSelector::m_player_coin_count -= coin_num;
  displayNumber(m_player_coin_count);
}