#include "board.h"

#include <Wire.h>
#include <Adafruit_INA260.h>
Adafruit_INA260 ina260;

bool USE_SPEED_KNOB_AS_LIMIT = true;

void initBoard() {
    Serial.begin(115200);

    Wire.begin(Pins::I2C::sda, Pins::I2C::scl);

    if (!ina260.begin(INA260_ADDRESS, &Wire)) {
        Serial.println("Couldn't find INA260 chip!");
        while (1);
    }

    pinMode(Pins::Remote::encoderSwitch,
            INPUT_PULLDOWN);  // Rotary Encoder Pushbutton

    pinMode(Pins::GPIO::pin1, OUTPUT);
    pinMode(Pins::GPIO::pin2, OUTPUT);
    pinMode(Pins::GPIO::pin3, OUTPUT);
    pinMode(Pins::GPIO::pin4, OUTPUT);

    pinMode(Pins::Driver::motorEnablePin, OUTPUT);
    pinMode(Pins::Wifi::resetPin, INPUT_PULLDOWN);
    pinMode(Pins::Remote::speedPotPin, INPUT);
    adcAttachPin(Pins::Remote::speedPotPin);

    analogReadResolution(12);
    analogSetAttenuation(ADC_11db);  // allows us to read almost full 3.3V range
    initStepper();
    initEncoder();
    initLED();
}
