# Cloud and Dashboard Architecture

## Overview

The Smart Parcel Counter Management System extends beyond the embedded hardware by incorporating cloud connectivity and remote monitoring.

Rather than connecting the Arduino Mega directly to the internet, the system uses an ESP8266 Wi-Fi module as a communication gateway. This separates the real-time locker control logic from cloud services, allowing each controller to focus on a specific responsibility.

The cloud platform stores locker information, customer session data and system activity, enabling an administrator to monitor the parcel counters remotely.

---

## System Architecture

The communication architecture is organised into four layers.

```text
Customer
      │
      ▼
Arduino Mega
      │
Serial UART
      │
      ▼
ESP8266
      │
Wi-Fi
      │
      ▼
Firebase Realtime Database
      │
      ▼
Administrator Dashboard
```

This layered architecture separates hardware control, wireless communication and cloud services into independent components.

---

## Arduino Mega Responsibilities

The Arduino Mega manages all time-critical operations within the parcel counter.

Its responsibilities include:

* Reading the fingerprint sensor
* Detecting keypad input
* Controlling locker relays
* Updating LEDs and the LCD display
* Monitoring locker status
* Packaging locker information for transmission

The Arduino does not communicate directly with Firebase. Instead, it sends locker status information to the ESP8266 using serial communication.

---

## ESP8266 Responsibilities

The ESP8266 acts as the communication bridge between the embedded system and the cloud.

After receiving data from the Arduino, it:

* Connects to the local Wi-Fi network
* Maintains communication with Firebase
* Updates locker information
* Retrieves cloud data when required
* Processes RFID-based session information

By separating these responsibilities, the embedded controller is not burdened with internet communication.

---

## Serial Communication

Communication between the Arduino Mega and ESP8266 takes place over a UART serial connection.

The Arduino creates a JSON object containing the current locker status before transmitting it to the ESP8266.

A simplified example is shown below.

```json
{
  "door1": true,
  "door2": false
}
```

This lightweight message format makes it easy to transfer information while keeping the firmware simple.

---

## Firebase Realtime Database

Firebase serves as the central data store for the system.

The ESP8266 uploads locker information whenever the locker state changes.

Typical information stored includes:

* Locker availability
* Customer session information
* RFID status
* Timestamp information
* Device activity

Using a cloud-hosted database allows the administrator dashboard to remain synchronised with the embedded hardware.

---

## Administrator Dashboard

The dashboard provides a central interface for monitoring the parcel counters.

Information available to an administrator includes:

* Current locker occupancy
* Locker availability
* Active customer sessions
* Device communication status
* Cloud database updates

Separating monitoring from embedded control allows the system to be observed without affecting normal operation.

---

## Advantages of the Architecture

Several design benefits are achieved through this communication model.

### Separation of Responsibilities

The Arduino focuses on hardware control while the ESP8266 manages networking.

### Modular Design

Either controller can be modified independently with minimal impact on the other.

### Scalability

Additional lockers or cloud services can be incorporated without redesigning the complete embedded platform.

### Remote Monitoring

System information is available without requiring direct access to the parcel counter hardware.

---

## Security Considerations

As a prototype, the cloud implementation demonstrates the feasibility of remote monitoring rather than providing production-level security.

A commercial implementation should:

* Store credentials securely rather than embedding them in firmware.
* Encrypt communications between devices and cloud services.
* Apply role-based authentication for administrators.
* Validate all cloud requests before processing.

These improvements would strengthen the system against unauthorised access.

---

## Summary

The cloud architecture extends the parcel counter beyond a standalone embedded system by enabling remote monitoring and centralised data storage.

By assigning the Arduino Mega responsibility for hardware control and the ESP8266 responsibility for wireless communication, the design remains modular, maintainable and suitable for future expansion.
