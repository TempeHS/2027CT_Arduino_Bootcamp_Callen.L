#include "Ultrasonic.h"


Ultrasonic ultrasonic(2);   // Grove 3-pin sensor: trigger and echo share D2

void setup() {
  Serial.begin(115200);
}


int readDistance() {
  return ultrasonic.read();
}

int classifyZone(int distance, int nearLimit, int farLimit) {
  if (distance < nearLimit) {
    return 0;              // danger
  } else if (distance < farLimit) {
    return 1;              // warning
  }
  return 2;                // safe
}

void loop() {
  int distance = readDistance();
  int zone = classifyZone(distance, 10, 30);
  Serial.print(distance);
  Serial.print(" cm, zone ");
  Serial.println(zone);
  delay(100);
}
