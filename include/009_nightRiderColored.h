#pragma once
#include <sketch.h>
#include <Adafruit_NeoPixel.h>
#include <time.h>

class nightRiderColored : public sketch
{
private:
  Adafruit_NeoPixel *pixels;
  int i;
  bool direction;

public:
  void setup();
  void loop();

};