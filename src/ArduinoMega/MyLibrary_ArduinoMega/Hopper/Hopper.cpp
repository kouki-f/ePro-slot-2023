#include "Hopper.h"
#include "Photointerrupter.h"
#include "Arduino.h"

Hopper::Hopper(int motor_pin, int photo_dinPin):hopperPhoto(photo_dinPin)
{
  m_motor_pin = motor_pin;
  pinMode(motor_pin, OUTPUT);
}

void Hopper::payOutCoin(int n){
  m_payOutCoin = n;
  coin_cnt = 0;
  while(m_payOutCoin > coin_cnt){
    Serial.println(coin_cnt);
    if(coin_cnt == m_payOutCoin-1){
      while(hopperPhoto.readPhoto()==LOW){  //Low is no coins
        slowRotateMotor();
      }
      while(hopperPhoto.readPhoto()==HIGH){
        slowRotateMotor();
      }
    }else{
      while(hopperPhoto.readPhoto()==LOW){  //Low is no coins
      rotateMotor();
      }
      while(hopperPhoto.readPhoto()==HIGH){
        rotateMotor();
      }      
    }
    coin_cnt++;
  }
  motorStop();
}

void Hopper::rotateMotor(){
  digitalWrite(m_motor_pin, HIGH);
}

void Hopper::slowRotateMotor(){
  analogWrite(m_motor_pin, 80);
}

void Hopper::motorStop(){
  digitalWrite(m_motor_pin, LOW);
}