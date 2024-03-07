#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>

#define ss 15
#define rst 16
#define dio0 4

void setup() {
  // Initialize Serial Monitor with a baud rate of 115200
  Serial.begin(115200);

  // Wait for the serial connection
  while (!Serial);

  // Print "LoRa Sender" to the Serial Monitor
  Serial.println("LoRa Sender");

  // Set up LoRa transceiver module with ss, rst, and dio0 pins
  LoRa.setPins(ss, rst, dio0);

  // Initialize LoRa with frequency 433E6 (433MHz) and check if it's successful
  if (!LoRa.begin(433E6)) {
    // Print "Starting LoRa failed!" to the Serial Monitor
    Serial.println("Starting LoRa failed!");

    // Halt the program with an infinite loop
    while (1);
  }

  // If LoRa initialized successfully, print "LoRa Initializing OK!" to the Serial Monitor
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  // Print "Sending packet: " to the Serial Monitor
  Serial.print("Sending packet: ");

  // Print "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" to the Serial Monitor
  Serial.println("Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz");

  // Begin sending LoRa packet to the receiver
  LoRa.beginPacket();

  // Print the message "Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz" to the LoRa packet
  LoRa.print("Channel Frequency for S1: 439MHz, Channel Frequency for S2: 441MHz");

  // End the LoRa packet transmission
  LoRa.endPacket();
}
