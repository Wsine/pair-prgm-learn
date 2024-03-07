#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Replace with your WiFi name
const char *ssid = "WIFI_SSID";
// Replace with your WiFi password
const char *password = "WIFI_PASSWORD";

// Replace with your MQTT broker's IP
const char *mqtt_broker = "broker's IP";
// Choose a topic for MQTT communication
const char *topic = "GROUP";
const char *mqtt_username = "client";
const char *mqtt_password = "test";
const int mqtt_port = 1883;

int i = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Set serial baud rate to 115200 for communication
  Serial.begin(115200);

  // Connect to WiFi network by calling WiFi.begin() with ssid and password as arguments
  WiFi.begin(ssid, password);

  // Use a while loop to check WiFi connection status until it is connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Once connected, print "Connected to the WiFi network" to serial monitor
  Serial.println("Connected to the WiFi network");

  // Set the MQTT server details (broker, port)
  client.setServer(mqtt_broker, mqtt_port);

  // Use a while loop to connect to the MQTT broker using client_id, mqtt_username, and mqtt_password
  while (!client.connected()) {
    if (client.connect("ESP8266Client", mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT Broker!");
    } else {
      Serial.print("Failed to connect to MQTT Broker, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  // Call the client.loop() function for the PubSubClient library to process incoming data and maintain connections
  client.loop();

  // Execute a for loop to send packets ten times using the send_pckts() function
  for (int i = 0; i < 10; i++) {
    send_pckts();
  }
}

// Create the send_pckts() function
void send_pckts() {
  /***************************************/
  /*Enter your client.publish() code here*/
  char msg[50];
  snprintf(msg, 50, "Packet Number %d", i);
  client.publish(topic, msg);
  i++;
}

