#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("C'est moi Doh");
  Serial.println("Bluetooth is ready to pair");

}

void loop() {
  if(SerialBT.available()){
     String incoming = SerialBT.readString();
     Serial.println("> " + incoming);
   }
}
