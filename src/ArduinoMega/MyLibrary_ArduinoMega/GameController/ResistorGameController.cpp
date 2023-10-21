#include "ResistorGameController.h"
#include "Arduino.h"

ResistorGameController::ResistorGameController(int* array):
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
  threeDigitsSeg(array[57], array[58], array[59], array[60], array[61], array[62], array[63], array[64], array[65], array[66]),
  motorPhoto1(array[67]),
  motorPhoto2(array[68]),
  motorPhoto3(array[69]),
  coinSelector(array[70]),
  reel(this)
{
}

ResistorGameController::Reel::Reel(ResistorGameController* gameController){
  gameController = gameController;
}

// int ResistorGameController::Reel::lot(int bet){
//   bool big, reg, pierrot, bell, cherry, grape, replay;
//   int true_cnt = 0;

//   while(true_cnt != 1){
//     big = rand(big_probability[bet - 1]);
//     reg = rand(reg_probability[bet - 1]);
//     pierrot = rand(pierrot_probability[bet - 1]);
//     bell = rand(bell_probability[bet - 1]);
//     cherry = rand(cherry_probability[bet - 1]);
//     grape = rand(grape_probability[bet - 1]);
//     replay = rand(replay_probability[bet - 1]);
//     if(big) true_cnt++;
//     if(reg) true_cnt++;
//     if(pierrot) true_cnt++;
//     if(bell) true_cnt++;
//     if(cherry) true_cnt++;
//     if(grape) true_cnt++;
//     if(replay) true_cnt++;
//     if(true_cnt == 0) return LOSE;
//     if(true_cnt > 1) true_cnt = 0;
//   }
  
//   if(big){
//     return BIG;
//   }else if(reg){
//     return REG;
//   }else if(pierrot){
//     return PIERROT;
//   }else if(bell){
//     return BELL;
//   }else if(cherry){
//     return CHERRY;
//   }else if(grape){
//     return GRAPE;
//   }else if(replay){
//     return REPLAY;
//   }else{
//     //Error
//   }
// }

bool ResistorGameController::Reel::rand(double percent){
  long rand_num = random(0, 100000);
  if(rand_num<percent*1000){
    return true;
  }
  return false;
}

void ResistorGameController::Reel::start2Stop(){
  gameController->stopBN1.turnOn();
  gameController->stopBN2.turnOn();
  gameController->stopBN3.turnOn();

  bool stopBN1_is_pushed = false;
  bool stopBN2_is_pushed = false;
  bool stopBN3_is_pushed = false;

  while(stopBN1_is_pushed == false || stopBN2_is_pushed == false || stopBN3_is_pushed == false){
    if(stopBN1_is_pushed == false) rotate10Step(1);  //stopBNが押されるまで回転し続ける
    if(stopBN2_is_pushed == false) rotate10Step(2);
    if(stopBN2_is_pushed == false) rotate10Step(3);

    if(gameController->stopBN1.readButton() && stopBN1_is_pushed == false){
      gameController->stopBN1.turnOff();  //BN-LED turn Off
      stopBN1_is_pushed = true;
    }
    if(gameController->stopBN2.readButton() && stopBN2_is_pushed == false){
      gameController->stopBN2.turnOff();
      stopBN2_is_pushed = true;
    }
    if(gameController->stopBN3.readButton() && stopBN3_is_pushed == false){
      gameController->stopBN3.turnOff();
      stopBN3_is_pushed = true;
    }
  }
}

void ResistorGameController::Reel::start2StopDark(){
  
}

void ResistorGameController::Reel::rotate10Step(int reel_num){
  switch(reel_num){
    case 1:
      if(gameController->motorPhoto1.readPhoto()){
        now_step_position[0] = 10;
        gameController->motor1.step(10);
      }else{
        gameController->motor1.step(10);
        now_step_position[0] += 10;
      }
      break;
    case 2:
      if(gameController->motorPhoto2.readPhoto()){
        now_step_position[1] = 10;
        gameController->motor2.step(10);
      }else{
        gameController->motor2.step(10);
        now_step_position[1] += 10;
      }
      break;
    case 3:
      if(gameController->motorPhoto3.readPhoto()){
        now_step_position[2] = 10;
        gameController->motor3.step(10);
      }else{
        gameController->motor3.step(10);
        now_step_position[2] += 10;
      }
      break;
    default:
      break;
  }
}

void ResistorGameController::payOutCoins(){
  for(int i=0;i<3;i++){
    reel.now_step_position[i] %= 200;
  }
  m_payout_coin_cnt = (reel.left_reel[reel.now_step_position[0] / 10] * 10 + reel.center_reel[reel.now_step_position[1] / 10]) / 20
                      + reel.right_reel[reel.now_step_position[2] / 10] * reel.right_reel[reel.now_step_position[2] / 10] / 2;
  showNum(PAYOUT7SEG, m_payout_coin_cnt);
  hopper.payOutCoin(m_payout_coin_cnt);
}

void ResistorGameController::launch(){
  while(motorPhoto1.readPhoto() == false){  //初期位置
    motor1.step(1);
  }
  while(motorPhoto2.readPhoto() == false){
    motor2.step(1);
  }
  while(motorPhoto3.readPhoto() == false){
    motor3.step(1);
  }
}

void ResistorGameController::waitForPushedStartBN(){
  bool canStart = false;
  while(startBN.readButton() == false || canStart == false){  //startBNが押されるまで待つ bet設定など可能
    if(coinSelector.nowPlayerCoinCount() >= bet){  //BET枚数と所有枚数の比較
      canStart = true;
      startBN.turnOn();  //もしstartできる状態ならstartBNを点灯する
    }else{
      canStart = false;
      startBN.turnOff();
    }

    // if(betBN.readButton()){  //BET額を設定
    //   bet == 3 ? bet = 1 : bet ++;
    //   showNum(BET7SEG, bet);
    // }

    if(payBN.readButton()){  //pay outボタン
      int have_coins = coinSelector.nowPlayerCoinCount();
      hopper.payOutCoin(have_coins);
      coinSelector.updatePlayerCoinCount(have_coins);
    }
  }
  showNum(PAYOUT7SEG, 0);
  coinSelector.updatePlayerCoinCount(bet);  //BET枚数分player coinを減らす
}

void ResistorGameController::showNum(int digit, int num){
  switch(digit){
    case BET7SEG:
      oneDigitSeg.displayNumber(num);
      break;
    case PLAYERCOIN7SEG:
      //twoDigitsSeg.displayNumber(num);
      break;
    case PAYOUT7SEG:
      threeDigitsSeg.displayNumber(num);
      break;
    default:
      break;
  }
}

void ResistorGameController::startLightSide(){
  launch();  //起動時の動作

  while(true){  //メインループ
    waitForPushedStartBN();  //startBNが押されるまで待機 BET設定、pay out可能
    reel.start2Stop();
    payOutCoins();
  }
}

void ResistorGameController::startDarkSide(){
  launch();

  while(true){

  }
}