
String get_pseudo_dict_data(String str, String n)
{ int idx_from=str.indexOf(n+",");
  int idx_to=str.indexOf("\n",idx_from);
  if (idx_from==-1)
    return "";
  if( idx_to==-1)
  {
   idx_to=str.length();
  }
  return str.substring(idx_from+n.length()+1, idx_to);
}

String file2str(File txtfile)
{ String output="";
  while (txtfile.available()) {
 
    output+=txtfile.read();
  }
  return output;
}

