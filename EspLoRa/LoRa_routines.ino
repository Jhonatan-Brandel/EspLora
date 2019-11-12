
void txlora()
{
  if(tictoc(3000))
 {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
 }
  
}






bool tictoc(long interval)
{
  tic=millis();
  if ((tic-toc)>=interval)
   {toc=tic;
   Serial.println("tictoc");
   return true;}
  return false;
}

