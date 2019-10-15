
boolean connect2ap(String ssid,String password)
{
 int ssid_len = ssid.length() + 1;
 char char_ssid[ssid_len];
 ssid.toCharArray(char_ssid, ssid_len);

 int pwd_len = password.length() + 1;
 char char_pwd[pwd_len];
 password.toCharArray(char_pwd, pwd_len);
 
 WiFi.begin(char_ssid,char_pwd);

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

