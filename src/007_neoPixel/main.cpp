#include <007_neoPixel.h>

void neoPixel::setup()
{
  pixels = new Adafruit_NeoPixel(10, 13, NEO_GRB + NEO_KHZ800);
  pixels->begin();
}

void neoPixel::loop()
{
  pixels->clear();

  for (int i = 0; i < 10; i++)
  {
    pixels->setPixelColor(i, pixels->Color(0, 150, 0));
    pixels->show();
    delay(500);
  }
}