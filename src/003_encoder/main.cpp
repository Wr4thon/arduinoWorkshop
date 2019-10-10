#include <sketch.h>

#include <ClickEncoder.h>
#include <TimerOne.h>

class enc : public sketch
{
private:
  int16_t oldEncPos, encPos;
  uint8_t buttonState;

  static ClickEncoder *encoder;

  static void StaticConstructor(){
    enc::encoder = new ClickEncoder(ENC_A, ENC_B, ENC_BTN, ENC_STEPS);
  }

  static void timerIsr()
  {
    enc::encoder->service();
  }

public:
  void setup(void)
  {
    Serial.begin(9600);

    Timer1.initialize(1000);
    Timer1.attachInterrupt(enc::timerIsr);

    enc::encoder->setAccelerationEnabled(true);

    Serial.print("Acceleration is ");
    Serial.println((enc::encoder->getAccelerationEnabled()) ? "enabled" : "disabled");

    oldEncPos = -1;
  }

  void loop(void)
  {

    encPos += enc::encoder->getValue();

    if (encPos != oldEncPos)
    {
      oldEncPos = encPos;
      Serial.print("Encoder Value: ");
      Serial.println(encPos);
    }

    buttonState = enc::encoder->getButton();

    if (buttonState != 0)
    {
      Serial.print("Button: ");
      Serial.println(buttonState);
      switch (buttonState)
      {
      case ClickEncoder::Open: //0
        break;

      case ClickEncoder::Closed: //1
        break;

      case ClickEncoder::Pressed: //2
        break;

      case ClickEncoder::Held: //3
        break;

      case ClickEncoder::Released: //4
        break;

      case ClickEncoder::Clicked: //5
        break;

      case ClickEncoder::DoubleClicked: //6
        break;
      }
    }
  }
};