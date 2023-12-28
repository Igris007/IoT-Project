// #include <SoftwareSerial.h>
// #define DEBUG true

// int moistureValue=100;

// SoftwareSerial esp8266(3,2);
void setup() {
  // Serial.begin(9600);
  // esp8266.begin(115200);

  // sendData("AT\r\n", 1000, DEBUG);
  // sendData("AT+RST\r\n",2000,DEBUG);
  // sendData("AT+CWJAP=\"Galaxy A51 3092\",\"agyy3416\"\r\n", 6000, DEBUG);
  // sendData("AT+CWMODE=1\r\n",1000,DEBUG);
  // sendData("AT+CIFSR\r\n",2000,DEBUG);
  // sendData("AT+CIPMUX=1\r\n",1000,DEBUG);
  // sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG);
}

void loop() {
  // String cipSend = "AT+CIPSEND=0,";
  // String data = "<html><head><title>ESP8266 Moisture Test</title></head><body>";
  // data += "<p>Moisture: " + String(moistureValue) + "</p>";
  // data += "</body></html>";
  // cipSend += data.length();
  // cipSend += "\r\n";
  // sendData(cipSend, 500, DEBUG);
  // sendData(data, 500, DEBUG);
  // String closeCommand = "AT+CIPCLOSE=0\r\n"; 
  // sendData(closeCommand,500,DEBUG);
  // delay(5000);
}

// void sendData(String command, const int timeout, boolean debug)
// {
//     esp8266.print(command);
//     long int time = millis();

//     while( (time+timeout) > millis())
//     {
//       while(esp8266.available())
//       {
//         Serial.write(esp8266.read());
//       }  
//     }
// }
