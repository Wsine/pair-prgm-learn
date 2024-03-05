/* 
Simple program that blinks an LED. 
Reference: ELEC3848 Lab 1
*/
const int ledPin = 13;             // declare read-only integer ledPin, set to correct pin number 

void setup() {                     // the setup() method is executed only once during powerup
  pinMode(ledPin, OUTPUT);         // the ledPin PIN is declared as digital output
}

void loop() {                      // the loop() method is called repeatedly
  digitalWrite(ledPin, HIGH);      // set a HIGH voltage to ledPin PIN 
  delay(1000);                     // stop the program for 1000 milliseconds
  digitalWrite(ledPin, LOW);       // set 0V (ground) to ledPin PIN 
  delay(1000);                     // stop the program for 1000 milliseconds
}
