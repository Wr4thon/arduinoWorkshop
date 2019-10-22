#include <005_breathing.h>

void breathing::setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_DUAL_GREEN, OUTPUT);
  pinMode(LED_DUAL_RED, OUTPUT);
  cycles = new cycleTemplate *[3] { cT0, cT1, cT2 };
}

void breathing::loop(void)
{
  c++;
  if (c >= turns)
  {
    c = 0;
  }
  cycle(cycles[c]);
}

unsigned long breathing::getDelay()
{
  return map(analogRead(POT), 1023, 400, 2, 20);
}

void breathing::cycle(cycleTemplate *ct)
{
  up(ct->mainPin);
  down(ct->mainPin);
  flash(ct->flashPins, ct->flashPinsAmount);
}

void breathing::flash(uint8_t *pins, uint8_t amount, uint8_t level)
{
  for (int i = 0; i < amount; i++)
  {
    uint8_t pin = pins[i];
    digitalWrite(pin, level);
  }
}

void breathing::flash(uint8_t *pins, uint8_t amount)
{
  for (int i = 0; i < 2; i++)
  {
    flash(pins, amount, HIGH);
    delay(50);
    flash(pins, amount, LOW);
    delay(50);
  }
}

void breathing::up(uint8_t pin)
{
  for (int i = 0; i < 128; i++)
  {
    analogWrite(pin, i);
    delay(getDelay());
  }
}

void breathing::down(uint8_t pin)
{
  for (int i = 128; i >= 0; i--)
  {
    analogWrite(pin, i);
    delay(getDelay());
  }
}