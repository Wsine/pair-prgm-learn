/*
  Fading LED with counter output
*/

int led_pin = 8;
int i = 0;

void setup() {
  // Set the LED pin as an output
  pinMode(led_pin, OUTPUT);
  // Initialize the Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Increase the LED brightness
  for (i = 0; i <= 255; i++) {
    analogWrite(led_pin, i);
    
    // Print counter values
    Serial.print("Counter1: ");
    Serial.print(i);
    Serial.print(", ");
    Serial.println("Counter2: 255");

    // Pause between increasing the brightness
    delay(10);
  }

  // Decrease the LED brightness
  for (i = 255; i >= 0; i--) {
    analogWrite(led_pin, i);
    
    // Print counter values
    Serial.print("Counter1: ");
    Serial.print(i);
    Serial.print(", ");
    Serial.println("Counter2: 0");

    // Pause between decreasing the brightness
    delay(10);
  }
}
