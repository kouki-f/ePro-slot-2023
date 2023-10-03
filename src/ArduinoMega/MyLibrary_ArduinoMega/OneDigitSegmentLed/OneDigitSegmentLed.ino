#include "OneDigitSegmentLed.h"

OneDigitSegmentLed OneSeg(2, 3, 4, 5, 6, 7, 8);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<10;i++){
    OneSeg.displayNumber(i);
    delay(1000);
  }
}
