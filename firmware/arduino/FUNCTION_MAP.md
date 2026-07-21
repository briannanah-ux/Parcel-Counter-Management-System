# Arduino Firmware Function Map

This document describes the main functions implemented in the Arduino Mega firmware for the Smart Parcel Counter Management System.

Rather than documenting every line of code, this file explains the purpose of each function, how it contributes to the overall system and which hardware it controls.

The function names have been kept exactly as they appear in the original project to preserve the original implementation.

---

# System Entry Points

## `setup()`

### Purpose

Runs once when the Arduino is powered on. It prepares every hardware component before the system becomes available to customers.

### Responsibilities

- Initialise serial communication with the ESP8266
- Initialise the fingerprint sensor
- Configure the LCD display
- Configure relay outputs
- Initialise SPI communication
- Configure LEDs and buzzer
- Display the startup screen
- Verify communication with the fingerprint sensor

### Hardware

- Arduino Mega 2560
- LCD Display
- Fingerprint Sensor
- ESP8266
- Relay Module
- LEDs
- Buzzer

---

## `loop()`

### Purpose

The main execution loop of the firmware.

The Arduino continuously waits for customer interaction before deciding which operation should be performed.

Depending on the keypad input, the firmware either starts a new parcel storage session or authenticates a returning customer collecting their parcel.

### Responsibilities

- Send locker status to the ESP8266
- Display the main menu
- Read keypad input
- Determine locker availability
- Begin parcel registration
- Begin parcel collection

---

# Communication

## `send_data()`

### Purpose

Packages the current locker status into a JSON object and sends it to the ESP8266.

The ESP8266 then synchronises this information with Firebase so that the web application reflects the current locker status.

### Inputs

Internal locker status variables.

### Outputs

JSON message sent over SoftwareSerial.

---

# Locker Monitoring

## `check_door()`

### Purpose

Reads the locker sensors and updates the internal status variables that indicate whether each locker is occupied.

These values are later transmitted to the ESP8266 by `send_data()`.

---

# Fingerprint Authentication

## `getFingerPrint()`

### Purpose

Attempts to identify the fingerprint currently placed on the sensor.

### Process

1. Capture fingerprint image.
2. Convert image into a template.
3. Compare against stored templates.
4. Return the matching fingerprint ID.

If no valid fingerprint is detected, the function returns an error code.

---

## `getFingerprintEnroll()`

### Purpose

Registers a new customer fingerprint before a parcel is stored.

This function guides the customer through the complete enrolment process by requesting the same fingerprint twice, verifying both scans match and storing the fingerprint template inside the sensor.

Once enrolment is complete, the selected locker is unlocked so the parcel can be stored.

### Responsibilities

- Capture first fingerprint image
- Capture second fingerprint image
- Compare both scans
- Store fingerprint template
- Unlock assigned locker
- Provide user feedback using the LCD and LEDs

---

# Parcel Session Management

## `same()`

### Purpose

Completes the registration process after fingerprint enrolment.

If fingerprint registration succeeds, the selected locker is locked again, the locker status is transmitted to the ESP8266 and the customer's shopping session begins.

Although the function name is not descriptive, it effectively acts as the controller that starts a new parcel storage session.

---

## `turnOn()`

### Purpose

Controls the shopping duration timer.

The function continuously updates the remaining time, changes the LED colour to indicate how much time remains and activates the buzzer as the session approaches its limit.

If the customer returns before the timer expires, parcel collection begins immediately.

### User Feedback

- Green LED — sufficient time remaining
- Amber LED — approaching time limit
- Red LED — time expired
- Buzzer — warning before expiry

---

# Parcel Collection

## `place()`

### Purpose

Displays instructions asking the customer to place their finger on the fingerprint sensor before collecting their parcel.

This function is responsible only for updating the user interface.

---

## `colle()`

### Purpose

Authenticates a returning customer before unlocking the assigned locker.

After successful authentication, the customer retrieves their parcel and confirms completion by scanning their fingerprint again, allowing the locker to be locked before the session ends.

---

# Timer Control

## `rotatemotor1()`

### Purpose

Starts the active shopping session for Locker 1 by transferring control to the timer routine.

---

## `rotatemotor2()`

### Purpose

Starts the active shopping session for Locker 2 by transferring control to the timer routine.

---

# Overall Firmware Behaviour

At a high level, the firmware follows this sequence:

Power On

↓

Initialise Hardware

↓

Display Main Menu

↓

Customer Chooses:

• Leave Parcel
or
• Collect Parcel

↓

Fingerprint Authentication

↓

Locker Operation

↓

Shopping Session Monitoring

↓

Customer Returns

↓

Authenticate Again

↓

Lock Locker

↓

Update ESP8266

↓

Ready for Next Customer
