

void handleRoot() {
  File file = SPIFFS.open("/status.html","r");
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

void handle_ap_config() {
  File file = SPIFFS.open("/ap_config.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

void action_ap_config() {
 goback();
 File config_file=SPIFFS.open("/apconf.txt","w");
 config_file.print("#SSID,"+server.arg("ssid")+"\n");
 config_file.print("#PWD,"+server.arg("password")+"\n");
 config_file.close();
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
  String gtwip= WiFi.gatewayIP().toString();
  String subnet= WiFi.subnetMask().toString();
  String rssi=String(WiFi.RSSI());
  
  String XML ="<?xml version='1.0'?>";
  XML+="<connect>";
  XML+="<ssid>";
  XML+=ssid;
  XML+="</ssid>";

  XML+="<ip>";
  XML+=ip;
  XML+="</ip>";

  XML+="<gateway>";
  XML+=gtwip;
  XML+="</gateway>";

  XML+="<subnet>";
  XML+=subnet;
  XML+="</subnet>";

  XML+="<rssi>";
  XML+=rssi;
  XML+="</rssi>";
  
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


void handle_lora_config() {
  File file = SPIFFS.open("/lora_config.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

void action_lora_config() {

 goback();
 File config_file=SPIFFS.open("/loraconf.txt","w");
 config_file.print("#FREQ,"+server.arg("FREQ")+"\n");
 config_file.print("#TXPOWER,"+server.arg("TXPOWER")+"\n");
 config_file.print("#SF,"+server.arg("SF")+"\n");
 config_file.print("#BW,"+server.arg("BW")+"\n");
 config_file.print("#CR,"+server.arg("CR")+"\n");
 config_file.print("#PREAMBLE,"+server.arg("PREAMBLE")+"\n");
 config_file.print("#SYNC,"+server.arg("SYNC")+"\n");
 config_file.print("#CRC,"+server.arg("CRC")+"\n");
 config_file.print("#SS,"+server.arg("SS")+"\n");
 config_file.print("#RESET,"+server.arg("RESET")+"\n");
 config_file.print("#DIO0,"+server.arg("DIO0")+"\n");
 config_file.print("#SPI,"+server.arg("SPI")+"\n");
 config_file.close();
}

void loraconfXML()
 {
  File file = SPIFFS.open("/loraconf.txt","r");
  String txt=String(file2str(file));
  file.close();
  
  String XML ="<?xml version='1.0'?>";
  XML+="<loraconf>";
  XML+="<freq>";
  XML+=get_pseudo_dict_data(txt,"#FREQ");
  XML+="</freq>";

  XML+="<txpower>";
  XML+=get_pseudo_dict_data(txt,"#TXPOWER");
  XML+="</txpower>";

  XML+="<sf>";
  XML+=get_pseudo_dict_data(txt,"#SF");
  XML+="</sf>";

  XML+="<bw>";
  XML+=get_pseudo_dict_data(txt,"#BW");
  XML+="</bw>";

  XML+="<cr>";
  XML+=get_pseudo_dict_data(txt,"#CR");
  XML+="</cr>";

  XML+="<preamble>";
  XML+=get_pseudo_dict_data(txt,"#PREAMBLE");
  XML+="</preamble>";
  
  XML+="<sync>";
  XML+=get_pseudo_dict_data(txt,"#SYNC");
  XML+="</sync>";

  
  XML+="<crc>";
  XML+=get_pseudo_dict_data(txt,"#CRC");
  XML+="</crc>";

  XML+="<ss>";
  XML+=get_pseudo_dict_data(txt,"#SS");
  XML+="</ss>";
 
  XML+="<reset>";
  XML+=get_pseudo_dict_data(txt,"#RESET");
  XML+="</reset>";

  XML+="<dio0>";
  XML+=get_pseudo_dict_data(txt,"#DIO0");
  XML+="</dio0>";

  XML+="<spi>";
  XML+=get_pseudo_dict_data(txt,"#SPI");
  XML+="</spi>";
  
  XML+="</loraconf>";
  
  server.send(200,"text/xml",XML);
  }

  void handleLoRaTerm() {
  File file = SPIFFS.open("/lora_terminal.html","r");
  server.streamFile(file, "text/html");
  file.close();
  Serial.println(server.arg("send"));
}

void lorapktXML()
{    
  String XML ="<?xml version='1.0'?>";

  XML+="<loraxml>";

  XML+="<id>";
  XML+=counter;
  XML+="</id>";
  
  XML+="<lastreceived>";
  XML+=pkt_message;
  XML+="</lastreceived>";
  
  XML+="</loraxml>";  
  server.send(200,"text/xml",XML);
  
}

void handleLoRasendform() {
  Serial.println(server.arg("send"));
  //send packet
  LoRa.beginPacket();
  LoRa.print(server.arg("send"));
  LoRa.endPacket();
}
