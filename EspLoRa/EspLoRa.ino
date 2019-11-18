/* Create a WiFi access point and provide a web server on it. */
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <FS.h>
#include <ESP8266mDNS.h> 
#include <SPI.h>
#include <LoRa.h>


//#include<LoRa.h> 
//Set ssid and password for SoftAP
const char *ssid = "ESP8266";
const char *password = "12345678";
long tic,toc,counter=0;

String pkt_message="";
int pkt_rssi=0;
float pkt_snr=0;

ESP8266WebServer server(80);

void setup() {
 SPIFFS.begin();
 Serial.begin(115200);
 setLora();
 startListeners();
tic=millis();
toc=tic;
 
}

void loop() {
server.handleClient();

//txlora();
LoRaRx();
 
}

//http://192.168.4.1 to access the softap
