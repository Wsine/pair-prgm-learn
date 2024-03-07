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
  pinMode(grnLedPin, OUTPUT);

  // Set the pinMode of 'buttonPin' as INPUT_PULLUP to enable internal pull-up resistor.
  pinMode(buttonPin, INPUT_PULLUP);
}

// Define the loop() function, which is called repeatedly during the program's execution.
void loop() {
  // Read the state of the 'buttonPin' and store it in the 'buttonState' variable.
  buttonState = digitalRead(buttonPin);

  // Check whether the 'buttonState' is LOW and 'lastButtonState' is HIGH (i.e., button press occurred).
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the 'ledToggle' state by negating its value ('!' operator).
    ledToggle = !ledToggle;

    // Write the new state of 'ledToggle' to the 'grnLedPin'.
    digitalWrite(grnLedPin, ledToggle);
  }

  // Update the 'lastButtonState' with the current 'buttonState' value.
  lastButtonState = buttonState;
  
  // Wait for 100 milliseconds before executing the next command.
  delay(100);
}
