

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESP";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);


//String MAIN_page  = "<!DOCTYPE html><html><body> <h2>Circuits4you<h2><h3> HTML Form ESP8266</h3> <form action=\"/action_page\">  First name:<br>  <input type=\"text\" \name=\"firstname\" value=\"Mickey\">  <br>  Last name:<br>  <input type=\"text\" name=\"lastname\" value=\"Mouse\">  <br><br>  <input type=\"submit\" value=\"Submit\"></form>  </body></html>";


/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */



void setup() {
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
  server.on("/action_page", handleForm); //form action is handled here
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
