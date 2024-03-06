/*
Simple program that triggers an interrupt at 1Hz using Timer 1 and the Compare Match Register.
*/

// Declare and assign the compare match register value for our desired interrupt rate (1Hz) and a prescaler of 1024
const unsigned int compareMatchReg = 15624;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Initialize the Serial communication with a baud rate of 115200
  // Hint: Use the Serial.begin() function with 115200 as its argument.

  // Disable global interrupts
  // Hint: Use the cli() function.

  // Reset Timer 1's control registers and counter
  // Hint: Set TCCR1A, TCCR1B and TCNT1 to 0.

  // Set the compare match register (OCR1A) to the desired value
  // Hint: Assign the value of compareMatchReg to OCR1A.

  // Enable Clear Timer on Compare match (CTC) mode for Timer 1
  // Hint: Set the WGM12 bit in the TCCR1B register using the |= operator and the << operator.

  // Set the prescaler to 1024
  // Hint: Set the CS12 and CS10 bits in the TCCR1B register using the |= operator and the << operator.

  // Enable the timer compare interrupt
  // Hint: Set the OCIE1A bit in the TIMSK1 register using the |= operator and the << operator.

  // Enable global interrupts
  // Hint: Use the sei() function.
}

// Define the interrupt service routine for the Timer 1 Compare A interrupt
// Hint: Use the ISR macro with TIMER1_COMPA_vect as its argument.
void TIMER1_COMPA_ISR() {
  // Print a message to the serial monitor
  // Hint: Use the Serial.println() function with the string "Here" as its argument.

}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // No loop code necessary for this example.
}
