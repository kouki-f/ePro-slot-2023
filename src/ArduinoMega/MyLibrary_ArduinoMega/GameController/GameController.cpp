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
  coinSelector(array[70], this),
  reel(this)
{
}

GameController::Reel::Reel(GameController* gameController){
  gameController = gameController;
}

int GameController::Reel::lot(int bet){
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
    if(big) true_cnt++;
    if(reg) true_cnt++;
    if(pierrot) true_cnt++;
    if(bell) true_cnt++;
    if(cherry) true_cnt++;
    if(grape) true_cnt++;
    if(replay) true_cnt++;
    if(true_cnt == 0) return LOSE;
    if(true_cnt > 1) true_cnt = 0;
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

bool GameController::Reel::rand(double percent){
  long rand_num = random(0, 100000);
  if(rand_num<percent*1000){
    return true;
  }
  return false;
}

void GameController::Reel::reelPosition(int result){
  switch(result){
    case LOSE:
      break;
    case SEVEN:
      setReelResultPosition(SEVEN);
      break;
    case BAR:
      setReelResultPosition(BAR);
      break;
    case PIERROT:
      setReelResultPosition(PIERROT);
      break;
    case BELL:
      setReelResultPosition(BELL);
      break;
    case CHERRY:
      setReelResultPosition(CHERRY);
      break;
    case GRAPE:
      setReelResultPosition(GRAPE);
      break;
    case REPLAY:
      setReelResultPosition(REPLAY);
      break;
    default:
      break;
  }
}

double GameController::Reel::getNearPosition(int reel_num, int pattern){
  int near_num; int for_i;
  switch(pattern){
    case LOSE:
      //はずれの時の関数
      break;
    case SEVEN:
      for_i = 2;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case BAR:
      for_i = 2;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case PIERROT:
      for_i = 4;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case BELL:
      for_i = 5;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case CHERRY:
      for_i = 5;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case GRAPE:
      for_i = 8;
      near_num = searchNearNum(reel_num, for_i);
      break;
    case REPLAY:
      for_i = 5;
      near_num = searchNearNum(reel_num, for_i);
      break;
    default:
      break;
  }
  return (near_num - now_posi_num) * BETWEEN_DEG;
}

int GameController::Reel::searchNearNum(int reel_num, int for_i){
  now_posi_num = now_position[reel_num - 1] / BETWEEN_DEG;
  int near_num = 100;
  //現在位置から原点までにその柄があるとき
  for(int i=0;i<for_i;i++){
    if(seven_position[reel_num][i] > 0 && seven_position[reel_num][i] > now_posi_num){  //not ND & now < newPosi
      if(near_num > (seven_position[reel_num][i] - now_posi_num)){
        near_num = seven_position[reel_num][i];
      }
    }
  }
  if(near_num == 100){
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
  }
  return near_num;
}

void GameController::Reel::setReelResultPosition(int result){
  for(int i=0;i<3;i++){
    reel_result_position[i] = getNearPosition(i+1, result);
  }
}

void GameController::Reel::start2Stop(int bet){
  slot_result = lot(bet);  //抽選結果をresultに代入
  reelPosition(slot_result);  //進めるべき角度をreel_result_positionにセット
  gameController->stopBN1.turnOn();
  gameController->stopBN2.turnOn();
  gameController->stopBN3.turnOn();

  bool stopBN1_is_pushed = false;
  bool stopBN2_is_pushed = false;
  bool stopBN3_is_pushed = false;

  while(stopBN1_is_pushed == false || stopBN2_is_pushed == false || stopBN3_is_pushed == false){
    if(stopBN1_is_pushed == false) rotate1Step(1);  //stopBNが押されるまで回転し続ける
    if(stopBN2_is_pushed == false) rotate1Step(2);
    if(stopBN2_is_pushed == false) rotate1Step(3);

    if(gameController->stopBN1.readButton() && stopBN1_is_pushed == false){
      gameController->stopBN1.turnOff();  //BN-LED turn Off
      for(int i=0;i<(int)(reel_result_position[0]/1.8);i++){  //柄まで進める
        rotate1Step(1);
      }
      stopBN1_is_pushed = true;
    }
    if(gameController->stopBN2.readButton() && stopBN2_is_pushed == false){
      gameController->stopBN2.turnOff();
      for(int i=0;i<(int)(reel_result_position[1]/1.8);i++){
        rotate1Step(2);
      }
      stopBN2_is_pushed = true;
    }
    if(gameController->stopBN3.readButton() && stopBN3_is_pushed == false){
      gameController->stopBN3.turnOff();
      for(int i=0;i<(int)(reel_result_position[2]/1.8);i++){
        rotate1Step(3);
      }
      stopBN3_is_pushed = true;
    }
  }
}

void GameController::Reel::rotate1Step(int reel_num){
  switch(reel_num){
    case 1:
      if(gameController->motorPhoto1.readPhoto()){
        now_position[0] = 1.8;
        gameController->motor1.step(1);
      }else{
        gameController->motor1.step(1);
        now_position[0] += 1.8;
      }
      break;
    case 2:
      if(gameController->motorPhoto2.readPhoto()){
        now_position[1] = 1.8;
        gameController->motor2.step(1);
      }else{
        gameController->motor2.step(1);
        now_position[0] += 1.8;
      }
      break;
    case 3:
      if(gameController->motorPhoto3.readPhoto()){
        now_position[2] = 1.8;
        gameController->motor3.step(1);
      }else{
        gameController->motor3.step(1);
        now_position[0] += 1.8;
      }
      break;
    default:
      break;
  }
}

void GameController::payOutCoins(int result, int bet){
  switch(result){
    case PIERROT:
      bet == 1 ? m_payout_coin_cnt = 10 : m_payout_coin_cnt = 14;
      break;
    case BELL:
      m_payout_coin_cnt = 14;
      break;
    case CHERRY:
      bet == 1 ? m_payout_coin_cnt = 1 : m_payout_coin_cnt = 14;
      break;
    case GRAPE:
      bet == 1 ? m_payout_coin_cnt = 7 : m_payout_coin_cnt = 14;
      break;
    default:
      m_payout_coin_cnt = 0;
      break;
  }
  showNum(PAYOUT7SEG, m_payout_coin_cnt);
  hopper.payOutCoin(m_payout_coin_cnt);
}

void GameController::launch(){
  while(motorPhoto1.readPhoto() == false){  //初期位置
    reel.rotate1Step(1);
  }
  while(motorPhoto2.readPhoto() == false){
    reel.rotate1Step(2);
  }
  while(motorPhoto3.readPhoto() == false){
    reel.rotate1Step(3);
  }
}

void GameController::waitForPushedStartBN(){
  bool canStart = false;
  while(startBN.readButton() == false || canStart == false){  //startBNが押されるまで待つ bet設定など可能
    if(coinSelector.nowPlayerCoinCount() >= bet){  //BET枚数と所有枚数の比較
      canStart = true;
      startBN.turnOn();  //もしstartできる状態ならstartBNを点灯する
    }else{
      canStart = false;
      startBN.turnOff();
    }

    if(betBN.readButton()){  //BET額を設定
      if(bet == 3){
        bet = 1;
      }else{
        bet++;
      }
      showNum(BET7SEG, bet);
    }

    if(payBN.readButton()){  //pay outボタン
      int have_coins = coinSelector.nowPlayerCoinCount();
      hopper.payOutCoin(have_coins);
      coinSelector.updatePlayerCoinCount(have_coins);
    }
  }
  showNum(PAYOUT7SEG, 0);
  coinSelector.updatePlayerCoinCount(bet);  //BET枚数分player coinを減らす
}

void GameController::showNum(int digit, int num){
  switch(digit){
    case BET7SEG:
      oneDigitSeg.displayNumber(num);
      break;
    case PLAYERCOIN7SEG:
      twoDigitsSeg.displayNumber(num);
      break;
    case PAYOUT7SEG:
      threeDigitsSeg.displayNumber(num);
      break;
    default:
      break;
  }
}

void GameController::start(){
  launch();  //起動時の動作

  while(true){  //メインループ
    waitForPushedStartBN();  //startBNが押されるまで待機 BET設定、pay out可能
    reel.start2Stop(bet);
    payOutCoins(reel.slot_result, bet);
  }
}