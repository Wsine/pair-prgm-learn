#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_light.h>

// Initialize MPU6050 mpu object to communicate on the I2C Wire.
MPU6050 mpu(Wire);
// Initialize a variable 'timer' to store value for printing data intervals.
unsigned long timer = 0;

// Fill in the setup() function, which is executed only once during power-up.
void setup() {
  // Initialize the Serial port with 115200 baud rate.
  // Hint: Use the Serial.begin() function with 115200 as its argument.

  // Initialize the Wire library.
  // Hint: Use the Wire.begin() function without any arguments.
  
  // Initialize the MPU6050 object.
  // Hint: Use the mpu.begin() function without any arguments.

  // Print a message to the Serial Monitor instructing the user not to move the MPU6050.
  // Hint: Display it using the Serial.println() function.

  // Print a message to the Serial Monitor indicating that calculation is in progress.
  // Hint: Display it using the Serial.println() function.

  // Delay 1 second (1000 milliseconds) before calculating gyro offsets.
  // Hint: Use the delay() function with 1000 as its argument.

  // Calculate and set gyroscope offsets.
  // Hint: Use the mpu.calcGyroOffsets() function without any arguments.

  // Print a message to the Serial Monitor indicating that the calibration is completed.
  // Hint: Display it using the Serial.println() function.
}

// Fill in the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Update the current MPU6050 data.
  // Hint: Use the mpu.update() function without any arguments.

  // Check if 10 milliseconds have passed since the last data was printed.
  // Hint: Use the millis() function and an 'if' statement.
  {
    // Print the pitch (angle X) value.
    // Hint: Use Serial.print() with appropriate string and mpu.getAngleX().

    // Print the roll (angle Y) value.
    // Hint: Use Serial.print() with appropriate string and mpu.getAngleY().

    // Print the yaw (angle Z) value.
    // Hint: Use Serial.println() with appropriate string and mpu.getAngleZ().

    // Update the timer variable with the current time.
    // Hint: Use the millis() function and assign it to the timer variable.
  }
}
