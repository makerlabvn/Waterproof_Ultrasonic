/* -------------------------------------------------------------------------- */
/*                                Link Product                                */
/* -------------------------------------------------------------------------- */
/**
 * Link Tutorial:
 *    https://tutorials.probots.co.in/communicating-with-a-waterproof-ultrasonic-sensor-aj-sr04m-jsn-sr04t/#the-aj-sr04m-has-5-working-modes
 * 
 * Link Product:
 *    https://hshop.vn/products/cam-bien-sieu-am-chong-nuoc-ultrasonic-jsn-sr04t
 * 
 */


#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3

SoftwareSerial jsnSerial(rxPin, txPin);

void setup() {
  jsnSerial.begin(9600);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baud rate speed
  Serial.println("Ultrasonic Sensor AJ-SR04M Mode 3 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  /*jsnSerial.write(0x01);
    delay(10);*/
  if(jsnSerial.available()){
    getDistance();
  }
}

void getDistance(){
  unsigned int distance;
  byte startByte, h_data, l_data, sum = 0;
  byte buf[3];
  
  startByte = (byte)jsnSerial.read();
  if(startByte ==255){
    jsnSerial.readBytes(buf, 3);
    h_data = buf[0];
    l_data = buf[1];
    sum = buf[2];
    distance = (h_data<<8) + l_data;
    if((( h_data + l_data)) != sum){
      Serial.println("Invalid result");
    }
    else{
      Serial.print("Distance [mm]: "); 
      Serial.println(distance);
      
    } 
  } 
  
  else return;
  delay(100);
}