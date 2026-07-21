# Arduino Firmware Architecture

## Purpose

The Arduino Mega 2560 acts as the primary embedded controller for the Smart Parcel Counter Management System.

Its responsibilities include:

- Managing parcel registration
- Controlling locker access
- Reading fingerprint data
- Monitoring RFID activity
- Updating the LCD
- Managing active storage sessions
- Communicating with the ESP8266

The firmware is designed so that all real-time hardware decisions are made locally by the Arduino. Networking responsibilities are delegated to the ESP8266, which synchronises data with Firebase and the web management system.
