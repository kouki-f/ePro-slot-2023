#include "ArduinoNanoLedTape.h"
#include "Arduino.h"

ArduinoNanoLedTape::ArduinoNanoLedTape(int tx, int rx)
{
  m_tx = tx; m_rx = rx;
}

bool ArduinoNanoLedTape::begin(){
  if(m_tx==18 and m_rx==19){
    Serial1.begin(9600);
    ledTape.m_serialNum = 1;
    return true;
  }else if (m_tx==16 && m_rx==17)
  {
    Serial2.begin(9600);
    ledTape.m_serialNum = 2;
    return true;
  }else if (m_tx==14 && m_rx==15)
  {
    Serial3.begin(9600);
    ledTape.m_serialNum = 3;
    return true;
  }else{
    return false;  //uart pin error
  }
}

void ArduinoNanoLedTape::test1(){
  ledTape.serialSendData(5);
}