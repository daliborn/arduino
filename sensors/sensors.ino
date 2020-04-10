#include <dht.h>
#define dht_apin A1
dht DHT;

//Motor 1
const int in1  = 13;
const int in2  = 7; 

int speed = 180;


void setup() {
  Serial.begin(9600); 
  //Set pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {  
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


  //Motor Control A in both directions
  analogWrite(in1, speed);
  delay(2000); 
  analogWrite(in1, 0);
}
