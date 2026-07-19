# 🚗 ESP32 Smart Parking System

An IoT-based Smart Parking System developed using the ESP32 microcontroller. This project monitors parking slot availability, controls an automatic parking gate using a servo motor, displays real-time information on an OLED display, and provides visual and audio indications using LEDs and a buzzer.

---

## 📌 Project Overview

The Smart Parking System detects the occupancy of parking slots and automatically opens or closes the parking gate based on slot availability. The system continuously updates the parking status on the OLED display and provides a professional embedded system interface.

---

## ✨ Features

- ESP32-based Smart Parking System
- Automatic Servo Gate Control
- Real-time Parking Slot Monitoring
- OLED Display Dashboard
- Parking Occupancy Percentage
- Green LED (Parking Available)
- Red LED (Parking Full)
- Buzzer Alert
- Serial Monitor Status Display
- Startup Animation
- Loading Animation
- Professional Embedded User Interface

---

## 🛠 Hardware Used

- ESP32 DevKit V1
- SSD1306 OLED Display (I2C)
- Servo Motor
- 4 Parking Slot Sensors (Simulated using Potentiometers)
- Green LED
- Red LED
- Buzzer
- 220Ω Resistors
- Jumper Wires

---

## 💻 Software Used

- Wokwi Simulator
- Arduino IDE
- ESP32 Board Package
- GitHub

---

## 📚 Libraries Used

- Adafruit SSD1306
- Adafruit GFX
- ESP32Servo
- Wire

---

## ⚙️ Working Principle

1. ESP32 continuously reads all parking slot sensors.
2. The system calculates:
   - Occupied Slots
   - Available Slots
   - Parking Usage Percentage
3. The OLED display updates automatically.
4. If parking slots are available:
   - Green LED turns ON.
   - Servo gate opens.
5. If parking is full:
   - Red LED turns ON.
   - Servo gate closes.
   - Buzzer alerts the user.
6. The Serial Monitor displays the current parking status.

---

## 📷 Project Preview

- OLED Dashboard
- Automatic Gate Control
- Parking Slot Monitoring
- LED and Buzzer Indicators
- Serial Monitor Output

---

## 🚀 Future Improvements

- RFID-based Vehicle Authentication
- Wi-Fi Monitoring using ESP32
- Blynk Mobile Dashboard
- Firebase Cloud Integration
- EEPROM Data Storage
- IR Sensor-Based Vehicle Detection
- Mobile Application
- Number Plate Recognition using ESP32-CAM

---

## 🎯 Applications

- Shopping Malls
- Office Buildings
- Apartment Parking
- College Campuses
- Smart Cities
- Hospitals
- Airports

---

## 📄 License

This project is intended for educational and learning purposes.
