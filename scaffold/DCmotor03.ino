// Declare the motor pins and their corresponding values
int motorPin1 = 6;
int motorPin2 = 7;

// Declare the encoder values and target encoder values
int encoderValue = 0;
int encoderValueTarget = -1000;
int cnt=0;

// Declare timer variables and target timer value
long int Timer=0;
long int InitTimer=0;
long int TimerR=0;
long int TargetTimer=1000;

// Create the setup function for initialization
void setup()
{
  // Initialize the serial communication at 115200 baud rate
  // Set the motor pins as outputs
  // Set pins 2 and 3 as input pullups
    
  // Attach interrupts to the input pins and link to Encoder_subroutine with FALLING trigger
  // Set pin 9 as output for PWM motor speed control
}

// Create the loop function to execute the main program
void loop()
{
  // Assign the initial value of the timer
  // Start a loop until the encoder value reaches a target value and the timer expires
  // Inside the loop, run motor clockwise and control its speed using PWM
  // Calculate and display the timer, encoder value and motor state
  // When the loop ends, stop the motor and display its final state and timer value
  
  // Run motor_stop function indefinitely 
}

// Create a subroutine for the encoder's interrupts
void Encoder_subroutine() {
  // Check the voltage of other encoder pins
  // Increment or decrement the encoder value based on the voltage level
}

// Create the motor control functions for clockwise, counterclockwise and stop actions
void motor_clockwise() {
  // Set motorPin1 to HIGH and motorPin2 to LOW
}

void motor_counterclockwise() {
  // Set motorPin1 to LOW and motorPin2 to HIGH
}

void motor_stop() {
  // Set motorPin1 and motorPin2 to LOW
}
