/*
Simple program that reads the state of a button and prints it to the serial monitor.
*/

// Declare a read-only integer constant named 'buttonPin' and assign the appropriate pin number for the button.
const int buttonPin = 2;

// Declare an integer variable to store the 'buttonState'.
int buttonState;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Set the pinMode of the 'buttonPin' as INPUT_PULLUP (internal pull-up resistor).
  // Hint: Use the pinMode() function with buttonPin and INPUT_PULLUP as its arguments.

  // Start the Serial communication with a baud rate of 115200.
  // Hint: Use the Serial.begin() function with 115200 as its argument.
  
}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Read the state of the button and store it in 'buttonState'.
  // Hint: Use the digitalRead() function with buttonPin as its argument.

  // Print the 'buttonState' to the serial monitor.
  // Hint: Use the Serial.println() function with buttonState as its argument.

  // Wait for 100 milliseconds before executing the next command.
  // Hint: Use the delay() function with 100 as its argument.

}
