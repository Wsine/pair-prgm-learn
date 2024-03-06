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
  // Hint: Use a for loop to increment i from 0 to 255, and use analogWrite to change the LED brightness

  // Print counter values
  // Hint: Use Serial.print and Serial.println to print the Counter1 value, a comma, and Counter2 value

  // Pause between increasing the brightness
  // Hint: Use delay(10) to add a short pause between each change in brightness

  // Decrease the LED brightness
  // Hint: Use a for loop to decrement i from 255 to 0, and use analogWrite to change the LED brightness

  // Print counter values
  // Hint: Use Serial.print and Serial.println to print the Counter1 value, a comma, and Counter2 value

  // Pause between decreasing the brightness
  // Hint: Use delay(10) to add a short pause between each change in brightness
}
