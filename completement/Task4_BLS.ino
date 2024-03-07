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
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensorPin, INPUT);
  
  digitalWrite(LED_BUILTIN, 0);
  
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  
  digitalWrite(LED_BUILTIN, 1);
  
  client.setServer(mqtt_broker, mqtt_port);
  
  while (!client.connected()) {
      String client_id = "esp8266-client-";
      client_id += String(WiFi.macAddress());
      Serial.printf("The client %s connects to the mqtt broker\n", client_id.c_str());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
          Serial.println("mqtt broker connected");
      } else {
          Serial.print("failed with state ");
          Serial.print(client.state());
          delay(2000);
      }
  }
  
  digitalWrite(LED_BUILTIN, 0);
   
  t=millis();
}

void loop() {
  client.loop();
  if(millis() > t+delayT){
    t=millis();

    if(!digitalRead(sensorPin)){

      if (client.publish(topic, "1")) { // publish "1" when sensor is triggered
         digitalWrite(LED_BUILTIN, 1);

         Serial.println("Publish ok");

         delayT=5000; // wait for 5 seconds before checking again

      } else {
         Serial.println("Publish failed");
      }
    } else {
      delayT=100; // check the sensor every 100 milliseconds when it's not triggered
    }
  } else digitalWrite(LED_BUILTIN, 0);
}
