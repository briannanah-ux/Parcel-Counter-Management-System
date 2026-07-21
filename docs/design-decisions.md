# Design Decisions

This document explains some of the key engineering decisions made during the development of the Smart Parcel Counter Management System.

Rather than focusing on implementation details, it describes why particular hardware and software components were selected and the trade-offs considered during development.

---

# Why Arduino Mega 2560?

The Arduino Mega 2560 was selected because the system required a large number of digital input/output pins and multiple serial interfaces.

The project combines several peripherals, including:

- Fingerprint sensor
- RFID subsystem
- LCD display
- Keypad
- Relay module
- ESP8266 communication
- LEDs and buzzer

Using an Arduino Uno would have significantly limited the available I/O and serial communication options. The Mega provided enough resources to integrate all peripherals without additional hardware.

---

# Why Separate the ESP8266?

One of the earliest design decisions was to separate hardware control from network communication.

The Arduino Mega is responsible for:

- Reading sensors
- Controlling the lockers
- Managing user interaction
- Running the parcel storage workflow

The ESP8266 is responsible for:

- Wi-Fi connectivity
- Firebase communication
- Updating the web application

This separation means that the embedded controller can continue operating even if network communication is temporarily unavailable.

Looking back, this was one of the strongest architectural decisions in the project because it clearly separates real-time control from cloud services.

---

# Why Fingerprint Authentication?

The fingerprint sensor was chosen to ensure that parcels could only be collected by the person who originally stored them.

Unlike passwords or PIN codes, fingerprints cannot easily be forgotten or shared.

Using biometric authentication also simplified the collection process, as customers did not need to remember any additional information.

---

# Why RFID Tracking?

RFID serves a different purpose from the fingerprint sensor.

Once a customer stores a parcel, an RFID tag is issued to represent their active storage session.

The tag allows the system to:

- Monitor whether the customer remains within the intended shopping area
- Display the remaining shopping time using the LEDs attached to the RFID tag
- Detect when the customer returns the tag after collecting their parcel
- Update the web application with the current session status

Separating RFID tracking from fingerprint authentication allowed each technology to solve a specific problem instead of overloading one device with multiple responsibilities.

---

# Why a Countdown Timer?

The system was designed primarily for supermarkets and retail stores where parcel storage is intended for customers who are actively shopping.

To encourage fair use, each parcel session is limited to a predefined duration.

The timer:

- Starts automatically after registration
- Updates the LCD display
- Synchronises with the LEDs on the RFID tag
- Warns customers as the session approaches expiry
- Helps prevent lockers from being occupied for extended periods

This improves locker availability for genuine shoppers.

---

# Why Firebase?

Firebase was selected because it provides a simple way to synchronise information between the embedded system and the web application in real time.

This allowed locker status and customer activity to be viewed remotely without implementing a custom server.

For a university project, Firebase offered an effective balance between functionality and development effort.

---

# Why JSON Communication?

The Arduino and ESP8266 exchange information using JSON messages over serial communication.

Using JSON provides a structured format that is easy to parse and extend as additional information is added to the system.

Although lightweight alternatives exist, JSON simplified debugging during development because the transmitted messages were human-readable.

---

# Prototype Considerations

This project was developed as a working prototype rather than a commercial product.

Several design choices were made to support rapid development and testing, including:

- Using development boards instead of a custom PCB
- Implementing the firmware as a single Arduino sketch
- Using jumper-wire connections during hardware integration

These decisions allowed the focus to remain on validating the overall concept and demonstrating the complete workflow.

---

# Looking Back

If I were developing a second iteration today, I would keep the overall system architecture but improve the maintainability of the firmware by introducing modular source files, clearer function naming and a formal finite state machine.

Despite those improvements, I still believe the original separation between embedded control, RFID tracking and cloud communication was the right architectural choice for this project.
