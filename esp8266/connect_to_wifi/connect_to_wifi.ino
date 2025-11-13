#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include "config.h"                     // Include WiFi credentials (not in Git)

// Serial communication settings
#define SERIAL_BAUD_RATE 115200         // Baud rate for ESP8266 (higher rate for better performance)
#define SERIAL_INIT_DELAY_MS 10         // Initial delay after serial initialization

// WiFi connection settings
#define WIFI_CONNECT_RETRY_DELAY_MS 1000  // Delay between WiFi connection attempts (milliseconds)

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);         // Start the Serial communication to send messages to the computer
  delay(SERIAL_INIT_DELAY_MS);
  Serial.println("@CSB ::\n");
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);   // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(WIFI_CONNECT_RETRY_DELAY_MS);
    Serial.print(+ +i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() { }
