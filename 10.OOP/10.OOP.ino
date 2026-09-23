/*
  Author: Callen Lin

  Learning Intention:
  The students will learn about the Object Oriented Paradigm and build their own
  classes and objects to manage hardware components.

  Success Criteria:
    1.  I understand what classes and objects are (blueprint vs instance)
    2.  I can create a class with private properties, public methods and a constructor
    3.  I understand the difference between public and private (encapsulation)
    4.  I can create multiple instances of my class to manage identical hardware

  Hardware (Grove cables to the base shield):
    LED module -> D6, plus the built-in LED on pin 13 as your second instance.
    Optional: Button module -> D4 or the ultrasonic sensor -> D2 for your own class.

  Documentation:
    https://www.youtube.com/watch?v=S_uaROFnWSg
    https://youtu.be/cUVryWbVkXk
*/

/*
  OOP in a Nutshell cause I won't remember while looking at the tabby cat in VS code pet :P

  Class = the blueprint for objects
    example:
      Class: Led

  Object = the thin made from that blueprint
    example:
      Led moduleLed(6);
      Led builtinLed(13);

  Properties: the data the object remembers
    example:
      pin = 6;
      isOn = false;

  Methods: things for the object to do
    example:
      turnOn();
      turnOff();
      toggle();

  Constructor: runs when the object is created
    example:
      Led(int ledPin);

  private: things that the object can not touch directly from outside the class
    example:
      int pin;
      bool isOn;

  public: things that the object can do from outside the class
    example:
      turnOn();
      turnOff();
      toggle();

  encapsulation: keep the internal state protected behind the interface
    example:
      Led moduleLed(6);
      moduleLed.turnOn();
      // can't access moduleLed.isOn directly because it's private
*/

class Led {
  private:
    int pin;          // properties: data each Led remembers
    bool isOn;

  public:
    Led(int ledPin) {  // constructor: runs when an object is created
      pin = ledPin;
      isOn = false;
    }

    void begin() {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    void turnOn() {    // methods: things every Led can do
      digitalWrite(pin, HIGH);
      isOn = true;
    }

    void turnOff() {
      digitalWrite(pin, LOW);
      isOn = false;
    }

    void toggle() {
      if (isOn) {
        turnOff();
      } else {
        turnOn();
      }
    }
};

Led moduleLed(6);    // the Grove LED module on D6
Led builtinLed(13);  // the LED soldered onto the Uno itself

void setup() {
  moduleLed.begin();
  builtinLed.begin();
  builtinLed.turnOn();   // start opposite to the module LED
}

void loop() {
  moduleLed.toggle();
  builtinLed.toggle();
  delay(500);
}
