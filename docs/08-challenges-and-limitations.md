# Challenges and Limitations

## Overview

The Smart Parcel Counter Management System successfully demonstrated the core functionality of biometric parcel storage and retrieval with cloud connectivity. As with most engineering prototypes, however, several design limitations were identified during development and testing.

Recognising these limitations is an important part of the engineering process, as it provides a foundation for future improvements and highlights the trade-offs made during prototype development.

---

# Limited Number of Lockers

The current prototype supports two lockers.

This was sufficient to demonstrate the complete workflow of parcel storage, fingerprint enrolment, timer management and parcel collection while keeping the prototype manageable.

However, expanding the system to support a larger number of lockers would require modifications to the firmware, as several operations are implemented specifically for Locker 1 and Locker 2.

A more scalable approach would represent lockers as data structures that can be managed using loops rather than individual sections of code.

---

# Blocking Program Execution

The firmware uses blocking functions, including delays, during certain operations such as timing and user interaction.

Although this simplifies program logic, it prevents the controller from performing multiple tasks simultaneously.

In a larger system, blocking delays could reduce responsiveness or delay processing of other events.

Future versions should adopt a non-blocking timing approach using `millis()` or a real-time operating system (RTOS) where appropriate.

---

# Monolithic Firmware Structure

The firmware is implemented as a single Arduino sketch containing all major functions.

While this structure is appropriate for a prototype, maintaining a single source file becomes increasingly difficult as additional functionality is introduced.

Separating the firmware into modules such as:

* Fingerprint management
* Locker control
* Display management
* Communication
* Timer management

would improve readability, maintainability and software reuse.

---

# Communication Reliability

Communication between the Arduino Mega and ESP8266 is performed using serial data transmission.

The current implementation assumes that transmitted messages are received successfully.

If communication were interrupted, there is no acknowledgement or retry mechanism to confirm successful data transfer.

A more robust communication protocol would include:

* Message validation
* Checksums
* Acknowledgement messages
* Automatic retransmission after communication failures

---

# Cloud Dependency

Remote monitoring depends on an active Wi-Fi connection and successful communication with Firebase.

Although local locker operation continues independently, cloud updates may be delayed or unavailable if network connectivity is lost.

Future versions could temporarily store updates locally and synchronise them automatically once network connectivity is restored.

---

# Credential Management

The prototype firmware contains network configuration and cloud credentials within the source code.

While acceptable during development, this approach is not appropriate for production systems because sensitive information could be exposed.

Future implementations should:

* Store credentials securely.
* Separate configuration from application code.
* Use secure authentication methods.
* Rotate access credentials when required.

---

# Limited Error Recovery

The prototype performs basic error handling for hardware initialisation and user interaction.

However, recovery from unexpected events remains limited.

Examples include:

* Communication interruptions.
* Unexpected power loss.
* Corrupted fingerprint data.
* Sensor disconnection.

More comprehensive diagnostic and recovery procedures would improve long-term reliability.

---

# User Interface Constraints

The character LCD provides clear and reliable feedback but is limited in the amount of information that can be displayed simultaneously.

As the system grows in complexity, presenting additional information may become challenging.

Future systems could use:

* Graphical LCD displays
* TFT touch screens
* Mobile applications
* Web-based user interfaces

depending on deployment requirements.

---

# Security Considerations

Fingerprint authentication provides secure user identification within the prototype, but a production system would require additional security measures.

Potential enhancements include:

* Encrypted communication between devices.
* Secure cloud authentication.
* Administrator access control.
* Comprehensive audit logging.
* Protection against unauthorised firmware modification.

These measures would improve resilience against malicious access while supporting commercial deployment.

---

# Hardware Scalability

The prototype demonstrates the feasibility of an automated parcel counter but was designed for proof-of-concept rather than large-scale deployment.

Supporting dozens of lockers would require consideration of:

* Power distribution.
* Wiring complexity.
* Distributed controllers.
* Network architecture.
* Fault tolerance.
* Maintenance procedures.

Addressing these factors would enable deployment in larger parcel collection facilities.

---

# Lessons from Development

Several important observations were made during development.

Separating hardware control from cloud communication simplified debugging and reduced software complexity.

Using modular functions improved code organisation despite the firmware being contained within a single sketch.

Incremental testing of individual hardware components before full integration reduced the likelihood of difficult-to-diagnose system failures.

Finally, developing the prototype reinforced the importance of considering maintainability and scalability alongside functional requirements during embedded system design.

---

# Summary

The identified limitations do not diminish the success of the prototype. Instead, they reflect the practical constraints of developing an engineering proof of concept.

By evaluating these challenges, the project establishes a clear path for future refinement and demonstrates an understanding of the engineering considerations required when transitioning from a prototype to a production-ready smart parcel management system.
