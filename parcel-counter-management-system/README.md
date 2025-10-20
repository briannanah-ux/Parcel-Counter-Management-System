# 📦 Parcel Counter Management System
**An IoT-based locker system integrating Arduino, NodeMCU, and Firebase for secure parcel management**

A 3-locker **smart parcel management prototype** developed as my final-year BEng (Hons) Electronic Engineering project at NUST.  
It automates the process of storing and collecting parcels using **fingerprint authentication, RFID tags, GPS and IoT connectivity** via Arduino Mega and NodeMCU.  
The system tracks locker usage in real time, records data to **Firebase**, and displays locker status on a simple web dashboard.

---

## 🚀 Features
- **Automated locker control:** Each locker door uses a 12 V solenoid lock controlled by the Arduino.
- **Biometric & RFID access:** Fingerprint and RFID card authentication for secure access.
- **LCD + Keypad interface:** For user interaction and locker selection.
- **LED indicators & buzzer:** Visual and audible feedback for system events.
- **IoT connectivity:** NodeMCU (ESP8266) uploads locker data to Firebase.
- **Web dashboard:** Real-time locker monitoring and historical usage logs.

---

## 🧩 System Architecture

| Component | Function |
|------------|-----------|
| **Arduino Mega** | Handles fingerprint, keypad, LCD, solenoid locks |
| **NodeMCU (ESP8266)** | Manages Wi-Fi and Firebase communication |
| **Firebase** | Cloud database for status and logs |
| **Web App** | Front-end dashboard and logs viewer |
| **Hardware** | 3 wooden lockers, solenoid locks, LEDs, LCD, keypad |

---

## 🛠️ Hardware Used
| Module | Description |
|---------|-------------|
| Arduino Mega 2560 | Main controller |
| NodeMCU ESP8266 | IoT communication |
| AS608 Fingerprint Sensor | Biometric access |
| RC522 RFID Reader | Card authentication |
| 16×2 LCD Display | Status messages |
| 4×4 Matrix Keypad | User input |
| 12 V Solenoid Locks | Locker actuation |
| Relay Module | Controls locks |
| LEDs & Buzzer | Indicators |
| GPS Modules | Tracking & alerts |

---

## 🌐 Web Dashboard
The dashboard connects to Firebase and updates locker status live.

- 🟩 **Green:** Available  
- 🟥 **Red:** Occupied  
- 📋 **Logs:** Timestamped locker entries and user IDs  

📸 Example screenshots are in `docs/demo_pictures/`.

---



