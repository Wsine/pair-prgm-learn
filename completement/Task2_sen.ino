#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "WIFI_SSID";
const char *password = "WIFI_PASSWORD";

const char *mqtt_broker = "broker IP";
const char *topic = "GROUP";
const char *mqtt_username = "client";
const char *mqtt_password = "test";
const int mqtt_port = 1883;

int cnter = 0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
  
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");

    client.setServer(mqtt_broker, mqtt_port);

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

    client.publish(topic, "hello world");

    Serial.println("Packet sent");
}

void loop() {
    client.loop();
}
