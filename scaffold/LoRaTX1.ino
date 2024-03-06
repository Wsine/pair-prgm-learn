#include <Arduino.h>

#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
 
#define ss 15
#define rst 16
#define dio0 4

void setup() {
  // Initialize Serial Monitor with a baud rate of 115200
  // Hint: Use the Serial.begin() function with 115200 as its argument

  // Wait for the serial connection
  // Hint: Use the while (!Serial) statement

  // Print "LoRa Sender" to the Serial Monitor
  // Hint: Use the Serial.println() function with "LoRa Sender" as its argument

  // Set up LoRa transceiver module with ss, rst, and dio0 pins
  // Hint: Use the LoRa.setPins() function with ss, rst, and dio0 as its arguments

  // Initialize LoRa with frequency 433E6 (433MHz) and check if it's successful
  // Hint: Use an if statement with the LoRa.begin() function and 433E6 as its argument

    // Print "Starting LoRa failed!" to the Serial Monitor
    // Hint: Use the Serial.println() function with "Starting LoRa failed!" as its argument

    // Halt the program with an infinite loop
    // Hint: Use a while loop with 1 as its condition (while (1);)

  // If LoRa initialized successfully, print "LoRa Initializing OK!" to the Serial Monitor
  // Hint: Use the Serial.println() function with "LoRa Initializing OK!" as its argument
  
}

void loop() {
  // Print "Sending packet: " to the Serial Monitor
  // Hint: Use the Serial.println() function with "Sending packet: " as its argument

  // Print "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" to the Serial Monitor
  // Hint: Use the Serial.println() function with "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" as its argument

  // Begin sending LoRa packet to the receiver
  // Hint: Use the LoRa.beginPacket() function with no arguments

  // Print the message "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" to the LoRa packet
  // Hint: Use the LoRa.print() function with "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" as its argument

  // End the LoRa packet transmission
  // Hint: Use the LoRa.endPacket() function with no arguments
}
