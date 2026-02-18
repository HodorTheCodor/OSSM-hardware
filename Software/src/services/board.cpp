#include "board.h"

#include "services/display.h" //4444444444

#include <Wire.h>
//TwoWire Wire1(1);
//TwoWire Wire1 = TwoWire(1);
#include <Adafruit_INA260.h>
Adafruit_INA260 ina260;

bool USE_SPEED_KNOB_AS_LIMIT = true;

void initBoard() {
    Serial.begin(115200);
    delay(300);

    if (displayMutex == nullptr) {
        displayMutex = xSemaphoreCreateMutex();
    }

    initStepper();

    Wire.begin(Pins::I2C::sda, Pins::I2C::scl);
    Serial.printf("Pins::I2C sda=%d scl=%d\n", Pins::I2C::sda, Pins::I2C::scl);
    Serial.flush();
    delay(50);

    if (!ina260.begin()) { //0x40, &Wire1
        Serial.println("Couldn't find INA260 chip!");
        //while (1);
    }

    /*
    pinMode(Pins::Remote::encoderSwitch,
            INPUT_PULLDOWN);  // Rotary Encoder Pushbutton

    pinMode(Pins::GPIO::pin1, OUTPUT);
    pinMode(Pins::GPIO::pin2, OUTPUT);
    pinMode(Pins::GPIO::pin3, OUTPUT);
    pinMode(Pins::GPIO::pin4, OUTPUT);
    */

    pinMode(Pins::Driver::motorEnablePin, OUTPUT);
    //pinMode(Pins::Wifi::resetPin, INPUT_PULLDOWN);
    //pinMode(Pins::Remote::speedPotPin, INPUT);
    //adcAttachPin(Pins::Remote::speedPotPin);

    //analogReadResolution(12);
    //analogSetAttenuation(ADC_11db);  // allows us to read almost full 3.3V range
    //Serial.println("Finished init pinModes");
    //initStepper();
    //Serial.println("Start initEncoder");
    //initEncoder();
    //Serial.println("End initEncoder");
    //Serial.println("Start initLED");
    //initLED();
    //Serial.println("End initLED");
    Serial.println("End initBoard");
}
