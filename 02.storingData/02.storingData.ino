/*
  Author: Callen Lin

  Learning Intention:
  The students will learn the different data types used in the C++ language,
  watch an integer overflow live, and understand variable scope.

  Success Criteria:
    1.  I understand and can store variables in the datatypes String, int, float, long and bool
    2.  I know how to access more information about the different datatypes in the documentation
    3.  I understand how (1, HIGH and true) and (0, LOW and false) all represent the same concept
    4.  I can convert an int, float and bool to a String and print it to the serial monitor
    5.  I understand the difference between an int and an unsigned int, and a long and an unsigned long
    6.  I understand the difference between a global variable and a function (local) variable

  Hardware:
    None needed. Serial Monitor at 115200 baud.

  Documentation:
    https://www.arduino.cc/reference/en/#variables
    https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/
*/

/*
  Goals of the lesson:
  1. Learn the different types of Type Systems in C++ and how to use them

  | Variable Type    | What it stores  | Range                            | Size      |
  | -----------------|-----------------|----------------------------------|-----------|
  | 1. int           | whole numbers   |  -32,768 to 32,767               |  2 bytes  |
  | 2. unsigned int  | whole numbers   |  0 to 65,535                     |  2 bytes  |
  | 3. long          | whole numbers   |  -2,147,483,648 to 2,147,483,647 |  4 bytes  |
  | 4. unsigned long | whole numbers   |  0 to 4,294,967,295              |  4 bytes  |
  | 5. float         | decimal numbers |  7 digits of precision           |  4 bytes  |
  | 6. bool          | true or false   |  1 or 0                          |  1 byte   |
  | 7. String        | text            |  limited by memory               |  Varies   |

  2. Bool specifics
  Meaning On:     true, HIGH, 1
  Meaning False:  false, LOW, 0

  3. Global and local scopes
  Global scopes are variables that are declared outside of any function and can be used anywhere!
  Local scopes are variables that are declared inside a function and can only be used inside that function.

  4. Integer overflow
  When a variable is incremented past its maximum value, it will "wrap around" to the minimum value.
  For example, if an int variable is incremented past 32,767, it will wrap around to -32,768. This is called integer overflow.
*/

  int counter = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("Starting counter demo");
  counter = 100;
}

void loop() {
  counter = counter + 1;         // loop() can use it too
  Serial.println(counter);
  delay(500);
}
