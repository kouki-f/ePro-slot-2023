#include <Adafruit_NeoPixel.h>

const int DIN_PIN = 3; // D1
const int LED_COUNT = 60; // LEDの数

Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //Serial.begin(9600);
  pixels.begin();  
}

// uint32_t red = pixels.Color(128, 0, 0);
// uint32_t orange = pixels.Color(128, 82, 0);
// uint32_t yellow = pixels.Color(128, 128, 0);
// uint32_t green = pixels.Color(0, 128, 0);
// uint32_t cyan = pixels.Color(0, 128, 128);
// uint32_t blue = pixels.Color(0, 0, 128);
// uint32_t purple = pixels.Color(128, 0, 128);

// uint32_t rainbow_color[] = {red, orange, yellow, green, cyan, blue, purple};
// int rainbow_index[] = {6, 5, 4, 3, 2, 1, 0};

void loop() {
  // while(Serial.available()>0){
  //   int val = Serial.read();
  //   if(val == '1'){

  //   }else if (val == '2') {

  //   }
  // }
  
  pixels.clear();
  pixels.show();
  delay(15);
  for(int i=0; i<60; i++){
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
  delay(30);
}