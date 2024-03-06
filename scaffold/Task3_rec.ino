#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Set the constants for your WiFi network
const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

// Set the constants for your MQTT Broker
const char *mqtt_broker = "broker IP";
const char *topic = "GROUP";
const char *mqtt_username = "client";
const char *mqtt_password = "test";
const int mqtt_port = 1883;

// Declare variables for timers
unsigned long timer1, timer2, time_diff = 0;

// Create objects for WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Initialize the Serial communication at the baud rate of 115200
  // Hint: Use the Serial.begin() function with 115200 as its argument.

  // Connect to the specified WiFi network
  // Hint: Use the WiFi.begin() function with ssid and password as its arguments.

  // Add a delay and print a message "Connecting to WiFi.." until connected
  // Hint: Use a while loop with WiFi.status() != WL_CONNECTED and Serial.println() function.

  // Print the connected WiFi network
  // Hint: Use the Serial.println() function to print "Connected to the WiFi network".

  // Configure the MQTT server and callback function
  // Hint: Use setServer() and setCallback() functions.

  // Connect to the MQTT broker and subscribe to the topic
  // Hint: Use a while loop and the client.connect(), client.subscribe() functions.
}

void callback(char *topic, byte *payload, unsigned int length) {
  // Mark processor time
  // Hint: Set timer1 to current value

  // Calculate the time difference between 2 packets if timer2 is not equal to 0
  // Hint: Use an if statement to check if timer2 is not equal to 0

  // Print the duration between 2 packets
  // Hint: Use Serial.print() and Serial.println() functions to print the duration.

  // Update timer2 with the value of timer1
  // Hint: Set timer2 to the current value of timer1

  // Print the message arrived in topic
  // Hint: Use Serial.print() and Serial.println() functions to print topic.

  // Print the received message
  // Hint: Use a for loop and Serial.print() function to print the message in payload.

}

void loop() {
  // Process and run the MQTT client loop
  // Hint: Use client.loop() function.
}
