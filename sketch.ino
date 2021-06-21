#include "distance_sensor.hpp"

const DistanceSensor forward(7, 6);
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
    long cm;
    cm = forward.measure_distance();


    digitalWrite(13, (cm >= 20 ? HIGH : LOW));
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
}
