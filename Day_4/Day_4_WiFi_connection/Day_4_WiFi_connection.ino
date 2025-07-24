#include <WiFi.h>

const char *ssid = "Tecno Spark 7";
const char *password = "UareD0m2tinkIamDatD0m";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() !=  WL_CONNECTED){
    delay(400);
    Serial.print(".");  
  }

  Serial.print("Connected!");
}

void loop() {
  // Nothing here, Just learning how to connect an esp32 to the internet.
}
