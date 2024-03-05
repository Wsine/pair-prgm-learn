/* 
 * Arduino 101: timer and interrupts
 * 2: Timer1 overflow interrupt example 
 * more infos: http://www.letmakerobots.com/node/28278
 * created by RobotFreak 
 * Note: 
 * Configuration for Arduino Mega:
 * Pins 4 and 13: controlled by Timer0
 * Pins 11 and 12: controlled by Timer1
 * Pins 9 and10: controlled by Timer2
 * Pin 2, 3 and 5: controlled by timer 3
 */

#define Freq 5   
// 1: pin5: 1MHz,   pin3: 1MHz
// 2: pin5: 500kHz, pin3: 500kHz 
// 3: pin5: 100kHz, pin3: 100kHz 
// 4: pin5: 3MHz,   pin3: 3MHz 
// 5: pin5: 1MHz,   pin3: 100kHz
// 6: pin5: 1MHz,   pin3: 62kHz 

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(4, OUTPUT);

// Config timer0 for pin 4
  TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(WGM02) | _BV(CS00);

// Config timer2 for pin 9
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20); 
  TCCR2B = _BV(WGM22) | _BV(CS20);
  
  switch (Freq) 
  {
  
  // 1: pin4: 1MHz,   pin9: 1MHz
  case 1:  
    // Config timer0 frequency for pin 4
    OCR0A = 15;
    OCR0B = 7;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 15;
    OCR2B = 7;
    TCNT2 = 0;
    break;
  
  // 2: pin5: 500kHz, pin9: 500kHz 
  case 2:
    // Config timer0 frequency for pin 4
    OCR0A = 31;
    OCR0B = 15;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 31;
    OCR2B = 15;
    TCNT2 = 0;
    break;

  // 3: pin5: 100kHz, pin9: 100kHz 
  case 3:
    // Config timer0 frequency for pin 4
    OCR0A = 159;
    OCR0B = 79;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 159;
    OCR2B = 79;
    TCNT2 = 0;
    break;

  // 4: pin4: 3MHz,   pin9: 3MHz 
  case 4:
    // Config timer0 frequency for pin 4 
    OCR0A = 3;
    OCR0B = 1;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 3;
    OCR2B = 1;
    TCNT2 = 0;
    break;
  
  // 5: pin4: 1MHz,   pin9: 100kHz
  case 5:
    // Config timer0 frequency for pin 4 
    OCR0A = 15;
    OCR0B = 7;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 159;
    OCR2B = 79;
    TCNT2 = 0;
  break;

  // 6: pin4: 1MHz,   pin9: 62kHz 
    case 6:
    // Config timer0 frequency for pin 4 
    OCR0A = 15;
    OCR0B = 7;
    TCNT0 = 0;
    // Config timer2 frequency for pin 9 
    OCR2A = 255;
    OCR2B = 127;
    TCNT2 = 0;
  break;
  } 
}


void loop()
{
}
