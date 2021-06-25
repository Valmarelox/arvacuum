#include "utils.hpp"
#include "pin.hpp"
    
bool DigitalPin::allocated_pins[DigitalPin::PIN_COUNT] = {false};

DigitalPin DigitalPin::alloc_pin(unsigned long num, Mode mode=DigitalPin::Mode::OUTPUT) {
    if (DigitalPin::allocated_pins[num]) {
        halt_program("Attempted to reuse pin %u\r\n", num);
    }

    DigitalPin pin(num);
    DigitalPin::allocated_pins[num] = true;
    return pin;
}

DigitalPin::~DigitalPin() {
    DigitalPin::allocated_pins[_num] = false;
}

void DigitalPin::set(Level level) {
    digitalWrite(_num, level);
}

void DigitalPin::set(Mode mode) {
    pinMode(_num, mode);
}

unsigned long DigitalPin::pulse_in(Level level) {
    return pulseIn(_num, level);
}
