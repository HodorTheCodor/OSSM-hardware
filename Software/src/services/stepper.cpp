#if defined(FASTACCELSTEPPER_USE_MCPWM)
#warning "FastAccelStepper: MCPWM backend"
#elif defined(FASTACCELSTEPPER_USE_RMT)
#warning "FastAccelStepper: RMT backend"
#else
#warning "FastAccelStepper: backend not explicitly set"
#endif

#include "stepper.h"

FastAccelStepperEngine stepperEngine = FastAccelStepperEngine();
FastAccelStepper *stepper = nullptr;
class StrokeEngine Stroker;

void initStepper() {
    Serial.println("before stepperEngine.init");
    stepperEngine.init();
    Serial.println("after stepperEngine.init");
    Serial.println("before connectToPin");
    stepper = stepperEngine.stepperConnectToPin(Pins::Driver::motorStepPin);
    Serial.println("after connectToPin");
    if (stepper) {
        stepper->setDirectionPin(Pins::Driver::motorDirectionPin, false);
        stepper->setEnablePin(Pins::Driver::motorEnablePin, true);
        stepper->setAutoEnable(false);
    }

    // disable motor briefly in case we are against a hard stop.
    digitalWrite(Pins::Driver::motorEnablePin, HIGH);
    delay(600);
    digitalWrite(Pins::Driver::motorEnablePin, LOW);
    delay(100);
    Serial.println("initStepper: exit");
}
