#include <Servo.h>

Servo myservo;
int servoPin = 9;
int moisturePin = A0;
int moisturePowerPin = 2;
int moistureThreshold = 1000;
int moistureCheckInterval = 15000;
bool flagRaised = false;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(moisturePowerPin, OUTPUT);
  digitalWrite(moisturePowerPin, LOW);
}

void loop() {
  int moistureLevel = readMoisture();
  
  if ((moistureLevel > moistureThreshold) && !(flagRaised)) {
    rotateServoSlowly();
    flagRaised = true;
  } else if ((moistureLevel < moistureThreshold) && (flagRaised)){
    stopServo();
    flagRaised = false;
  }

  delay(moistureCheckInterval);
}

int readMoisture() {
  digitalWrite(moisturePowerPin, HIGH);
  delay(100);
  int moistureValue = analogRead(moisturePin);
  digitalWrite(moisturePowerPin, LOW);
  Serial.println(moistureValue);
  return moistureValue;
}

void rotateServoSlowly() {
  myservo.write(180);
  delay(150);
  myservo.write(90);
}

void stopServo() {
  myservo.write(0);
  delay(150);
  myservo.write(90);
}
