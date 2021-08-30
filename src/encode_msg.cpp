#include "encode_msg.h"

char testmsg[60];

char *encode_cmsg(char msgtype){
  char h_timestamp[10];
  char h_latitude[10];
  char h_longitude[11];
  char h_bat[4];
  char h_msgtype=msgtype;
  memset(testmsg,'\0',60);
  sprintf(h_timestamp,"%x",(unsigned int)utctime());
  sprintf(h_latitude,"%x",(int)(((sLatitude.toFloat())+90)*1000000));
  sprintf(h_longitude,"%x",(int)(((sLongitude.toFloat())+180)*1000000));
  sprintf(h_bat,"%x",bat2);
  sprintf(testmsg,"%s;%s;%s;%s;%c",h_timestamp,h_latitude,h_longitude,h_bat,h_msgtype);
  
  return testmsg;
}

// String encode_fmsg(String msgtype){  //legacy function
//   String s_date=syear+smonth+sday;
//   String s_time=String(ptime);
//   String ftmsg=s_date+";"+s_time+";"+sLatitude+";"+sLongitude+";"+String(bat2)+";"+msgtype;
//   String h_date=String(pdate,HEX);
//   String h_time=String(ptime,HEX);
//   String h_latitude=String(int((sLatitude.toFloat()+90)*1000000),HEX);
//   String h_longitude=String(int((sLongitude.toFloat()+180)*1000000),HEX);
//   String h_battery=String(bat2,HEX);
//   String s=";";
//   String encode_msg=h_date +s+ h_time +s+ h_latitude +s+ h_longitude +s+ h_battery +s+ msgtype;
//   //Serial.printf("ftmsg: %s\r\n",fmsg);
//   //Serial.printf("encode msg: %s\r\n",encode_msg);
//   return encode_msg;
// }
