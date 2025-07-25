#include <WiFi.h>
#include <WebServer.h>

const String ssid = "ESP32 DOH";
const char* password = "3venWhenIamJ0stplay1ngAr0und";

const byte redLed = 22;
const byte greenLed = 23;
const byte blueLed = 26;

bool redState = false;
bool blueState = false;
bool greenState = false;

WebServer server(80); // 1st objective.

void handleRoot(){
  String html = "<!DOCTYPE html><html><head><title><ESP 32 as Server></title></head>";  
  html = html + "<body><h1>ESP32 sever Led Control</h1>";
  html = html + "<p><a href=\"/toggle?led=red\"><button>Toggle RED</button></a></p>";
  html = html + "<p><a href=\"/toggle?led=green\"><button>Toggle GREEN</button></a></p>";
  html = html + "<p><a href=\"/toggle?led=blue\"><button>Toggle BLUE</button></a></p>";

  server.send(200, "text/html", html); // here
}

void handleToggle(){
  if (server.hasArg("led")){
    String led = server.arg("led");

    if(led == "red"){
      redState = !redState;
      digitalWrite(redLed, redState);  
    }
    else if(led == "blue"){
      blueState = !blueState;
      digitalWrite(blueLed, blueState);  
    }
    else if(led == "green"){
      greenState = !greenState;
      digitalWrite(greenLed, greenState);  
    }
  }
  server.sendHeader("Location", "/"); 
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  WiFi.softAP(ssid, password); // 2nd objective.
  Serial.println("Access Point Started");
  Serial.print("IP Address");
  Serial.println(WiFi.softAPIP()); // 3rd objective.

  server.on("/", handleRoot); // 4th objective. like app.post("/",handleRoot)
  server.on("/toggle", handleToggle);

  server.begin(); // 5th and last objective.
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

}
