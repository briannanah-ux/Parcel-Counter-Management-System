# Arduino Firmware Function Map

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
