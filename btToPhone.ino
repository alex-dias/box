#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bluetooth(0, 1); //TX, RX (Bluetooth)
  
const int ledPin1 = 4;
const int ledPin2 = 13;
const int sensor1 = A1;
const int sensor2 = A2;
int incomingByte;
int sensorValue;
int sensorValue2;

void setup() {
  //Initialize the software serial
  bluetooth.begin(9600);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensor1);
  sensorValue2 = analogRead(sensor2);
  
  if(analogRead(sensor1) < 150){
    digitalWrite(ledPin1, HIGH);
    
    bluetooth.print("Led Vermelho (");
    bluetooth.print(sensorValue);
    bluetooth.println(")");
    delay(200);
  }
  if(analogRead(sensor1) > 150){
    digitalWrite(ledPin1, LOW);
    
    bluetooth.print("Led Vermelho (");
    bluetooth.print(sensorValue);
    bluetooth.println(")");
    delay(200);
  }

  if(analogRead(sensor2) < 150){
    digitalWrite(ledPin2, HIGH);

    bluetooth.print("Led Verde (");
    bluetooth.print(sensorValue2);
    bluetooth.println(")");
    delay(200);
  }
  
  if(analogRead(sensor2) > 150){
    digitalWrite(ledPin2, LOW);
    
    bluetooth.print("Led Verde (");
    bluetooth.print(sensorValue2);
    bluetooth.println(")");
    delay(200);
  }
}


