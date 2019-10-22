#include <sketch.h>
#include <Adafruit_NeoPixel.h>
#include <time.h>

class main : public sketch
{
private:
  Adafruit_NeoPixel *pixels;
  int i;
  bool direction;

public:
  void setup()
  {
    direction = false;
    pixels = new Adafruit_NeoPixel(10, 13, NEO_GRB + NEO_KHZ800);
    pixels->begin();
    Serial.begin(SERIAL_SPEED);
    srand((int) time(NULL));
  }
  void loop()
  {
    pixels->clear();

    if (direction)
    {
      i++;
      Serial.print(" inc");
    }
    else
    {
      i--;
      Serial.print(" dec");
    }

    i = constrain(i, 0,9);


    Serial.print(i);
    pixels->setPixelColor(
      i, 
      pixels->Color(
        rand() % (255 + 1 - 0) + 0, 
        rand() % (255 + 1 - 0) + 0, 
        rand() % (255 + 1 - 0) + 0
      )
    );
    pixels->show();
    delay(120);

    if (i >= 9||i <= 0)
    {
      Serial.print(" change direction ");
      direction = !direction;
    }
    Serial.println();
  }
};