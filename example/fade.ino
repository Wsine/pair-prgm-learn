const int redPin = 13;  // pin for red led

int brightness = 0; // initial brightness of led
int stepAmount = 5; // brightness step amount

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin, brightness);
  
  brightness = brightness + stepAmount;

  if (brightness == 0 || brightness == 255)
    stepAmount = -stepAmount;

  Serial.println(brightness);
  delay(100);
  
  
}
