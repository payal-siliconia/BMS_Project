# BMS_Project
Battery Management System (BMS) using STM32 microcontroller and BQ76907 for voltage monitoring, protection, and safety management.
STM32-Based Battery Management System Using BQ76907
# STM32-Based Battery Management System (BMS) Using BQ76907

This repository contains the firmware for a Battery Management System (BMS) implemented using an STM32 microcontroller and the Texas Instruments BQ76907 battery monitor IC. The project focuses on safe battery monitoring, protection, and communication with a host PC using USB CDC (Virtual COM Port).

---

## 🔋 Project Overview

A Battery Management System (BMS) is a critical component in lithium-ion battery packs.  
This project monitors battery parameters such as cell voltage and fault conditions using the BQ76907 IC and communicates data to a PC via USB.

---

## 🧰 Hardware Used

- **Microcontroller:** STM32 (STM32CubeIDE compatible)
- **Battery Monitor IC:** TI BQ76907
- **Battery Type:** Lithium-ion (configurable)
- **Communication Interfaces:**
  - I2C (STM32 ↔ BQ76907)
  - USB CDC (STM32 ↔ PC)

---

## 💻 Software & Tools

- **IDE:** STM32CubeIDE
- **Configuration Tool:** STM32CubeMX
- **HAL Drivers:** STM32 HAL Library
- **USB Stack:** STM32 USB Device Library (CDC Class)
- **Version Control:** Git & GitHub

---

## 📁 Project Structure
STM32-BMS-BQ76907/
│
├── Core/
│ ├── Inc/
│ │ ├── main.h
│ │ └── bq76907.h
│ │
│ └── Src/
│ ├── main.c
│ └── bq76907.c
│
├── USB_DEVICE/
│ ├── App/
│ │ ├── usbd_cdc_if.c
│ │ └── usbd_cdc_if.h
│ │
│ └── Target/
│ ├── usbd_conf.c
│ └── usbd_desc.c
│
├── Drivers/
│ └── STM32_HAL/
│
├── Middlewares/
│ └── STM32_USB_Device_Library/
│
├── README.md
└── .gitignore
