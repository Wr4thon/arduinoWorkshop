#include <sketch.h>

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_DUAL_GREEN, OUTPUT);
  pinMode(LED_DUAL_RED, OUTPUT);
  Serial.begin(9600);
}

void loop(void)
{
  cycle(LED_GREEN, LED_DUAL_RED, "GREEN");
  cycle(LED_YELLOW, LED_DUAL_RED, "YELLOW");
  cycle(LED_RED, LED_DUAL_GREEN, "RED");
}

unsigned long getDel() {
  return map(analogRead(POT), 0, 1023, 2, 20);
}

void cycle(uint8_t pin, uint8_t flashPin, String name)
{
  Serial.print(name);
  Serial.println(" UP");
  up(pin);
  Serial.print(name);
  Serial.println(" DOWN");
  down(pin);
  flash(flashPin);
}

void flash(uint8_t pin)
{
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(pin, HIGH);
    delay(50);
    digitalWrite(pin, LOW);
    delay(50);
  }
}

void up(uint8_t pin)
{
  for (int i = 0; i < 128; i++)
  {
    analogWrite(pin, i);
    delay(getDel());
  }
}

void down(uint8_t pin)
{
  for (int i = 128; i >= 0; i--)
  {
    analogWrite(pin, i);
    delay(getDel());
  }
}