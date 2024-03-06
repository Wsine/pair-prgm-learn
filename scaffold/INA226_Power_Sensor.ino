#include <Wire.h>
#include <INA226.h>

INA226 ina;

void checkConfig()
{
  // Hint: Print "Mode: " to the Serial monitor
  // Hint: Inside the switch statement, call ina.getMode() and print the corresponding mode name in the Serial monitor

  // Hint: Print "Samples average: " to the Serial monitor
  // Hint: Inside the switch statement, call ina.getAverages() and print the corresponding averages value in the Serial monitor

  // Hint: Print "Bus conversion time: " to the Serial monitor
  // Hint: Inside the switch statement, call ina.getBusConversionTime() and print the corresponding bus conversion time value in the Serial monitor

  // Hint: Print "Shunt conversion time: " to the Serial monitor
  // Hint: Inside the switch statement, call ina.getShuntConversionTime() and print the corresponding shunt conversion time value in the Serial monitor

  // Hint: Print "Max possible current: " to the Serial monitor
  // Hint: Call ina.getMaxPossibleCurrent() and print its value in the Serial monitor
  
  // Hint: Print "Max current: " to the Serial monitor
  // Hint: Call ina.getMaxCurrent() and print its value in the Serial monitor

  // Hint: Print "Max shunt voltage: " to the Serial monitor
  // Hint: Call ina.getMaxShuntVoltage() and print its value in the Serial monitor

  // Hint: Print "Max power: " to the Serial monitor
  // Hint: Call ina.getMaxPower() and print its value in the Serial monitor
}

void setup() 
{
  // Hint: Initialize the Serial communication with a baud rate of 115200

  // Hint: Print a message indicating that INA226 is being initialized

  // Hint: Begin using the INA226 with the default address (0x40)

  // Hint: Configure the INA226 with the following parameters:
  //       Averages: 16
  //       Bus conversion time: 2116us
  //       Shunt conversion time: 2116us
  //       Mode: Shunt and Bus continuous

  // Hint: Calibrate the INA226 with the following parameters:
  //       Shunt resistance: 0.0015 Ohm
  //       Maximum expected current: 4A

  // Hint: Display the configuration by calling checkConfig() function
}

void loop()
{
  // Hint: Print "Bus voltage: " and call ina.readBusVoltage() to print the bus voltage in Volts

  // Hint: Print "Bus power: " and call ina.readBusPower() to print the bus power in Watts

  // Hint: Print "Shunt voltage: " and call ina.readShuntVoltage() to print the shunt voltage in Volts

  // Hint: Print "Shunt current: " and call ina.readShuntCurrent() to print the shunt current in Amperes

  // Hint: Add an empty line to the Serial monitor
  // Hint: Wait for 1000 milliseconds (1 second) before repeating the loop
}
