// Define echoPin as 11 and trigPin as 12
#define echoPin 11
#define trigPin 12

// Declare variable distance_in_cm as long
long distance_in_cm;

void setup() {
  // Initialize serial communication at 9600 bits per second rate
  // Hint: Use the Serial.begin() function with 9600 as its argument.
  
  // Set echoPin as input
  // Hint: Use pinMode() function with echoPin and INPUT as its arguments.
  
  // Set trigPin as output
  // Hint: Use pinMode() function with trigPin and OUTPUT as its arguments.
  
}

void loop() {
  // Call measure_distance() function to update distance_in_cm
  
  // Print distance_in_cm to the serial monitor
  // Hint: Use Serial.print() function with distance_in_cm as its argument.
  
  // Print a new line
  // Hint: Use Serial.println() function with an empty string as its argument ("")
  
  // Delay for 1000 milliseconds (1 second) before looping again
  // Hint: Use delay() function with 1000 as its argument.

}

void measure_distance() {
  // Declare variable duration as long
  
  // Set trigPin to LOW
  // Hint: Use digitalWrite() function with trigPin and LOW as its arguments.
  
  // Delay for 2 microseconds
  // Hint: Use delayMicroseconds() function with 2 as its argument.
  
  // Set trigPin to HIGH
  // Hint: Use digitalWrite() function with trigPin and HIGH as its arguments.
  
  // Delay for 10 microseconds
  // Hint: Use delayMicroseconds() function with 10 as its argument.
  
  // Set trigPin to LOW
  // Hint: Use digitalWrite() function with trigPin and LOW as its arguments.
  
  // Measure the time it takes for the echo signal to return
  // Hint: Use pulseIn() function with echoPin and HIGH as its arguments and store the result in duration.
  
  // Calculate distance_in_cm using the time duration and speed of sound
  // Hint: Use the formula distance_in_cm = (duration/2.0) / 29.1.
  
}
