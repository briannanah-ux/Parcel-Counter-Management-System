# Bill of Materials

## Overview

This bill of materials lists the main electronic and mechanical components used to develop the Smart Parcel Counter Management System prototype.

The quantities reflect the two-locker prototype and may need to be adjusted for a larger implementation.

## Main Components

| Component                       |    Quantity | Purpose                                                                          |
| ------------------------------- | ----------: | -------------------------------------------------------------------------------- |
| Arduino Mega                    |           1 | Main embedded controller responsible for hardware control and customer workflows |
| ESP8266 Wi-Fi module            |           1 | Provides Wi-Fi connectivity and communication with Firebase                      |
| Fingerprint sensor              |           1 | Enrols and verifies customer fingerprints                                        |
| RFID reader                     |           1 | Supports parcel session and tracking functions                                   |
| RFID cards or tags              | As required | Used with the RFID reader during system operation                                |
| Character LCD                   |           1 | Displays menu options, instructions and system messages                          |
| Matrix keypad                   |           1 | Allows customers to select storage or collection options                         |
| Relay module                    |           2 | Controls the electronic locking mechanism for each locker                        |
| Electronic lock or solenoid     |           2 | Locks and unlocks the parcel compartments                                        |
| Green LED                       |           1 | Indicates normal storage time or system status                                   |
| Amber LED                       |           1 | Indicates that the storage period is approaching expiry                          |
| Red LED                         |           1 | Indicates that the permitted storage time has expired                            |
| Buzzer                          |           1 | Provides audible notifications and warnings                                      |
| Breadboard or prototyping board |           1 | Supports temporary electronic connections during development                     |
| Jumper wires                    | As required | Connects sensors, controllers and output devices                                 |
| Resistors                       | As required | Limits current through LEDs and supports circuit connections                     |
| Power supply                    |           1 | Supplies power to the controllers and connected modules                          |
| USB cables                      |           2 | Used for programming and powering the Arduino Mega and ESP8266                   |
| Prototype locker enclosure      |           1 | Houses the two parcel compartments and electronic components                     |

## Software and Development Tools

| Tool                       | Purpose                                                        |
| -------------------------- | -------------------------------------------------------------- |
| Arduino IDE                | Firmware development and uploading                             |
| Embedded C++               | Programming language used for the Arduino and ESP8266 firmware |
| Firebase Realtime Database | Stores and synchronises parcel and locker information          |
| Serial Monitor             | Supports debugging and communication testing                   |
| Git and GitHub             | Version control and project documentation                      |

## Notes

The prototype was developed using components that were available during the project. Equivalent components may be substituted where their electrical specifications and communication requirements are compatible.

The exact fingerprint sensor, RFID reader, LCD and relay module models should be confirmed against the original hardware or project records before this document is treated as a complete procurement list.

A production version would also require additional items such as:

* Proper printed circuit boards
* Fuses and electrical protection
* Lock drivers
* Cable management
* Secure enclosures
* Emergency access mechanisms
* Environmental protection
* Mounting hardware

## Summary

The prototype combines embedded controllers, biometric and RFID sensing, electronic locking, local user feedback and cloud connectivity.

The bill of materials reflects the components needed to demonstrate the complete parcel storage and collection workflow using two lockers.
