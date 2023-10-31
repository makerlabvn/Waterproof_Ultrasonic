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


#define echoPin 3 // attach pin D3 Arduino to pin Echo of JSN-SR04T
#define trigPin 2 //attach pin D2 Arduino to pin Trig of JSN-SR04T

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baud rate speed
  Serial.println("Ultrasonic Sensor AJ-SR04M Mode 2 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);  //
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 1500 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1500);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");// working  code for aj-sr04m
}