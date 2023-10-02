#include "TwoDigitsSegmentLed.h"

TwoDigitsSegmentLed TwoSeg(2,3,4,5,6,7,8,9,10,11,12,13,14,15);

void setup() {
}

void loop() {
  for(int i=0;i<100;i++){
    TwoSeg.DisplayNumber(i);
    delay(200);
  }
TwoSeg.turnOffAllLed();
delay(1000);
}
