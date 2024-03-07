// Declare motor pins for uno board
int motorPin1 = 6;
int motorPin2 = 7;

// Declare variables for encoder value and target count
int encoderValue = 0;
int TargetEC = 200;

// Setup function for setting up pin modes and interrupts
void setup() {
  // Initialize serial communication with 115200 baud rate
  Serial.begin(115200);

  // Set motor pins as OUTPUT
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Set external interrupt pins as INPUT_PULLUP
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
    
  // Attach a function that will be called when an interrupt 0 is triggered on falling edge of pin 2
  attachInterrupt(digitalPinToInterrupt(2), Encoder_subroutine, FALLING);
}

// Continuously running main loop
void loop() {
  // Run the motor clockwise while the encoderValue is less than target value(TargetEC)
  while (encoderValue < TargetEC) {
    motor_clockwise();
    Serial.print("Encoder value: ");
    Serial.println(encoderValue);
    delay(100);
  }
  
  // Print messages when the motor stops and final encoder value
  Serial.println("Motor stopped");
  Serial.print("Final encoder value: ");
  Serial.println(encoderValue);

  // Stop the motor and keep it stopped after reaching target value
  while (1) {
    motor_stop();
  }
}

// Function to update encoder values based on the direction of rotation
void Encoder_subroutine() {
  // Check the voltage of another encoder pin (pin 3)
  int state = digitalRead(3);
  
  // Update encoderValue based on digitalRead result (increment or decrement encoderValue)
  if (state == 1) {
    encoderValue++;
  } else {
    encoderValue--;
  }
}

// Function to signal the motor to revolve in clockwise direction
void motor_clockwise() {
  // Set motorPin1 to HIGH (1) and motorPin2 to LOW (0) for clockwise rotation
  digitalWrite(motorPin1, 1);
  digitalWrite(motorPin2, 0);
}

// Function to signal the motor to revolve in counterclockwise direction
void motor_counterclockwise() {
  // Set motorPin1 to LOW (0) and motorPin2 to HIGH (1) for counterclockwise rotation
  digitalWrite(motorPin1, 0);
  digitalWrite(motorPin2, 1);
}

// Function to signal the motor to stop
void motor_stop() {
  // Set motorPin1 and motorPin2 to LOW (0) to stop motor
  digitalWrite(motorPin1, 0);
  digitalWrite(motorPin2, 0);
}
