/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/
#include <ESP8266WiFi.h>
const int trigPin =13;
const int echoPin =12;
const int gpio2 =2;
const int gpio0 =3;
const int gpio4 =4;
const int gpio5 =5;
const int gpio16 =0;
const int led =11;
const int led2= 10;


const char* ssid     = "Bangna5_floor4_01";
const char* password = "bng5linux";

const char* host = "172.25.4.69";
const char* streamId   = "....................";
const char* privateKey = "....................";

String clientName, command;


String macToStr(const uint8_t* mac)
{
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5)
      result += ':';
  }
  return result;
}
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //pinMode(led, OUTPUT);
  //pinMode(led2, OUTPUT);

  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Generate client name based on MAC address and last 8 bits of microsecond counter
  
  clientName += "esp8266-";
  uint8_t mac[6];
  WiFi.macAddress(mac);
  clientName += macToStr(mac);
  clientName += "-";
  clientName += String(micros() & 0xff, 16);
  Serial.println("Client name "+clientName);

  pinMode(gpio2, OUTPUT);
  pinMode(gpio4, OUTPUT);
}
int value = 0;
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    //digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  //digitalWrite(led2,LOW);
}
  else {
    //digitalWrite(led,LOW);
    //digitalWrite(led2,HIGH);
  }
  if (distance >= 300 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  //delay(500);



  delay(1000);
  ++value;

  //Serial.print("connecting to ");
  //Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/cgi-bin/insert_temp5.py?devi1=10002&val1="+String(distance);

  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(1000);
  //"Content-Type: text/html; charset=UTF-8\n\n"

  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String command = client.readStringUntil('\r');
    //command = line;
    int idx = command.indexOf("[(");
    //Serial.println(command);
    if(idx>0){
      String comm[10] = { "-", "-", "-","-", "-", "-","-", "-", "-","-" };
      //command = command.substring(0,idx);
      command.replace(")]","");
      command.replace("[(","");
      //command.replace("\r","");
      command.replace("\n","");
      Serial.println("command "+command);
      //Serial.println("");
      for(int i=0;i<10;i++){
        String comm = getValue(command, ';', i);
        if(comm.length()<=0){
          continue;
        }
        String node = getValue(comm, ',', 0);
        //node.replace("\r","");
        node.replace("\n","");
        //Serial.println("node "+node);
        String onoff = getValue(comm, ',', 1);
        //onoff.replace("\r","");
        onoff.replace("\n","");
        onoff.replace(";","");
        Serial.print("onoff "+onoff);

        onoff=="ON" ? digitalWrite(gpio4, HIGH) : digitalWrite(gpio4, LOW);
        //if(onoff=="ON"){
        //  Serial.print("aaaa ");
        //  digitalWrite(gpio4, HIGH);
        //}else{
        //  Serial.print("bbbb ");
        //  digitalWrite(gpio4, LOW);
        //}
      }
    }
  }
  
  Serial.println();
  Serial.println("closing connection");
  
}
