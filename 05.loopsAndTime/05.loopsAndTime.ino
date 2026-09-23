/*
  Author: Callen Lin

  Learning Intention:
  The students will apply loop logic (count, pre-test and post-test loops) and manage
  time responsively with millis() instead of blocking with delay().

  Success Criteria:
    1.  I understand loop logic is repeating (or not) based on a true or false answer
    2.  I can apply comparison operators in count (for) and pre-test (while) loops
    3.  I understand a post-test (do while) loop runs its body at least once
    4.  I can iterate over an array with a for-each loop
    5.  I can detect and fix an infinite loop
    6.  I understand why delay() is blocking and not preferred for time event management
    7.  I can use millis() and binary logic to trigger events by time
    8.  I can seed and generate a random number
    9.  I understand micros() exists for microsecond timing
    10. I can read a simple logic flowchart

  Hardware (Grove cables to the base shield):
    Button module  -> D4
    LED module     -> D6
    Buzzer module  -> D5

  Student Notes:
    See the four loop flowcharts in this folder's Readme.md.

  Optional breadboard reference:
    Bootcamp-workingWithTime.png in this folder.

  Documentation:
    https://www.arduino.cc/reference/en/#structure
    https://www.arduino.cc/reference/en/language/functions/time/millis/
    https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
*/

/*
  # MARK: loops and time (read below obv.)

  for loops repeats from a X amount of time
  while loops keep checking condition every time
  do while loops always run once before remembering there was a condition
  for-each loop can iterate every single item in an array.

  micros() is similar to millis() but measures time in microseconds.
  but (<- pun intended), im not exactly sure when you'd use it if its unless your being super precise:
  0.000001 second = 1 microsecond

  delay() blocks Arduino from doing other work while it goes for a nap.
  millis() allow the elapsed time to be checked without being a brick wall
*/

// Blinking LED variables for millis()
unsigned long previousBlink = 0;
const long INTERVAL = 1000;
int ledState = LOW;

const int BUTTON_PIN = 4;  // Grove Button on D4
const int BUZZER_PIN = 5;  // Grove Buzzer on D5
const int LED_PIN = 6;     // Grove LED on D6

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  randomSeed(analogRead(A3)); // cool trick you taught me to throw a random one here.

  Serial.println("Reaction Time Game!");
  Serial.println("Get ready...");
}

void loop() {
  digitalWrite(LED_PIN, LOW);

  Serial.println("Wait for the LED...");

  delay(random(2000, 5000));

  digitalWrite(LED_PIN, HIGH);
  unsigned long startTime = millis();

  while (digitalRead(BUTTON_PIN) == LOW) {
  }

  unsigned long reactionTime = millis() - startTime;

  digitalWrite(LED_PIN, LOW);

  Serial.println("Your reaction time is: ");
  Serial.print("Drum roll...");
  Serial.print(reactionTime);
  Serial.println(" ms");

  if (reactionTime < 250) {
    Serial.println("Amazing! Under 250 ms!");
    tone(BUZZER_PIN, 1000, 200);
    delay(250);
    tone(BUZZER_PIN, 1500, 200);
    delay(250);
    tone(BUZZER_PIN, 2000, 300);
  }

  delay(2000);

  Serial.println();
  Serial.println("Get ready for the next round...");

  /*
  // Archive of siren because it is pretty damn annoying.
  // Use with caution!

  for (int pitch = 200; pitch < 1000; pitch += 10) {
    tone(BUZZER_PIN, pitch);
    delay(10);
  }
  for (int pitch = 1000; pitch > 200; pitch -= 10) {
    tone(BUZZER_PIN, pitch);
    delay(10);
  }
  */

  /*
  // millis() blinking LED code, excluded from the main reaction time game.
  // Remove the comment block and comment the main reaction time game code to use this code ;P
  unsigned long now = millis();

  if (now - previousBlink >= INTERVAL) {
    previousBlink = now;
    ledState = !ledState;            // flip HIGH to LOW and back
    digitalWrite(LED_PIN, ledState);
  }

  if (digitalRead(BUTTON_PIN) == HIGH) {
    Serial.println("Button pressed!");
  }
  */

}
