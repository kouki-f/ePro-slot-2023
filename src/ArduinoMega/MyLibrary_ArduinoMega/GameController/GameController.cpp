#include "StepperMotor.h"
#include "GameController.h"
#include "Arduino.h"

GameController::GameController(int* array, int size):
  motor1(array[0], array[1], array[2], array[3], array[4]),
  motor2(array[5], array[6], array[7], array[8], array[9]),
  motor3(array[10], array[11], array[12], array[13], array[14]),
  SE(array[15], array[16]),
  nanoLedTape(array[17], array[18]),
  // <- nano2
  hopper(array[21], array[22]),
  startBN(array[23], array[24]),
  stopBN1(array[25], array[26]),
  stopBN2(array[27], array[28]),
  stopBN3(array[29], array[30]),
  betBN(array[31], array[32]),
  payBN(array[34], array[35]),
  oneDigitSeg(array[36], array[37], array[38], array[39], array[40], array[41], array[42]),
  twoDigitsSeg(array[43], array[44], array[45], array[46], array[47], array[48], array[49], array[50], array[51], array[52], array[53], array[54], array[55], array[56]),
  // <- 7seg3
  motorPhoto1(array[67]),
  motorPhoto2(array[68]),
  motorPhoto3(array[69])
{
}