#include <002_helloWorld.h>

void helloWorld::setup(void)
{
  Serial.begin(SERIAL_SPEED);
}

void helloWorld::loop(void)
{
  Serial.println("Hello World!");
  delay(1000);
}