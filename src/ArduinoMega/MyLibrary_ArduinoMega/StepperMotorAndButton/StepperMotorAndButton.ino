#include "StepperMotor.h"
#include "ButtonWithLed.h"

StepperMotor motor1(80, 2, 3, 4, 5);
StepperMotor motor2(80, 6, 7, 8, 9);
StepperMotor motor3(80, 10, 11, 12, 13);
ButtonWithLed startBN(22, 23);
ButtonWithLed stopBN1(24, 25);
ButtonWithLed stopBN2(26, 27);
ButtonWithLed stopBN3(28, 29);

bool stBN1IsPushed = false;
bool stBN2IsPushed = false;
bool stBN3IsPushed = false;

void setup() {
  Serial.begin(9600);
  // while(1){
  //   startBN.turnOn();
  //   stopBN1.turnOn();
  //   stopBN2.turnOn();
  // }
}

void loop() {
  startBN.turnOn();
  while(!startBN.readButton()){}

  startBN.turnOff();
  stopBN1.turnOn();
  stopBN2.turnOn();
  stopBN3.turnOn();
  while(!(stBN1IsPushed && stBN2IsPushed && stBN3IsPushed)){
    if(!stBN1IsPushed)motor1.step(1);
    if(!stBN2IsPushed)motor2.step(1);
    if(!stBN3IsPushed)motor3.step(1);
    if(stopBN1.readButton()){
      stBN1IsPushed = true;
      stopBN1.turnOff();
      Serial.println("bn1 pushed");
    }
    if(stopBN2.readButton()){
      stBN2IsPushed = true;
      stopBN2.turnOff();
      Serial.println("bn2 pushed");
    }
    if(stopBN3.readButton()){
      stBN3IsPushed = true;
      stopBN3.turnOff();
      Serial.println("bn3 pushed");
    }
  }
  stBN1IsPushed = false;
  stBN2IsPushed = false;
  stBN3IsPushed = false;
}
