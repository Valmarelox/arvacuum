#include "distance_sensor.hpp"
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const DistanceSensor forward(7, 6);
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, cm;
   cm = forward.measure_distance();

   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long pulse_distance_forward() {
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

