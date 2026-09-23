/*
  Author: Callen Lin

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

/*
  A completely unnecessary but necessary Arduino experiment where:

  1. Turning a knob makes the LED dim (which is oddly contradictory),
  2. The buzzer scream at increasingly higher pitches as your turn it up HIGHER!, and
  3. The Serial Monitor undergo a full-blown existential crisis about basic mathematics and how you set the potentiometer.

  INSERT A AMAZING PHOTO OF THE PROJECT SOMEWHERE!
*/

/*
  # MARK: RESULTS TABLE!
  Sensor          Min seen   Max seen   How I tested
  Potentiometer   0          1023       full turn each way
  Light sensor    20         758        covered with garment / put under LED lighting
  Sound sensor    20         834        quiet room / whistling
*/

const int POT_PIN = A0;    // Grove Potentiometer on A0
const int LED_PIN = 6;     // Grove LED on D6 (PWM)
const int BUZZER_PIN = 5;  // Grove Buzzer on D5 (PWM)
const int SOUND_PIN = A2;  // Grove Sound sensor on A2

// Why does these two lines need to exist. To be honest, I'm not sure 🤷‍♂️.
const int LIGHT_PIN = A3;  // Grove Light sensor on A3
// Well I just gave it a purpose

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("========================================");
  Serial.println("WHEN CHAOS MEETS POTENTIOMETER: INTERROGATION TIME!!!!!!!");
  Serial.println("========================================");
  Serial.println("Beginning investigation...");
  delay(1000);
  Serial.println("Please provide a number. But you can't");
  delay(1000);
  Serial.println("The potentiometer has been notified.");
  delay(1000);

  Serial.println("Before we do so, let's do some math.");
  delay(1000);
  Serial.println("7 / 2");
  delay(100);

  Serial.println(7 / 2);                 // prediction: 3
  delay(100);
  Serial.println("7.0 / 2");
  delay(100);

  Serial.println(7.0 / 2);               // prediction: 3.5
  delay(100);
  Serial.println("2 + 3 * 4");
  delay(100);

  Serial.println(2 + 3 * 4);             // prediction: 14
  delay(100);
  Serial.println("(2 + 3) * 4");
  delay(100);

  Serial.println((2 + 3) * 4);           // prediction: 20
  delay(100);
  Serial.println("7 % 3");
  delay(100);

  Serial.println(7 % 3);                 // prediction: 1
  delay(100);

  Serial.println("Why was it done?");
  delay(500);

  Serial.println("Cause its absolutely necessary.");
  delay(500);

  Serial.println("========================================");
  delay(2000);
}


void loop() {
  int value = analogRead(POT_PIN);

  Serial.println();
  Serial.println("OMG! NEW POTENTIOMETER VALUE DETECTED.");
  Serial.print("The number is: ");
  Serial.println(value);

  if (value == 0) {
    Serial.println("You have somehow chosen NOTHING.");
  }

  else if (value < 256) {
    Serial.println("The potentiometer is feeling rather low.");
  }

  else if (value < 512) {
    Serial.println("We are approaching the middle.");
  }

  else if (value < 768) {
    Serial.println("We have exceeded the middle.");
  }

  else if (value < 1023) {
    Serial.println("This is getting suspiciously high.");
  }

  else {
    Serial.println("MAXIMUM POTENTIOMETER POWER ACHIEVED.");
    Serial.println("There is nowhere left to go.");
  }

  // LEDs must go dimmer as the POT_PIN gets higher. Why is it contradictory. Cause its necessary.
  int ledBrightness = map(value, 0, 1023, 255, 0);
  analogWrite(LED_PIN, ledBrightness);

  // Of course we need to put a buzzerPitch cause it is ALSO necessary.
  int buzzerPitch = map(value, 0, 1023, 100, 2000);
  tone(BUZZER_PIN, buzzerPitch);

  Serial.println("");

  delay(2000);
}
