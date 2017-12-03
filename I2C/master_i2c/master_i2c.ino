#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

char x = 'a';
int c;

void loop() {
  //delay(1000); 
  Wire.beginTransmission(1); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
  Serial.println("sent data");
 // delay(2000);
  Wire.requestFrom(1,1);
  while(Wire.available())
  {
    c=Wire.read();
    
     Serial.print("load cell: ");
     Serial.println(c);
    
  }
}
