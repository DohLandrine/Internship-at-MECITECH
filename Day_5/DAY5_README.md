# Day 5 - ESP32 Web Server + Completion of IoT Mini Project

**Date:** Friday July 25, 2025

## Tasks Done

- Completed the **hardware implementation** of the IoT mini project (LEDs + ESP32).
- Implemented an ESP32-based **web server** that serves two endpoints to control LEDs remotely.
- Integrated and tested the full **software-hardware flow**.
- Successfully controlled LEDs by sending HTTP requests with query parameters.
- Explored and understood how ESP32 can act as a Wi-Fi access point and HTTP server.

---

## 🔹 ESP32 Web Server Functionality

Built a simple ESP32 server to control LEDs through HTTP endpoints.

### Endpoints

- **`/`** — Root endpoint, serves the HTML interface.
- **`/toggle?led=color`** — Toggles a specific LED (`red`, `blue`, or `green`) based on the query parameter.

### Example Usage

- Accessing `http://<esp32_ip>/toggle?led=green` toggles the Green LED.
- Similarly for Blue and Red.

### Logic Flow

1. ESP32 starts Wi-Fi and HTTP server.
2. Waits for client requests.
3. Parses query parameters from the `/toggle` endpoint.
4. Toggles the appropriate LED.

---

## 🔹 Mini Project Milestone Achieved

 **Backend (Day 4)**: Complete  
 **Frontend + Hardware (Today)**: Complete

The entire IoT mini project — comprising a **Node.js backend**, **Kotlin mobile frontend (planned)**, and **ESP32 hardware control** — is now fully functional on the hardware side.

---

## what I Learned

- How to create and deploy a simple **HTTP server on ESP32**.
- Handling **query parameters** in URLs to control GPIOs dynamically.
- Completed the full development cycle from **server logic to physical hardware control**.
- Gained experience in building real-world embedded web interfaces.

---

## Tools/Technologies Used

- ESP32
- Arduino IDE
- Wi-Fi-based Web Server
- HTML + Query Parameters
- LEDs (Red, Green, Blue)
- 3 × 220Ω Resistors
- Breadboard & Jumper Wires
- Node.js + Express.js (backend from Day 4)
