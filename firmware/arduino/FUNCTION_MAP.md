# Arduino Firmware Function Map

| Function            | Purpose               | Called From |
| ------------------- | --------------------- | ----------- |
| setup()             | Initialise system     | Boot        |
| loop()              | Main firmware loop    | Runtime     |
| verifyFingerprint() | Authenticate customer | loop()      |
| updateTimer()       | Countdown management  | loop()      |
| readRFID()          | Read RFID activity    | loop()      |


This document describes the responsibilities of each major function in the Arduino firmware.

The descriptions are based on the original implementation submitted as part of my final-year Electronic Engineering project. The aim is to explain the firmware structure without changing the original design.

---

## setup()

**Purpose**

Runs once when the Arduino powers on.

**Responsibilities**

- Configure serial communication
- Initialise LCD
- Initialise fingerprint sensor
- Initialise RFID reader
- Configure relay outputs
- Prepare communication with the ESP8266
- Display initial system status

---

## loop()

**Purpose**

Main firmware execution loop.

**Responsibilities**

- Wait for customer interaction
- Process registrations
- Update countdown timer
- Monitor RFID activity
- Verify returning customers
- Control locker access
- Send status updates to the ESP8266

## verifyFingerprint()

### Purpose

Authenticates the customer before a locker is opened.

### Inputs

Fingerprint image from the AS608 sensor.

### Outputs

- Success or failure result.
- Unlock request if authentication succeeds.

### Called By

loop()

### Related Hardware

- AS608 Fingerprint Sensor
- Relay Module
- Solenoid Lock
