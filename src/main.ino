#include <sketch.h>

uint8_t c1[1]{LED_DUAL_GREEN};
uint8_t c2[2]{LED_DUAL_RED, LED_DUAL_GREEN};
uint8_t c3[1]{LED_DUAL_RED};

struct cycleTemplate
{
  uint8_t mainPin;
  uint8_t *flashPins;
  uint8_t flashPinsAmount;
  String name;

  cycleTemplate(uint8_t mP, uint8_t *fP, uint8_t fPA, String n)
  {
    mainPin = mP;
    flashPins = fP;
    flashPinsAmount = fPA;
    name = n;
  }
} cT0(LED_GREEN, c1, 1, "GREEN"), cT1(LED_YELLOW, c2, 2, "YELLOW"), cT2(LED_RED, c3, 1, "RED");

cycleTemplate *cycles[3];
uint8_t c = - 1;
uint8_t turns = 3;

void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_DUAL_GREEN, OUTPUT);
  pinMode(LED_DUAL_RED, OUTPUT);

  cycles[0] = &cT0;
  cycles[1] = &cT1;
  cycles[2] = &cT2;
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
  return map(analogRead(POT), 0, 1023, 2, 20);
}

void cycle(cycleTemplate *ct)
{
  Serial.print(ct->name);
  Serial.println(" UP");
  up(ct->mainPin);
  Serial.print(ct->name);
  Serial.println(" DOWN");
  down(ct->mainPin);
  flash(ct->flashPins, ct->flashPinsAmount);
}

void flash(uint8_t *pins, uint8_t amount, uint8_t level)
{
  for (int i = 0; i < amount; i++)
  {
    uint8_t pin = pins[i];
    Serial.print(pin);
    Serial.print(" ");
    Serial.print(level);
    digitalWrite(pin, level);
    Serial.print(" ");
  }
  
  Serial.println();
}

void flash(uint8_t *pins, uint8_t amount)
{
  Serial.print("flash '");
  Serial.print(amount);
  Serial.print("' pins - ");
  Serial.print(pins[0]);

  if(amount == 2) {
    Serial.print(" and ");
    Serial.print(pins[1]);
  }

  Serial.println();

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