
boolean connect2ap(String ssid,String password)
{
 int ssid_len = ssid.length() + 1;
 char char_ssid[ssid_len];
 ssid.toCharArray(char_ssid, ssid_len);

 int pwd_len = password.length() + 1;
 char char_pwd[pwd_len];
 password.toCharArray(char_pwd, pwd_len);
 
 WiFi.begin(char_ssid,char_pwd);//---Essa funçao realmente acessa o AP desejado

 //WiFi.config(staticIP, gateway, subnet);
 int attempts=0;
 while ((WiFi.status() != WL_CONNECTED)&&(attempts<60)    )

{

delay(500);
Serial.print(".");
attempts++;

}

//Verificar se conectou ou nao e alterar propriedades de IP e tal (que ai da pra ver na pagina de status pelo softap)

Serial.println();

Serial.print("Connected, IP address: ");

if (WiFi.status() == WL_CONNECTED)
{
  Serial.println(WiFi.localIP());
  return true;
}
return false;

}

void str2ip(String strIP,int &iparray0,int &iparray1,int &iparray2,int &iparray3)
{
  int Parts[4] = {0,0,0,0};
  int Part = 0;
  for ( int i=0; i<strIP.length(); i++ )
    {
     char c = strIP[i];
      if ( c == '.' )
        {
          Part++;
          continue;
        }
      Parts[Part] *= 10;
      Parts[Part] += c - '0';
    }
 iparray0=Parts[0];
 iparray1=Parts[1];
 iparray2=Parts[2];
 iparray3=Parts[3];
}


void autoconnect()
{
  File file = SPIFFS.open("/autocon.txt","r");
  String txt=String(file2str(file));
  file.close();
  String autocon=get_pseudo_dict_data(txt,"#AUTOCON");
  if (autocon.equals("check"))//Se esta marcado que e para conectar durante o boot
  {
    File file2 = SPIFFS.open("/conf.txt","r");
    String txt=file2str(file2);
   Serial.println(txt);
   file2.close();
   connect2ap(get_pseudo_dict_data(txt,"#SSID"),get_pseudo_dict_data(txt,"#PWD"));
  }
}

