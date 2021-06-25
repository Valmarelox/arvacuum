#include "sensor.hpp"

class IRSensor: public Sensor {
public:
    IRSensor(unsigned long pin) : _pin(pin) {}

private:
    unsigned long _pin;
};
