# Arduino Firmware Overview

## Overview

The Arduino Mega 2560 is the main controller of the Smart Parcel Counter Management System.

It is responsible for coordinating the embedded hardware, managing customer interactions and controlling the parcel lockers. The Arduino performs all real-time operations locally, while networking and cloud communication are delegated to a separate ESP8266 module.

Separating these responsibilities allowed the embedded controller to remain focused on deterministic hardware control without depending on an internet connection.

---

## Hardware Controlled

The Arduino interfaces with several hardware components, including:

- Fingerprint sensor
- RFID subsystem
- LCD display
- Keypad
- Relay module
- Solenoid locker mechanism
- ESP8266 serial interface

---

## Main Responsibilities

The firmware is responsible for:

- Initialising hardware peripherals
- Registering parcel storage sessions
- Authenticating returning customers
- Managing locker occupancy
- Monitoring RFID activity
- Controlling storage timers
- Updating the user interface
- Exchanging information with the ESP8266

---

## Runtime Behaviour

After power-up, the Arduino initialises all peripherals before entering its main execution loop.

During normal operation, the firmware continuously responds to customer interactions, monitors active parcel sessions and updates the communication module whenever system status changes.

The firmware therefore acts as the central controller for the entire embedded system.
