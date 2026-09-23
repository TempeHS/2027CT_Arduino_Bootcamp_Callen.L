/*
  Author: Callen Lin
  Learning Intention: Students will use an ultrasonic sensor to control a servo motor

  Student Notes:
  1. Make sure you include flow chart of your logic
  2. Students should aim to implement different logic approaches to the problem

  3. Suggested Grove ports: Ultrasonic D2 (single signal pin), Servo D3
*/

// WIP

#include <Servo.h>

const int TRIG_PIN = 2;
const int ECHO_PIN = 4;
const int SERVO_PIN = 3;

const int DETECTION_DISTANCE = 20;

const unsigned long DELAYER2000 = 2000;

Servo gateServo;

enum GateState {
  CLOSED,
  OPEN,
  WAIT
};

GateState gateState = CLOSED;

unsigned long clearStartTime = 0;


float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.0343 / 2;

  return distance;
}


void setup() {
  Serial.begin(9600);

  gateServo.attach(SERVO_PIN);
  gateServo.write(CLOSED);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}


void loop() {
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  bool vehicleDetected =
    distance > 0 && distance < DETECTION_DISTANCE;


  switch (gateState) {

    case CLOSED:

      if (vehicleDetected) {
        gateServo.write(OPEN);
        gateState = OPEN;

        Serial.println("Yo its Mr Vehicle - OPEN SESAME!!!!");
      }

      break;


    case OPEN:

      if (!vehicleDetected) {
        clearStartTime = millis();
        gateState = WAIT;

        Serial.println("Mr Vehicle - Beep... Beep... Beep...");
      }

      break;


    case WAIT:

      if (vehicleDetected) {
        gateServo.write(OPEN);
        gateState = OPEN;

        Serial.println("Mr Vehicle Still here? - STAY OPEN!!!!");
      }

      else if (millis() - clearStartTime >= DELAYER2000) {
        gateServo.write(CLOSED);
        gateState = CLOSED;

        Serial.println("No one around... - hmm... CLOSED");
      }

      break;
  }

  delay(100);
}
