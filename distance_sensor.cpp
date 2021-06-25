#include "distance_sensor.hpp"
#include <Arduino.h>

static long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

unsigned long DistanceSensor::measure() {
    _ping_pin.set(DigitalPin::Level::LOW);
    delayMicroseconds(2);
    _ping_pin.set(DigitalPin::Level::HIGH);
    delayMicroseconds(10);
    _ping_pin.set(DigitalPin::Level::LOW);

    unsigned long duration = _echo_pin.pulse_in(DigitalPin::Level::HIGH);
    return microsecondsToCentimeters(duration);

}

