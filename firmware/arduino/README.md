# Arduino Firmware

The Arduino Mega 2560 is the primary controller for the Smart Parcel Counter Management System.

It is responsible for coordinating all real-time hardware interactions, including user registration, fingerprint authentication, RFID monitoring, timer management, LCD updates and locker control.

Networking is intentionally handled by a separate ESP8266 module, allowing the Arduino to focus solely on embedded control and deterministic behaviour.

## Responsibilities

- Initialise hardware peripherals
- Register customer sessions
- Authenticate returning users
- Monitor RFID activity
- Control locker relays
- Manage storage timers
- Exchange data with the ESP8266
