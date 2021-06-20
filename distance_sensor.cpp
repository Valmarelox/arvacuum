#include "distance_sensor.hpp"
#include <Arduino.h>

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

unsigned long DistanceSensor::measure_distance() {
    pinMode(_ping_pin, OUTPUT);
    digitalWrite(_ping_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(_ping_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_ping_pin, LOW);
    pinMode(_echo_pin, INPUT);
    unsigned long duration = pulseIn(_echo_pin, HIGH);
    return microsecondsToCentimeters(duration);

}

