#ifdef __AVR_ATmega2560__
  const byte CLOCKOUT = 11;
#else
  const byte CLOCKOUT = 9;
#endif

// Define the setup function
void setup()
  {
  // Set the pinMode for CLOCKOUT as OUTPUT
  pinMode(CLOCKOUT, OUTPUT);

  // Configure Timer 1 settings
  TCCR1A = (1 << COM1A0); // Toggle OC1A on compare match
  TCCR1B = (1 << WGM12) | (1 << CS10); // CTC mode, no prescaler
  OCR1A = F_CPU / 8 / 2 - 1; // Set frequency for 8 Hz, duty cycle 50% (toggle CLOCKOUT at 4 Hz) with a 16 MHz clock
  }  // end of setup

// Define the loop function
void loop()
  {
  // Add any additional code, if necessary
  }  // end of loop
