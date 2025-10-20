#include "config.h"
#include "helpers.h"

#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SPI.h>
#include <SoftwareSerial.h>

SoftwareSerial nodemcu(NODEMCU_RX_PIN, NODEMCU_TX_PIN);
Adafruit_Fingerprint finger(&Serial1);
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

char hexaKeys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), KEYPAD_ROW_PINS, KEYPAD_COL_PINS, KEYPAD_ROWS, KEYPAD_COLS);

LockerState lockers[N_LOCKERS];
unsigned long lastBroadcast = 0;
const unsigned long BROADCAST_INTERVAL = 5000UL;

void initHardware();
void lcdPrintLine(int row, const char *msg);
bool checkFingerprintForLocker(int &uid);
int matchFingerprint();
void startLocker(int i, int uid);
void stopLocker(int i);
void sendLockerUpdate(int i);
void checkOverdue();

void setup() {
  Serial.begin(SERIAL_BAUD);
  nodemcu.begin(115200);
  Serial1.begin(57600);
  initHardware();

  for (int i = 0; i < N_LOCKERS; i++) {
    lockers[i] = {false, -1, 0, ACCESS_TIME_MS};
  }

  lcd.clear();
  lcdPrintLine(0, "Parcel Counter");
  lcdPrintLine(1, "System Ready");
  delay(1500);
  lcd.clear();

  if (finger.begin(57600)) {
    Serial.println("Fingerprint ready");
  } else {
    lcdPrintLine(0, "Fingerprint");
    lcdPrintLine(1, "Error!");
  }
}

void loop() {
  char key = customKeypad.getKey();
  if (key == 'A') {
    lcdPrintLine(0, "Place finger...");
    int uid;
    if (checkFingerprintForLocker(uid)) {
      for (int i = 0; i < N_LOCKERS; i++) {
        if (!lockers[i].occupied) {
          startLocker(i, uid);
          break;
        }
      }
    }
  } else if (key == 'B') {
    lcdPrintLine(0, "Scan to open...");
    int uid;
    if (checkFingerprintForLocker(uid)) {
      for (int i = 0; i < N_LOCKERS; i++) {
        if (lockers[i].occupied && lockers[i].userId == uid) {
          stopLocker(i);
          break;
        }
      }
    }
  }

  if (millis() - lastBroadcast > BROADCAST_INTERVAL) {
    for (int i = 0; i < N_LOCKERS; i++) sendLockerUpdate(i);
    lastBroadcast = millis();
  }

  checkOverdue();
}

void initHardware() {
  for (int i = 0; i < N_LOCKERS; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
    digitalWrite(RELAY_PINS[i], HIGH);
  }
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_AMBER_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.begin(16, 2);
}

void lcdPrintLine(int row, const char *msg) {
  lcd.setCursor(0, row);
  lcd.print("                ");
  lcd.setCursor(0, row);
  lcd.print(msg);
}

bool checkFingerprintForLocker(int &uid) {
  uid = -1;
  int id = matchFingerprint();
  if (id >= 0) {
    uid = id;
    tone(BUZZER_PIN, 1200, 150);
    return true;
  }
  return false;
}

int matchFingerprint() {
  unsigned long start = millis();
  while (millis() - start < 4000) {
    if (finger.getImage() == FINGERPRINT_OK) {
      if (finger.image2Tz() != FINGERPRINT_OK) return -1;
      int id = finger.fingerSearch();
      if (id >= 0) {
        Serial.print("Match ID: "); Serial.println(id);
        return id;
      }
    }
  }
  return -1;
}

void startLocker(int i, int uid) {
  lockers[i] = {true, uid, millis(), ACCESS_TIME_MS};
  digitalWrite(RELAY_PINS[i], LOW);
  tone(BUZZER_PIN, 800, 200);
  lcdPrintLine(0, "Locker Assigned");
  char buf[16]; sprintf(buf, "Locker %d", i);
  lcdPrintLine(1, buf);
  delay(800);
  digitalWrite(RELAY_PINS[i], HIGH);
  sendLockerUpdate(i);
}

void stopLocker(int i) {
  lockers[i] = {false, -1, 0, ACCESS_TIME_MS};
  digitalWrite(RELAY_PINS[i], LOW);
  tone(BUZZER_PIN, 600, 200);
  lcdPrintLine(0, "Locker Opened");
  delay(800);
  digitalWrite(RELAY_PINS[i], HIGH);
  sendLockerUpdate(i);
}

void checkOverdue() {
  unsigned long now = millis();
  for (int i = 0; i < N_LOCKERS; i++) {
    if (lockers[i].occupied && now - lockers[i].startAt > lockers[i].allowedMs) {
      digitalWrite(LED_AMBER_PIN, HIGH);
      tone(BUZZER_PIN, 1000, 200);
      sendLockerUpdate(i);
      delay(100);
      digitalWrite(LED_AMBER_PIN, LOW);
    }
  }
}

void sendLockerUpdate(int i) {
  String msg = createStatusJson(i, lockers[i]);
  nodemcu.println(msg);
  Serial.println(msg);
}
