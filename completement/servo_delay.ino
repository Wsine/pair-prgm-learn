/*****************************************************
IDP  Feedback and control of servo motor (V20210915)
Potentiometer controlled servo
*****************************************************/

#include <Servo.h>

// Create a Servo object named 'myServo' to control a servo motor.
Servo myServo;

void setup() {
  // Set the pinMode of pin A0 as INPUT.
  pinMode(A0, INPUT);

  // Attach the servo motor to pin 9 using the Servo object 'myServo'.
  myServo.attach(9);

  // Start a serial communication at a baud rate of 115200.
  Serial.begin(115200);

  // Set the initial position of the servo motor to 0 degrees.
  myServo.write(0);

  // Wait for 1000 milliseconds (1 second) for the servo motor to reach its initial position.
  delay(1000);
}

void loop() {
  // Read the analog input from pin A0 and store it in an integer variable 'inputSignal'.
  int inputSignal = analogRead(A0);

  // Map the input range (0 to 1023) to a final servo range (0 to 180 degrees) as an integer variable 'pos'.
  int pos = map(inputSignal, 0, 1023, 0, 180);

  // Move the servo motor to the position (angle) specified by 'pos'.
  myServo.write(pos);

  // Output the value of 'inputSignal' to the serial monitor with the "Reads Bit: " label.
  Serial.print("Reads Bit: ");
  Serial.println(inputSignal);

  // Output the value of 'pos' to the serial monitor with the "Writes angle: " label.
  Serial.print("Writes angle: ");
  Serial.println(pos);

  // Wait for 15 milliseconds before executing the next iteration of the loop().
  delay(15);
}
