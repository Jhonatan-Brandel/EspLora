
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
 File file = SPIFFS.open("/actionconnect.html","r");
 server.streamFile(file, "text/html");
 file.close();
 File file2 = SPIFFS.open("/conf.txt","r");
 String txt=file2str(file2);
 Serial.println(txt);
 file2.close();
 connect2ap(get_pseudo_dict_data(txt,"#SSID"),get_pseudo_dict_data(txt,"#PWD"));
}

//Funçao para setar modo de auto-conectar no boot do sistema
//chamada quando e enviado o formulario
void handle_action_autocon() {
 goback();
 File file = SPIFFS.open("/autocon.txt","w");
 file.print("#AUTOCON,"+server.arg("autocon")+"\n");
 file.close();
}

void XMLcontent()
 {
  File file = SPIFFS.open("/conf.txt","r");
  String txt=String(file2str(file));
  file.close();
  String ssid=get_pseudo_dict_data(txt,"#SSID");
  //Serial.println(txt);
  //Serial.println("xmlconteudo");

  String ip= WiFi.localIP().toString();
  String XML ="<?xml version='1.0'?>";
  XML+="<connect>";
  XML+="<ssid>";
  XML+=ssid;
  XML+="</ssid>";

  XML+="<ip>";
  XML+=ip;
  XML+="</ip>";
  XML+="</connect>";
  server.send(200,"text/xml",XML);
  }

void autoconXMLcontent()
 {
  File file = SPIFFS.open("/autocon.txt","r");
  String txt=String(file2str(file));
  file.close();
  String autocon=get_pseudo_dict_data(txt,"#AUTOCON");

  String XML ="<?xml version='1.0'?>";
  XML+="<autoconnect>";
  XML+="<autocon>";
  XML+=autocon;
  XML+="</autocon>";
  XML+="</autoconnect>";
  
  server.send(200,"text/xml",XML);
  }



