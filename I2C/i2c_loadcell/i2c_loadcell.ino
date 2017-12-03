/* FOR 40KG
 * E+ RED
 * E- WHITE
 * A- GREEN
 * A+ BLUE 
 * circuits4you.com
 * 2016 November 25
 * Load Cell HX711 Module Interface with Arduino to measure weight in Kgs
 Arduino 
 pin 
 2 -> HX711 CLK
 3 -> DOUT
 5V -> VCC
 GND -> GND

 Most any pin on the Arduino Uno will be compatible with DOUT/CLK.
 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.
*/

#include "HX711.h"  //You must have this library in your arduino library folder
#include <Wire.h>
byte x,y;
float a,b;
#define DOUT  A0
#define CLK  A1

HX711 scale(DOUT, CLK);

//Change this calibration factor as per your load cell once it is found you many need to vary it in thousands
float calibration_factor = -96650; //-106600 worked for my 40Kg max scale setup 

//=============================================================================================
//                         SETUP
//=============================================================================================
void setup() {
  Serial.begin(9600);
  scale.set_scale(calibration_factor);
  scale.tare(); //Reset the scale to 0
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent);
}

//=============================================================================================
//                         LOOP
//=============================================================================================
void loop() {
  
  float w=scale.get_units();
  int wt=int(w);
  x=wt;
  y=wt*10;
  Serial.println(wt,3);
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
//=============================================================================================
