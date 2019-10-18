#include <sketch.h>

class main : public sketch
{
private:
  int min = 1024, max = 0;
public:
  void setup()
  {
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    Serial.begin(SERIAL_SPEED);
  }

  void loop()
  {
    int value = analogRead(PHOTO);
    analogWrite(LED_RED, mapRed(value));
    analogWrite(LED_YELLOW, mapYellow(value));
    analogWrite(LED_GREEN, mapGreen(value));
    
    if(value < min){
      min = value;
    }
    
    if(value > max){
      max = value;
    }

    Serial.print(min);
    Serial.print(" - ");
    Serial.print(max);
    Serial.print(" - ");
    Serial.println(value);
  }

  int mapRed(int value) {
    return map(value, 1024, 250, 0, 127);
  }

  int mapYellow(int value) {
    return map(value, 682, 341, 0, 127);
  }
  
  int mapGreen(int value) {
    return map(value, 250, 1024, 0, 127);
  }
};