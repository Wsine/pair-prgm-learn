#include <ESP8266WiFi.h> // Include ESP8266WiFi library to enable Wi-Fi functionality

#define WIFI_SSID "ELEC3848" // Define the Wi-Fi SSID (network name) to connect to
#define WIFI_PW "password" // Define the Wi-Fi password to connect to the network

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED pin as output

  digitalWrite(LED_BUILTIN, HIGH); // Turn off the built-in LED

  Serial.begin(115200); // Initialize serial communication at a baud rate of 115200

  WiFi.begin(WIFI_SSID, WIFI_PW); // Connect to the Wi-Fi network with the specified SSID and password
  while (WiFi.status() != WL_CONNECTED) { // Loop until the Wi-Fi connection is successful
    delay(250); // Wait for 250 milliseconds
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle the state of the built-in LED
    Serial.println("Connecting to WiFi..."); // Print a message indicating connecting to Wi-Fi
  }
  Serial.println("Connected to the WiFi network"); // Print a message indicating successful connection to Wi-Fi
  delay(100); // Wait for 100 milliseconds
  digitalWrite(LED_BUILTIN, LOW); // Turn on the built-in LED to indicate Wi-Fi connection success
  Serial.println("-------------------------"); // Print a line separator
  Serial.println("Hello from ESP8266"); // Print a welcome message
  Serial.print("Connected to hotspot: "); // Print a message indicating the connected hotspot
  Serial.println(WIFI_SSID); // Print the hotspot's SSID
  Serial.print("IP address is: "); // Print a message indicating the ESP8266's IP address
  Serial.println(WiFi.localIP()); // Print the actual IP address
  Serial.println("-------------------------"); // Print another line separator
}

void loop() {
  // The loop function is empty since all the tasks are performed in the setup function
}
