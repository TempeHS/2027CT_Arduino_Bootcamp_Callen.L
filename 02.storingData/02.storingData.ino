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
  The program below picks 2 random numbers and will continue rolling random numbers until both numbers matches.
  There is also a secret number of ten where hitting it gives a custom notification.

  I finally learnt the "// MARK - Example" alternative on VScode over Xcode lol.
*/

/*
  // MARK: Storing Data on Arduino
  There are different forms of data types in C++ such as int, long, float, bool, and String.
  They are used to store different types of information

  | Data Type              | What it stores  | Range                            | Size       | Notes                                   |
  | -----------------------|-----------------|----------------------------------|------------|-----------------------------------------|
  | bool (boolean)         | true or false   | true or false                    |  1 byte    | Use for if conditions                   |
  | int (integer)          | whole numbers   |  -32,768 to 32,767               |  2 bytes   | Use for non-decimal whole numbers       |
  | long (long integer)    | whole numbers   |  -2,147,483,648 to 2,147,483,647 |  4 bytes   | Use for large non-decimal whole numbers |
  | float (floating point) | decimal numbers |  6 digits of precision           |  4 bytes   | Use for decimal numbers                 |
  | String (text)          | text            |  Depends                         |  N/A       | Use for storing text                    |
  NOTE: To indicate ON on bool "true / HIGH / 1" is the same, and OFF is "false / LOW / 0". No difference.

  Unsigned Values
  | Data Type                             | What it stores  | Range              | Size     | Notes                                   |
  | --------------------------------------|-----------------|--------------------|----------|-----------------------------------------|
  | Unsigned int (unsigned integer)       | whole numbers   | 0 to 65,535        | 2 bytes  | Large numbers :O.                       |
  | Unsigned long (unsigned long integer) | whole numbers   | 0 to 4,294,967,295 | 4 bytes  | Amazing for timers                      |
  Note: They allow you to use A LOT larger numbers but the only con is that you can't use negative numbers.

  The different size of different is very important as a Arduino UNO only has so much RAM.
  Geeked out: has 2,048 bytes of RAM available for storing variables and data.

  That means if you use long 512x, you run of RAM, but then if they can be int, you can use them twice more!

  To use it you simply declare in:
  [DATA TYPE] [VARIABLE NAME] = [INITIAL VALUE];

  That's it!
*/

/*
  // MARK: Global and Local Scope
  A cool thing about Arduino is it has a thing called variable scopes. A variable can be either:

  1. A global scope: The variable is accessible from anywhere in the code.
  2. A local scope: The variable is only accessible within the function it is declared in.

  A global scope is used when we want to store the data for the entire duration of the program.
  A local scope is used when we want to store the data temporarily.
*/

String text = "hello world 123!";
int number = 21;
float decimal = 3.14159;
long largeNumber = 314159256;
bool veryImportantThing = true; // shhh.. you probably don't want to know why its true.

int numberAchievementTen = 10;
int numberCounter = 0;

long firstRandomNumber = random(100);
long secondRandomNumber = random(100);

void setup() {

  Serial.begin(115200);
  randomSeed(analogRead(A0));

  Serial.println();
  Serial.println("========================================");
  Serial.println("Beginning Program...");
  Serial.println("Welcome to the Random Number Game where you have to wait till the two random numbers match.");
  delay(5000);

  Serial.println();
  Serial.println("Generating Your Random Numbers...");
  Serial.println();
  delay(2000);

  Serial.println("Your First Random Number Is: " + String(firstRandomNumber));
  delay(2000);

  Serial.println("Your Second Random Number Is: " + String(secondRandomNumber));
  delay(2000);

  Serial.println("========================================");

  delay(1500);

  numberCounter++;

}

void loop() {

  numberCounter++;

  Serial.println();
  Serial.println("Do they match?");
  delay(1000);

  if (firstRandomNumber == secondRandomNumber) {
    Serial.println("Congratulations! You won.");
    while (true) {}
  } else {
    Serial.println("No.");
    Serial.println();
  }

  delay(1000);

  firstRandomNumber = random(100);
  secondRandomNumber = random(100);

  Serial.println("Attempt " + String(numberCounter) + ": Rerolling the random numbers...");

  delay(2000);

  Serial.println(
    "Your First Random Number Is: " + String(firstRandomNumber) + "\n" +
    "Your Second Random Number Is: " + String(secondRandomNumber)
  );

  delay(1500);

  if (firstRandomNumber == numberAchievementTen || secondRandomNumber == numberAchievementTen) {
    Serial.println("You hit the secret number " + String(numberAchievementTen) + "!");
  }

}

/*
  The sketch above is a refined version of the original.

  Containing a few white spaces for readability purposes and better structure :P
  I personally use camelCase over snake_case since I code quite frequently in Swift.
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
