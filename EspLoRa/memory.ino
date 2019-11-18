
String get_pseudo_dict_data(String str, String n)

{ int idx_from=str.indexOf(n+",");
  int idx_to=str.indexOf("\n",idx_from);
    //debug
 /* Serial.println("--------------");
  Serial.println(str+","+n);
  Serial.println(idx_from);
  Serial.println(idx_to);*/
 
  if (idx_from==-1)
    return "";
  if( idx_to==-1)
  {
   idx_to=str.length();
  }
   
   /*Serial.println(str.substring(idx_from+n.length(), idx_to));

   Serial.println(str.substring(idx_from+n.length()+1, idx_to));
   
   Serial.println("--------------");*/
  return str.substring(idx_from+n.length()+1, idx_to);
}

String file2str(File txtfile)
{ String output="";
  while (txtfile.available()) {
     output+=char(txtfile.read());
  }
  return output;
}

