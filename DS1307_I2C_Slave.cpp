#include <Wire.h>

byte trigger; 
byte SensorValue[4] = {125, 135, 145, 155};

void setup(){
  Wire.begin(8);
  Wire.onReceive(onReceiveEvent);
  Wire.onRequest(onRequestEvent);  
  Serial.begin(9600);
}
 
void loop(){
}
 
void onReceiveEvent(int a){
  trigger =  Wire.read();
}

void onRequestEvent(){
  if(trigger==255){
    Wire.write(SensorValue,4);
  }
}
