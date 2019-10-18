
void handleRoot() {
 server.send(200, "text/html", F("<!DOCTYPE html><html><body> <h2>Selecione SSID e senha<h2><h3> HTML Form ESP8266</h3> <form action=\"/actionConfig\">  SSID:<br>  <input type=\"text\" name=\"ssid\" value=\"SSID\">  <br>  Senha:<br>  <input type=\"text\" name=\"password\" value=\"Senha\">  <br><br>  <input type=\"submit\" value=\"Submit\"></form>  </body></html>")); //Send web page
}


void eeprom_status() {

 
 server.send(200, "text/html",layout_template(read_EEPROM_str(SSID_MEM,SSID_LEN)));
 
}

void handleConfig() {

 server.send(200, "text/html",layout_template(F(" <!DOCTYPE html> <html> <head> <title>EspLora </title><style>.menubar ul { font-family: Arial, Helvetica, sans-serif; list-style-type: none; overflow: hidden; background-color: #4CAF50; border-radius: 5px; padding: 10px;}.menubar li { float: left;}.menubar li a { display: block; color: white; text-align: center; padding: 14px 16px; text-decoration: none;}.menubar li a:hover { background-color: #4CAF50;}.menubar p{ font-family: Arial, Helvetica, sans-serif;}.cabecalho h1{ font-family: Arial, Helvetica, sans-serif; color:#4CAF50}</style> </head> <body><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><style>* { box-sizing: border-box;}h2{ font-family: Arial, Helvetica, sans-serif; }input[type=text], select, textarea { width: 100%; padding: 12px; border: 1px solid #ccc; border-radius: 4px; resize: vertical;}label { padding: 12px 12px 12px 0; display: inline-block;}input[type=submit] { background-color: #4CAF50; color: white; padding: 12px 20px; border: none; border-radius: 4px; cursor: pointer; float: right;}input[type=submit]:hover { background-color: #45a049;}.container { border-radius: 5px; background-color: #f2f2f2; padding: 20px; font-family: Arial, Helvetica, sans-serif; font-weight: bold;}.col-25 { float: left; width: 25%; margin-top: 6px;}.col-75 { float: left; width: 75%; margin-top: 6px;}.row:after { content: \"\"; display: table; clear: both;} .col-25, .col-75, input[type=submit] { width: 100%; margin-top: 0; }}</style> </head> <body> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <div class=\"cabecalho\"> <h1 class=\"logo\">( ( ( EspLora ) ) )</h1> </div> <header> <div class=\"menubar\"> <strong><nav> <ul> <li><a href=\"/status\">Status</a></li> <li><a href=\"/config\">Options</a></li> <li><a href=\"/tb\">Testbench</a></li> <li><a href=\"/connect\">Connect</a></li> <li><a href=\"/about\">About</a></li> </ul> </nav></strong> </div> </header> <div class=\"conteudo\"> <h2>ESP8266 Station mode network settings:</h2><p></p><div class=\"container\"> <form action=\"/actionConfig\"> <div class=\"row\"> <div class=\"col-25\"> <label for=\"ssid\">SSID</label> </div> <div class=\"col-75\"> <input type=\"text\" id=\"ssid\" name=\"ssid\" placeholder=\"\"> </div> </div> <div class=\"row\"> <div class=\"col-25\"> <label for=\"password\">Password</label> </div> <div class=\"col-75\"> <input type=\"text\" id=\"password\" name=\"password\" placeholder=\"\"> </div> </div> <div class=\"row\"> <div class=\"col-25\"> <label for=\"manual\">Manual mode</label> </div> <div class=\"col-75\"> <input type=\"checkbox\" name=\"manual\" value=\"auto\"> </div> </div> <div class=\"row\"> If manual mode was choosed, the fields below need to be filled: </div> <div class=\"row\"> <div class=\"col-25\"> <label for=\"gateway\">Gateway</label> </div> <div class=\"col-75\"> <input type=\"text\" id=\"gateway\" name=\"gateway\" placeholder=\"\"> </div> </div> <div class=\"row\"> <div class=\"col-25\"> <label for=\"subnet\">Subnet mask</label> </div> <div class=\"col-75\"> <input type=\"text\" id=\"subnet\" name=\"subnet\" placeholder=\"\"> </div> </div> <div class=\"row\"> <div class=\"col-25\"> <label for=\"ip\">IP</label> </div> <div class=\"col-75\"> <input type=\"text\" id=\"ip\" name=\"ip\" placeholder=\"\"> </div> </div><br> <div class=\"row\"> <input type=\"submit\" value=\"Submit\"> </div> </form></div></div> </body> </html>")));
}

