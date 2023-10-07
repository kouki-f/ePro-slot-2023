#include "ArduinoNanoLedTape.h"

ArduinoNanoLedTape nanoTapeUart(18, 19);

void setup() {
  nanoTapeUart.begin();
}

void loop() {
  nanoTapeUart.test();
}
