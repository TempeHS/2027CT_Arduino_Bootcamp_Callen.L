/*
  Author:
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Student Notes:
  1. Make sure you include a copy of your schematic
  2. Students should use either the button or potentiometer in an unconventional way

  3. Suggested Grove ports: Button D4, Potentiometer A0, LED D6, Light sensor A3
*/

const int POT_PIN = A0;
const int BUZZER_PIN = A2;  // Grove Sound sensor on A2
const int LED_PIN = 6;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);

  int LED_VALUE = map(potValue, 0, 1023, 0, 255);

  if (LED_VALUE == 128) {
    analogWrite(LED_PIN, 200);
    noTone(BUZZER_PIN);
    tone(BUZZER_PIN, 250);
  }
  else {
    analogWrite(LED_PIN, 0);
    tone(BUZZER_PIN, 1000);
  }

  delay(10);
}
