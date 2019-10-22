#pragma once
#include <sketch.h>

struct lightState
{
  uint8_t led;
  uint8_t state;
  lightState(uint8_t pin, uint8_t s)
  {
    led = pin;
    state = s;
  }
};
    
struct trafficLightCycle
{
  lightState *activeLEDs;
  uint8_t amountLeds;
  unsigned long delay;

  trafficLightCycle(lightState *leds, uint8_t amount, unsigned long d)
  {
    activeLEDs = leds;
    amountLeds = amount;
    delay = d;
  }
};

class trafficLightAdvanced : public sketch
{
private:
  trafficLightCycle *fullCycle;
  uint8_t cycleCurrentStep;
  uint8_t cycleStepsAmount;
  void applyCycle(trafficLightCycle cycle);
  void setLightState(lightState state);
public:
  void setup(void);
  void loop(void);
};