// Declare a read-only integer constant named 'redPin' and assign the appropriate pin number for the red LED.
const int redPin = 13;

// Declare an integer variable named 'brightness' and initialize it with 0 (initial brightness of the LED)
int brightness = 0;

// Declare an integer variable named 'stepAmount' and initialize it with 5 (increment value of brightness)  
int stepAmount = 5;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Set the pinMode of the 'redPin' as OUTPUT (digital output).
  // Hint: Use the pinMode() function with redPin and OUTPUT as its arguments.

  // Initialize serial communication at 115200 baud rate:
  // Hint: Use the Serial.begin() function with 115200 as its argument.
}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Write the value of 'brightness' variable to the 'redPin'
  // Hint: Use the analogWrite() function with redPin and brightness as its arguments.

  // Increase value of 'brightness' by 'stepAmount'
  // Hint: Use '+' operator.

  // Check if 'brightness' is equal to 0 or 255
  // Hint: Use an if statement with '==' and '||' operators.
  // If the condition is true, change the sign of 'stepAmount'
  // Hint: Use the '*=' operator with -1 as an argument.

  // Print the value of 'brightness' to Serial Monitor
  // Hint: Use the Serial.println() function with 'brightness' as its argument.

  // Wait for 100 milliseconds before executing the next command
  // Hint: Use the delay() function with 100 as its argument.
}
