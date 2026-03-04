#include <Arduino.h>
#include <SoftwareSerial.h>
int xPin = A5; 
int yPin = A4; 
SoftwareSerial BT(6, 7); // BT RX, BT TX  (Arduino reads on 7, writes on 6)

void setup() {
  Serial.begin(9600)    ;// Serial Monitor
  BT.begin(9600);        // HC-05 AT baud (try 9600 if needed)
  Serial.println("Bridge ready");
  pinMode(12, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  int yVal = analogRead(yPin);
  int xVal = analogRead(xPin);
  xVal-=512;
  yVal-=512;
  int q = yVal; 
  yVal = xVal * -1; 
  xVal = q * -1;

  int left = map(xVal + yVal, -1024, 1024, -128, 128); 
  int right = map(yVal - xVal, -1024, 1024, -128, 128);
  left = -1 * left; 
  right = -1 * right;
  if (abs(left)<20){left = 0;}
  if (abs(right)<20){right = 0;}
  Serial.print("x ");
  Serial.println(xVal);
  Serial.print("y ");
  Serial.println(yVal);
  /*
  Serial.print("left ");
  Serial.println(left);
  Serial.print("right ");
  Serial.println(right);
  delay(2000);*/

  BT.println(1);
  BT.println(left);
  BT.println(right);
  /*if (BT.available()){
    int x = BT.parseInt(); 
    for (int i = 0; i<x; i++){
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);}

    while (BT.available()){
      BT.read();
    }
  }*/
}
