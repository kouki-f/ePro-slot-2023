#include "../ButtonWithLed.h"
int bn = 5;
int led = 6;
ButtonWithLed BN1(bn,led);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BN1.readButton()){
    BN1.ledOn();
  }
}
