#include "GameController.h"

int pinArray[] = {80, 2, 3, 4, 5,  //motor1 speed, A1, A2, B1, B2
                 80, 6, 7, 8, 9,  //motor2 speed, A1, A2, B1, B2
                 80, 10, 11, 12, 13,  //motor3 speed, A1, A2, B1, B2
                 15, 14,  //mp3Player rx, tx
                 17, 16,  //Nano2 rx, tx
                 19, 18,  //Nano1 rx, tx
                 20,  // Hopper_PhotoSensor
                 22, 23,  // startBN bn, led
                 24, 25  //stopBN1 bn, led
                 26, 27,  //stopBN2 bn, led
                 28, 29,  //stopBN3 bn, led
                 30, 31,  //betBN bn, led
                 32, 33,  //payBN bn, led
                 34, 35, 36, 37, 38, 39, 40,  //7seg1
                 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,  //7seg3
                 51,  //PhotoSensor1
                 52,  //PhotoSensor2
                 53,  //PhotoSensor3
                 A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13,  //7seg2
                 A15  //Hopper
                 };

int arraySize = sizeof(pinArray) / sizeof(pinArray[0]);

GameController game(pinArray, arraySize);
//game.StepperMotor1Init(80, 2, 3, 4, 5);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
