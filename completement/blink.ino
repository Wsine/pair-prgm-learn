/*
Simple program that blinks an LED.
*/

// Declare a read-only integer constant named 'ledPin' and assign the appropriate pin number for the LED.
const int ledPin = 13;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Set the pinMode of the 'ledPin' as OUTPUT (digital output).
  pinMode(ledPin, OUTPUT);
}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Turn the LED on by setting a HIGH voltage to the 'ledPin'.
  digitalWrite(ledPin, HIGH);

  // Wait for 1000 milliseconds (1 second) before executing the next command.
  delay(1000);

  // Turn the LED off by setting a LOW voltage to the 'ledPin'.
  digitalWrite(ledPin, LOW);

  // Wait for 1000 milliseconds (1 second) before executing the next command.
  delay(1000);
}
