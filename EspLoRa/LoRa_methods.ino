
void setLora(){
  Serial.println("setLora");
  File file = SPIFFS.open("/loraconf.txt","r");
  String txt=String(file2str(file));
  file.close();
  if(txt.equals("")){//arquivo nao esta presente, configura do modo default
  int ss=D8;
  int reset=D0;
  int dio0=D2;
  LoRa.end();
  LoRa.setPins(ss, reset, dio0);
  if (!LoRa.begin(915.0E6)) {
    Serial.println("Starting LoRa failed!");
    return;
  }
  LoRa.setTxPower(20);
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setCodingRate4(5);
  }
  else
  { 
   // int ss=esp8266pinmap((get_pseudo_dict_data(txt,"#SS")).toInt());
  //  int reset=esp8266pinmap((get_pseudo_dict_data(txt,"#RESET")).toInt());
  //  int dio0=esp8266pinmap((get_pseudo_dict_data(txt,"#DIO0").toInt()));
    float freq=(get_pseudo_dict_data(txt,"#FREQ")).toFloat();
      int ss=D8;
  int reset=D0;
  int dio0=D2;
    LoRa.setPins(ss, reset, dio0);
    if (!LoRa.begin(freq)) {
      Serial.println("Starting LoRa failed!");
      return;
    }
    
    int SF=esp8266pinmap((get_pseudo_dict_data(txt,"#SF")).toInt());
    int POWER=esp8266pinmap((get_pseudo_dict_data(txt,"#TXPOWER")).toInt());
    int CR=esp8266pinmap((get_pseudo_dict_data(txt,"#CR")).toInt());
    float BW=(get_pseudo_dict_data(txt,"#BW")).toFloat();
    LoRa.setTxPower(POWER);
    LoRa.setSpreadingFactor(SF);
    LoRa.setSignalBandwidth(BW*1000);
    LoRa.setCodingRate4(CR);    
   
  }
Serial.println("Starting LoRa, ok!");
}










int esp8266pinmap(int DN)
{
  switch (DN) {
  case 0:
    return 16;
    break;
  case 1:
    return 5;
    break;
  case 2:
    return 4;
    break;
  case 3:
    return 0;
    break;
  case 4:
    return 2;
    break;
  case 5:
    return 14;
    break;   
  case 6:
    return 12;
    break;  
  case 7:
    return 13;
    break;
  case 8:
    return 15;
    break;
  case 9:
    return 3;
    break;
  case 10:
    return 1;
    break;
          
  default:
    return-1;
    break;
}
return -1;
}

