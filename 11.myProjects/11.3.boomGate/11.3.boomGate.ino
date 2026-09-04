
#include <Servo.h>

const int TRIG_PIN = 2;
const int ECHO_PIN = 2;
const int SERVO_PIN = 3;

Servo gateServo;

void setup() {
  Serial.begin(9600);

  gateServo.attach(SERVO_PIN);

  gateServo.write(90);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance < 20) {
    gateServo.write(180);
  } else {
    gateServo.write(90);
  }

  delay(100);
}

/*
  Author:
  Learning Intention: Students will use an ultrasonic sensor to control a servo motor

  Student Notes:
  1. Make sure you include flow chart of your logic
  2. Students should aim to implement different logic approaches to the problem

  3. Suggested Grove ports: Ultrasonic D2 (single signal pin), Servo D3
*/
