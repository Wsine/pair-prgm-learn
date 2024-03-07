/*
Arduino program that uses an interrupt to toggle an LED on and off when a button is pressed.
*/

const int grnLedPin = 9;
const int buttonPin = 2;

volatile int ledToggle = LOW;
volatile int lastButtonState = HIGH;
volatile int buttonState;

void setup() {
  pinMode(grnLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), button_ISR, CHANGE);
}

void loop() {
  // Nothing to do in the loop() since LED control is done using an interrupt
}

void button_ISR() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    ledToggle = !ledToggle;
    digitalWrite(grnLedPin, ledToggle);
  }

  lastButtonState = buttonState;
}
