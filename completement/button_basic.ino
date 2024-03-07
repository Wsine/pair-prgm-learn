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
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Start the Serial communication with a baud rate of 115200.
  Serial.begin(115200);
}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Read the state of the button and store it in 'buttonState'.
  buttonState = digitalRead(buttonPin);

  // Print the 'buttonState' to the serial monitor.
  Serial.println(buttonState);

  // Wait for 100 milliseconds before executing the next command.
  delay(100);
}
