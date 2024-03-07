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
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  aT = millis();
  alerted = true;
  digitalWrite(LED_BUILTIN, 1);
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  display.init();
  display.clear();

  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Connecting to Wi-Fi");
  display.display();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  display.clear();
  display.drawString(0, 0, "WiFi connected");
  display.display();
  
  display.clear();
  display.drawString(0, 0, "Connecting to MQTT");
  display.display();

  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);

  while (!client.connected()) {
    client.connect("ESP8266Client", mqtt_username, mqtt_password);
  }

  client.publish("log", "ESP8266Client connected");
  client.subscribe("alert");

  display.clear();
  display.drawString(0, 0, "DONE");
  display.display();
  
  delay(1000);
  digitalWrite(LED_BUILTIN, 1);

  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, alertT);
  display.display();

  t = millis();
}

void loop() {
	client.loop();

  if (alerted && (millis() - t) > 1000) {
    digitalWrite(LED_BUILTIN, 0);
    
    aSec =(millis()-aT)/1000;

    sprintf(alertT, "Alert: %lud:%02luh:%2lum:%2lus", aSec/86400L, (aSec%86400L)/3600, (aSec%3600)/60, aSec%60);

    display.clear();
    display.drawString(0, 0, alertT);
    display.display();
  }
}
