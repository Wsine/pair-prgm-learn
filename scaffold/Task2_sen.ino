#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Declare a constant character pointer named 'ssid' and assign your WiFi name to it
const char *ssid = "WIFI_SSID";
// Declare a constant character pointer named 'password' and assign your WiFi password to it
const char *password = "WIFI_PASSWORD";

// Declare a constant character pointer named 'mqtt_broker' and assign your MQTT broker's IP address to it
const char *mqtt_broker = "broker IP";
// Declare a constant character pointer named 'topic' and assign a topic you'd like to create
const char *topic = "GROUP";
// Declare a constant character pointer named 'mqtt_username' and assign your mqtt username to it
const char *mqtt_username = "client";
// Declare a constant character pointer named 'mqtt_password' and assign your mqtt password to it
const char *mqtt_password = "test";
// Declare a constant integer named 'mqtt_port' and assign your MQTT broker's port number to it
const int mqtt_port = 1883;

int cnter=0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Initialize the UART communication with a baud rate of 115200
  Serial.begin(115200);
  
  // Connect to the WiFi network
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  // Print a message when connected to WiFi network
  Serial.println("Connected to the WiFi network");
  
  // Set the MQTT broker server and the port number
  client.setServer(mqtt_broker, mqtt_port);

  // Establish connection to the MQTT broker
  while (!client.connected()) {
      String client_id = "esp8266-client-";
      client_id += String(WiFi.macAddress());
      Serial.printf("The client %s connects the mqtt broker\n", client_id.c_str());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("mqtt broker connected");
      } else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
      }
  }

  // Publish a message to the specified MQTT topic
  client.publish(topic, "hello world");

  // Print a message when the packet is sent
  Serial.println("Packet sent");
}

void loop() {
  // Process all the incoming messages and maintain the MQTT connection
  client.loop();
}
