
void handleRoot() {
 server.send(200, "text/html", F("<!DOCTYPE html><html><body> <h2>Selecione SSID e senha<h2><h3> HTML Form ESP8266</h3> <form action=\"/action_page\">  SSID:<br>  <input type=\"text\" name=\"ssid\" value=\"SSID\">  <br>  Senha:<br>  <input type=\"text\" name=\"password\" value=\"Senha\">  <br><br>  <input type=\"submit\" value=\"Submit\"></form>  </body></html>")); //Send web page
}


void eeprom_status() {

 //server.send(200, "text/html",read_EEPROM_str(SSID_MEM,SSID_LEN) );
 server.send(200, "text/html",layout_template(read_EEPROM_str(SSID_MEM,SSID_LEN)));
 
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

String layout_template(String content)
{
  return String(F(" <!DOCTYPE html> <html> <head> <title>EspLora </title><style>.menubar ul { font-family: Arial, Helvetica, sans-serif; list-style-type: none; margin: 0; padding: 0; overflow: hidden; background-color: #003d99;}.menubar li { float: left;}.menubar li a { display: block; color: white; text-align: center; padding: 14px 16px; text-decoration: none;}/* Change the link color to #111 (black) on hover */.menubar li a:hover { background-color: #002966;}.menubar p{ font-family: Arial, Helvetica, sans-serif;}.cabecalho h1{ font-family: Arial, Helvetica, sans-serif; color:#003d99}</style> </head> <body> <div class=\"cabecalho\"> <h1 class=\"logo\">EspLora</h1> </div> <header> <div class=\"menubar\"> <strong><nav> <ul> <li><a href=\"/status\">Status</a></li> <li><a href=\"/config\">Configurar</a></li> <li><a href=\"/tabela\"></a></li> </ul> </nav></strong> </div> </header> <div class=\"conteudo\"> "))+content+String(F(" </div> </body> </html>"));
}

