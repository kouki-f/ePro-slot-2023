#include "StepperMotor.h"
#include "GameController.h"
#include "Arduino.h"

GameController::GameController(int* array, int size):motor1(array[0], array[1], array[2], array[3], array[4]){
  
}