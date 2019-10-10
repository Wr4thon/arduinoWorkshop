#pragma once

#include <pinnames.h>

class sketch
{
public:
  virtual void setup(void) = 0;
  virtual void loop(void) = 0;
};