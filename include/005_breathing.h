#pragma once
#include <sketch.h>

struct cycleTemplate
{
  uint8_t mainPin;
  uint8_t *flashPins;
  uint8_t flashPinsAmount;

  cycleTemplate(uint8_t mP, uint8_t *fP, uint8_t fPA)
  {
    mainPin = mP;
    flashPins = fP;
    flashPinsAmount = fPA;
  }
};


class breathing : public sketch
{
private:
  const uint8_t turns = 3;
  uint8_t c1[1]{LED_DUAL_GREEN};
  uint8_t c2[2]{LED_DUAL_RED, LED_DUAL_GREEN};
  uint8_t c3[1]{LED_DUAL_RED};
  cycleTemplate *cT0 = new cycleTemplate(LED_GREEN, c1, 1);
  cycleTemplate *cT1 = new cycleTemplate(LED_YELLOW, c2, 2);
  cycleTemplate *cT2 = new cycleTemplate(LED_RED, c3, 1);

  uint8_t c = -1;
  cycleTemplate **cycles;

  unsigned long getDelay();
  void cycle(cycleTemplate *ct);
  void down(uint8_t pin);
  void up(uint8_t pin);
  void flash(uint8_t *pins, uint8_t amount);
  void flash(uint8_t *pins, uint8_t amount, uint8_t level);

public:
  void setup();
  void loop(void);
};