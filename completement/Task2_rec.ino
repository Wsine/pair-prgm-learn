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
  Serial.begin(115200);

  // Connect the ESP8266 to the WiFi network with your credentials
  WiFi.begin(ssid, password);

  // Wait until ESP8266 is connected to the WiFi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print to the serial monitor that the connection to the WiFi network is established
  Serial.println("WiFi connected");

  // Set the MQTT server settings (address and port)
  client.setServer(mqtt_broker, mqtt_port);

  // Set the MQTT client callback function
  client.setCallback(callback);

  // Connect the client to the MQTT broker with the generated clientId and MQTT credentials
  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker...");
    if (client.connect("ESP8266Client", mqtt_username, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" trying again in 5 seconds");
      delay(5000);
    }
  }

  // Subscribe to the MQTT topic
  client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
  // Print the received topic to the serial monitor
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.println("]");

  // Print the received message payload character by character to the serial monitor
  for (int i = 0; i < length; i++){
    Serial.print((char)payload[i]);
  }

  // Insert a new line at the end of the message
  Serial.println();
}

void loop() {
  // Call the MQTT loop method to process incoming messages
  client.loop();
}

