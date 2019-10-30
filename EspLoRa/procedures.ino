void startListeners()
{ SPIFFS.begin();
  delay(10);
  File file = SPIFFS.open("/apconf.txt","r");
  String txt=String(file2str(file));
  file.close();
  if(txt.equals("")){
   WiFi.softAP(ssid, password);}
  else
  {
    String ssid2=get_pseudo_dict_data(txt,"#SSID");
    String password2=get_pseudo_dict_data(txt,"#PWD");
    WiFi.softAP(ssid2, password2);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  autoconnect();
  WiFi.hostname("esp8266");
  
  server.on("/", handleRoot);
  server.on("/status", handleRoot);
  server.on("/options",handle_options);
  server.on("/softapconfig",handle_ap_config);
  server.on("/actionapconfig", action_ap_config);
  server.on("/stconfig",handle_st_config);
  server.on("/actionstconfig", action_st_config);
  server.on("/connect",handle_connect);
  server.on("/actionconnect",handle_action_connect);
  server.on("/actionautoconnect",handle_action_autocon);
  server.on("/autoconxml", autoconXMLcontent);  
  server.on("/goback",goback);
  server.on("/conf.txt",handle_conf_file);
  server.on("/connectxml", XMLcontent);
  server.on("/loraconfig",handle_lora_config); 
  server.on("/actionloraconfig",action_lora_config);
  server.on("/loraconfxml", loraconfXML);
  server.begin();
  Serial.println("HTTP server started");

}

