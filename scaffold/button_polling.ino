// Declare two read-only integer constants 'grnLedPin' and 'buttonPin' and assign the appropriate pin numbers.
const int grnLedPin = 9;
const int buttonPin = 2;

// Declare three integer variables: 'ledToggle', 'lastButtonState', and 'buttonState'.
int ledToggle = LOW;
int lastButtonState = HIGH;
int buttonState;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Set the pinMode of the 'grnLedPin' as OUTPUT (digital output).
  // Hint: Use the pinMode() function with grnLedPin and OUTPUT as its arguments.

  // Set the pinMode of 'buttonPin' as INPUT_PULLUP to enable internal pull-up resistor.
  // Hint: Use the pinMode() function with buttonPin and INPUT_PULLUP as its arguments.
}

// Define the loop() function, which is called repeatedly during the program's execution.
void loop() {
  // Read the state of the 'buttonPin' and store it in the 'buttonState' variable.
  // Hint: Use the digitalRead() function with buttonPin as its argument.

  // Check whether the 'buttonState' is LOW and 'lastButtonState' is HIGH (i.e., button press occurred).
  // Hint: Use if statement with buttonState and lastButtonState as its conditions.

    // Toggle the 'ledToggle' state by negating its value ('!' operator).
    
    // Write the new state of 'ledToggle' to the 'grnLedPin'.
    // Hint: Use the digitalWrite() function with grnLedPin and ledToggle as its arguments.

  // Update the 'lastButtonState' with the current 'buttonState' value.
  
  // Wait for 100 milliseconds before executing the next command.
  // Hint: Use the delay() function with 100 as its argument.
}
