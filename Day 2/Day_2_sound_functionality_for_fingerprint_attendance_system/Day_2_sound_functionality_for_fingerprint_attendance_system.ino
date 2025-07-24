const byte buzzerPin = 9;
unsigned long prev;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  printMenu();
}

void loop() {
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

void playConnected() {
  playTone(1568, 90);
  delay(70);
  playTone(2093, 170);
}

void playDisconnected() {
  playTone(2093, 90);
  delay(70);
  playTone(1568, 170);
}

void playLowBattery() {
  for (int i = 0; i < 3; i++) {
    playTone(4000, 180);
    delay(45);
  }
}

void playAlertToPowerOff() {
  for (int i = 0; i < 2; i++) {
    playTone(1568, 200);
    delay(100);
    playTone(1318, 200);
    delay(100);
  }
}

void playTurnedOn() {
  playTone(1318, 300);
  playTone(1568, 150);
  playTone(2093, 200);
}

void playPowerOff() {
  playTone(2093, 200);
  playTone(1568, 150);
  playTone(1318, 300);
}

void playError() {
  playTone(4500, 600);
  noTone(buzzerPin);
}

void playNoMatch() {
  playTone(784, 150);
  delay(100);
  playTone(660, 150);
}

void playWelcomeAccepted() {
  playTone(1047, 100);
  playTone(1318, 100);
  playTone(1568, 200);
}

void playGoodbyeAccepted() {
  playTone(1568, 100);
  playTone(1318, 100);
  playTone(1047, 200);
}

void playRemoveFinger() {
  playTone(1568, 90);
  delay(50);
  playTone(1318, 120);
}

void playPlaceFinger() {
  playTone(1318, 140);
  delay(50);
  playTone(1568, 120);
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
