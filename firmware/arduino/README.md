# Arduino Mega Firmware

## Overview

This firmware controls the Smart Parcel Counter Management System.

The Arduino Mega is responsible for:

* Customer interaction through the keypad and LCD
* Fingerprint enrolment and verification
* Locker control using relay modules
* LED and buzzer status indication
* Timer management
* Communication with the ESP8266

The firmware communicates with the ESP8266 over a UART serial connection. The ESP8266 manages all Wi-Fi and Firebase communication, allowing the Arduino Mega to focus on real-time hardware control.

## Main Functions

* System initialisation
* Parcel storage workflow
* Parcel collection workflow
* Fingerprint management
* Locker state monitoring
* Serial communication

Refer to **`docs/04-firmware-architecture.md`** for a detailed explanation of the firmware design and execution flow.
