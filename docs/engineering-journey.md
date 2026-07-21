# Engineering Journey

The Smart Parcel Counter Management System was my final-year Electronic Engineering project.

When I first started thinking about the project, I wasn't trying to build a smart locker. I was interested in solving a problem I had noticed in busy retail environments.

Many supermarkets provide parcel counters where customers can temporarily leave bags while they shop. From what I observed, these spaces could easily become occupied by people who were no longer shopping or who simply wanted somewhere convenient to leave their belongings. That reduced the availability of storage for genuine customers.

I wanted to see whether an embedded system could make that process fairer while improving security and making the experience easier for customers.

---

## Turning an idea into a complete system

As the project developed, I realised it couldn't be solved with a single technology.

The system needed to identify customers securely, manage locker availability, monitor how long parcels had been stored, communicate with a web application and provide clear feedback to users throughout the process.

That led me to combine several technologies into one solution instead of treating them as separate projects.

The final system brought together:

- Embedded firmware
- Electronic hardware
- RFID technology
- Fingerprint authentication
- Wi-Fi communication
- Firebase
- A web-based monitoring dashboard

Looking back, integrating all of these components into a working system was probably the most challenging part of the project.

---

## What challenged me most

Most components worked well on their own.

The real challenge was making them work together reliably.

A fingerprint scan had to unlock the correct locker.

The RFID tag needed to represent the customer's active shopping session.

The countdown timer had to remain synchronised with both the LCD and the LEDs on the RFID tag.

At the same time, the ESP8266 needed to keep the web application updated without affecting the responsiveness of the Arduino.

Building those interactions taught me much more than writing individual pieces of code.

---

## Looking back

Since completing this project, I've gained more experience in software development, renewable energy systems and data analysis.

If I were building the system today, I would organise the firmware differently and improve its maintainability, but I would keep the overall architecture.

Separating hardware control from networking proved to be a good design decision and allowed each controller to focus on a specific responsibility.

---

## What this project taught me

This project changed how I think about engineering.

At the beginning, I focused on making each individual component work.

By the end, I understood that the real challenge was designing a complete system where hardware, software and user interaction all support one another.

That mindset has stayed with me and continues to influence how I approach engineering projects today.
