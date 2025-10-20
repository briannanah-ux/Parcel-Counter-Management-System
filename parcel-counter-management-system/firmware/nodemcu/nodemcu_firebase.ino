#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <ArduinoJson.h>

#define WIFI_SSID "WIFI_NAME"
#define WIFI_PASS "WIFI_PASSWORD"
#define FIREBASE_HOST "project.firebaseio.com"
#define FIREBASE_AUTH "FIREBASE_DATABASE_SECRET"

#define LED_CONN   D4
#define LED_ERROR  D3
#define LED_TX     D2

FirebaseData fbdo;
FirebaseJson json;

void connectWiFi();
void handleIncomingJson(const String &line);
void blink(int pin, int durationMs);

void setup() {
  Serial.begin(115200);
  pinMode(LED_CONN, OUTPUT);
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_TX, OUTPUT);

  connectWiFi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  digitalWrite(LED_CONN, HIGH);
  Serial.println("\nNodeMCU ready — listening for Arduino data...");
}

void loop() {
  if (Serial.available()) {
    String payload = Serial.readStringUntil('\n');
    payload.trim();
    if (payload.length() > 0) handleIncomingJson(payload);
  }
  delay(10);
}

void connectWiFi() {
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected!");
    Serial.print("IP: "); Serial.println(WiFi.localIP());
    digitalWrite(LED_CONN, HIGH);
  } else {
    Serial.println("\nWi-Fi failed.");
    digitalWrite(LED_ERROR, HIGH);
  }
}

void handleIncomingJson(const String &line) {
  StaticJsonDocument<256> doc;
  if (deserializeJson(doc, line)) return;

  int locker = doc["locker"] | -1;
  bool occupied = doc["occupied"] | false;
  int userId = doc["userId"] | -1;
  unsigned long startAt = doc["startAt"] | 0;
  unsigned long allowedMs = doc["allowedMs"] | 0;
  unsigned long ts = doc["ts"] | 0;

  if (locker < 0 || locker > 2) return;

  String pathLocker = "/lockers/locker" + String(locker);
  String pathLog = "/attendance/locker" + String(locker) + "/entry_" + String(ts);

  FirebaseJson lockerJson;
  lockerJson.set("occupied", occupied);
  lockerJson.set("userId", userId);
  lockerJson.set("startAt", startAt);
  lockerJson.set("allowedMs", allowedMs);
  lockerJson.set("timestamp", ts);

  if (Firebase.setJSON(fbdo, pathLocker, lockerJson)) blink(LED_TX, 50);
  Firebase.setJSON(fbdo, pathLog, lockerJson);
}

void blink(int pin, int durationMs) {
  digitalWrite(pin, HIGH);
  delay(durationMs);
  digitalWrite(pin, LOW);
}
