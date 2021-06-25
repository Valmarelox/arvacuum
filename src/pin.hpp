#pragma once
#include <Arduino.h>
#undef LOW
#undef HIGH
#undef INPUT
#undef OUTPUT

class DigitalPin {
public:
    enum Level {
        LOW = 0x0,
        HIGH = 0x1,
    };
    enum Mode {
        INPUT = 0x0,
        OUTPUT = 0x1,
    };

    static DigitalPin alloc_pin(unsigned long num, Mode mode=Mode::OUTPUT);

    void set(Level level);
    void set(Mode mode);

    unsigned long pulse_in(Level level);
    virtual ~DigitalPin();

protected: 
    static const unsigned long PIN_COUNT = 14;
    DigitalPin(unsigned long num): _num(num) {}
    static bool allocated_pins[PIN_COUNT];

    unsigned long _num;
};
