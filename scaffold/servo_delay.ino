/*****************************************************
IDP  Feedback and control of servo motor (V20210915)
Potentiometer controlled servo
*****************************************************/

#include <Servo.h>

// Create a Servo object named 'myServo' to control a servo motor.


Servo myServo;

void setup() {
  // Set the pinMode of pin A0 as INPUT.
  

  // Attach the servo motor to pin 9 using the Servo object 'myServo'.
   
  
  // Start a serial communication at a baud rate of 115200.
  
     
  // Set the initial position of the servo motor to 0 degrees.
  
  
  // Wait for 1000 milliseconds (1 second) for the servo motor to reach its initial position.
  
}

void loop() {
  // Read the analog input from pin A0 and store it in an integer variable 'inputSignal'.
  
  // Map the input range (0 to 1023) to a final servo range (0 to 180 degrees) as an integer variable 'pos'.
   

  // Move the servo motor to the position (angle) specified by 'pos'.
    
    
  // Output the value of 'inputSignal' to the serial monitor with the "Reads Bit: " label.
  

  // Output the value of 'pos' to the serial monitor with the "Writes angle: " label.

  
  // Wait for 15 milliseconds before executing the next iteration of the loop().
    
}
