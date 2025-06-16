# 🔌 Smart Meter using ESP8266

This project demonstrates how to convert a traditional analog electricity meter into a digital smart meter using an **ESP8266** microcontroller and an **LDR (Light Dependent Resistor)** module.

---

## 📘 Description   

The smart meter system detects LED blinks or dial movement on analog meters using an LDR sensor. These readings are then processed and transmitted by the ESP8266 microcontroller, allowing users to monitor their energy consumption digitally.

---

## 🔧 Hardware Used 
        
- ESP8266 (NodeMCU or similar)
- LDR (Light Dependent Resistor)
- Resistors (e.g., 10kΩ)
- Analog energy meter (with blinking LED or rotating disk)
- Breadboard and jumper wires
- Optional: Wi-Fi access point for real-time data logging

---

## 🧠 How It Works

1. The **LDR sensor** is placed in front of the blinking LED or dial of an analog electricity meter.
2. Every time the LED blinks (or the dial passes the sensor), it indicates a fixed energy unit (e.g., 1 Wh).
3. The ESP8266 reads this change in light intensity through its ADC (analog pin).
4. It counts the blinks and calculates energy consumption in real time.
5. The data can optionally be sent over Wi-Fi for remote monitoring.

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/3idhun/Smart-Meter-using-ESP-8266.git
cd Smart-Meter-using-ESP-8266


