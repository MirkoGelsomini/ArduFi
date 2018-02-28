#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>

#define TRIGGER_PIN D4 //(D4=2, only 0 and 2 work, always set them HIGH at power-up. If the pin is low, the config manager starts)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting...");

  delay(1000);
  Serial.print("IP:");
  Serial.println(WiFi.localIP());
  //Serial.println(WiFi.gatewayIP());
  //Serial.println(WiFi.subnetMask());

  pinMode(TRIGGER_PIN, INPUT);

}


void loop() {
  
  if (digitalRead(TRIGGER_PIN) == LOW) // is configuration portal requested?
  {
    Serial.println("------------ WiFiManager ---------");

    WiFiManager wifiManager; //Local initialization of WiFiManager
    //wifiManager.resetSettings(); //reset settings - for testing
   if (!wifiManager.startConfigPortal("OnDemandAP")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000); 
      ESP.reset(); //reset and try again, or maybe put it to deep sleep
      delay(5000);
    }

    Serial.println("Connected");
    Serial.print("IP:");
    Serial.println(WiFi.localIP());
    //Serial.println(WiFi.gatewayIP());
    //Serial.println(WiFi.subnetMask());
  }

  
  /*WiFiClient client = WiFi.getClient();
  if (!client) {
    return;
  }

    //Recheck if the client is really available
  int temp=0;
  while(!client.available()){
    delay(1);
    temp+=1;
    if(temp==1000){
      Serial.println("Client not available: aborted");
      return;
    }
  }
  
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.print("Client request:");
  Serial.println(request);
  String path = request.substring(request.indexOf("GET ")+4,request.indexOf(" HTTP/1.1"));
  Serial.print("Path: ");
  Serial.println(path);*/

  // put your main code here, to run repeatedly:

}
