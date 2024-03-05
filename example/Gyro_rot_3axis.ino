#include <Arduino.h>

#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(115200);                                        
  Wire.begin();
  mpu.begin();
  Serial.println("Calculating gyro offset, do not move MPU6050");
  Serial.println("............");
  delay(1000);
  mpu.calcGyroOffsets();                          // This does the calibration
  Serial.println("Done");    
}

void loop() {
  mpu.update();  
  if((millis()-timer)>10)                         // print data every 10ms
  {                                             
    Serial.print("Pitch (Angle_X) : ");
    Serial.print(mpu.getAngleX());
    Serial.print("  Roll  (Angle_Y) : ");
    Serial.print(mpu.getAngleY());
    Serial.print("  Yaw   (Angle_Z) : ");
    Serial.println(mpu.getAngleZ());
    //Serial.println("==========================");
    timer = millis();  
    //delay(1000);
  }
}
