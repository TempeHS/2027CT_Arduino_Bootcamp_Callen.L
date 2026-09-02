// Yep! I added more functions to this lol.

const int BUTTON_PIN = 4;
const int LED_PIN = 6;

unsigned long milisecondsTracker = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  milisecondsTracker = millis();

  if (buttonState == HIGH) {

    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button pressed: LED on");

    while (digitalRead(BUTTON_PIN) == HIGH) {
      // Stops the print until the button is released
      milisecondsTracker = 0;

     while (millis() - milisecondsTracker < 10000) {
        Serial.println("Why are you holding it for so long?? Good question.");
      }

    }

  } else {

    digitalWrite(LED_PIN, LOW);
    Serial.println("Button released: LED off");

    while (digitalRead(BUTTON_PIN) == LOW) {
      // Stops the print until the button is released

      while (millis() - milisecondsTracker < 10000) {
        Serial.println("Hmm... why don't you press the button?");
      }

      milisecondsTracker = 0;
    }

  }
}








/*
  Author:

  Learning Intention:
  The students will read a Grove Button module and control a Grove LED module,
  applying binary selection logic (if, if else, if else if else, switch/case).

  Success Criteria:
    1.  I can connect Grove modules to the base shield and know which port each uses
    2.  I know how to read binary data from a specific PIN (digitalRead)
    3.  I know how to write binary data to a specific PIN (digitalWrite)
    4.  I understand that LOW = false = 0 and HIGH = true = 1
    5.  I understand binary selection is asking questions with only true and false outcomes
    6.  I can apply comparison operators in if, if else, and if else if else structures
    7.  I understand a switch/case structure and the role of break
    8.  I understand the difference between a nested if and boolean operators
    9.  I can read a simple logic flowchart
    10. I can apply this knowledge to the Button and the Line Finder modules

  Hardware (Grove cables to the base shield):
    Button module  -> D4
    LED module     -> D6
    Line Finder    -> D7  (application task)

  Student Notes:
    Comparison Operators: != , < , <= , == , > , >=
    Boolean Operators: ! (not), && (and), || (or)
    The Grove Button reads HIGH while pressed. Inside the module a resistor
    holds the pin LOW when released. See the flowcharts in this folder's Readme.md.

  Optional breadboard reference (how this wiring works without Grove modules):
    Bootcamp-digitalWrite.png and Bootcamp-digitalRead.png in this folder.

  Documentation:
    https://sensorkit.arduino.cc/
    https://www.arduino.cc/reference/en/#structure
    https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
*/
/*
  Goals of the lesson:

  Learning C++ Syntax and Fundamentals:
  1. const (constant)
  This is a variable that can not be changed after it is declared.
  We use "digitalRead(BUTTON_PIN);" and all we need to update is const int "BUTTON_PIN = 7;" to change pins.

  2. Function Parameters
  Functions that require two different pieces of information. Its like when you are ordering coffee, you need to tell it size and milk.
  An example includes "pinMode(LED_PIN, OUTPUT);".

  3. Return Values
  Functions that return a value aka gives something back.
  "int buttonState = digitalRead(BUTTON_PIN);" is a example where Arduino reads the values like english and using digitalRead and to store it in a variable.

  4. Decision Making
  Using if, if else, and switch/case structures to make decisions based on conditions.
  if checks if the condition is true and if its false, it will go to the next step else if (same as elif in python) if applicable, and else is the catch it all if none is true before.

  5. Comparison Operators
  This shows the relationship between two values and returns a boolean value (true or false).
  | Operator | Full Name                | Meaning                                                             | Example               | Result                                    |
  | -------- | ------------------------ | ------------------------------------------------------------------- | --------------------- | ----------------------------------------- |
  | ==       | Equal to                 | Checks if two values are the same.                                  | `buttonState == HIGH` | `true` if `buttonState` is `HIGH`         |
  | !=       | Not equal to             | Checks if two values are different.                                 | `buttonState != HIGH` | `true` if `buttonState` is **not** `HIGH` |
  | <        | Less than                | Checks if the left value is smaller than the right.                 | `temperature < 20`    | `true` if `temperature` is below 20       |
  | <=       | Less than or equal to    | Checks if the left value is smaller than **or equal to** the right. | `temperature <= 20`   | `true` if `temperature` is 20 or less     |
  | >        | Greater than             | Checks if the left value is larger than the right.                  | `distance > 100`      | `true` if `distance` is above 100         |
  | >=       | Greater than or equal to | Checks if the left value is larger than **or equal to** the right.  | `battery >= 50`       | `true` if `battery` is 50 or higher       |

  6. The legendary Assign and Compare sign.
  | Operator | Meaning                                                          |
  | -------- | ---------------------------------------------------------------- |
  | ==       | Compares two values and returns a boolean value (true or false). |
  | =        | Assigns a value to a variable.                                   |

  This touches one of the most important things... Don't Repeat Yourself (DRY).
*/
/*
  Useful quick codes:

  int buttonState = digitalRead(BUTTON_PIN);
  That returns a HIGH or LOW value. You can then use that variable in an if statement to make decisions.

  if (buttonState == HIGH) {
    // do something if the button is pressed
  } else {
    // do something if the button is not pressed
  }
*/
