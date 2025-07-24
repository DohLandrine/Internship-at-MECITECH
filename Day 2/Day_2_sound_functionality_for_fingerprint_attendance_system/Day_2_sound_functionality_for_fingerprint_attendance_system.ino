const byte buzzerPin = 25;

void setup() {
    Serial.begin(115200);
//  delay(10);
    ledcAttach(buzzerPin, 2000, 8);
    printMenu();
}

void loop() {
   //playConnected();
  if (Serial.available()) {
    int option = Serial.parseInt();
    Serial.print("Selected Option: ");
    Serial.println(option);
    handleOption(option);
    printMenu();
  }

  delay(20);
}


// utility
void playTone(int freq, int duration) {
  ledcWriteTone(buzzerPin, freq);
  delay(duration);
  ledcWriteTone(buzzerPin, 0);
  delay(30);
}

void playConnected() {
  playTone(3136, 90);
  delay(70);
  playTone(4186, 170);
}

void playDisconnected() {
  playTone(4186, 90);
  delay(70);
  playTone(3136, 170);
}

void playLowBattery() {
  for (int i = 0; i < 3; i++) {
    playTone(4000, 180);
    delay(45);
  }
}

void playAlertToPowerOff() {
  for (int i = 0; i < 2; i++) {
    playTone(3136, 200);
    delay(100);
    playTone(2636, 200);
    delay(100);
  }
}

void playTurnedOn() {
  playTone(2636, 300);
  playTone(1568, 150);
  playTone(2093, 200);
}

void playPowerOff() {
  playTone(4186, 200);
  playTone(3136, 150);
  playTone(2636, 300);
}

void playError() {
  playTone(4500, 600);
  noTone(buzzerPin);
}

void playNoMatch() {
  playTone(1568, 150);
  delay(100);
  playTone(1320, 150);
}

void playWelcomeAccepted() {
  playTone(2094, 100);
  playTone(2636, 100);
  playTone(3136, 200);
}

void playGoodbyeAccepted() {
  playTone(3136, 100);
  playTone(2636, 100);
  playTone(2094, 200);
}

void playRemoveFinger() {
  playTone(3136, 90);
  delay(50);
  playTone(2636, 120);
}

void playPlaceFinger() {
  playTone(2636, 140);
  delay(50);
  playTone(3136, 120);
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
  Serial.println("11 - Place Finger");
  Serial.println("12 - Remove Finger");
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
    case 9: playError(); break;
    case 10: playAlertToPowerOff(); break;
    case 11: playPlaceFinger(); break;
    case 12: playRemoveFinger(); break;
    default:
      Serial.println("❌ Invalid choice. Try again.");
      break;
  }
}
