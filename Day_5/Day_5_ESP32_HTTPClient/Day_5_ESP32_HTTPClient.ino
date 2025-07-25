#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char *ssid = "MECITECH LTD";
const char *password = "m3c1t3ch";

const byte redPin = 22;
const byte greenPin = 23;
const byte bluePin = 26;

JsonDocument doc; 

void setup() {
  Serial.begin(115200);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Setting up WiFi
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    if(millis() == 10000UL){
        Serial.println("Error connecting to WiFi network.");
        Serial.print(WiFi.status());
        break;
    }
    Serial.print(".");
    delay(200);
  }
  if (WiFi.status() == WL_CONNECTED){
  Serial.println("Connected!");
  }
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){

    //Setting up http client
    HTTPClient http;
    
    http.begin("https://internship-at-mecitech.onrender.com/leds/led-settings");
    
    int httpResponseStatusCode = http.GET();
    
    if(httpResponseStatusCode == 200){
        Serial.println("Success");
        String payload = http.getString();
        Serial.println(payload);

        DeserializationError error = deserializeJson(doc, payload);

        if (error) {
          Serial.print("deserializeJson() failed: ");
          Serial.println(error.f_str());
          return;
        }

        JsonArray arr = doc.as<JsonArray>();
        JsonObject obj = arr[0];

        int red = obj["red"];
        int green = obj["green"];
        int blue = obj["blue"];
        
        Serial.print("Red: ");
        Serial.println(red);

        Serial.print("Green: ");
        Serial.println(green);

        Serial.print("Blue: ");
        Serial.println(blue);

        http.end();

        if(red == 0){
            digitalWrite(redPin, LOW);
        }
        else{
            digitalWrite(redPin, HIGH);
        }
 
        if(blue == 0){
            digitalWrite(bluePin, LOW);
        }
        else{
            digitalWrite(bluePin, HIGH);
        }
        
        if(green == 0){
            digitalWrite(greenPin, LOW);
        }
        else{
            digitalWrite(greenPin, HIGH);
        }
    }
  }

  delay(1000000); // To avoid spamming the server
}
