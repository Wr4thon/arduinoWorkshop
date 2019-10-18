#include <004_trafficlight.h>

class main : public sketch
{
private:
  trafficLightCycle *fullCycle;
  uint8_t cycleCurrentStep;
  uint8_t cycleStepsAmount;
public:
  void setup(void)
  {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_DUAL_GREEN, OUTPUT);
    pinMode(LED_DUAL_RED, OUTPUT);

    cycleStepsAmount = 6;
    cycleCurrentStep = cycleStepsAmount;
    
    setLightState(lightState(LED_DUAL_RED, HIGH));
    
    lightState *cycleState0 = new lightState[2]{
      lightState(LED_YELLOW, LOW),
      lightState(LED_RED, HIGH)
    };

    lightState *cycleState1 = new lightState[2]{
      lightState(LED_DUAL_GREEN, HIGH),
      lightState(LED_DUAL_RED, LOW)
    };

    lightState *cycleState2 = new lightState[2]{
      lightState(LED_DUAL_GREEN, LOW),
      lightState(LED_DUAL_RED, HIGH)
    };

    lightState *cycleState3 = new lightState[2]{
      lightState(LED_RED, HIGH),
      lightState(LED_YELLOW, HIGH)
    };

    lightState *cycleState4 = new lightState[3]{
      lightState(LED_RED, LOW),
      lightState(LED_YELLOW, LOW),
      lightState(LED_GREEN, HIGH)
    };

    lightState *cycleState5 = new lightState[2]{
      lightState(LED_YELLOW, HIGH),
      lightState(LED_GREEN, LOW)
    };

    fullCycle = new trafficLightCycle[6]{
        trafficLightCycle(cycleState0, 2, 750), // car red
        trafficLightCycle(cycleState1, 2, 2500), // pedestrian green
        trafficLightCycle(cycleState2, 2, 1500), // pedestrian red - delay for slow walkers.
        trafficLightCycle(cycleState3, 2, 1000), // car red, yellow
        trafficLightCycle(cycleState4, 3, 5000), // car green 
        trafficLightCycle(cycleState5, 2, 1000), // car yellow
    };
  }

  void loop(void)
  {
    cycleCurrentStep++;
    if(cycleCurrentStep >= cycleStepsAmount){
      cycleCurrentStep = 0;
    }

    trafficLightCycle currentStep = fullCycle[cycleCurrentStep];
    applyCycle(currentStep);
    delay(currentStep.delay);
  }

  void applyCycle(trafficLightCycle cycle) {
    for (size_t i = 0; i < cycle.amountLeds; i++)
    {
      setLightState(cycle.activeLEDs[i]);
    }    
  }

  void setLightState(lightState state){
    digitalWrite(state.led, state.state);
  }
};