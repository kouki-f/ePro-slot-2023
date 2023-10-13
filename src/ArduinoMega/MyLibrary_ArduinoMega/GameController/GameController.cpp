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

Reel::reel(){

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

void Reel::reelPosition(int result, double now_position){
  switch(result){
    case LOSE:
      break;
    case SEVEN:
      setReelResultPosition(SEVEN, now_position);
      break;
    case BAR:
      setReelResultPosition(BAR, now_position);
      break;
    case PIERROT:
      setReelResultPosition(PIERROT, now_position);
      break;
    case BELL:
      setReelResultPosition(BELL, now_position);
      break;
    case CHERRY:
      setReelResultPosition(CHERRY, now_position);
      break;
    case GRAPE:
      setReelResultPosition(GRAPE, now_position);
      break;
    case REPLAY:
      setReelResultPosition(REPLAY, now_position);
      break;
    default
      break;
  }
}

double Reel::getNearPosition(int reel_num, int pattern, double now_position){  //now_position is Deg
  double now_posi_num = now_position / BETWEEN_DEG;
  int near_num; int for_i;
  switch(pattern){
    case LOSE:
      //はずれの時の関数
      break;
    case SEVEN:
      for_i = 2;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case BAR:
      for_i = 2;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case PIERROT:
      for_i = 4;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case BELL:
      for_i = 5;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case CHERRY:
      for_i = 5;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case GRAPE:
      for_i = 8;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    case REPLAY:
      for_i = 5;
      near_num = searchNearNum(reel_num, now_position, for_i);
      break;
    default
      break;
  }
  return (near_num - now_posi_num) * BETWEEN_DEG;
}

int Reel::searchNearNum(int reel_num, double now_position, int for_i){
  int near_num = 100;
  //現在位置から原点までにその柄があるとき
  for(int i=0;i<for_i;i++){
    if(seven_position[reel_num][i] > 0 && seven_position[reel_num][i] > now_posi_num){  //not ND & now < newPosi
      if(near_num > (seven_position[reel_num][i] - now_posi_num)){
        near_num = seven_position[reel_num][i];
      }
    }
  }
  if(near_num != 100){
    break;
  }
  //現在位置から原点までにその柄がないとき
  double min_deg = 1000.0;
  for(int i=0;i<for_i;i++){
    if(seven_position[reel_num][i] > 0){
      if(min_deg > seven_position[reel_num][i] + now_posi_num){
        min_deg = seven_position[reel_num][i] + now_posi_num;
        near_num = seven_position[reel_num][i];
      }
    }
  }
  near_num += 21;
  return near_num;
}

void Reel::setReelResultPosition(int result, double now_position){
  for(int i=0;i<3;i++){
    reel_result_position[i] = getNearPosition(i+1, result, now_position);
  }
}

void Reel::start2Stop(int bet){
  slot_result = lot(bet);  //抽選結果をresultに代入
  reelPosition(slot_result);  //進めるべき角度をreel_result_positionにセット
  stopBN1.turnOn();
  stopBN2.turnOn();
  stopBN3.turnOn();

  bool stopBN1_is_pushed = false;
  bool stopBN2_is_pushed = false;
  bool stopBN3_is_pushed = false;
  while(stopBN1_is_pushed == false || stopBN2_is_pushed == false || stopBN3_is_pushed == false){
    if(stopBN1.readButton() && stopBN1_is_pushed == false){
      stopBN1.turnOff();  //BN-LED turn Off
      motor1.rotateAngle(reel_result_position[0]);  //抽選結果の位置まで進める
      stopBN1_is_pushed = true;
    }
    if(stopBN2.readButton() && stopBN2_is_pushed == false){
      stopBN2.turnOff();
      motor2.rotateAngle(reel_result_position[1]);
      stopBN2_is_pushed = true;
    }
    if(stopBN3.readButton() && stopBN3_is_pushed == false){
      stopBN3.turnOff();
      motor3.rotateAngle(reel_result_position[2]);
      stopBN3_is_pushed = true;
    }
    if(stopBN1_is_pushed == false) motor1.rotateAngle(1);
    if(stopBN2_is_pushed == false) motor2.rotateAngle(1);
    if(stopBN3_is_pushed == false) motor3.rotateAngle(1);
  }
}

void GameController::lotting(int bet){
  reel.start2Stop(bet);
  println(reel.slot_result);
}

// void GameController::payOutCoins(int result, int bet){
//   swich(result){
//     case
//   }
// }