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
  Serial.begin(115200);

  // Initialize the Wire library.
  Wire.begin();
  
  // Initialize the MPU6050 object.
  mpu.begin();

  // Print a message to the Serial Monitor instructing the user not to move the MPU6050.
  Serial.println("Please don't move the MPU6050");

  // Print a message to the Serial Monitor indicating that calculation is in progress.
  Serial.println("Calculating gyroscope offsets...");

  // Delay 1 second (1000 milliseconds) before calculating gyro offsets.
  delay(1000);

  // Calculate and set gyroscope offsets.
  mpu.calcGyroOffsets();

  // Print a message to the Serial Monitor indicating that the calibration is completed.
  Serial.println("Calibration completed");
}

// Fill in the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Update the current MPU6050 data.
  mpu.update();

  // Check if 10 milliseconds have passed since the last data was printed.
  if (millis() - timer > 10) {
    // Print the pitch (angle X) value.
    Serial.print("Pitch: ");
    Serial.print(mpu.getAngleX());

    // Print the roll (angle Y) value.
    Serial.print(" Roll: ");
    Serial.print(mpu.getAngleY());

    // Print the yaw (angle Z) value.
    Serial.print(" Yaw: ");
    Serial.println(mpu.getAngleZ());

    // Update the timer variable with the current time.
    timer = millis();
  }
}
