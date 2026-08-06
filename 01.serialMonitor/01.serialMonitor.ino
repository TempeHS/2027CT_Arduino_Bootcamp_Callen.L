/*
  Author: Callen Lin

  Learning Intention:
  The students will understand the difference between the inbuilt setup and loop methods,
  and use the Serial Monitor as a debugging window into a running program.

  Success Criteria:
    1.  I understand the different behaviours of the setup and loop methods
    2.  I can print information to the serial monitor
    3.  I can print information to a new line of the serial monitor
    4.  I understand the impact of having more than one setup or loop method in my sketch
    5.  I understand single-line and multi-line comments
    6.  I can recognise a missing-semicolon compiler error

  The Rules of Every Sketch:
    1. The .ino file name must match its folder name
    2. Exactly ONE setup() { } function
    3. Exactly ONE loop() { } function
    4. Every function needs BOTH braces
    5. Every statement ends with a semicolon ;

  Hardware:
    None needed. Just your Arduino, the USB cable and the Serial Monitor at 115200 baud.

  Documentation:
    https://www.arduino.cc/reference/en/language/functions/communication/serial/
    https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-plotter
*/

/*
  The goal of this project is:

  RUNNING THE SKETCH:
  1. Understand that void setup() runs only at the start of the program
  2. Understand that void loop() runs repeatedly after setup() has finished

  STARTING THE SKETCH:
  3. Understand that Serial.begin(115200) starts the serial communication at 115200 baud

  PRINTING TO THE SERIAL MONITOR:
  4. Understand that Serial.print() prints to the serial monitor without a new line
  5. Understand that Serial.println() prints to the serial monitor with a new line

  PAUSING THE SKETCH:
  6. Understand that delay(1000) pauses the program for 1000 milliseconds

  MAKING COMMENTS IN THE CODE:
  7. Understand that comments are ignored by the compiler and are for humans to read
  8. Understand that single-line comments start with // and multi-line comments start with /*
*/

// The setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);                  // Start talking to the computer at 115200 baud
  Serial.println("Arduino ready!");    // When does this line print? During the start.
}

void loop() {
  // SOMEBODY SAID THAT HE LIKES ORANGES 🍊🍊🍊 (this is a single line note)

  /*
    I was bored so i put this extra large comment.
    This is one another lonely comment that is here to make the code look more interesting.

    // I put a comment inside of a comment LOL :D
    (this is a multi-line comment)
  */

  delay(1000);  // Wait 1 second each cycle
  Serial.println("Ready to run and get cooking potatoes :D");
  Serial.print("I am printing a value beside here: ");
  Serial.println("42");  // Print the value of 42 to the serial monitor
  Serial.println("Hmm \n Bonus");
  Serial.println();  // Print a blank line to the serial monitor
}

