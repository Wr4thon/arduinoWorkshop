#include <001_blink.h>
#include <002_helloWorld.h>
#include <003_trafficLight.h>
#include <004_trafficlight.h>
#include <005_breathing.h>
#include <006_lightTester.h>
#include <007_neoPixel.h>
#include <008_nightRider.h>
#include <009_nightRiderColored.h>

sketch **s = new sketch*[9]{
  new blink(),
  new helloWorld(),
  new trafficLightSimple(),
  new trafficLightAdvanced(),
  new breathing(),
  new lightTester(),
  new neoPixel(),
  new nightRider(),
  new nightRiderColored()
};

void setup()
{
  s[7]->setup();
}

void loop()
{
  s[7]->loop();
}
