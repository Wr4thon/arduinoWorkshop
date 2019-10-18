#include <consts.h>

uint8_t c1[1]{LED_DUAL_GREEN};
uint8_t c2[2]{LED_DUAL_RED, LED_DUAL_GREEN};
uint8_t c3[1]{LED_DUAL_RED};

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
} cT0(LED_GREEN, c1, 1), cT1(LED_YELLOW, c2, 2), cT2(LED_RED, c3, 1);

const uint8_t turns = 3;
uint8_t c = -1;
cycleTemplate *cycles[turns] = {&cT0, &cT1, &cT2};

void setup()
{
  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_DUAL_GREEN, OUTPUT);
  pinMode(LED_DUAL_RED, OUTPUT);
}

void loop(void)
{
  c++;
  if (c >= turns)
  {
    c = 0;
  }
  cycle(cycles[c]);
}

unsigned long getDelay()
{
  uint32_t val = analogRead(PHOTO);

  Serial.println(val);

  return map(val, 1023, 400, 2, 20);
}

void cycle(cycleTemplate *ct)
{
  up(ct->mainPin);
  down(ct->mainPin);
  flash(ct->flashPins, ct->flashPinsAmount);
}

void flash(uint8_t *pins, uint8_t amount, uint8_t level)
{
  for (int i = 0; i < amount; i++)
  {
    uint8_t pin = pins[i];
    digitalWrite(pin, level);
  }
}

void flash(uint8_t *pins, uint8_t amount)
{
  for (int i = 0; i < 2; i++)
  {
    flash(pins, amount, HIGH);
    delay(50);
    flash(pins, amount, LOW);
    delay(50);
  }
}

void up(uint8_t pin)
{
  for (int i = 0; i < 128; i++)
  {
    analogWrite(pin, i);
    delay(getDelay());
  }
}

void down(uint8_t pin)
{
  for (int i = 128; i >= 0; i--)
  {
    analogWrite(pin, i);
    delay(getDelay());
  }
}