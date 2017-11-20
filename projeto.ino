#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bluetooth(0, 1); //TX, RX (Bluetooth)
  
const int ledPin1 = 7;
const int ledPin2 = 6;

const int sensor1 = A1;
const int sensor2 = A2;

const int buzzer = 2;

int incomingByte;
int sensorValue;
int sensorValue2;

int vetorDePecas[10] = {};
int contador = 1;

void setup() {
  //Initialize the software serial
  bluetooth.begin(9600);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);


}

void loop() {
  sensorValue = analogRead(sensor1);
  sensorValue2 = analogRead(sensor2);
  
  if((sensorValue < 150) && (sensorValue2 < 150) && (vetorDePecas[(contador - 1)] == 0)){
    vetorDePecas[contador] = 1;

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    
    bluetooth.println("Frente");
    bluetooth.println(vetorDePecas[contador]);
    bluetooth.println(contador);
    delay(200);

    contador ++;
  }

  if((sensorValue < 150) && (sensorValue2 > 150) && (vetorDePecas[(contador - 1)] == 0)){
    vetorDePecas[contador] = 2;

    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    
    bluetooth.println("Esquerda");
    bluetooth.println(vetorDePecas[contador]);
    bluetooth.println(contador);
    delay(200);
    
    contador ++;
  }

  if((sensorValue > 150) && (sensorValue2 < 150) && (vetorDePecas[(contador - 1)] == 0)){
    vetorDePecas[contador] = 3;

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    
    bluetooth.println("Direita");
    bluetooth.println(vetorDePecas[contador]);
    bluetooth.println(contador);
    delay(200);
    
    contador ++;
  }

  if((sensorValue > 150) && (sensorValue2 > 150) && (vetorDePecas[(contador - 1)] != 0)){
    vetorDePecas[contador] = 0;

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    
    bluetooth.println("Vazio");
    bluetooth.println(vetorDePecas[contador]);
    bluetooth.println(contador);
    delay(200);

    contador ++;
  }

  /*

  if(contador == 30){
    for(int i = 0; i<30; i++){
      if(vetorDePecas[i] == 1){
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        delay(1000);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        delay(100);
      }
      if(vetorDePecas[i] == 2){
        digitalWrite(ledPin1, HIGH);
        delay(1000);
        digitalWrite(ledPin1, LOW);
        delay(100);
      }
      if(vetorDePecas[i] == 3){
        digitalWrite(ledPin2, HIGH);
        delay(1000);
        digitalWrite(ledPin2, LOW);
        delay(100);
      }
    }

    contador = 1;
  }

  */

}

void piscaLed(int nomePorta, int tempo){
  digitalWrite(nomePorta, HIGH);
  delay(tempo);
  digitalWrite(nomePorta, LOW);
  delay(tempo);
}

void beep(int nomePorta, int frequencia, int tempo){
  tone(nomePorta, frequencia); 
  delay(tempo);       
  noTone(nomePorta);     
  delay(tempo);        
}



