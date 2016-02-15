#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
SMSGSM sms;
SoftwareSerial HC05(10, 11);
boolean x;
int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];
int BluetoothData;

void setup() 
{
  //Serial connection.
  Serial.begin(38400);
  pinMode(12, INPUT);
  HC05.begin(9600);
  Serial.println("GSM Shield testing.");
  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
  if (gsm.begin(19200)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  }


void loop() 
{
  x = digitalRead(12);
  if(HC05.available()){
    BluetoothData = HC05.read();
    if(BluetoothData == '2'){
      if(x == 1){
      // put your number here and the text you want
        if (sms.SendSMS("xxxxxxxx", "PIR is HIGH")){
        Serial.println("\nSMS sent OK");
        delay(60000);
     }
  
  }
 }
 if(BluetoothData == '1'){
  digitalWrite(12, LOW);
  }
 }
}
