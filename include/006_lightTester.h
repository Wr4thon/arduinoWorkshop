#pragma once
#include <sketch.h>


class lightTester : public sketch
{
private:
  int min = 1024, max = 0;
  int mapGreen(int value);
  int mapYellow(int value);
  int mapRed(int value);
public:
  void loop();
  void setup();

};