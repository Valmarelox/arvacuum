#include <Arduino.h>
#include <stdio.h>
#include <stdarg.h>
#include "utils.hpp"

__attribute__((noreturn))
void halt_program(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    auto size = vsnprintf(NULL, 0 , fmt, args);
    // TODO: Should handle size -1?
    auto _what = new char[size + 1];

    va_start(args, fmt);
    vsnprintf(_what, size, fmt, args);
    Serial.print(_what);
    Serial.flush();
    delete _what;
    while (true);
}
