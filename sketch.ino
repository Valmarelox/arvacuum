#include "prog.hpp"
#include "distance_sensor.hpp"

int main() {
    ArduinoProgram prog;
    DistanceSensor forward(7, 6);
    DigitalPin led = DigitalPin::alloc_pin(13);
    Serial.print("boot\n");

    while (true) {
        prog.loop();

        long cm;
        cm = forward.measure();

        led.set((cm >= 20 ? DigitalPin::Level::HIGH : DigitalPin::Level::LOW));
        Serial.print(cm);
        Serial.print("cm");
        Serial.println();
        delay(100);
    }
    return 0;
}
