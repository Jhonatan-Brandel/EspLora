
void handleRoot() {
  File file = SPIFFS.open("/index.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

void goback() {
  File file = SPIFFS.open("/goback.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

void handle_options() {
  File file = SPIFFS.open("/options.html","r");
  server.streamFile(file, "text/html");
  file.close();
}


void handle_st_config() {
  File file = SPIFFS.open("/st_config.html","r");
  server.streamFile(file, "text/html");
  file.close();
}




void action_st_config() {

 goback();

 File config_file=SPIFFS.open("/conf.txt","w");
 config_file.print("#SSID,"+server.arg("ssid")+"\n");
 config_file.print("#PWD,"+server.arg("password")+"\n");
 config_file.print("#MODE,"+server.arg("manual")+"\n");
 config_file.print("#GTW,"+server.arg("gateway")+"\n");
 config_file.print("#SUBNET,"+server.arg("subnet")+"\n");
 config_file.print("#IP,"+server.arg("ip")+"\n");
 config_file.close();
}

void handle_conf_file() {
  File file = SPIFFS.open("/conf.txt","r");
  server.streamFile(file, "text/html");
  file.close();
}



void handle_connect() {
  File file = SPIFFS.open("/connect.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

void handle_action_connect() {
 goback(); 
 File file = SPIFFS.open("/conf.txt","r");
 String txt=file2str(file);
 Serial.println(txt);
 file.close();
 connect2ap(get_pseudo_dict_data(txt,"#SSID"),get_pseudo_dict_data(txt,"#PWD"));
 
}





/*
void eeprom_status() {

 
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

//Templates functions
String layout_template(String content)
{ //return String(F(""))+content+String(F(""));
  return String(F(" <!DOCTYPE html> <html> <head> <title>EspLora </title><style>.menubar ul { font-family: Arial, Helvetica, sans-serif; list-style-type: none; overflow: hidden; background-color: #4CAF50; border-radius: 5px; padding: 10px;}.menubar li { float: left;}.menubar li a { display: block; color: white; text-align: center; padding: 14px 16px; text-decoration: none;}.menubar li a:hover { background-color: #4CAF50;}.menubar p{ font-family: Arial, Helvetica, sans-serif;}.cabecalho h1{ font-family: Arial, Helvetica, sans-serif; color:#4CAF50}</style> </head> <body><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><style>* { box-sizing: border-box;}h2{ font-family: Arial, Helvetica, sans-serif; }input[type=text], select, textarea { width: 100%; padding: 12px; border: 1px solid #ccc; border-radius: 4px; resize: vertical;}label { padding: 12px 12px 12px 0; display: inline-block;}input[type=submit] { background-color: #4CAF50; color: white; padding: 12px 20px; border: none; border-radius: 4px; cursor: pointer; float: right;}input[type=submit]:hover { background-color: #45a049;}.container { border-radius: 5px; background-color: #f2f2f2; padding: 20px; font-family: Arial, Helvetica, sans-serif; font-weight: bold;}.col-25 { float: left; width: 25%; margin-top: 6px;}.col-75 { float: left; width: 75%; margin-top: 6px;}.row:after { content: \"\"; display: table; clear: both;} .col-25, .col-75, input[type=submit] { width: 100%; margin-top: 0; }}</style> </head> <body> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <div class=\"cabecalho\"> <h1 class=\"logo\">( ( ( EspLora ) ) )</h1> </div> <header> <div class=\"menubar\"> <strong><nav> <ul> <li><a href=\"/status\">Status</a></li> <li><a href=\"/config\">Options</a></li> <li><a href=\"/tb\">Testbench</a></li> <li><a href=\"/connect\">Connect</a></li> <li><a href=\"/about\">About</a></li> </ul> </nav></strong> </div> </header> <div class=\"conteudo\">"))+content+String(F(" </div> </body> </html>"));
}
*/
