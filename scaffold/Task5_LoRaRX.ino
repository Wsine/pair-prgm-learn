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
  // Hint: Use Serial.begin() with a baud rate of 115200 as its argument
  
  // Wait for the serial port to connect
  // Hint: Use a while loop to wait for Serial.

  // Print an initial message to the Serial Monitor
  // Hint: Use Serial.println() to print the strings

  // Setup LoRa transceiver module pins
  // Hint: Use LoRa.setPins(ss, rst, dio0)

  // Print instructions for the user
  // Hint: Use multiple Serial.println() statements to print each line of instructions
}

// Define the loop() function, which is called repeatedly during the program execution
void loop() {
  // Check if there is data in the Serial Monitor
  // Hint: Use an if statement and the Serial.available() function
  
    // Read the serial data into myString variable
    // Hint: Assign Serial.readString() to myString

    // Check if the input frequency is within the valid range
    // Hint: Use an if-else statement with myString.toDouble() and logical operators

      // Print an error message if the frequency is invalid
      // Hint: Use Serial.println()

    // Else, if the frequency is valid
    else {

      // Print the new frequency to change to
      // Hint: Use Serial.print() and Serial.println()

      // Start LoRa with the new frequency
      // Hint: Use LoRa.begin() with myString.toDouble() as its argument

      // If starting LoRa failed, print an error message and freeze the loop
      // Hint: Use an if statement, Serial.println() and an infinite while loop (while(1);)

    }
  
  // Check for new LoRa packets and store their size in a variable
  // Hint: Use LoRa.parsePacket() and store the result in an int variable (e.g., packetSize)

  // If a packet has been received
  if (packetSize) {
    // Print the received packet on the Serial Monitor
    // Hint: Use Serial.print()

    // Read the packet content and print it
    // Hint: Use a while loop with LoRa.available() and Serial.print((char)LoRa.read())
  }
}
