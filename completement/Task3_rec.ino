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
unsigned long	timer1, timer2, time_diff = 0;

// Create objects for WiFi and MQTT clients
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
 // Initialize the Serial communication at the baud rate of 115200
 Serial.begin(115200);

 // Connect to the specified WiFi network
 WiFi.begin(ssid, password);

 // Add a delay and print a message "Connecting to WiFi.." until connected
 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Connecting to WiFi..");
 }

 // Print the connected WiFi network
 Serial.println("Connected to the WiFi network");

 // Configure the MQTT server and callback function
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);

 // Connect to the MQTT broker and subscribe to the topic
 while (!client.connected()) {
  if (client.connect("ESP8266", mqtt_username, mqtt_password)) {
   client.subscribe(topic);
  } else {
   delay(5000); // Retry connecting after 5 seconds
  }
 }
}

void callback(char *topic, byte *payload, unsigned int length) {
 // Mark processor time
 timer1 = micros();

 // Calculate the time difference between 2 packets if timer2 is not equal to 0
 if (timer2 != 0) {
  time_diff = timer1 - timer2;
 }

 // Print the duration between 2 packets
 Serial.print("Duration between 2 packets: ");
 Serial.println(time_diff);

 // Update timer2 with the value of timer1
 timer2 = timer1;

 // Print the message arrived in topic
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);

 // Print the received message
 Serial.print("Message: ");
 for (int i = 0; i < length; i++) {
  Serial.print((char)payload[i]);
 }
 Serial.println();
}

void loop() {
 // Process and run the MQTT client loop
 client.loop();
}
