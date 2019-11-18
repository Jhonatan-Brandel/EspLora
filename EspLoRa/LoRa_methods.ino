



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
   int ss=esp8266pinmap((get_pseudo_dict_data(txt,"#SS")).toInt());
    int reset=esp8266pinmap((get_pseudo_dict_data(txt,"#RESET")).toInt());
    int dio0=esp8266pinmap((get_pseudo_dict_data(txt,"#DIO0").toInt()));
    float freq=(get_pseudo_dict_data(txt,"#FREQ")).toFloat();
  //    int ss=D8;
  //int reset=D0;
//  int dio0=D2;
    LoRa.setPins(ss, reset, dio0);
    if (!LoRa.begin(freq)) {
      Serial.println("Starting LoRa failed!");
      return;
    }
    
    float SF=get_pseudo_dict_data(txt,"#SF").toInt();
    int POWER=get_pseudo_dict_data(txt,"#TXPOWER").toInt();
    int CR=get_pseudo_dict_data(txt,"#CR").toInt();
    float BW=get_pseudo_dict_data(txt,"#BW").toFloat();

    Serial.print(freq);
    Serial.print(",");       
    Serial.print(SF);
    Serial.print(",");
    Serial.print(POWER);
    Serial.print(",");
    Serial.print(BW*1000);
    Serial.print(",");
    Serial.print(CR);
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
    return D0;
    break;
  case 1:
    return D1;
    break;
  case 2:
    return D2;
    break;
  case 3:
    return D3;
    break;
  case 4:
    return D4;
    break;
  case 5:
    return D5;
    break;   
  case 6:
    return D6;
    break;  
  case 7:
    return D7;
    break;
  case 8:
    return D8;
    break;
  case 9:
    return D9;
    break;
  case 10:
    return D10;
    break;
          
  default:
    return-1;
    break;
}
return -1;
}


void LoRaRx()
{
    // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    
    pkt_message="";   // read packet
    while (LoRa.available()) {
      pkt_message+=String((char)LoRa.read());
    }
    counter++;//PRECISA DISSO PARA ATUALIZAR O ID DA MENSAGEM E ATUALIZAR A INTERFACE NA WEB
    pkt_rssi=LoRa.packetRssi();
    pkt_snr=LoRa.packetSnr();
    
    Serial.print("Received: '");
    Serial.print(pkt_message);
    
    // print RSSI of packet
    Serial.print(" RSSI: ");
    Serial.print(pkt_rssi);

    Serial.print(" SNR: ");
    Serial.println(pkt_snr);
  
    }
}

