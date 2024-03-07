// Define echoPin and trigPin constants
#define echoPin 11
#define trigPin 12

unsigned long start_time = 0;
int done = 1;
long distance_in_cm;

void setup() {
  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set echoPin as an input pin
  pinMode(echoPin, INPUT);

  // Set trigPin as an output pin
  pinMode(trigPin, OUTPUT);
}

void loop() {
  // Call the measure_distance() function
  measure_distance();

  // Print the measured distance_in_cm value
  Serial.print(distance_in_cm);

  // Print a newline character (empty line) to separate the distance values
  Serial.println();

  // Wait for 1000 milliseconds (1 second) before repeating the loop
  delay(1000);
}

void measure_distance() {
  long duration;

  // Check if the distance has been measured in the last invocation of the method
  if(done == 1){
    // If done is 1, set done to 0, and assign the current time (in milliseconds) to start_time
    done = 0;
    start_time = millis();

    // Set trigPin to LOW level before starting the measurement
    digitalWrite(trigPin, LOW);
  }

  // Check if 2 milliseconds have passed since starting the measurement
  if (millis() >= start_time + 2) {
    // If 2 milliseconds have passed, set trigPin to HIGH level
    digitalWrite(trigPin, HIGH);
  }

  // Check if 10 milliseconds have passed since starting the measurement
  if (millis() >= start_time + 10) {
    // If 10 milliseconds have passed, set trigPin to LOW level
    digitalWrite(trigPin, LOW);

    // Measure the duration of the echo signal (pulse width) in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters based on the duration of the echo signal
    distance_in_cm = (duration / 2.0) / 29.1;

    // Set done to 1 to indicate that the distance measurement has been completed
    done = 1;
  }
}
