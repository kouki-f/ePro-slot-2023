#include "ButtonWithLed.h"
int bn = 22;
int led = 23;
ButtonWithLed BN1(bn,led);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BN1.readButton()){
    BN1.turnOn();
  }
  BN1.turnOff();
}
