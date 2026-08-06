/*
  Author:

  Learning Intention:
  The students will read analogue sensors, use math (map, constrain, integer division)
  to convert value ranges, and write analogue output using PWM to an LED and buzzer.

  Success Criteria:
    1.  I know how to read analogue data from a specific PIN (analogRead)
    2.  I know the range of analogue data (0 to 1023) and can record a sensor's real range
    3.  I understand integer vs float division and order of operations
    4.  I can map an analogue value (0-1023) to a PWM value (0-255) with map() and constrain()
    5.  I understand what pulse width modulation is and can identify the PWM PINs (~)
    6.  I can write PWM data with analogWrite to control LED brightness
    7.  I can control the buzzer's pitch with tone()
    8.  I can organise output data so it correctly plots on the Serial Plotter
    9.  I can apply this knowledge to the Light, Sound and Potentiometer modules

  Hardware (Grove cables to the base shield):
    Potentiometer  -> A0
    Sound sensor   -> A2
    Light sensor   -> A3
    LED module     -> D6  (PWM capable)
    Buzzer module  -> D5  (PWM capable)

  Optional breadboard reference:
    Bootcamp-analogueRead.png, Bootcamp-PWMOutput.png and Bootcamp-MAP-PotLED.png
    in this folder show the same circuits hand-wired without Grove modules.
    Pulse-Width-Modulation.jpg explains the duty cycle.

  Documentation:
    https://sensorkit.arduino.cc/
    https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
    https://www.arduino.cc/reference/en/language/functions/math/map/
    https://en.cppreference.com/w/cpp/language/operator_precedence
*/

const int POT_PIN = A0;    // Grove Potentiometer on A0
const int SOUND_PIN = A2;  // Grove Sound sensor on A2
const int LIGHT_PIN = A3;  // Grove Light sensor on A3
const int LED_PIN = 6;     // Grove LED on D6 (PWM)
const int BUZZER_PIN = 5;  // Grove Buzzer on D5 (PWM)

void setup() {
  Serial.begin(115200);                  // Start talking to the computer at 115200 baud
  pinMode(LED_PIN, OUTPUT); // add
  Serial.println("Arduino ready!");      // When does this line print?
  Serial.println(7 / 2);                 // prediction: ?
  Serial.println(7.0 / 2);               // prediction: ?
  Serial.println(2 + 3 * 4);             // prediction: ?
  Serial.println((2 + 3) * 4);           // prediction: ?
  Serial.println(7 % 3);                 // prediction:
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // 5 volts on the pin: LED on
  delay(1000);
  digitalWrite(LED_PIN, LOW);   // 0 volts: LED off
  delay(1000);
  analogWrite(LED_PIN, 0);
  delay(1000);
  analogWrite(LED_PIN, 64);    // 25 percent duty
  delay(1000);
  analogWrite(LED_PIN, 127);   // 50 percent duty
  delay(1000);
  analogWrite(LED_PIN, 255);   // always on
  delay(1000);
  tone(BUZZER_PIN, 262);   // middle C
  delay(250);
  tone(BUZZER_PIN, 523);   // C an octave up
  delay(250);
  noTone(BUZZER_PIN);      // silence
  delay(100000000000000000000000000);
}
