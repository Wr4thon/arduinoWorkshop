#include <consts.h>


void setup()
{
  Serial.begin(SERIAL_SPEED);
}

void loop()
{
  Serial.println("Hello World!");
  delay(1000);
}
