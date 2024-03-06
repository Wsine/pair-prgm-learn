#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Set your WiFi network name
const char *ssid = "WIFI_SSID";
// Set your WiFi network password
const char *password = "WIFI_PASSWORD";

// Set the IP address of your MQTT broker
const char *mqtt_broker = "broker IP";
// Set the name of the MQTT topic
const char *topic = "GROUP";
// Set the MQTT client username
const char *mqtt_username = "client";
// Set the MQTT client password
const char *mqtt_password = "test";
// Set the MQTT broker port (default: 1883)
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Begin the serial communication with the baud rate 115200
  

  // Connect the ESP8266 to the WiFi network with your credentials
  

  // Wait until ESP8266 is connected to the WiFi network
  

  // Print to the serial monitor that the connection to the WiFi network is established
  

  // Set the MQTT server settings (address and port)
  

  // Set the MQTT client callback function
  

  // Connect the client to the MQTT broker with the generated clientId and MQTT credentials
  

  // Subscribe to the MQTT topic
}

void callback(char *topic, byte *payload, unsigned int length) {
  // Print the received topic to the serial monitor
  

  // Print the received message payload character by character to the serial monitor
  

  // Insert a new line at the end of the message
}

void loop() {
  // Call the MQTT loop method to process incoming messages
}

