#include <stdarg.h>
#include <stdio.h>
#include "fexception.hpp"

fexception::fexception(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    auto size = vsnprintf(NULL, 0 , fmt, args);
    // TODO: Should handle size -1?
    _what = new char[size + 1];

    va_start(args, fmt);
    vsnprintf(_what, size, fmt, args);
}
