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
  int coin_cnt = 0;
  while(m_payOutCoin >= coin_cnt){
    while(hopperPhoto.readPhoto()==LOW){  //Low is no coins
      rotateMotor();
    }
    while(hopperPhoto.readPhoto()==HIGH){
      rotateMotor();
    }
    coin_cnt++;
  }
  motorStop();
}

void Hopper::rotateMotor(){
  digitalWrite(m_motor_pin, HIGH);
}

void Hopper::motorStop(){
  digitalWrite(m_motor_pin, LOW);
}