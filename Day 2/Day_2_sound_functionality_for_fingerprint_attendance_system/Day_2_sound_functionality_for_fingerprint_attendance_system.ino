const byte buzzerPin = 9;
unsigned long prev;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  printMenu();
}

void loop() {
//  if(millis() - prev >= 200UL){
//    playRemoveFinger();
//    prev = millis();
//    }
  //playError(200UL);
  if (Serial.available()) {
    int option = Serial.parseInt();
    Serial.print("Selected Option: ");
    Serial.println(option);
    handleOption(option);
    printMenu();
  }
}


// utility
void playTone(int freq, int duration) {
  tone(buzzerPin, freq, duration);
  delay(duration);
  noTone(buzzerPin);
  delay(30);
}

// GOOD
void playConnected() {
  playTone(784, 90);    
  delay(70);      
  playTone(1047, 170); 
}

// GOOD
void playDisconnected() {
   playTone(1047, 90);  
  delay(70);         
  playTone(784, 170);   
}

// GOOD
void playLowBattery() {
  for (int i = 0; i < 3; i++) {
    playTone(392, 180);  
    delay(45);
  }
}

// GOOD
void playAlertToPowerOff() {
  for (int i = 0; i < 2; i++) {
    playTone(784, 200); 
    delay(100);
    playTone(659, 200);  
    delay(100);
  }
}

// GOOD
void playTurnedOn() {
  playTone(659, 300);  
  playTone(784, 150);  
  playTone(1047, 200); 
}


//GOOD
void playPowerOff() {
  playTone(1047, 200); 
  playTone(784, 150);  
  playTone(659, 300);  
}

// GOOD
void playError(unsigned long howLong) {
  if (millis() - prev >= howLong){
  playTone(300, 100);
  prev = millis();
  noTone(buzzerPin);
  }
}


// GOOD
void playNoMatch() {
  playTone(392, 150);  
  delay(100);
  playTone(330, 150);  
}

// GOOD
void playWelcomeAccepted() {
playTone(523, 100); 
  playTone(659, 100); 
  playTone(784, 200); 
}

// GOOD
void playGoodbyeAccepted() {
  playTone(784, 100);
  playTone(659, 100); 
  playTone(523, 200); 
}

void playRemoveFinger(unsigned long howLong) {
  playTone(784, 90); 
  delay(50);
  playTone(659, 120);
}

void playPlaceFinger(unsigned long howLong) {
  playTone(659, 140);  
  delay(50);
  playTone(784, 120);  
}


void printMenu() {
  Serial.println("\n🎵 SOUND TEST MENU 🎵");
  Serial.println("1  - Connected");
  Serial.println("2  - Disconnected");
  Serial.println("3  - Welcome Accepted");
  Serial.println("4  - Goodbye Accepted");
  Serial.println("5  - Turned On");
  Serial.println("6  - Power Off");
  Serial.println("7  - No Match");
  Serial.println("8  - Low Battery");
  Serial.println("9  - Error");
  Serial.println("10 - Alert to Power Off");
  Serial.print("Enter your choice: ");
}


void handleOption(int option) {
  switch (option) {
    case 1: playConnected(); break;
    case 2: playDisconnected(); break;
    case 3: playWelcomeAccepted(); break;
    case 4: playGoodbyeAccepted(); break;
    case 5: playTurnedOn(); break;
    case 6: playPowerOff(); break;
    case 7: playNoMatch(); break;
    case 8: playLowBattery(); break;
    case 9: playError(200UL); break;
    case 10: playAlertToPowerOff(); break;
    case 11: playPlaceFinger(); break;
    case 12: playRemoveFinger(); break;
    default:
      Serial.println("❌ Invalid choice. Try again.");
      break;
  }
}