void actionConfig() {
 
 String ssid = server.arg("ssid"); 
 String password = server.arg("password"); 
 String configMode = server.arg("manual"); 
 String ip = server.arg("ip"); 
 String gateway = server.arg("gateway"); 
 String subnet = server.arg("subnet"); 
 Serial.print("SSID:");
 Serial.println(ssid);
 Serial.print("Senha:");
 Serial.println(password);
 Serial.print("Modo:");
 Serial.println(configMode);
 
 Serial.print("ip:");
 int intip [4]={0,0,0,0};
 str2ip(ip,intip[0],intip[1],intip[2],intip[3]);
 Serial.print(intip[0]);
 Serial.print(intip[1]);
 Serial.print(intip[2]);
 Serial.print(intip[3]);
 
  Serial.print("gateway:");
 Serial.println(gateway);
  Serial.print("subnet:");
 Serial.println(subnet);
 
 String s = "<a href='/'> Go Back </a>";
 server.send(200, "text/html", s); //Send web page
 //connect2ap(ssid,password);
 write_EEPROM_str(ssid,100);
 write_EEPROM_str(password,PWD_MEM);

}




void connectAPForm() {
 
 String ssid = server.arg("ssid"); 
 String password = server.arg("password"); 
 
 Serial.print("SSID:");
 Serial.println(ssid);
 
 Serial.print("Senha:");
 Serial.println(password);
 
 String s = "<a href='/'> Go Back </a>";
 server.send(200, "text/html", s); //Send web page
 connect2ap(ssid,password);
 write_EEPROM_str(ssid,100);
 write_EEPROM_str(password,PWD_MEM);

}

//Templates functions
String layout_template(String content)
{ //return String(F(""))+content+String(F(""));
  return String(F(" <!DOCTYPE html> <html> <head> <title>EspLora </title><style>.menubar ul { font-family: Arial, Helvetica, sans-serif; list-style-type: none; overflow: hidden; background-color: #4CAF50; border-radius: 5px; padding: 10px;}.menubar li { float: left;}.menubar li a { display: block; color: white; text-align: center; padding: 14px 16px; text-decoration: none;}.menubar li a:hover { background-color: #4CAF50;}.menubar p{ font-family: Arial, Helvetica, sans-serif;}.cabecalho h1{ font-family: Arial, Helvetica, sans-serif; color:#4CAF50}</style> </head> <body><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><style>* { box-sizing: border-box;}h2{ font-family: Arial, Helvetica, sans-serif; }input[type=text], select, textarea { width: 100%; padding: 12px; border: 1px solid #ccc; border-radius: 4px; resize: vertical;}label { padding: 12px 12px 12px 0; display: inline-block;}input[type=submit] { background-color: #4CAF50; color: white; padding: 12px 20px; border: none; border-radius: 4px; cursor: pointer; float: right;}input[type=submit]:hover { background-color: #45a049;}.container { border-radius: 5px; background-color: #f2f2f2; padding: 20px; font-family: Arial, Helvetica, sans-serif; font-weight: bold;}.col-25 { float: left; width: 25%; margin-top: 6px;}.col-75 { float: left; width: 75%; margin-top: 6px;}.row:after { content: \"\"; display: table; clear: both;} .col-25, .col-75, input[type=submit] { width: 100%; margin-top: 0; }}</style> </head> <body> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <div class=\"cabecalho\"> <h1 class=\"logo\">( ( ( EspLora ) ) )</h1> </div> <header> <div class=\"menubar\"> <strong><nav> <ul> <li><a href=\"/status\">Status</a></li> <li><a href=\"/config\">Options</a></li> <li><a href=\"/tb\">Testbench</a></li> <li><a href=\"/connect\">Connect</a></li> <li><a href=\"/about\">About</a></li> </ul> </nav></strong> </div> </header> <div class=\"conteudo\">"))+content+String(F(" </div> </body> </html>"));
}

