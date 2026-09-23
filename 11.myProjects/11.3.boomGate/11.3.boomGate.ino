/*
  Author: Callen Lin
  Learning Intention: Students will use an ultrasonic sensor to control a servo motor

  Student Notes:
  1. Make sure you include flow chart of your logic
  2. Students should aim to implement different logic approaches to the problem

  3. Suggested Grove ports: Ultrasonic D2 (single signal pin), Servo D3
*/

#include <Servo.h>
#include "Ultrasonic.h"

const int ULTRASONIC_PIN = 2;
const int SERVO_PIN = 3;

const int DETECTION_DISTANCE = 20;

const int CLOSED_ANGLE = 0;
const int OPEN_ANGLE = 90;

const unsigned long CLEAR_DELAY = 2000;
const unsigned long SERVO_INTERVAL = 1;

Ultrasonic ultrasonic(ULTRASONIC_PIN);
Servo gateServo;

enum GateState {
  CLOSED,
  OPENING,
  OPEN,
  WAIT,
  CLOSING
};

GateState gateState = CLOSED;

unsigned long clearStartTime = 0;
unsigned long servoTimer = 0;

int gateAngle = CLOSED_ANGLE;

float getDistance() {

  return ultrasonic.read();

}

void setGateAngle(int targetAngle) {

  if (gateAngle < targetAngle) {
    gateAngle++;
  }

  else if (gateAngle > targetAngle) {
    gateAngle--;
  }

  gateServo.write(gateAngle);
}


void setup() {

  Serial.begin(115200);

  gateServo.attach(SERVO_PIN);
  gateServo.write(CLOSED_ANGLE);

  Serial.println("========================================");
  Serial.println("THE LEGENDARYBOOM GATE FOR MR VEHICLE");
  Serial.println("========================================");
}


void loop() {

  unsigned long currentTime = millis();

  float distance = getDistance();

  bool vehicleDetected =
    distance > 0 && distance < DETECTION_DISTANCE;

  if (currentTime - servoTimer >= SERVO_INTERVAL) {

    servoTimer = currentTime;

    if (gateState == OPENING) {

      setGateAngle(OPEN_ANGLE);

      if (gateAngle == OPEN_ANGLE) {
        gateState = OPEN;

        Serial.println("Gate fully open.");
      }
    }

    else if (gateState == CLOSING) {
      if (vehicleDetected) {

        gateState = OPENING;

        Serial.println("Vehicle detected during closing! Reopening gate.");

      }

      else {

        setGateAngle(CLOSED_ANGLE);

        if (gateAngle == CLOSED_ANGLE) {
          gateState = CLOSED;

          Serial.println("No one around... CLOSED.");
        }
      }
    }
  }


  switch (gateState) {

    case CLOSED:

      if (vehicleDetected) {

        gateState = OPENING;

        Serial.println("Yo its Mr Vehicle - OPEN SESAME!!!!");
      }

      break;

    case OPENING:
      break;

    case OPEN:

      if (!vehicleDetected) {
        clearStartTime = currentTime;
        gateState = WAIT;
        Serial.println("Yo Mr Vehicle is here! OPEN UP!");
      }

      break;

    case WAIT:

      if (vehicleDetected) {

        gateState = OPEN;
        Serial.println("Mr Vehicle Still here? Uh. STAY OPEN!!!!");
      }

      else if (currentTime - clearStartTime >= CLEAR_DELAY) {

        gateState = CLOSING;

        Serial.println("Closing da gate.");
      }

      break;

    case CLOSING:
      break;
  }


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Current State: ");

  switch (gateState) {

    case CLOSED:
      Serial.println("CLOSED");
      break;

    case OPENING:
      Serial.println("OPENING");
      break;

    case OPEN:
      Serial.println("OPEN");
      break;

    case WAIT:
      Serial.println("WAIT");
      break;

    case CLOSING:
      Serial.println("CLOSING");
      break;
  }

  delay(25);
}
