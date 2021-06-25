#pragma once
#include <Arduino.h>
#include <avr/wdt.h>

class ArduinoProgram {
public:
    void loop();
    ArduinoProgram();

private:
    //static ArduinoProgram singleton;
};
