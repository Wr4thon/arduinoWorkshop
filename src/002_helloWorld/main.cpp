#include <sketch.h>

class main : public sketch
{
public:
  void setup(void)
  {
    Serial.begin(SERIAL_SPEED);
  }

  void loop(void)
  {
    Serial.println("Hello World!");
    delay(1000);
  }
};