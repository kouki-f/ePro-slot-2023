#pragma once
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

class SoundEffect{
private:
  int m_rx, m_tx;
  SoftwareSerial mySoftwareSerial;
  DFRobotDFPlayerMini myDFPlayer;
public:
  SoundEffect(int rx, int tx);
  void begin();
  void play(int folder, int file);
  void setVolume(int n);
  void volumeUp();
  void volumeDown();
  void loop(int n);
  void pause();
  void start();
  void enableLoop();
  void disableLoop();
};