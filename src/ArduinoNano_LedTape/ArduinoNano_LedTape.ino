#include <Adafruit_NeoPixel.h>
#include <NanoLedTape.h>

const int DIN_PIN = 2;     // D2
const int LED_COUNT = 120; // LEDの数。とりあえず全部つなげることを想定して作成。

Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // Serial.begin(9600);
  pixels.begin();
}

uint32_t red = pixels.Color(128, 0, 0);
uint32_t orange = pixels.Color(128, 82, 0);
uint32_t yellow = pixels.Color(128, 128, 0);
uint32_t green = pixels.Color(0, 128, 0);
uint32_t cyan = pixels.Color(0, 128, 128);
uint32_t blue = pixels.Color(0, 0, 128);
uint32_t purple = pixels.Color(128, 0, 128);
uint32_t rainbow_color[] = {red, orange, yellow, green, cyan, blue, purple};
int rainbow_index[] = {6, 5, 4, 3, 2, 1, 0};

void loop()
{
  while (Serial.available() > 0)
  {
    int val = Serial.read();
    if (val == '1')
    {
      // WINしたときの動作
      for (int i = 0; i < LED_COUNT; i++)
      {
        pixels.clear();
        for (int j = 0; j < 7; j++)
        {
          rainbow_index[j] = i + 6 - j;
          if (rainbow_index[j] >= LED_COUNT)
            rainbow_index[j] -= LED_COUNT;

          pixels.setPixelColor(rainbow_index[j], rainbow_color[j]);
        }
        pixels.show();
        delay(10);
      }
    }
    else if (val == '2')
    {
      // コインが入ったときの動作
      pixels.clear();
      for (int i = 0; i < LED_COUNT; i++)
      {
        pixels.setPixelColor(i, pixels.Color(128, 128, 128));
        pixels.show();
        delay(25);
      }
    }
    else if (val == '3')
    {
      // LOSEしたときの動作
      pixels.clear();
      for (int i = 0; i < LED_COUNT; i++)
      {
        pixels.setPixelColor(i, pixels.Color(100, 0, 0));
        pixels.show();
      }
      delay(1000);
    }
    else if (val == '4')
    {
      // プレイ中の動作
      pixels.clear();
      for (int i = 0; i < LED_COUNT; i += 2)
      {
        pixels.setPixelColor(i, pixels.Color(100, 0, 0));
        pixels.show();
        delay(10);
      }
      delay(1000);
      for (int i = LED_COUNT; i > 0; i -= 2)
      {
        pixels.setPixelColor(i, pixels.Color(128, 128, 128));
        pixels.show();
        delay(10);
      }
      delay(1000);
    }
  }

  /*pixels.clear();
  pixels.show();
  delay(15);
  for (int i = 0; i < 60; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
  delay(30);*/
}