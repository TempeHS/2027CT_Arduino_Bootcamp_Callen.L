/*
  Author: Callen Lin
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Student Notes:
  1. Make sure you include a copy of your schematic
  2. Students should use either the button or potentiometer in an unconventional way

  3. Suggested Grove ports: Button D4, Potentiometer A0, LED D6, Light sensor A3
*/

const int POT_PIN = A0; // pot (yes pot, not pot., that is the wrong pot)
const int LED_PIN = 6;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(POT_PIN);

  if (potValue < 481) { // where'd i get the number? i threw blindly typed three number and then had to delete a ridiculous a that sneaked in.
    analogWrite(LED_PIN, 0);
    Serial.println("Light: OFF");
  }

  else if (potValue < 783) { // where did this number come from. used a pen and chose randomly.
    analogWrite(LED_PIN, 100);
    Serial.println("Light: Pretty DIM");
  }

  else {
    analogWrite(LED_PIN, 255);
    Serial.println("Light: FULL");
  }

  delay(50);
}
