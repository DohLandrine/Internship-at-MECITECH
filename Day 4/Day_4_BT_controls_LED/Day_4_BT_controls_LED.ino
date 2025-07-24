#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const byte redLED = 25;
const byte blueLED = 23;
const byte greenLED = 22;

bool toggleRed;
bool toggleBlue;
bool toggleGreen;

void setup() {
  Serial.begin(115200);

  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  SerialBT.begin("Doh's LED");
  Serial.println("Doh's LED available to pair");
}

void loop() {
  if(SerialBT.available()){
    
    String value = SerialBT.readString();
    SerialBT.println(value);
    value.trim();
    
    if(value == "1" || value == "Green"){
       toggleGreen = !toggleGreen;
       digitalWrite(greenLED, toggleGreen);
    }
    else if(value == "2" || value == "Blue"){
       toggleBlue = !toggleBlue;
       digitalWrite(blueLED, toggleBlue);
    }
    else if(value == "3" || value == "Red"){
       toggleRed = !toggleRed;
       digitalWrite(redLED, toggleRed);
    }
    else {
       SerialBT.println("Invalid option.");
       SerialBT.println(" enter `1` or `Green` for green LED");
       SerialBT.println(" enter `2` or `Blue` for blue LED");
       SerialBT.print(" enter `3` or `Red` for red LED");
    }  
  }
}
