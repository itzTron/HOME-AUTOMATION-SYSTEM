# HOME-AUTOMATION-SYSTEM

*COMPANY* : CODTECH IT SOLUTIONS
*NAME* : TANMOY NASKAR
INTERN ID : CT04DR1389
*DOMAIN* : INTERNET OF THINGS
*DURATION* : 4 WEEKS
*MENTOR* : NEELA SANTOSH

🏠 Smart Home Automation System (ESP32 Web Server)
==================================================

📖 Overview
-----------

This project is an **IoT-based Home Automation prototype** that allows users to control multiple home appliances (Lights, Fans) via a web interface hosted directly on an **ESP32 microcontroller**.

Unlike cloud-based solutions (like Blynk or MQTT), this project uses a **Local Web Server** approach. The ESP32 acts as the server, hosting a responsive HTML dashboard that can be accessed from any device (Smartphone, Laptop, Tablet) connected to the same WiFi network.

This repository includes code designed to run seamlessly on the **Wokwi IoT Simulator**.

✨ Features
----------

*   **Web-Based Control:** Control devices using a simple HTML dashboard.
    
*   **Multi-Device Support:** Configured to control 4 distinct devices (simulated as LEDs).
    
*   **Status Feedback:** The web button changes color (Green/Red) to indicate the ON/OFF state of the device.
    
*   **No Cloud Dependency:** Runs entirely on the local network (LAN) for lower latency and privacy.
    
*   **Cross-Platform:** Works on any device with a web browser.
    

🛠️ Tech Stack
--------------

*   **Microcontroller:** ESP32 DevKit V1
    
*   **Programming Language:** C++ (Arduino Framework)
    
*   **Web Technologies:** HTML5, CSS3 embedded in C++
    
*   **Libraries:** WiFi.h, WebServer.h
    
*   **Simulation:** Wokwi.com
    

🔌 Hardware Pinout
------------------

The project simulates 4 home appliances using LEDs connected to the ESP32 GPIO pins:

**ComponentFunctionGPIO PinRed LED**Living Room LightGPIO 26**Green LED**Kitchen LightGPIO 27**Blue LED**Ceiling FanGPIO 14**Yellow LED**Porch LightGPIO 12

🚀 How to Run (Simulation)
--------------------------

You can run this project instantly without physical hardware using Wokwi.

1.  Open [Wokwi.com](https://wokwi.com/).
    
2.  Select **ESP32**.
    
3.  Copy the code from sketch.ino in this repo to the code editor.
    
4.  Copy the wiring configuration from diagram.json to the diagram tab.
    
5.  **Important:** To view the web page, you must install the [**Wokwi IoT Gateway**](https://docs.wokwi.com/guides/esp32-wifi#the-private-gateway) if you want to access it via your local browser localhost:8180.
    
    *   _Without the gateway, you can view the logic via the Serial Monitor logs._
        

💻 How to Run (Hardware)
------------------------

1.  Install the **Arduino IDE**.
    
2.  Install the **ESP32 Board Manager** in Arduino IDE preferences.
    
3.  Connect your ESP32 to your PC via USB.
    
4.  C++const char\* ssid = "YOUR\_WIFI\_NAME";const char\* password = "YOUR\_WIFI\_PASSWORD";
    
5.  Upload the code.
    
6.  Open the **Serial Monitor** (Baud Rate 115200) to find the ESP32's IP address (e.g., 192.168.1.15).
    
7.  Type that IP address into your web browser to access the dashboard.
    

📷 Screenshots
--------------

<img width="1904" height="967" alt="Image" src="https://github.com/user-attachments/assets/27048308-3199-47b0-a55a-c57c7f064a75" />

🔮 Future Improvements
----------------------

*   **Security:** Add a login page (Username/Password) to restrict access.
    
*   **Physical Hardware:** Replace LEDs with **Relay Modules** to control actual AC bulbs and fans.
    
*   **Sensors:** Add a DHT11 sensor to display temperature and humidity on the dashboard.
    
*   **Global Access:** Implement Port Forwarding or MQTT to control devices from outside the home network.
    

🤝 Contributing
---------------

Contributions are welcome! Please feel free to submit a Pull Request.
