/*
  Author: Callen Lin
  Learning Intention: Students will build a monitoring system that watches
  conditions and raises alerts, like the guardian inside a smart fridge

  The build: FRIDGE MONITOR
  1. Calibrate the light sensor FIRST (see below), then set your threshold
  2. The light sensor detects the door opening (light floods into a dark fridge)
  3. If the door stays open longer than 10 seconds, sound the buzzer and flash
     the LED until the door closes
  4. Keep the loop non-blocking: use the millis() pattern for the alarm flash
     AND the Serial Plotter output (no delay() anywhere)
  5. Plot the light level and door state so you can watch your threshold work

  Calibration (why: every bench is different):
    Ambient light, sensor tolerance and how enclosed your "fridge" is all
    change the raw readings, so a threshold that works for one build fails on
    another. Upload a bare reader first:
        void setup() { Serial.begin(115200); }
        void loop()  { Serial.println(analogRead(A3)); delay(50); }
    Watch the Serial Plotter. Record the covered (door closed) and uncovered
    (door open) values, set your threshold roughly halfway between them, and
    keep both measurements as a comment: evidence the number is not a guess.

  Student Notes:
  1. Make sure you include a flowchart of your logic
  2. Stretch goal: add a second sensor (Temp & Humidity I2C) or an OLED dashboard

  Suggested Grove ports: Light A3, Buzzer D5, LED D6
*/

// Don't have enough cables for the temperature sensor, so it's not included in this version (they are commented tho) :P
// The box only comes with 3 and all 3 are used, if there was one more open it can be used.

/*
// For the temperature and humidity sensor and OLED display
#include "Arduino_SensorKit.h"
#include <Wire.h>

#define Environment Environment_I2C

float temperature;
float humidity;
*/

const int lightPin = A3;
const int buzzerPin = 5;
const int ledPin = 6;

const int doorOpenThreshold = 497;

const unsigned long alarmDelay = 10000;
const unsigned long flashInterval = 250;
const unsigned long serialInterval = 100;

unsigned long doorOpenedTime = 0;
unsigned long flashTimer = 0;
unsigned long serialTimer = 0;

bool doorIsOpen = false;
bool alarmIsActive = false;
bool ledIsOn = false;

/*
// For the temperature and humidity sensor and OLED display
void readSensor() {
  temperature = Environment.readTemperature();
  humidity = Environment.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}


void updateDisplay() {
  Oled.setFont(u8x8_font_chroma48medium8_r);

  Oled.clearDisplay();

  Oled.setCursor(0, 0);
  Oled.print("Temperature:");

  Oled.setCursor(0, 1);
  Oled.print(temperature);
  Oled.print(" C");

  Oled.setCursor(0, 3);
  Oled.print("Humidity:");

  Oled.setCursor(0, 4);
  Oled.print(humidity);
  Oled.print(" %");

  Oled.refreshDisplay();
}


void checkAlert() {
  const float TEMP_LIMIT = 30.0;

  Oled.setCursor(0, 6);

  if (temperature >= TEMP_LIMIT) {
    Oled.print("!!! REALLY HOT"); // gotta add that 3 !!!.
  } else {
    Oled.print("Temperature OK"); // inspired by dyson's machine
  }

  Oled.refreshDisplay();
}
*/

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(115200);

  Serial.println("========================================");
  Serial.println("Starting... THE FRIDGE MONITOR™");
  Serial.println("========================================");
  Serial.print("THE FRIDGE MONITOR™ Door partial open threshold: ");
  Serial.println(doorOpenThreshold);
  Serial.println("========================================");

  /*
  // For the temperature and humidity sensor and OLED display
  Wire.begin();

  Environment.begin();
  Oled.begin();
  Oled.setFlipMode(true);
  */
}

void loop() {

  unsigned long currentTime = millis();

  int lightLevel = analogRead(lightPin);

  bool newDoorState = lightLevel > doorOpenThreshold;

  /*
  // For the temperature and humidity sensor and OLED display
  readSensor();
  updateDisplay();
  checkAlert();

  delay(250);
  */

  if (newDoorState != doorIsOpen) {

    doorIsOpen = newDoorState;

    if (doorIsOpen) {

      doorOpenedTime = currentTime;
      alarmIsActive = false;

      Serial.println("Door opened.");

    } else {

      alarmIsActive = false;
      ledIsOn = false;

      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);

      Serial.println("Door closed.");
    }
  }


  if (doorIsOpen && !alarmIsActive) {

    if (currentTime - doorOpenedTime >= alarmDelay) {

      alarmIsActive = true;
      flashTimer = currentTime;
    }
  }


  if (alarmIsActive) {

    if (currentTime - flashTimer >= flashInterval) {

      flashTimer = currentTime;

      ledIsOn = !ledIsOn;

      digitalWrite(ledPin, ledIsOn);

      if (ledIsOn) {
        tone(buzzerPin, 1000);
      } else {
        noTone(buzzerPin);
      }
    }
  }

  if (currentTime - serialTimer >= serialInterval) {

    serialTimer = currentTime;

    Serial.print("light:");
    Serial.print(lightLevel);

    Serial.print("\tthreshold:");
    Serial.print(doorOpenThreshold);

    Serial.print("\tdoor:");
    Serial.print(doorIsOpen);

    Serial.print("\talarm:");
    Serial.println(alarmIsActive);
  }
}
