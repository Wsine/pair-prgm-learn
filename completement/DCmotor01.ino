// Declare motorPin1 and motorPin2 for controlling motor direction, and Dtime for delay duration
int motorPin1 = 6;
int motorPin2 = 7;
int Dtime = 50;

// Declare encoderValue for counting encoder steps and Time for storing the current time
int encoderValue = 0;
long int Time = 0;

void setup()
{
  // Initialize the Serial communication and set the baud rate to 115200
  Serial.begin(115200);
  // Set motorPin1 and motorPin2 as OUTPUT pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Set pin 2 and 3 to INPUT_PULLUP state
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  // Attach interrupt service routine Encoder_subroutine() to pin 2 on falling edge
  attachInterrupt(digitalPinToInterrupt(2), Encoder_subroutine, FALLING);
}

void loop()
{
  // Run motor_clockwise() function in a loop with printing encoderValue and current time
  for (int i=0;i<10;i++){
    motor_clockwise();
    delay(Dtime);
    Serial.print("Encoder Value: ");
    Serial.print(encoderValue);
    Serial.print(" Time: ");
    Serial.println(millis());
  }

  // Add motor_return() Serial print operation
  motor_stop();
  Serial.println("Motor Return");

  // Uncomment the following block to control motor_counterclockwise or motor_stop
  for (int j=0;j<10;j++){
    motor_counterclockwise();
    delay(Dtime);
    Serial.print("Encoder Value: ");
    Serial.print(encoderValue);
    Serial.print(" Time: ");
    Serial.println(millis());
  }

  // Add motor_stop() Serial print operation
  motor_stop();
  Serial.println("Motor Stop");

}

void Encoder_subroutine() {
  // Check the voltage of another encoder pin (pin 3) and update the encoderValue accordingly
  if (digitalRead(3) == LOW) {
    encoderValue++;
  } else {
    encoderValue--;
  } 
}

void motor_clockwise() {
  // Set motor to rotate clockwise by controlling motorPin1 and motorPin2
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void motor_counterclockwise() {
  // Set motor to rotate counterclockwise by controlling motorPin1 and motorPin2
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void motor_stop() {
  // Stop the motor by controlling motorPin1 and motorPin2
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}
