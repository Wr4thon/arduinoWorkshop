#include <consts.h>

#include <ClickEncoder.h>
#include <TimerOne.h>

int16_t oldEncPos, encPos;
uint8_t buttonState;

static ClickEncoder *encoder = new ClickEncoder(ENC_A, ENC_B, ENC_BTN, ENC_STEPS);

static void timerIsr()
{
  encoder->service();
}

void setup()
{
  Serial.begin(SERIAL_SPEED);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);

  encoder->setAccelerationEnabled(true);

  Serial.print("Acceleration is ");
  Serial.println((encoder->getAccelerationEnabled()) ? "enabled" : "disabled");

  oldEncPos = -1;
}

void loop()
{

  encPos += encoder->getValue();

  if (encPos != oldEncPos)
  {
    oldEncPos = encPos;
    Serial.print("Encoder Value: ");
    Serial.println(encPos);
  }

  buttonState = encoder->getButton();

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
