#pragma once
#include <sketch.h>
#include <Adafruit_NeoPixel.h>

class neoPixel : public sketch
{
private:
  Adafruit_NeoPixel *pixels;

public:
  void setup();
  void loop();
};