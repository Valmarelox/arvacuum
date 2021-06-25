#include "prog.hpp"

ArduinoProgram::ArduinoProgram() {
    init();
    Serial.begin(9600);
#if defined(USBCON)
    USBDevice.attach();
#endif
    //setup();
    wdt_enable(WDTO_2S);
}

void ArduinoProgram::loop() {
    wdt_reset();
    if (serialEventRun) serialEventRun();
}
