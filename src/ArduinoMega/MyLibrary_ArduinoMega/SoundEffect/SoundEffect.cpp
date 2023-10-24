#include "SoundEffect.h"
#include "Arduino.h"

SoundEffect::SoundEffect(int rx, int tx):mySoftwareSerial(rx, tx){
  m_rx = rx;
  m_tx = tx;
}

void SoundEffect::begin(){
  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  setVolume(10);
}

void SoundEffect::play(int folder, int file){
  myDFPlayer.playFolder(folder, file);
}

void SoundEffect::setVolume(int n){
  myDFPlayer.volume(n);
}

void SoundEffect::volumeUp(){
  myDFPlayer.volumeUp();
}

void SoundEffect::volumeDown(){
  myDFPlayer.volumeDown();
}

void SoundEffect::loop(int n){
  myDFPlayer.loop(n);
}

void SoundEffect::pause(){
  myDFPlayer.pause();
}

void SoundEffect::start(){
  myDFPlayer.start();
}

void SoundEffect::enableLoop(){
  myDFPlayer.enableLoop();
}

void SoundEffect::disableLoop(){
  myDFPlayer.disableLoop();
}