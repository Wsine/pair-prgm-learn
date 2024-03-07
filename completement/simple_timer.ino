/*
Simple program that triggers an interrupt every 1 second.
*/

void setup() {
  Serial.begin(115200);
  
  // Disable global interrupts
  cli();

  // Reset Timer 1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  // Set the compare match register
  OCR1A = 15624;

  // Turn on CTC (Clear Timer on Compare) mode
  TCCR1B |= (1 << WGM12);

  // Set prescaler to 1024 for Timer 1
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // Enable timer compare interrupt for Timer 1
  TIMSK1 |= (1 << OCIE1A);

  // Enable interrupts
  sei();
}

// Function to be called when Timer 1 interrupts
ISR(TIMER1_COMPA_vect) {
  // Print "Here" in Serial Monitor when Timer 1 hits the compare match value
  Serial.println("Here");
}

void loop() {
  // Nothing needed here for this specific program
}

