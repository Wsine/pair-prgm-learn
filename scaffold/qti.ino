// Includes a constant integer named 'qtiPin' and assigns it the value of 2.
const int qtiPin = 2;

// Declares the 'setup()' function, to be executed once.
void setup() {
  // Initializes the Serial communication at a baud rate of 9600.
  // Hint: Use the Serial.begin() function with 9600 as its argument.
}

// Declares the 'loop()' function, which is executed repeatedly.
void loop() {

  // Configures 'qtiPin' as an OUTPUT.
  // Hint: Use the pinMode() function with qtiPin and OUTPUT as its arguments.

  // Sets 'qtiPin' to HIGH to charge the capacitor.
  // Hint: Use the digitalWrite() function with qtiPin and HIGH as its arguments.

  // Pauses the program for 230 microseconds.
  // Hint: Use the delayMicroseconds() function with 230 as its argument.

  // Configures 'qtiPin' as an INPUT.
  // Hint: Use the pinMode() function with qtiPin and INPUT as its arguments.

  // Sets 'qtiPin' to LOW to prepare for voltage reading.
  // Hint: Use the digitalWrite() function with qtiPin and LOW as its arguments.

  // Pauses the program for 230 microseconds.
  // Hint: Use the delayMicroseconds() function with 230 as its argument.

  // Reads the 'qtiPin' and determines if it's HIGH or LOW.
  // Hint: Use the digitalRead() function with qtiPin as its argument, and store the result in a variable.

  // Checks if the value read is HIGH.
  // If so, prints "black" to the Serial Monitor.
  // Else, prints "white" to the Serial Monitor.
  // Hint: Use an if statement along with the Serial.println() function.

  // Pauses the program for 100 milliseconds.
  // Hint: Use the delay() function with 100 as its argument.

}

