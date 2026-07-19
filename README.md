# ESP32 Smart Parking System

## Project Overview

The ESP32 Smart Parking System is an embedded systems project designed to monitor parking slot availability and automate vehicle entry using an ESP32 microcontroller. The system continuously monitors parking occupancy, controls a servo-operated gate, displays parking information on an OLED display, and provides visual and audio alerts using LEDs and a buzzer.

---

## Features

- Real-time parking slot monitoring
- Automatic gate control using a servo motor
- OLED display for parking status
- Occupied and available slot calculation
- Parking occupancy percentage display
- Green LED indication when parking is available
- Red LED indication when parking is full
- Buzzer alert for full parking condition
- Serial Monitor output for debugging
- Startup and loading screen animations

---

## Hardware Components

- ESP32 DevKit V1
- SSD1306 OLED Display (I2C)
- Servo Motor
- Four Potentiometers (used to simulate parking sensors)
- Green LED
- Red LED
- Buzzer
- 220 Ω Resistors
- Jumper Wires

---

## Software and Tools

- Arduino IDE
- Wokwi Simulator
- ESP32 Board Package
- GitHub

---

## Libraries Used

- Adafruit SSD1306
- Adafruit GFX Library
- ESP32Servo
- Wire

---

## Working Principle

1. The ESP32 reads the status of all parking sensors.
2. The system calculates occupied and available parking slots.
3. The parking occupancy percentage is calculated.
4. Parking information is displayed on the OLED screen.
5. If parking space is available, the servo gate opens and the green LED turns on.
6. If all parking slots are occupied, the servo gate closes, the red LED turns on, and the buzzer is activated.
7. The parking status is continuously displayed on the Serial Monitor.

---

## Project Files

- sketch.ino
- diagram.json
- libraries.txt
- README.md

---

## Future Enhancements

- RFID-based vehicle authentication
- Wi-Fi monitoring using ESP32
- Blynk mobile dashboard
- Firebase cloud integration
- EEPROM data storage
- IR sensor-based vehicle detection
- ESP32-CAM number plate recognition
- Mobile application support

---

## Applications

- Shopping malls
- Apartment parking
- Office buildings
- Educational institutions
- Hospitals
- Airports
- Smart city parking systems

---

## License

This project is developed for educational and learning purposes.
