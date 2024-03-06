#include <Servo.h>

#define SERVO_PIN 9        
#define TOL   50
#define K   5

Servo myservo;

int int_position=90;

int int_adc0, int_adc0_m, int_adc0_c;
int int_adc1, int_adc1_m, int_adc1_c;     
int int_left, int_right;

void setup() 
{
  Serial.begin(115200);
  myservo.attach(SERVO_PIN);
  myservo.write(int_position);
  Serial.println();

  Serial.println("Calibration in progress, put the sensors under the light (~ 5 sec) ......");
  Serial.println("***********************");
  delay(5000); 

  // Read the light intensity of left sensor at ambient light intensity into int_adc0
  // Read the light intensity of right sensor at ambient light intensity into int_adc1
  

  Serial.println("\nCalibration in progress, cover the sensors with your fingers (~ 8 sec to set)......");
  Serial.println("************ Put Fingers *****************");
   
  delay(5000);
  Serial.println("********* START Calibration **************");

  // Read the light intensity of left sensor at zero light intensity into int_adc0_c
  // Read the light intensity of right sensor at zero light intensity into int_adc1_c

  // Calculate the slope of the equation for left sensor
  // Calculate the slope of the equation for right sensor
  
  delay(10000);

  Serial.println("\n******** Completed! Remove your hands ********");
  delay(4000);
}

void loop() 
{
  // Calculate the light intensity of left sensor using equation
  // Calculate the light intensity of right sensor using equation
  
  // Print the values of the light intensity of both sensors and the servo angle
  
  tracker();
  delay(100);
}

void tracker()
{
  // Check if left sensor is brighter than right sensor and if servo angle can be decreased
  // If the condition is met, decrease the servo angle and write the new angle to the servo
  
  
  // Check if right sensor is brighter than left sensor and if servo angle can be increased
  // If the condition is met, increase the servo angle and write the new angle to the servo

}
