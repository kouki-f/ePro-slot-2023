#include "LedTape.h"
#include <Arduino.h>

LedTape::LedTape(){
}

void LedTape::serialSendData(int n){
  if(m_serialNum==1){
    Serial1.write(n);
  }else if(m_serialNum==2){
    Serial2.write(n);
  }else if(m_serialNum==3){
    Serial3.write(n);
  }else{
    //Error
  }
}