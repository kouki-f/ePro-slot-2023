#include "GameController.h"
#include "Arduino.h"

GameController::GameController(int* array):
  motor1(array[0], array[1], array[2], array[3], array[4]),
  motor2(array[5], array[6], array[7], array[8], array[9]),
  motor3(array[10], array[11], array[12], array[13], array[14]),
  soundEffect(array[15], array[16]),
  nanoLedTape(array[17], array[18]),
  nanoMatrix(array[19], array[20]),
  hopper(array[21], array[22]),
  startBN(array[23], array[24]),
  stopBN1(array[25], array[26]),
  stopBN2(array[27], array[28]),
  stopBN3(array[29], array[30]),
  betBN(array[31], array[32]),
  payBN(array[34], array[35]),
  oneDigitSeg(array[36], array[37], array[38], array[39], array[40], array[41], array[42]),
  twoDigitsSeg(array[43], array[44], array[45], array[46], array[47], array[48], array[49], array[50], array[51], array[52], array[53], array[54], array[55], array[56]),
  threeDigitsSeg(array[57], array[58], array[59], array[60], array[61], array[62], array[63], array[64], array[65], array[66]),
  motorPhoto1(array[67]),
  motorPhoto2(array[68]),
  motorPhoto3(array[69]),
  coinSelector(array[70])
{
}

int Reel::lot(int bet){
  bool big, reg, pierrot, bell, cherry, grape, replay;
  int true_cnt = 0;

  while(true_cnt != 1){
    big = rand(big_probability[bet - 1]);
    reg = rand(reg_probability[bet - 1]);
    pierrot = rand(pierrot_probability[bet - 1]);
    bell = rand(bell_probability[bet - 1]);
    cherry = rand(cherry_probability[bet - 1]);
    grape = rand(grape_probability[bet - 1]);
    replay = rand(replay_probability[bet - 1]);

    if(big == false && reg == false && pierrot == false && bell == false && cherry == false && grape == false && replay == false){
      return LOSE;
    }
  }
  
  if(big){
    return BIG;
  }else if(reg){
    return REG;
  }else if(pierrot){
    return PIERROT;
  }else if(bell){
    return BELL;
  }else if(cherry){
    return CHERRY;
  }else if(grape){
    return GRAPE;
  }else if(replay){
    return REPLAY;
  }else{
    //Error
  }
}

bool Reel::rand(double percent){
  int rand_num = random(100000);
  if(rand_num<percent*1000){
    return true;
  }
  return false;
}