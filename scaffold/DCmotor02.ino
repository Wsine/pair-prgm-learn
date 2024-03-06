// Declare motor pins for uno board
int motorPin1 = 6;
int motorPin2 = 7;

// Declare variables for encoder value and target count
int encoderValue = 0;
int TargetEC = 200;

// Setup function for setting up pin modes and interrupts
void setup()
{
  // Initialize serial communication with 115200 baud rate
  // Hint: Use the Serial.begin function with 115200 as its argument.

  // Set motor pins as OUTPUT
  // Hint: Use the pinMode() function with motorPin1 and motorPin2 as its arguments and OUTPUT as its second argument.
  
  // Set external interrupt pins as INPUT_PULLUP
  // Hint: Use the pinMode() function with pin numbers 2 and 3 as its arguments, and INPUT_PULLUP as its second argument. 
    
  // Attach a function that will be called when an interrupt 0 is triggered on falling edge of pin 2
  // Hint: Use the attachInterrupt() function with digitalPinToInterrupt(2), Encoder_subroutine, and FALLING as its arguments.
  
}

// Continuously running main loop
void loop()
{
  // Run the motor clockwise while the encoderValue is less than target value(TargetEC)
  // Hint: Use the motor_clockwise() function together with a print statement to print respective values.
  // Hint: Use a delay() function with an appropriate value to control the speed of the motor.
  
  
  // Print messages when the motor stops and final encoder value
  // Hint: Use Serial.print() and Serial.println() functions with appropriate values.
  
  // Stop the motor and keep it stopped after reaching target value
  // Hint: Use a motor_stop() function in a while(1) loop.
}

// Function to update encoder values based on the direction of rotation
void Encoder_subroutine() {
  // Check the voltage of another encoder pin (pin 3)
  // Hint: Use the digitalRead() function with pin number 3 and compare the result.
  
  // Update encoderValue based on digitalRead result (increment or decrement encoderValue)
  // Hint: Use if-else statements with increment (++) or decrement (--) operators.
  
}

// Function to signal the motor to revolve in clockwise direction
void motor_clockwise() {
  // Set motorPin1 to HIGH (1) and motorPin2 to LOW (0) for clockwise rotation
  // Hint: Use the digitalWrite() function with motorPin1 and motorPin2 as its arguments, and 1 or 0 as its second argument.
  
}

// Function to signal the motor to revolve in counterclockwise direction
void motor_counterclockwise() {
  // Set motorPin1 to LOW (0) and motorPin2 to HIGH (1) for counterclockwise rotation
  // Hint: Use the digitalWrite() function with motorPin1 and motorPin2 as its arguments, and 0 or 1 as its second argument.
  
}

// Function to signal the motor to stop
void motor_stop() {
  // Set motorPin1 and motorPin2 to LOW (0) to stop motor
  // Hint: Use the digitalWrite() function with motorPin1 and motorPin2 as its arguments, and 0 as its second argument. 
  
}
