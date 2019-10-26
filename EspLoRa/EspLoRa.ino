/* Create a WiFi access point and provide a web server on it. */
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <FS.h>
#include <ESP8266mDNS.h>    
//Set ssid and password for SoftAP
const char *ssid = "ESP";
const char *password = "12345678";

ESP8266WebServer server(80);

void setup() {
 Serial.begin(115200);
 startListeners();
}

void loop() {
 server.handleClient();
}

//http://192.168.4.1 to access the softap
