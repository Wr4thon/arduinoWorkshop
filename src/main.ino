#include <001_blink.h>
#include <002_helloWorld.h>
#include <003_trafficLight.h>
#include <004_trafficlight.h>
#include <005_breathing.h>
#include <006_lightTester.h>
#include <007_neoPixel.h>
#include <008_nightRider.h>
#include <009_nightRiderColored.h>

const int sketchAmount = 9;
int currentSketch = 0;

sketch **sketches = new sketch*[sketchAmount]{
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
  Serial.begin(SERIAL_SPEED);
  currentSketch = 0;
  sketches[currentSketch]->setup();
}

void loop()
{
  if(Serial.available()){
    String s = Serial.readString();
    char *cs = new char[s.length()];
    s.toCharArray(cs, s.length());

    int sketchId = atoi(cs);
    if (sketchId < sketchAmount && sketchId > 0) {
      currentSketch = sketchId;
    }
    
    sketches[currentSketch]->setup();
  }

  sketches[currentSketch]->loop();
}
