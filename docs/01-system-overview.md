# System Overview

## Introduction

The Smart Parcel Counter Management System is an embedded Internet of Things (IoT) prototype developed as my final-year project for the BEng (Hons) in Electronic Engineering.

The project investigates how embedded systems can improve temporary parcel storage in retail environments by combining biometric authentication, RFID session tracking, electronic locker control and cloud-based monitoring into a single integrated solution.

Rather than focusing on a single technology, the project demonstrates how multiple hardware and software components can be integrated into a complete embedded system.

---

## Motivation

The idea for the project came from observing how temporary parcel counters could be misused in busy retail environments.

Lockers intended for customers while they shopped could remain occupied for extended periods, reducing availability for genuine users and making the service difficult to manage efficiently.

The objective was to investigate whether an embedded system could automate parcel management while improving security, fairness and visibility for both customers and administrators.

---

## Project Objectives

The project was designed around five primary objectives.

| Objective | Description |
|-----------|-------------|
| Secure parcel collection | Ensure that only the registered customer can retrieve their parcel. |
| Improve locker availability | Reduce unnecessary occupation of parcel lockers. |
| Automate locker management | Minimise manual supervision through embedded control. |
| Enable remote monitoring | Synchronise locker information with a cloud dashboard. |
| Improve customer experience | Provide simple step-by-step interaction using embedded hardware. |

---

## Scope

The project focuses on demonstrating a working embedded prototype rather than developing a commercial parcel locker product.

Included within the project scope are:

- Embedded hardware integration
- Firmware development
- Electronic locker control
- Fingerprint authentication
- RFID session management
- Cloud communication using Firebase
- Browser-based monitoring dashboard

The project does not include commercial features such as payment processing, large-scale locker deployment or mobile applications.

---

## Technology Stack

| Layer | Technology |
|--------|------------|
| Embedded Controller | Arduino Mega 2560 |
| Networking | ESP8266 |
| Cloud Platform | Firebase Realtime Database |
| Programming Languages | C++, HTML, CSS, JavaScript |
| Authentication | Fingerprint Sensor |
| Session Management | RFID |
| User Interface | LCD Display, Keypad, LEDs, Buzzer |

---

## Engineering Outcomes

This project provided practical experience in:

- Embedded systems development
- Hardware integration
- Microcontroller programming
- Internet of Things (IoT)
- Cloud-connected embedded systems
- Firmware architecture
- Human-centred embedded design
- Technical documentation

---

## Related Documentation

For more detailed information, see:

- 02-system-architecture.md
- 03-hardware-design.md
- 04-firmware-architecture.md
- 05-cloud-communication.md
