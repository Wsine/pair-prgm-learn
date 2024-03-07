/*
Potentiometer controlled servo motor
*/

#include <Servo.h>

// Declare an unsigned long variable 't' for storing timer values.
unsigned long t;

// Create a Servo object named 'myServo' to control a servo motor.
Servo myServo;

void setup() {
  // Set the pinMode of pin A0 as INPUT to read the signal from the potentiometer.
  pinMode(A0, INPUT);

  // Attach the servo motor to pin 9 on the Arduino board.
  myServo.attach(9);

  // Initialize serial communication at 115200 baud rate.
  Serial.begin(115200);

  // Store the current processor time (in milliseconds) into the timer variable 't'.
  t = millis();

  // Set the initial position of the servo motor to 0 degrees.
  myServo.write(0);

  // Wait for 1000 milliseconds (1 second) before executing the next command.
  delay(1000);
  
}

void loop() {
  // Check if the current processor time (in milliseconds) is greater than 't' plus 15 milliseconds.
  if (millis() > t + 15) {
    
    // Store the current processor time (in milliseconds) into the timer variable 't'.
    t = millis();
    
    // Read the signal from the analog pin A0 (connected to the potentiometer) and store it in the variable 'inputSignal'.
    int inputSignal = analogRead(A0);
    
    // Map the input signal range (0 - 1023) to the servo motor angle range (0 - 180) and store it in the variable 'pos'.
    int pos = map(inputSignal, 0, 1023, 0, 180);
    
    // Control the servo motor angle based on the mapped position value 'pos'.
    myServo.write(pos);
    
    // Send the following information via serial communication.
    // - Current processor time (in milliseconds) stored in 't'.
    // - Input signal value 'inputSignal'.
    // - Servo motor angle 'pos'.
    Serial.print("Time: ");
    Serial.print(t);
    Serial.print(" | Input Signal: ");
    Serial.print(inputSignal);
    Serial.print(" | Servo angle: ");
    Serial.println(pos);

  }
}

