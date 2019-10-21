/* Create a WiFi access point and provide a web server on it. */
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <FS.h>


#define SSID_MEM 100// memory position of SSID to station mode connect it
#define SSID_LEN 30 //lenght of SSID memory block
#define PWD_MEM 130 // memory position of password to station mode connect it
#define PWD_LEN 30 //lenght of password memory block

//Set ssid and password for SoftAP
const char *ssid = "ESP";
const char *password = "12345678";


ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */

void setup() {
  SPIFFS.begin();
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
  
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);
	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
  //server.on("/action", connectAPForm); //form action is handled here
  //server.on("/status",eeprom_status);
  server.on("/options",handle_options);
  server.on("/stconfig",handle_st_config);
  server.on("/actionstconfig", action_st_config);
  server.on("/connect",handle_connect);
  server.on("/actionconnect",handle_action_connect);
  server.on("/goback",goback);
  server.on("/conf.txt",handle_conf_file);
	server.begin();
	Serial.println("HTTP server started");
  //connect2ap("q6","12345678");//read_EEPROM_str(SSID_MEM,SSID_LEN) , read_EEPROM_str(PWD_MEM,PWD_LEN));//Set station with preset values read from EEPROM


}

void loop() {
	server.handleClient();
}
