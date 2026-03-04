#include <Arduino.h>
#include <SoftwareSerial.h>
int drive1 = 5; 
int dir1 = 3; 
int dir2 = 4;

int drive2 = 10; 
int dir3 = 8; 
int dir4 = 9;

int xPin = A5; 
int yPin = A4; 
#include <SoftwareSerial.h>
int rxPin = 6; 
int txPin = 7; 
SoftwareSerial BT(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  pinMode(drive1, OUTPUT);
  pinMode(drive2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (BT.available()){
    int hello = BT.parseInt();
    if (hello==1){
      int leftVal = BT.parseInt();
      int rightVal = BT.parseInt(); 

      if (leftVal>0){
        analogWrite(drive1, leftVal);
        digitalWrite(dir1, HIGH);
        digitalWrite(dir2, LOW);
      }else{
        analogWrite(drive1, leftVal * -1);
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);

      }

      if (rightVal>0){
        analogWrite(drive2, rightVal);
        digitalWrite(dir3, LOW);
        digitalWrite(dir4, HIGH);
      }else{
        analogWrite(drive2, rightVal * -1);
        digitalWrite(dir3, HIGH);
        digitalWrite(dir4, LOW);
      }
      

    }
  }
}