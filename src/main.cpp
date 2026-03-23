#include <Arduino.h>
#include <EncButton.h>

static const uint8_t ENC_CLK_PIN = 18;
static const uint8_t ENC_DT_PIN = 19;
static const uint8_t ENC_SW_PIN = 5;

EncButton enc(ENC_CLK_PIN, ENC_DT_PIN, ENC_SW_PIN, INPUT_PULLUP, INPUT_PULLUP, LOW);
int val = 0;

void onEncoderAction()
{
  switch (enc.action())
  {
  case EB_TURN: {
    const bool pressed = enc.pressing();
    const int8_t dir = enc.dir();

    val += (dir > 0) ? (pressed ? 5 : 1) : (pressed ? -5 : -1);

    Serial.print(pressed ? "[TURN_HOLD] dir=" : "[TURN] dir=");
    Serial.print(dir);
    Serial.print(" val=");
    Serial.println(val);
    break;
  }

  case EB_CLICK:
    val = 0;
    Serial.println("[RESET_CLICK] val=0");
    break;

  default:
    break;
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  enc.setBtnLevel(LOW);
  enc.setEncType(EB_STEP4_LOW);
  enc.attach(onEncoderAction);
  Serial.println("[BOOT] Encoder ready");
}

void loop()
{
  enc.tick();
}