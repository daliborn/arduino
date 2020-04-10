#include <dht.h>
#define dht_apin A1
dht DHT;

const int in1  = 13;
int speed = 180;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
}

void loop() {  
  readData();
  readCommand();
}

void readCommand() {
    if (Serial.available() > 0) {
        char receivedChar = Serial.read();
        startMotor();
    }
}

void readData() {
  int val;  
  val = analogRead(0); //connect sensor to Analog 0   
  Serial.print(val); //print the value to serial port   
  Serial.print(",");
  DHT.read11(dht_apin);
  Serial.print(DHT.humidity);
  Serial.print(",");
  Serial.print(DHT.temperature);
  Serial.println("");
  delay(1000);
}

//run motor for 15 seconds on one side and stop it
void startMotor(){
  analogWrite(in1, speed);
  delay(15000); 
  analogWrite(in1, 0);
 }
