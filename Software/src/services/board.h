#ifndef OSSM_SOFTWARE_BOARD_H
#define OSSM_SOFTWARE_BOARD_H

#include <Arduino.h>
#include <NimBLEDevice.h>

#include <Adafruit_INA260.h>
extern Adafruit_INA260 ina260;

#include "constants/Pins.h"
#include "services/encoder.h"
#include "services/stepper.h"
#include "services/led.h"

extern bool USE_SPEED_KNOB_AS_LIMIT;
void initBoard();

#endif  // OSSM_SOFTWARE_BOARD_H
