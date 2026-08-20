#include "Ultrasonic.h"
#include <Servo.h>

const int BUZZER_PIN = 5;

const int LED_PIN = 6;

const int SERVO_PIN = 3;

Ultrasonic ultrasonic(2);

Servo boomGate;

int readDistance() {
  return ultrasonic.read();
}

int classifyZone(int distance, int nearLimit, int farLimit) {

  if (distance < nearLimit) {
    return 0;
  } else if (distance < farLimit) {
    return 1;
  }

  return 2;
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  boomGate.attach(SERVO_PIN);
  boomGate.write(90);
}

void loop() {

  int distance = readDistance();

  int zone = classifyZone(distance, 10, 30);

  Serial.print(distance);
  Serial.print(" cm, zone ");
  Serial.println(zone);

  if (distance > 0 && distance < 30) {
    boomGate.write(180);
  } else {
    boomGate.write(90);
  }

  delay(100);
}
