#include "SoundEffect.h"

SoundEffect playSound(10, 11);

void setup()
{
  playSound.begin();
  playSound.setVolume(20);  // ボリュームをセット、 ボリュームは0から30の値で指定可能
  playSound.play(3);  // 001のmp3ファイルを再生
}

void loop()
{
  
}