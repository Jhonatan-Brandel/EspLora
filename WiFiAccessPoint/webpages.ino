
void handleRoot() {
 server.send(200, "text/html", F("<!DOCTYPE html><html><body> <h2>Circuits4you<h2><h3> HTML Form ESP8266</h3> <form action=\"/action_page\">  First name:<br>  <input type=\"text\" name=\"firstname\" value=\"Mickey\">  <br>  Last name:<br>  <input type=\"text\" name=\"lastname\" value=\"Mouse\">  <br><br>  <input type=\"submit\" value=\"Submit\"></form>  </body></html>")); //Send web page
}


void handleForm() {
 String firstName = server.arg("firstname"); 
 String lastName = server.arg("lastname"); 
 
 Serial.print("First Name:");
 Serial.println(firstName);
 
 Serial.print("Last Name:");
 Serial.println(lastName);
 
 String s = "<a href='/'> Go Back </a>";
 server.send(200, "text/html", s); //Send web page
}
