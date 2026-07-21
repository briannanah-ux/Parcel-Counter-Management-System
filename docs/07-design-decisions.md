# Design Decisions

## Overview

The Smart Parcel Counter Management System was designed as an embedded Internet of Things (IoT) prototype that combines biometric authentication, automated locker control and cloud connectivity.

Throughout the project, design decisions were made to balance functionality, implementation complexity, hardware availability and future scalability. This chapter explains the rationale behind the principal hardware and software choices.

---

# Choosing the Arduino Mega

The Arduino Mega was selected as the primary controller because the prototype required a large number of input and output connections.

The system interfaces with multiple peripherals simultaneously, including:

* Fingerprint sensor
* ESP8266 Wi-Fi module
* Keypad
* LCD display
* Relay modules
* LEDs
* Buzzer

The Arduino Mega provides a greater number of digital I/O pins and multiple hardware serial interfaces compared with smaller Arduino boards. This simplified hardware integration and allowed dedicated serial communication channels for external devices.

---

# Separating Hardware Control and Cloud Communication

Rather than connecting the main controller directly to the internet, the project uses an ESP8266 as a dedicated communication module.

This separation offers several advantages:

* Hardware control remains independent of network connectivity.
* Wireless communication can be developed separately from embedded control.
* Network failures do not interfere with the core locker management logic.
* Each controller performs a clearly defined role.

This modular architecture also simplifies future upgrades, as either controller can be replaced with minimal impact on the other.

---

# Fingerprint Authentication

Fingerprint recognition was selected as the primary authentication method because it provides a convenient and secure means of identifying users without requiring physical keys or passwords.

Compared with traditional authentication methods, biometric identification:

* Eliminates the need to remember PINs.
* Reduces the risk of lost or duplicated keys.
* Associates each parcel with a unique customer.
* Simplifies the collection process.

For a parcel storage system intended for public use, fingerprint authentication provides a practical balance between usability and security.

---

# RFID Integration

RFID technology was incorporated to support parcel management and customer sessions within the prototype.

Rather than replacing biometric authentication, RFID complements the overall system by assisting with identification and system tracking.

Separating authentication from session management reduces complexity while maintaining flexibility for future development.

---

# Relay-Controlled Lockers

Electromechanical relays were selected to simulate electronically controlled locker doors.

Relays provide electrical isolation between the low-voltage control electronics and higher-power locking mechanisms, making them suitable for prototype development.

This approach also allows alternative locking hardware to be incorporated in future revisions without requiring significant changes to the firmware.

---

# LCD User Interface

A character LCD was chosen to provide immediate feedback to users throughout the storage and collection process.

Typical information displayed includes:

* Welcome messages
* Menu options
* Authentication prompts
* Locker allocation
* Error messages
* Collection instructions

A character LCD provides a simple, reliable and low-cost interface that is well suited to embedded applications.

---

# Visual Status Indicators

Green, amber and red LEDs were incorporated to provide an intuitive visual indication of locker status and storage time.

Using colour-coded indicators enables customers to determine the current system state without reading detailed messages.

This approach improves usability while reducing dependence on the LCD display.

---

# Audible Notifications

A buzzer was included to attract the customer's attention when action is required.

Audible alerts complement the visual indicators and improve accessibility by notifying users of important events such as storage time warnings or required interactions.

---

# Firebase Realtime Database

Firebase was selected as the cloud platform because it provides a straightforward method of synchronising data between embedded devices and remote applications.

Its real-time update capability enables locker information to be viewed remotely without requiring a dedicated server or custom communication infrastructure.

For an engineering prototype, Firebase provided an effective platform for demonstrating cloud connectivity while minimising backend development effort.

---

# Modular Software Structure

The firmware was organised around dedicated functions that perform individual responsibilities such as fingerprint enrolment, locker control and communication.

Although implemented within a single Arduino sketch, separating functionality into reusable functions improved readability and simplified debugging throughout development.

This modular approach also supports future refactoring into multiple source files if the project is expanded.

---

# Simplicity Over Complexity

As an engineering prototype, the project prioritised reliability and demonstrable functionality over advanced software architecture.

Where appropriate, straightforward implementation techniques were selected to reduce development complexity and facilitate testing.

Examples include:

* Direct function-based program flow.
* Serial communication between controllers.
* Fixed locker allocation.
* Character-based LCD interface.

These decisions allowed development effort to focus on validating the core concept of the system.

---

# Design Trade-offs

Every engineering decision involves balancing competing requirements.

| Design Choice                | Benefit                                        | Trade-off                                                          |
| ---------------------------- | ---------------------------------------------- | ------------------------------------------------------------------ |
| Arduino Mega                 | Large number of I/O pins and serial interfaces | Larger physical footprint than smaller boards                      |
| ESP8266 communication module | Modular cloud connectivity                     | Requires coordination between two controllers                      |
| Fingerprint authentication   | Secure and convenient user identification      | Additional hardware and enrolment process required                 |
| Firebase Realtime Database   | Rapid cloud integration with real-time updates | Dependency on internet connectivity                                |
| Relay-controlled lockers     | Simple interface to electronic locks           | Mechanical relays switch more slowly than solid-state alternatives |
| Character LCD                | Low-cost and reliable user interface           | Limited display resolution compared with graphical displays        |

Understanding these trade-offs was an important aspect of the system design process.

---

# Summary

The design decisions made throughout this project were guided by the objectives of creating a reliable, modular and functional smart parcel counter prototype.

By separating embedded control from cloud communication, combining biometric authentication with remote monitoring and adopting a modular hardware architecture, the system demonstrates the principles of embedded systems engineering while providing a clear foundation for future enhancement.
