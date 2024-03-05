const int grnLedPin = 9;
const int buttonPin = 2;

volatile int ledToggle = LOW;
volatile int lastButtonState = HIGH;
volatile int buttonState;

void setup() {
  // put your setup code here, to run once:
  pinMode(grnLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), button_ISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void button_ISR()
{
  buttonState = digitalRead(buttonPin);
  // The variables are reset back to it's initial state once released. Hence, we use this condition.
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledToggle = !ledToggle;
    digitalWrite(grnLedPin, ledToggle);
  }
  lastButtonState = buttonState;

}
