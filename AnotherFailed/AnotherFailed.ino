#include <SoftwareSerial.h>
#include  <Wire.h>

String apiKey = "H9Z3VMZ40X4QJ2EC";

#define SSID = "Galaxy A51 3092"
#define password = "agyy5416"

SoftwareSerial SoftSer(11,10);
const int moisturePower = 13;
const int moistureSignal = A0;

void setup() {
  pinMode(moisturePower, OUTPUT);
  pinMode(moistureSignal, INPUT);
  Serial.begin(9600);
  SoftSer.begin(115200);
}

void loop() {
  SoftSer.print("AT+CWJAP=\"Galaxy A51 3092\",\"agyy5416\"\r\n");
  delay(6000);
  digitalWrite(moisturePower, HIGH);
  delay(150);
  float moistureSignalValue = analogRead(moistureSignal);
  delay(100);
  // Turn off the moisture sensor to save power
  digitalWrite(moisturePower, LOW);

  char buf[16];
  String strMoisture = dtostrf(moistureSignalValue, 4, 1, buf);

  Serial.print(strMoisture);

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149";
  cmd+= "\",80\r\n";

  SoftSer.print(cmd);

  if (SoftSer.find("Error")){
    Serial.println("AT+CIPSTART Error");
    return;
  }

  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr += "&field1=";
  getStr += String(strMoisture);
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=0,";
  cmd += String(getStr.length());
  SoftSer.println(cmd);

  if (SoftSer.find(">")) 
  {
    SoftSer.print(getStr);
  }
  else 
  {
    SoftSer.println("AT+CIPCLOSE=0");
    
    Serial.println("AT+CIPCLOSE");
  }
  SoftSer.println("AT+RST");
  
  delay(15000);
}
