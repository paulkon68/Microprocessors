#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
int trigger_now;
int trigger_before = -1;

byte trigger =255;
byte value;
void setup () {
  Wire.begin();
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}
void loop () {
  DateTime now = rtc.now();
  trigger_now = now.second();

  if((trigger_now % 5 == 0) && (trigger_before%5 != trigger_now%5)){
    Wire.beginTransmission(8);
    Wire.write(trigger);
    delay(10);
    
    Wire.requestFrom(8, 4);
    for(int i = 0; i<=3; i++){
      value = Wire.read();
      Serial.println(value);   
    }
   Wire.endTransmission();      
  }  
  trigger_before = trigger_now;
}
