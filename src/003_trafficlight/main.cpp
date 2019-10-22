#include <003_trafficLight.h>

void trafficLightSimple::setup(void)
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_DUAL_GREEN, OUTPUT);
  pinMode(LED_DUAL_RED, OUTPUT);
  digitalWrite(LED_DUAL_RED, HIGH);
}

void trafficLightSimple::loop(void)
{
  digitalWrite(LED_GREEN, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_DUAL_RED, LOW);
  digitalWrite(LED_DUAL_GREEN, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_DUAL_GREEN, LOW);
  digitalWrite(LED_DUAL_RED, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_YELLOW, HIGH);
  delay(cycleDelay);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}