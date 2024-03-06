/*
Arduino program that uses an interrupt to toggle an LED on and off when a button is pressed.
*/

// Define a read-only constant named 'grnLedPin' and assign the pin number connected to the green LED
const int grnLedPin = 9;
// Define a read-only constant named 'buttonPin' and assign the pin number connected to the button
const int buttonPin = 2;

// Declare 'ledToggle', 'lastButtonState', and 'buttonState' as global volatile integers to use in the interrupt
volatile int ledToggle = LOW;
volatile int lastButtonState = HIGH;
volatile int buttonState;

// Define the setup() function, which is executed only once during power-up.
void setup() {
  // Set the pinMode of the 'grnLedPin' as OUTPUT (digital output)
  // Hint: Use pinMode() function with grnLedPin and OUTPUT as its arguments.
  
  // Set the pinMode of the 'buttonPin' as INPUT_PULLUP (digital input with built-in pullup resistor)
  // Hint: Use pinMode() function with buttonPin and INPUT_PULLUP as its arguments.

  // Set the interrupt that triggers when the 'buttonPin' changes its state (RISING, FALLING, or CHANGE)
  // Hint: Use attachInterrupt() function with digitalPinToInterrupt(buttonPin), button_ISR, and CHANGE as its arguments.
}

// Define the loop() function, which is called repeatedly during the program execution
void loop() {
  // Since the LED control is done using an interrupt, no code is needed in the loop()
}

// Define the 'button_ISR()' function for the interrupt service routine
void button_ISR() {
  // Read the state of the 'buttonPin' and store it in 'buttonState'
  // Hint: Use digitalRead() function with buttonPin as its argument.
  
  // Check if the buttonState is LOW (pressed) and the lastButtonState is HIGH (not pressed)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Toggle the ledToggle variable between LOW and HIGH
    ledToggle = !ledToggle;

    // Update the state of the 'grnLedPin' according to the value of 'ledToggle'
    // Hint: Use digitalWrite() function with grnLedPin and ledToggle as its arguments.
  }

  // Set the value of lastButtonState to the current value of buttonState
}
