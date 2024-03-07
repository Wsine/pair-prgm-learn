/*
Arduino 101: timer and interrupts (completed code)
*/

// Define the frequency option number
#define Freq 5

// Define the setup() function, which is used to set up initial configuration of timer0 and timer2
void setup()
{
  // Set pinMode for pins 9 and 4 as OUTPUT
  pinMode(9, OUTPUT);
  pinMode(4, OUTPUT);

  // Configure Timer0 for pin 4
  TCCR0A = _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
  TCCR0B = _BV(CS00);
  
  // Configure Timer2 for pin 9
  TCCR2A = _BV(COM2B1) | _BV(WGM20) | _BV(WGM21);
  TCCR2B = _BV(CS20);

  // Switch statement to configure frequencies based on the value of 'Freq' preprocessor constant
  switch (Freq)
  {
    case 1: // Set timer frequency for pins 4 and 9 as 1MHz each
      OCR0A = 1;
      OCR0B = 0;
      TCNT0 = 0;
      OCR2A = 1;
      OCR2B = 0;
      TCNT2 = 0;
      break;
      
    case 2: // Set timer frequency for pins 4 and 9 as 500kHz each
      OCR0A = 3;
      OCR0B = 1;
      TCNT0 = 0;
      OCR2A = 3;
      OCR2B = 1;
      TCNT2 = 0;
      break;

    case 3: // Set timer frequency for pins 4 and 9 as 100kHz each
      OCR0A = 19;
      OCR0B = 9;
      TCNT0 = 0;
      OCR2A = 19;
      OCR2B = 9;
      TCNT2 = 0;
      break;

    case 4: // Set timer frequency for pins 4 and 9 as 3MHz each
      OCR0A = 0;
      OCR0B = 0;
      TCNT0 = 0;
      OCR2A = 0;
      OCR2B = 0;
      TCNT2 = 0;
      break;

    case 5: // Set timer frequency for pin 4 as 1MHz and pin 9 as 100kHz
      OCR0A = 1;
      OCR0B = 0;
      TCNT0 = 0;
      OCR2A = 19;
      OCR2B = 9;
      TCNT2 = 0;
      break;

    case 6: // Set timer frequency for pin 4 as 1MHz and pin 9 as 62kHz
      OCR0A = 1;
      OCR0B = 0;
      TCNT0 = 0;
      OCR2A = 31;
      OCR2B = 15;
      TCNT2 = 0;
      break;
  }
}

// Define the loop() function, which remains empty in this example
void loop()
{
}
