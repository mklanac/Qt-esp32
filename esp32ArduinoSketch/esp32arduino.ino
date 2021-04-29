#include <WiFi.h>

#define LED0 23
#define NUMBER_OF_DEVICES 4

const char* ssid = "esp32";
const char* password = "0987654321";
int channel = 12; //1-13
int max_connection = 4;
WiFiServer server(80);
// Set your Static IP address
IPAddress local_IP(192, 168, 4, 1);
// Set your Gateway IP address
IPAddress gateway(192, 168, 4, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

char sendEndOfFight[20];
char inChar;
IPAddress DeviceIPadress[NUMBER_OF_DEVICES];
IPAddress currentIP;
int NumberOfDevices = 0;


String html ="<!DOCTYPE html> \
<html> \
<body> \
<center><h1>Ring1</h1></center> \
<center><p1>Fight:START</p1></center> \
</body> \
</html>";

void Connect_WiFi()
{
WiFi.begin(ssid, password);
while(WiFi.status() != WL_CONNECTED)
{
delay(100);
}
}

void setup()
{
Serial.begin(115200);
pinMode(LED0, OUTPUT);
digitalWrite(LED0, LOW);
Serial.print("Setting soft access point mode");
WiFi.softAP(ssid, password, channel, max_connection);
IPAddress IP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(IP);
server.begin();
}


void loop()
{
WiFiClient client=server.available();
if(client)
{
String request = client.readStringUntil('\r');
if(request.indexOf("J1=C1") != -1){
  Serial.write("J1=C1\r\n");
}
if(request.indexOf("J1=C2") != -1){
  Serial.write("J1=C2\r\n");
}
if(request.indexOf("J2=C1") != -1) Serial.write("J2=C1\r\n");
if(request.indexOf("J2=C2") != -1) Serial.write("J2=C2\r\n");
if(request.indexOf("J3=C1") != -1) Serial.write("J3=C1\r\n");
if(request.indexOf("J3=C2") != -1) Serial.write("J3=C2\r\n");
request="";
client.print("HTTP/1.1 200 OK");
client.print(html);

bool newDevice = true;
currentIP = client.remoteIP();
for (int Device = 0; Device < NumberOfDevices; Device++) {
    if(DeviceIPadress[Device] == currentIP) newDevice = false;
  }
if(newDevice){
 DeviceIPadress[NumberOfDevices] = currentIP; 
 //Serial.print("New device: ");
 //Serial.println(DeviceIPadress[NumberOfDevices]);
 NumberOfDevices++;
}
//Serial.print("All devices:    ");
//for (int Device = 0; Device < NumberOfDevices; Device++) {
//   Serial.println(DeviceIPadress[Device]);
// }
}

int i = 0;
while(Serial.available() > 0){
    inChar = Serial.read(); // Read a character
    if(inChar == '\n'){
      sendEndOfFight[i] = '\0';  // terminate the string

      Serial.write(sendEndOfFight);
      Serial.println(sendEndOfFight);
      sendEndOfFight[0] = '\0';
      break;
      }
    sendEndOfFight[i] = inChar; // Store it
    i++; // Increment where to write next
}

if(sendEndOfFight == "FightEnd"){
  Serial.println("Hello test");
  for (int Device = 0; Device < NumberOfDevices; Device++) {
    Serial.println(DeviceIPadress[Device]);
    if (!client.connect(DeviceIPadress[Device], 80)) {
      Serial.println("Connection to host failed");
      delay(1000);
      return;
    }
  }
  digitalWrite(LED0, HIGH);//digitalWrite(LED0, HIGH);
}
else if(sendEndOfFight == "FightStart") digitalWrite(LED0, LOW);
    
}
