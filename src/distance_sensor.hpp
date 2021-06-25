#include "pin.hpp"
#include "sensor.hpp"

class DistanceSensor: public Sensor {
public:
    DistanceSensor(unsigned int ping_pin, unsigned int echo_pin) :
        _ping_pin(DigitalPin::alloc_pin(ping_pin, DigitalPin::Mode::OUTPUT)), 
        _echo_pin(DigitalPin::alloc_pin(echo_pin, DigitalPin::Mode::INPUT)) { }

    unsigned long measure();


private:
    DigitalPin _ping_pin;
    DigitalPin _echo_pin;
};
