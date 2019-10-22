#pragma once

#include <sketch.h>
#include <Adafruit_NeoPixel.h>

class nightRider : public sketch
{
private:
  Adafruit_NeoPixel *pixels;
  int i;
  bool direction;

public:
  void setup();
  void loop();
};