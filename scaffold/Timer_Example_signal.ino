/*
Arduino 101: timer and interrupts (without code statements)
*/

// Define the frequency option number
#define Freq 5   

// Define the setup() function, which is used to set up initial configuration of timer0 and timer2
void setup()
{
  // Set pinMode for pins 9 and 4 as OUTPUT

  // Configure Timer0 for pin 4
  // Hint: Use TCCR0A and TCCR0B registers

  // Configure Timer2 for pin 9
  // Hint: Use TCCR2A and TCCR2B registers

  // Switch statement to configure frequencies based on the value of 'Freq' preprocessor constant

  // Case 1: Set timer frequency for pins 4 and 9 as 1MHz each
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for Timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2

  // Case 2: Set timer frequency for pins 4 and 9 as 500kHz each
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2
  
  // Case 3: Set timer frequency for pins 4 and 9 as 100kHz each
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for Timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2

  // Case 4: Set timer frequency for pins 4 and 9 as 3MHz each
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for Timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2

  // Case 5: Set timer frequency for pin 4 as 1MHz and pin 9 as 100kHz
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for Timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2

  // Case 6: Set timer frequency for pin 4 as 1MHz and pin 9 as 62kHz
  // Hint: Use OCR0A, OCR0B, TCNT0 registers for Timer0
  // Hint: Use OCR2A, OCR2B, TCNT2 registers for Timer2
}

// Define the loop() function, which remains empty in this example
void loop()
{
}
