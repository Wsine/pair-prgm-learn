#include <Wire.h>
#include <INA226.h>

INA226 ina;

void checkConfig()
{
  Serial.print("Mode: ");
  switch (ina.getMode()) {
    // Add more cases for different modes as necessary
    case 0:
      Serial.print("Shunt and Bus continuous");
      break;
  }

  Serial.print("Samples average: ");
  switch (ina.getAverages()) {
    case 16:
      Serial.print("16");
      break;
  }

  Serial.print("Bus conversion time: ");
  switch (ina.getBusConversionTime()) {
    // Add more cases for different values as necessary
    case 2116:
      Serial.print("2116us");
      break;
  }

  Serial.print("Shunt conversion time: ");
  switch (ina.getShuntConversionTime()) {
    // Add more cases for different values as necessary
    case 2116:
      Serial.print("2116us");
      break;
  }

  Serial.print("Max possible current: ");
  Serial.println(ina.getMaxPossibleCurrent(), 9);
  
  Serial.print("Max current: ");
  Serial.println(ina.getMaxCurrent(), 9);

  Serial.print("Max shunt voltage: ");
  Serial.println(ina.getMaxShuntVoltage(), 9);

  Serial.print("Max power: ");
  Serial.println(ina.getMaxPower(), 9);
}

void setup() 
{
  Serial.begin(115200);
  Serial.println("Initializing INA226...");

  ina.begin();
  ina.configure(INA226_AVERAGES_16, INA226_BUS_CONV_TIME_2116us, INA226_SHUNT_CONV_TIME_2116us, INA226_MODE_SHUNT_BUS_CONT);
  
  ina.calibrate(0.0015, 4);
  
  checkConfig();
}

void loop()
{
  Serial.print("Bus voltage: ");
  Serial.println(ina.readBusVoltage());

  Serial.print("Bus power: ");
  Serial.println(ina.readBusPower());

  Serial.print("Shunt voltage: ");
  Serial.println(ina.readShuntVoltage());

  Serial.print("Shunt current: ");
  Serial.println(ina.readShuntCurrent());

  Serial.println();
  delay(1000);
}
