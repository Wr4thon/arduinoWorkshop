#include <001_blink.h>

void blink::setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink::loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}