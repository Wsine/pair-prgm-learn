// Includes a constant integer named 'qtiPin' and assigns it the value of 2.
const int qtiPin = 2;

// Declares the 'setup()' function, to be executed once.
void setup() {
  // Initializes the Serial communication at a baud rate of 9600.
  Serial.begin(9600);
}

// Declares the 'loop()' function, which is executed repeatedly.
void loop() {

  // Configures 'qtiPin' as an OUTPUT.
  pinMode(qtiPin, OUTPUT);

  // Sets 'qtiPin' to HIGH to charge the capacitor.
  digitalWrite(qtiPin, HIGH);

  // Pauses the program for 230 microseconds.
  delayMicroseconds(230);

  // Configures 'qtiPin' as an INPUT.
  pinMode(qtiPin, INPUT);

  // Sets 'qtiPin' to LOW to prepare for voltage reading.
  digitalWrite(qtiPin, LOW);

  // Pauses the program for 230 microseconds.
  delayMicroseconds(230);

  // Reads the 'qtiPin' and determines if it's HIGH or LOW.
  int qtiValue = digitalRead(qtiPin);

  // Checks if the value read is HIGH.
  // If so, prints "black" to the Serial Monitor.
  // Else, prints "white" to the Serial Monitor.
  if (qtiValue == HIGH) {
    Serial.println("black");
  } else {
    Serial.println("white");
  }

  // Pauses the program for 100 milliseconds.
  delay(100);

}
