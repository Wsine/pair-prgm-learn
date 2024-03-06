// Define echoPin and trigPin constants
#define echoPin 11
#define trigPin 12

unsigned long start_time = 0;
int done = 1;
long distance_in_cm;

void setup() {
  // Initialize Serial communication at 9600 baud rate
  // Hint: Use the Serial.begin() function with 9600 as the argument.

  // Set echoPin as an input pin
  // Hint: Use the pinMode() function with echoPin and INPUT as its arguments.

  // Set trigPin as an output pin
  // Hint: Use the pinMode() function with trigPin and OUTPUT as its arguments.
}

void loop() {
  // Call the measure_distance() function
  // Hint: Simply call the function by its name measure_distance().

  // Print the measured distance_in_cm value
  // Hint: Use the Serial.print() function with distance_in_cm as the argument.

  // Print a newline character (empty line) to separate the distance values
  // Hint: Use the Serial.println() function with an empty string or space as the argument.

  // Wait for 1000 milliseconds (1 second) before repeating the loop
  // Hint: Use the delay() function with 1000 as its argument.
}

void measure_distance() {
  long duration;

  // Check if the distance has been measured in the last invocation of the method
  // Hint: Use an if statement to check if the variable "done" is equal to 1.

    // If done is 1, set done to 0, and assign the current time (in milliseconds) to start_time
    // Hint: Use the millis() function to get the current time and assign it to the start_time variable.

    // Set trigPin to LOW level before starting the measurement
    // Hint: Use the digitalWrite() function with trigPin and LOW as its arguments.

  // Check if 2 milliseconds have passed since starting the measurement
  // Hint: Use an if statement to compare the current time (millis()) to the value of (start_time + 2).

    // If 2 milliseconds have passed, set trigPin to HIGH level
    // Hint: Use the digitalWrite() function with trigPin and HIGH as its arguments.

  // Check if 10 milliseconds have passed since starting the measurement
  // Hint: Use an if statement to compare the current time (millis()) to the value of (start_time + 10).

    // If 10 milliseconds have passed, set trigPin to LOW level
    // Hint: Use the digitalWrite() function with trigPin and LOW as its arguments.

    // Measure the duration of the echo signal (pulse width) in microseconds 
    // Hint: Use the pulseIn() function with echoPin and HIGH as its arguments, and assign the result to the "duration" variable.

    // Calculate the distance in centimeters based on the duration of the echo signal
    // Hint: Use the formula: distance_in_cm = (duration / 2.0) / 29.1

    // Set done to 1 to indicate that the distance measurement has been completed
    // Hint: Assign the value 1 to the "done" variable.
}
