# 🛒 Smart Trolley System (RFID-Based)

## 📌 Introduction

The Smart Trolley System is an IoT-based project designed to modernize the shopping experience in supermarkets. Traditional billing systems require customers to wait in long queues for checkout. This project eliminates that delay by enabling real-time billing directly on the shopping trolley using RFID technology.

Each product is equipped with an RFID tag, and the trolley contains an RFID reader connected to an Arduino Uno. When a product is scanned, the system automatically detects it and updates the total bill, which is displayed on an OLED screen.

---

## 🎯 Objectives

* To reduce long billing queues in shopping malls
* To provide real-time bill calculation inside the trolley
* To enhance customer convenience and experience
* To implement a budget monitoring system
* To minimize human errors in billing

---

## ⚙️ System Architecture

The system consists of both hardware and software components working together:

### 🔹 Hardware Components

* **Arduino UNO** – Main controller that processes all operations
* **MFRC522 RFID Module** – Reads RFID tags attached to products
* **OLED Display (SSD1306)** – Displays item status and total bill
* **Push Buttons (3)** – Used for user interaction
* **LEDs (3)** – Provide visual feedback
* **Buzzer** – Provides audio indication
* **Breadboard & Jumper Wires** – For circuit connections

### 🔹 Software Components

* Arduino IDE
* Embedded C/C++ code
* Libraries:

  * SPI.h
  * MFRC522.h
  * Wire.h
  * Adafruit_GFX.h
  * Adafruit_SSD1306.h

---

## 🔘 Functional Description

### 📦 1. Item Scanning (RFID)

* When a user places a product near the RFID reader
* The RFID module reads the unique UID of the tag
* The Arduino processes the UID and adds the item price to total
* OLED displays: *Item Added + Total Amount*
* LED (Add) glows and buzzer beeps

---

### ➖ 2. Remove Item Button

* Pressing the **Remove Button** subtracts the item price
* OLED updates the new total
* Remove LED glows

---

### 💰 3. Budget Button

* Displays current total amount
* If total exceeds predefined budget:

  * OLED shows **"Budget Exceeded"**
  * Buzzer alerts the user

---

### 🧾 4. Final / Clear Button

* Displays the final bill
* Final LED glows
* Can also be used to reset the total amount (based on implementation)

---

## 🔄 Workflow

1. System starts and initializes components
2. User scans an item using RFID
3. Item price is added to total
4. OLED updates the display
5. User can:

   * Remove item
   * Check budget
   * Generate final bill
6. System provides LED and buzzer feedback

---

## 💡 LED Indications

* **LED 1 (Add)** → Item added
* **LED 2 (Remove)** → Item removed
* **LED 3 (Final)** → Final bill displayed

---

## 🔔 Buzzer Indications

* Short beep → Item scanned
* Long beep → Budget exceeded

---

## 📺 Display Output (OLED)

* Item status (Added/Removed)
* Total amount
* Budget warning
* Final bill

---

## 🚀 Advantages

* Saves time by reducing checkout queues
* Provides real-time billing
* Easy to use and user-friendly
* Helps customers manage their budget
* Reduces human errors

---

## ⚠️ Limitations

* Requires RFID tagging for all products
* Limited scanning range (~3–5 cm)
* No database integration in basic version
* Cannot identify items without UID mapping

---

## 🔮 Future Enhancements

* Integration with mobile application
* Online payment (UPI / QR Code)
* Cloud-based product database
* WiFi module (NodeMCU/ESP8266) for real-time sync
* Auto item recognition with barcode/QR scanner
* AI-based recommendation system

---

## 🧪 Testing & Results

* RFID successfully detects tags and updates total
* Buttons work for remove, budget check, and final bill
* OLED displays correct output
* LEDs and buzzer provide proper indications

---

## 📚 Conclusion

The Smart Trolley System is an efficient and innovative solution for modern retail environments. It simplifies the billing process, enhances user experience, and demonstrates the practical application of IoT in everyday life.

---

## 🧑‍💻 Developed By

* Your Name
* Course / College Name

---
