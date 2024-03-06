#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define sensorPin 4

const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

const char *mqtt_broker = "broker's IP";
const char *topic = "GROUP";
const char *mqtt_username = "client";
const char *mqtt_password = "test";
const int mqtt_port = 1883;

unsigned long t;
int delayT = 100;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Set up pin IO modes
  // Hint: Use pinMode() with sensorPin and INPUT as arguments

  // Turn off the LED
  // Hint: Use digitalWrite() with LED_BUILTIN and 0 as arguments

  // Initialize serial communication
  // Hint: Use Serial.begin() with 115200 as the baud rate

  // Connect to WiFi
  // Hint: Use WiFi.begin() with ssid and password as arguments
  //       Use a while loop to check the WiFi connection status

  // Indicate successful WiFi connection by turning on the LED
  // Hint: Use digitalWrite() with LED_BUILTIN and 1 as arguments

  // Set up MQTT connection
  // Hint: Use client.setServer() with mqtt_broker and mqtt_port as arguments
  //       Use a while loop to check the MQTT connection status

  // Turn off the LED to indicate successful MQTT connection
  // Hint: Use digitalWrite() with LED_BUILTIN and 0 as arguments

  // Set the initial value of processor time
  // Hint: Use millis() function and store the value in t variable
}

void loop() {
  // Keep MQTT client connected
  // Hint: Use client.loop() function

  // Check if the timed event has occurred
  // Hint: Compare the current time (using millis() function) with the previously stored processor time (t) and delayT

  // Update processor time for next comparison
  // Hint: Use millis() function and store the value in t variable

  // Check if the sensor is activated
  // Hint: Use digitalRead() function with sensorPin as its argument

  // Publish a message on the topic if the sensor is activated
  // Hint: Use client.publish() function with appropriate arguments

  // Indicate successful publishing by turning on the LED
  // Hint: Use digitalWrite() with LED_BUILTIN and 1 as arguments

  // Set the delayT value based on the sensor state
  // Hint: Assign a value to the delayT variable based on the sensor state

  // Turn off the LED if the timed event has not occurred
  // Hint: Use digitalWrite() with LED_BUILTIN and 0 as arguments
}

