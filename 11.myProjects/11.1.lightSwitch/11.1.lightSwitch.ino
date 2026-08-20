/*
  Author:
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Student Notes:
  1. Make sure you include a copy of your schematic
  2. Students should use either the button or potentiometer in an unconventional way

  3. Suggested Grove ports: Button D4, Potentiometer A0, LED D6, Light sensor A3
*/

const int LIGHT_PIN = A3;
const int BUZZER_PIN = 5;
const int LED_PIN = 6;

unsigned long startTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int lightValue = analogRead(LIGHT_PIN);

  Serial.println(lightValue);

  if (lightValue > 1) {

    if (startTime == 0) {
      startTime = millis();
    }

    if (millis() - startTime > 10000) {
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1000);
    }

  }
  else {
    startTime = 0;
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
}
