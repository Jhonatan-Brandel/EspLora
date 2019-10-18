
//write to memory
void write_EEPROM_str(String x,int pos){
  for(int n=pos;n<x.length()+pos;n++){
     EEPROM.write(n,x[n-pos]);
  }
  EEPROM.write(x.length()+pos,'\n');//Adciona uma quebra de linha no final da String
  EEPROM.commit();
}


//write to memory
String read_EEPROM_str(int pos,int len){
  String readstr;
  char readc;
  for(int n=pos;n<len+pos;n++){
     readc=char(EEPROM.read(n));
     if(readc!='\n')//concatena o caractere se nao e fim de linha
     readstr+=String(readc);
     else
     break;
  }
  return readstr;
}

