/*
[link]: https://hshop.vn/products/cam-bien-sieu-am-chong-nuoc-ultrasonic-jsn-sr04t

Echo(Tx)----3 (uno)
Trig(Rx)----2 (uno)

*/

#include "Waterproof_Ultrasonic.h"

Waterproof_Ultrasonic Waterproof_Ultrasonic(2,3,1);          // Mode 1: 
// Waterproof_Ultrasonic Waterproof_Ultrasonic(2,3,3);       // Mode 3: get data when we need (The best mode to get data)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MakerLab.vn test Waterproof Ultrasonic");
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Testing with Mode " + Waterproof_Ultrasonic.getMode() + ",with R27 = " + Waterproof_Ultrasonic.getR27() + "\tvalue: ");
  Serial.println(Waterproof_Ultrasonic.ping_cm());
  delay(100);
}