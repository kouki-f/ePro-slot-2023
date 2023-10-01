#include "SoundEffect.h"

SoundEffect playSound(10, 11);

void setup()
{
  playSound.begin();
  //playSound.setVolume(10);  // ボリュームをセット、 ボリュームは0から30の値で指定可能
  playSound.play(1);  // 001のmp3ファイルを再生
  delay(5000);
  playSound.pause();
  delay(2000);
  playSound.start();
}

void loop()
{
  
}