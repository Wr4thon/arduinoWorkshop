#include <008_nightRider.h>

void nightRider::setup()
{
  direction = false;
  pixels = new Adafruit_NeoPixel(10, 13, NEO_GRB + NEO_KHZ800);
  pixels->begin();
}

void nightRider::loop()
{
  pixels->clear();

  if (direction)
  {
    i++;
  }
  else
  {
    i--;
  }

  i = constrain(i, 0, 9);

  pixels->setPixelColor(i, pixels->Color(150, 0, 0));
  pixels->show();
  delay(50);

  if (i >= 9 || i <= 0)
  {
    direction = !direction;
  }
}