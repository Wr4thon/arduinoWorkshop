#include <006_lightTester.h>

void lightTester::setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(SERIAL_SPEED);
}

void lightTester::loop()
{
  int value = analogRead(PHOTO);
  analogWrite(LED_RED, mapRed(value));
  analogWrite(LED_YELLOW, mapYellow(value));
  analogWrite(LED_GREEN, mapGreen(value));

  if (value < min)
  {
    min = value;
  }

  if (value > max)
  {
    max = value;
  }

  Serial.print(min);
  Serial.print(" - ");
  Serial.print(max);
  Serial.print(" - ");
  Serial.println(value);
}

int lightTester::mapRed(int value)
{
  return map(value, 1024, 250, 0, 127);
}

int lightTester::mapYellow(int value)
{
  return map(value, 682, 341, 0, 127);
}

int lightTester::mapGreen(int value)
{
  return map(value, 250, 1024, 0, 127);
}