# Reflections and Future Improvements

Developing the Smart Parcel Counter Management System was one of the most rewarding parts of my Electronic Engineering degree. It gave me the opportunity to combine embedded programming, electronics, networking and software development into a single system that solved a real operational problem.

Looking back after gaining more experience, there are several areas where I would improve the design if I were developing a second iteration today.

---

## 1. Improve the Firmware Structure

The original firmware was written with functionality as the primary goal. As the project grew, more features were added to a single Arduino sketch, making it harder to navigate.

If I revisited the project, I would separate the firmware into modules such as:

- Authentication
- Locker Control
- RFID Tracking
- User Interface
- Communication
- Timer Management

This would improve readability and make future maintenance easier without changing the overall behaviour of the system.

---

## 2. Replace Blocking Delays

The project uses several `delay()` calls to control timing.

For this prototype, the delays simplified the implementation and made the behaviour predictable while developing and testing the hardware.

For a production system, I would replace these with a non-blocking timing approach using `millis()` or a scheduler so that multiple tasks could run concurrently without reducing system responsiveness.

---

## 3. Introduce a Finite State Machine

The firmware naturally follows a sequence of states:

- Waiting for customer
- Parcel registration
- Fingerprint enrolment
- Shopping session
- Parcel collection
- Session complete

Although this behaviour is implemented successfully, I would now represent it explicitly using a finite state machine.

This would make the firmware easier to understand, test and extend.

---

## 4. Improve Function Naming

Some function names, such as `same()` and `colle()`, reflected my focus on getting the system working rather than making the code easy for others to understand.

If I were writing the project today, I would use more descriptive names that clearly communicate each function's purpose while preserving the underlying logic.

---

## 5. Separate Configuration

Many hardware pin assignments and configuration values are defined directly within the source file.

A dedicated configuration file would make the firmware easier to maintain and simplify hardware changes.

---

## 6. Improve Error Handling

The prototype provides user feedback through the LCD, LEDs and buzzer.

A future version could include more detailed diagnostic messages and structured error reporting to simplify troubleshooting during deployment and maintenance.

---

## 7. PCB Integration

The project was developed using development boards to allow rapid prototyping and testing.

If this system were developed as a commercial product, I would design a custom PCB integrating the Arduino functionality, power regulation and peripheral interfaces into a single board to improve reliability and reduce wiring complexity.

---

## 8. Secure Communication

Communication between the Arduino and ESP8266 was sufficient for demonstrating the concept.

For a production deployment, I would introduce message validation and stronger security mechanisms to improve the reliability of communication with cloud services.

---

## Final Reflection

Although there are many aspects I would refine today, I would not fundamentally change the overall system architecture.

Separating the embedded controller from the networking module proved to be an effective design decision. The Arduino remained responsible for time-critical hardware control, while the ESP8266 handled communication with Firebase and the web application.

Looking back, this project taught me that designing an embedded system is about much more than writing code. It requires balancing hardware, software and user interaction to create a reliable system that solves a practical problem. That experience has continued to influence how I approach engineering projects today.
