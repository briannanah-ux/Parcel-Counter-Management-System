# ESP8266 Firmware

## Overview

The ESP8266 firmware provides wireless connectivity between the embedded system and Firebase Realtime Database.

Its primary responsibilities include:

* Connecting to the local Wi-Fi network
* Receiving serial data from the Arduino Mega
* Updating Firebase with locker status information
* Maintaining communication with the cloud platform

Separating networking from the main embedded controller reduces firmware complexity and keeps real-time hardware control independent of cloud communication.

For more information, see **`docs/05-cloud-and-dashboard.md`**.
