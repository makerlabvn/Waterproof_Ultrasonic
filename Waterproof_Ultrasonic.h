#ifndef _Waterproof_Ultrasonic_h_
#define _Waterproof_Ultrasonic_h_

#include "arduino.h"

#define db_sa(...)        { Serial.println(__VA_ARGS__); }
#define db_sa_t(...)      {Serial.print(__VA_ARGS__);Serial.print("\t");}
#define db_sa(...)
#define db_sa_t(...)

#include "SoftwareSerial.h"

class Waterproof_Ultrasonic{
  public:
    Waterproof_Ultrasonic(uint8_t _Trig_RX_, uint8_t _Echo_TX_, uint8_t _mode_ = 1);
    float ping_cm();
    void begin();
    float readMode_1();
	  String getMode(){return String(mode);}
	  String getR27(){
		if(mode == 1) return "Empty";
		else if(mode == 2) return "47K";
		else if(mode == 3) return "120K";
	}
		
  private:
    unsigned long lastTime;
    uint8_t trigRX;
    uint8_t echoTX;
    uint8_t mode;
    int value_mm;
    float lastvalue_mm;
    
    const uint8_t numReadings = 4;
    int readings[4];      // the readings from the Serial
    int readIndex = 0;              // the index of the current reading
    int total = 0;                  // the running total
    
    SoftwareSerial * sieuam = 0;
    
    bool readSieuAm_available3(){
      bool temStatus = false;
      if(!sieuam)this->begin();
      while(sieuam->available()){
        readings[3] = readings[2];
        readings[2] = readings[1];
        readings[1] = readings[0];
        // read from the serial:
        readings[0] = sieuam->read();
        
        db_sa_t(readings[3], HEX);
        db_sa_t(readings[2], HEX);
        db_sa_t(readings[1], HEX);
        db_sa_t(readings[0], HEX);
        
        if(readings[3] == 0xff){
          int sum = readings[3] + readings[1] + readings[2];
          if((uint8_t)sum == readings[0]){
            value_mm = (readings[2] << 8) + readings[1];
            lastvalue_mm = value_mm;
            
            temStatus = true;
          }
        }
       }
        
      return temStatus;
    }
};

/*
Waterproof_Ultrasonic_basic.ino
*/

// /*
// [link]: https://hshop.vn/products/cam-bien-sieu-am-chong-nuoc-ultrasonic-jsn-sr04t

// Wiring:
//   Echo(Tx)----3 (uno)
//   Trig(Rx)----2 (uno)

// Add Resistor to Hardware
//   Mode 1: R float (No value)
//   Mode 3: R = 120K

// */

// #include "Waterproof_Ultrasonic.h"

// Waterproof_Ultrasonic Waterproof_Ultrasonic(2,3,1);          // Mode 1: 
// // Waterproof_Ultrasonic Waterproof_Ultrasonic(2,3,3);       // Mode 3: get data when we need (The best mode to get data)

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   Serial.println("MakerLab.vn tests Waterproof Ultrasonic");
// }

// void loop() {
//   // put your main code here, to run repeatedly:

//   Serial.print("Testing with Mode " + Waterproof_Ultrasonic.getMode() + ",with R = " + Waterproof_Ultrasonic.getR27() + "\tvalue: ");
//   Serial.println(Waterproof_Ultrasonic.ping_cm());
//   delay(100);
// }
#endif
