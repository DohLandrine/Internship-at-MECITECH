# Day 4 - Bluetooth-Controlled LEDs + Mini IoT Project Backend Setup

**Date:** Thursday July 26, 2025

## Tasks Done

- Successfully completed the **Bluetooth-based LED control** project using ESP32.
- Initiated a **mini IoT project** with backend and frontend components.
- Completed the **backend (Node.js + Express)** setup for the project.
- Planned to begin working on the **hardware (ESP32) implementation** the following day.

---

## 🔹 Part 1: Bluetooth-Controlled LED System

Used an ESP32's Bluetooth feature to receive commands from a phone and control three LEDs.

### Command Mapping

| Command Received  | Action Performed         |
|-------------------|--------------------------|
| `"1"` or `"Green"`| Turns on Green LED       |
| `"2"` or `"Blue"` | Turns on Blue LED        |
| `"3"` or `"Red"`  | Turns on Red LED         |

### Components Used

- ESP32  
- 3 LEDs (Red, Green, Blue)  
- 2 Resistors for Green and Blue LEDs  
- Potentiometer (for Green LED)  
- Breadboard, jumper wires  

---

## 🔹 Part 2: IoT Mini Project (Backend Development)

### Goal
Build a complete IoT system where the ESP32 connects to a Wi-Fi network, retrieves LED status data from a custom backend, and controls LEDs accordingly.

### Architecture

#### 📦 Backend (Completed Today)

- Developed using **Node.js** and **Express.js**.
- Contains:
  - A table for **Wi-Fi credentials** (SSID & password).
  - A table for **LED status control** (Red, Green, Blue states).

#### 📱 Mobile App (Planned)
- Will be built using **Kotlin**.
- Two main screens:
  1. **Wi-Fi Credential Input**
  2. **LED Status Toggler**

#### 🔌 Hardware (In Progress)
- ESP32 acts as a **Wi-Fi station**, connects to a given Wi-Fi network.
- Fetches LED state from the database and updates hardware in real-time.

### Components Used

#### Hardware
- ESP32  
- 3 LEDs (Red, Green, Blue)  
- 3 × 220Ω Resistors  
- Breadboard and jumper wires  

#### Software
- **Backend:** Node.js, Express.js  
- **Frontend App:** Kotlin (planned)  

---

## 🧠 What I Learned

- How to control GPIOs on ESP32 via Bluetooth commands.
- How to design and build a RESTful backend API using Express.js.
- The importance of separating concerns in full-stack IoT projects (backend, frontend, device logic).
- Planning and structuring real-world embedded + web + mobile systems.

---

## 🔧 Tools/Technologies Used

- ESP32
- Arduino IDE
- Bluetooth Serial Monitor App (Android)
- Node.js + Express.js (Backend)
- Kotlin (planned mobile app)
- LEDs, Resistors, Potentiometer
- Breadboard, Jumper Wires
