#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>

// Define pins for the LoRa module
#define ss 15
#define rst 16
#define dio0 4

// Declare a String variable named myString
String myString;

// Define the setup() function, which is executed only once during powerup
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Wait for the serial port to connect
  while (!Serial);
  
  // Print an initial message to the Serial Monitor
  Serial.println("LoRa Frequency Changer");

  // Setup LoRa transceiver module pins
  LoRa.setPins(ss, rst, dio0);

  // Print instructions for the user
  Serial.println("Enter a frequency (in Hz) to change the LoRa module to:");
}

// Define the loop() function, which is called repeatedly during the program execution
void loop() {
  // Check if there is data in the Serial Monitor
  if (Serial.available()) {
    // Read the serial data into myString variable
    myString = Serial.readString();

    // Check if the input frequency is within the valid range
    if (myString.toDouble() < 863000000 || myString.toDouble() > 870000000) {
      // Print an error message if the frequency is invalid
      Serial.println("Error: Invalid frequency. Enter a frequency between 863000000 and 870000000 Hz.");
    }
    // Else, if the frequency is valid
    else {
      // Print the new frequency to change to
      Serial.print("Changing LoRa frequency to ");
      Serial.println(myString);

      // Start LoRa with the new frequency
      if (!LoRa.begin(myString.toDouble())) {
        // If starting LoRa failed, print an error message and freeze the loop
        Serial.println("Starting LoRa failed!");
        while (1);
      }
    }
  }

  // Check for new LoRa packets and store their size in a variable
  int packetSize = LoRa.parsePacket();

  // If a packet has been received
  if (packetSize) {
    // Print the received packet on the Serial Monitor
    Serial.print("Received packet: ");

    // Read the packet content and print it
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}
