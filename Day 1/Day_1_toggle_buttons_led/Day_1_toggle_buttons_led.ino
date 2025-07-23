int button_1 = 7;
int button_2 = 13;
int led_1 = 2;
int led_2 = 4;

const int on_time_1 = 200;
const int off_time_1 = 3500;
const int on_time_2 = 964;
const int off_time_2 = 549;

bool led_1_state, led_2_state, led_1_on, led_2_on;
unsigned long starttime1, starttime2, starting1, starting2;

bool can_press_1 = true, can_press_2 = true;

void setup() {
  Serial.begin(9600);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
}

void loop() {
  if (digitalRead(button_1) == LOW) {
    if (can_press_1) {
      led_1_state = !led_1_state;
      if ((led_1_state) && (led_1_on == false)) {
        led_1_on = true;
        digitalWrite(led_1, led_1_on);
      } else if ((led_1_  state == false) && (led_1_on == true)) {
        led_1_on = false;
        digitalWrite(led_1, led_1_on);
      }
      starttime1 = millis();
    }
    starting1 = millis();
    can_press_1 = false;
  } else {
    if (millis() - starting1 > 200) {
      can_press_1 = true;
    }
  }
  if (led_1_state) {
    if ((led_1_on) && (millis() - starttime1 >= on_time_1)) {
      led_1_on = false;
      digitalWrite(led_1, led_1_on);
      starttime1 = millis();
    } else if ((led_1_on == false) && (millis() - starttime1 >= off_time_1)) {
      led_1_on = true;
      digitalWrite(led_1, led_1_on);
      starttime1 = millis();
    }
  }
  if (digitalRead(button_2) == LOW) {
    if (can_press_2) {
      led_2_state = !led_2_state;
      if ((led_2_state) && (led_2_on == false)) {
        led_2_on = true;
        digitalWrite(led_2, led_2_on);
      } else if ((led_2_state == false) && (led_2_on == true)) {
        led_2_on = false;
        digitalWrite(led_2, led_2_on);
      }
      starttime2 = millis();
    }
    starting2 = millis();
    can_press_2 = false;
  } else {
    if (millis() - starting2 > 200) {
      can_press_2 = true;
    }
  }
  if (led_2_state) {
    if ((led_2_on) && (millis() - starttime2 >= on_time_2)) {
      led_2_on = false;
      digitalWrite(led_2, led_2_on);
      starttime2 = millis();
    } else if ((led_2_on == false) && (millis() - starttime2 >= off_time_2)) {
      led_2_on = true;
      digitalWrite(led_2, led_2_on);
      starttime2 = millis();
    }
  }
}
