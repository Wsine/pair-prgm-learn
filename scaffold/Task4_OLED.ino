#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>               
#include "SSD1306Wire.h"   

// WiFi configuration
const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

// MQTT Broker configuration
const char *mqtt_broker = "broker's IP";
const char *topic = "GROUP";
const char *mqtt_username = "client";
const char *mqtt_password = "test";
const int mqtt_port = 1883;

char alertT[20] = "Never"; // Text to display when alerted

unsigned long aT, t, aSec=0; // Processor time marks

SSD1306Wire display(0x3c, SDA, SCL);   // Setup OLED display (SDA = D2, SCL = D1)
boolean alerted=false; //Flag to indicate first alert

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length) {
  // Print the topic and payload
  // Hint: Use Serial print functions

  // Set the value of aT and change the alerted flag
  
  // Turn on the LED
  // Hint: Use the digitalWrite() function with LED_BUILTIN and 1 as its arguments
  
}

void setup() {
  // Initialize Serial communication and set the baud rate

  // Set up the onboard LED as output and turn it off
  // Hint: Use pinMode() and digitalWrite() functions

  // Initialize the OLED display and clear it

  // Set font, display connecting to Wi-Fi and attempt to connect

  // Print Wi-Fi connection status

  // Set font, display connecting to MQTT broker, and attempt to connect

  // Set the MQTT client's server and callback functions
  // Hint: Use client.setServer() and client.setCallback()

  // Connect to the MQTT broker
  
  // Publish a message to the "log" topic
	
  // Subscribe to the "alert" topic

  // Display "DONE" on the OLED

  // Wait for 1000ms, then turn on the LED

  // Set font for the main display and show the initial alert time

  // Get the current processor time
  // Hint: Use millis() function

}

void loop() {
	client.loop();

	// Check the alerted flag and time elapsed, then update the display
	// Hint: use the millis() function to get current time

	// Set the LED off

	// Calculate elapsed time in seconds
	
	// Create a string for the elapsed time

	// Update the OLED display with the new elapsed time
	
}
