#include <WiFi.h>
#include <WiFiClient.h>
#include "libraries/WebServerEsp32/src/Parsing.cpp"
#include "libraries/WebServerEsp32/src/WebServer.cpp"
#include <ESPmDNS.h>
#include "libraries/WiFiManager-dev/WiFiManager.cpp"

WebServer server(80);

const int led = LED_BUILTIN;

int myData = -1;

void setup() {
  // Led configuration
  pinMode(LED_BUILTIN, OUTPUT);

  // Serial configuration
  Serial.begin(115200);
  Serial.println("Starting...");

  // Wifi configuration
  Serial.println("------------ WiFiManager ---------");
  
  WiFiManager wifiManager; //Local initialization of WiFiManager
  //wifiManager.resetSettings(); //reset settings - for testing
  if (!wifiManager.autoConnect("ArduFi - WiFi")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000); 
    ESP.restart(); //reset and try again, or maybe put it to deep sleep
    delay(5000);
  }
  Serial.println("Connected");

  
  // HTTP configuration
  server.on("/", handleRoot);
  server.on("/info", info);
  server.on("/getData", getData);
  server.on("/setData", setData);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println("Connected to Wifi:"+WiFi.SSID());
  Serial.println("Ip Address:"+WiFi.localIP().toString());

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  // Ask to the Wemos if there is a pending request
  server.handleClient();
}

void handleRoot() {
  digitalWrite(led, LOW);
  server.sendHeader("Access-Control-Max-Age", "10000");
  server.sendHeader("Access-Control-Allow-Methods", "*");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Hello world, from esp8266!");
  digitalWrite(led, HIGH);
}

void info() {
  digitalWrite(led, LOW);
  int seconds=(millis()/1000);
  server.sendHeader("Access-Control-Max-Age", "10000");
  server.sendHeader("Access-Control-Allow-Methods", "*");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/html", String("<html><body><b>Info</b><br/><br/>I'm connected to ") + WiFi.SSID() + 
  "<br/>My address is " + WiFi.localIP().toString() +
  "<br/><br/>I was turned on " + seconds + " seconds ago</body></html>");
  digitalWrite(led, HIGH);
}

void getData(){
  digitalWrite(led, LOW);
  server.sendHeader("Access-Control-Max-Age", "10000");
  server.sendHeader("Access-Control-Allow-Methods", "*");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", String(millis()));
  digitalWrite(led, HIGH);
}

void setData(){
  digitalWrite(led, LOW);
  String key=server.argName(0);
  String value=server.arg(0);

  String message;
  if(key=="data"){
    myData=value.toInt();
    Serial.println(String("New data: ") + myData);
    message= "ok";
  }else{
    message= "error";
  }
  server.sendHeader("Access-Control-Max-Age", "10000");
  server.sendHeader("Access-Control-Allow-Methods", "*");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "ok");
  digitalWrite(led, HIGH);
}

void handleNotFound(){
  digitalWrite(led, LOW);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.sendHeader("Access-Control-Max-Age", "10000");
  server.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(404, "text/plain", message);
  digitalWrite(led, HIGH);
}
