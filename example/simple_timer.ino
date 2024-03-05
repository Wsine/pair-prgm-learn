// set timer1 interrupt at 1Hz using Compare Match Reg

//Note: Refer to Adruino Mega2560 spec sheet for timer interrupt register configs

// Set compareMatchReg to the correct value for our interrupt interval
// compareMatchReg = [16, 000, 000Hz / (prescaler * desired interrupt frequency)] - 1
  
/* E.g. 1Hz with 1024 Pre-Scaler:
  compareMatchReg = [16, 000, 000 / (prescaler * 1)] - 1
  compareMatchReg = [16, 000, 000 / (1024 * 1)] - 1 = 15624
  
   since 256 < 15,624 < 65,536, you must use timer1 for this interrupt.
   Note:65536 is the max value for timer 1. Hence, the value must be <65536.
*/
void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  
  cli();    // disable global interrupts

  // reset Timer 1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  /////////////////

  OCR1A = 15624;    // set the compare match register

  TCCR1B |= (1 << WGM12);  // turn on CTC mode
  
  /*
  Prescaler:
    (timer speed(Hz)) = (Arduino clock speed(16MHz)) / prescaler
      So 1Hz = 16000000 / 1 --> Prescaler: 1
      Prescaler can equal the below values and needs the relevant bits setting
      1    [CS10]
      8    [CS11]
      64   [CS11 + CS10]
      256  [CS12]
      1024 [CS12 + CS10]
  */
  TCCR1B |= (1 << CS12) | (1 << CS10);  // set to 1024 prescaler
  
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  
  sei();  // enable interrupts
}


// function to be called when Timer 1 interrupts
ISR(TIMER1_COMPA_vect) {
  Serial.println("Here");
}


void loop() {
  // put your main code here, to run repeatedly:
}
