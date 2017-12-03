#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

char x,y;
char a,b;

void loop() {
  //delay(1000); 
  if (Serial.available())
  {
    x=Serial.read();
    y=Serial.read();
  }
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.write(y);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  delay(500);
  Serial.println("sent data");
 // delay(2000);
  Wire.requestFrom(8,2);
  
  if (Wire.available())
  {
    a=Wire.read();
    b=Wire.read();
    Serial.println(a);
    Serial.println(b);
  }
}
