const int grnLedPin = 9;
const int buttonPin = 2;

int ledToggle = LOW;
int lastButtonState = HIGH;
int buttonState;

void setup() {
  // put your setup code here, to run once:
  pinMode(grnLedPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  //Serial.begin(115200);
}

// use a counter to keep track of how many times the button has been pressed
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledToggle = !ledToggle;
    digitalWrite(grnLedPin, ledToggle);
    
  }
  lastButtonState = buttonState;
  delay(100);
  //Serial.println(lastButtonState);
}
