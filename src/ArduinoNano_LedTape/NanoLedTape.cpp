#include "NanoLedTape.h"
#include "Arduino.h"

NanoLedTape::NanoLedTape(int dinPin):pixels(m_kLED_COUNT, dinPin, NEO_GRB + NEO_KHZ800)
{
}

bool NanoLedTape::begin(){
  pixels.begin();
}

void NanoLedTape::showLedPattern(int n){
  switch (n){
    case WAIT_FOR_START:
      break;
    case WIN:
      break;
    case COIN_INSERTED:
      break;
    case LOSE:
      break;
    case PLAYING:
      break;
    default:
      break;
  }
}