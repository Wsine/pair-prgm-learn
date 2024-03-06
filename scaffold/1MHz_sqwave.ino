#ifdef __AVR_ATmega2560__
  const byte CLOCKOUT = 11;
#else
  const byte CLOCKOUT = 9;
#endif

// Define the setup function
void setup()
  {
  // Set the pinMode for CLOCKOUT as OUTPUT
  // Hint: Use the pinMode() function with CLOCKOUT and OUTPUT as its arguments
  
  // Configure Timer 1 settings
  // Hint: Assign appropriate bitwise operations for TCCR1A, TCCR1B, and OCR1A variables
  
  }  // end of setup

// Define the loop function
void loop()
  {
  // Add any additional code, if necessary
  }  // end of loop
