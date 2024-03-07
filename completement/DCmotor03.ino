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
  Serial.begin(115200);

  // Set the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Set pins 2 and 3 as input pullups
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  // Attach interrupts to the input pins and link to Encoder_subroutine with FALLING trigger
  attachInterrupt(digitalPinToInterrupt(2), Encoder_subroutine, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), Encoder_subroutine, FALLING);

  // Set pin 9 as output for PWM motor speed control
  pinMode(9, OUTPUT);
}

// Create the loop function to execute the main program
void loop()
{
  // Assign the initial value of the timer
  Timer=millis();
  InitTimer=Timer;
  TimerR=Timer%1000+InitTimer;

  // Start a loop until the encoder value reaches a target value and the timer expires
  while(encoderValue <= encoderValueTarget && Timer <= TimerR)
  {
    // Inside the loop, run motor clockwise and control its speed using PWM
    motor_clockwise();
    analogWrite(9, 255);

    // Calculate and display the timer, encoder value and motor state
    Timer=millis();
    Serial.print("Timer: ");
    Serial.print(Timer);
    Serial.print(", Encoder Value: ");
    Serial.print(encoderValue);
    Serial.println(", Motor State: Clockwise");
  }

  // When the loop ends, stop the motor and display its final state and timer value
  motor_stop();
  Serial.print("Final Timer: ");
  Serial.print(Timer);
  Serial.println(", Final Motor State: Stopped");

  // Run motor_stop function indefinitely
  while(1) {
    motor_stop();
  }
}

// Create a subroutine for the encoder's interrupts
void Encoder_subroutine() {
  // Check the voltage of other encoder pins
  int B = digitalRead(3);

  // Increment or decrement the encoder value based on the voltage level
  if (B == HIGH){
    encoderValue++;
  } else {
    encoderValue--;
  }
}

// Create the motor control functions for clockwise, counterclockwise and stop actions
void motor_clockwise() {
  // Set motorPin1 to HIGH and motorPin2 to LOW
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void motor_counterclockwise() {
  // Set motorPin1 to LOW and motorPin2 to HIGH
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void motor_stop() {
  // Set motorPin1 and motorPin2 to LOW
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
