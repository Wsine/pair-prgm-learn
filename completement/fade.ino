const int redPin = 13;
int brightness = 0;
int stepAmount = 5;

void setup() {
  pinMode(redPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  analogWrite(redPin, brightness);
  brightness += stepAmount;

  if (brightness == 0 || brightness == 255) {
    stepAmount *= -1;
  }

  Serial.println(brightness);
  delay(100);
}
