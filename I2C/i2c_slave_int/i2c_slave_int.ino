#include <Wire.h>
byte x,y;
int a,b;
void setup() 
{
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent);
  Serial.begin(9600);           // start serial for output
}

void loop() {
  if (Serial.available())
  {
    x=Serial.parseInt();
    y=Serial.parseInt();
  }
  delay(100);
}


void receiveEvent(int count)
{
  if (Wire.available())
  {
    a=Wire.read();
     b=Wire.read();
  }
    Serial.println(a);
    Serial.println(b);
    
}
  //Wire.beginTransmission(1);
void requestEvent() {
  Wire.write(x);
  Wire.write(y);
  //Wire.endTransmission();
  Serial.println("data sent to master");
}
