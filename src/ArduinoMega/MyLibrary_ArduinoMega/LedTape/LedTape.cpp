#include "LedTape.h"
#include <Arduino.h>

LedTape::LedTape(int tx, int rx){
  m_tx = tx; m_rx = rx;
}

bool LedTape::begin(){
  if(m_tx==18 and m_rx==19){
    Serial1.begin(9600);
    return true;
  }else if (m_tx==16 && m_rx==17)
  {
    Serial2.begin(9600);
    return true;
  }else if (m_tx==14 && m_rx==15)
  {
    Serial3.begin(9600);
    return true;
  }else{
    return false;  //uart pin error
  }
}

void LedTape::test1(){
  Serial1.write('1');
}

void LedTape::test2(){
  Serial1.write('2');
}
