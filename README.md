# Multi Segment Display
![image](https://github.com/user-attachments/assets/752496d7-2365-4362-8190-8187fe7c8f44)
## Overview

This project involves reverse-engineering and re-purposing a unique multi-segment display salvaged from disposable vaping devices. The display features **6 numeric digits** and **6 info segments**, driven by just **7 pins**, making it both cost-effective and innovative.

## Background

### Discovery
The display was discovered in a disposable vaping device. Upon closer inspection, its compact design and creative implementation intrigued me. Instead of discarding these devices, I salvaged their displays and batteries for reuse in various projects. With 5+ units at hand, the possibilities were exciting!

### Reverse Engineering
Initially, I de-soldered the display and connected jumper wires to explore its behavior. Despite having 32 segments, it only utilizes **7 pins**, where each pin can act as **both ground and voltage**, depending on the configuration. I mapped all the high/low combinations to control each segment effectively.

---

## Coding and Development

### Initial Testing
Using the **Arduino IDE**, I started with basic functionality tests. After completing the initial tests, the project was migrated to **PlatformIO** for better project management. Several utility functions were developed for seamless control of the display.

### Advanced Usage
Once the basic functionalities were implemented, I brainstormed potential applications. The idea that stood out was to use the display to show **system information** (e.g., CPU, RAM, and battery levels) from a connected PC. 

---

## Application Design

### Concept
The display connects to a PC via an **Arduino** and shows critical system information:
- **Left numeric segments:** CPU usage percentage.
- **Right numeric segments:** RAM usage percentage.
- **Battery indicator:** Displays charge level.
  - **Red:** Below 30%.
  - **Orange:** Between 30%-70%.
  - **Green:** Above 70%.
- **Liquid segment:** Indicates charging status.
  - **Red:** Not plugged in.
  - **Green:** Plugged in.

![image](https://github.com/user-attachments/assets/f1f26913-a7dc-4236-9244-ab55e2153024)

![image](https://github.com/user-attachments/assets/514f963f-8f68-464b-baa7-8867f7c04475)

The display alternates between showing CPU/RAM usage and battery status depending on the system's state.

### Implementation
The Arduino communicates with the PC via a **Python script** that gathers system information (CPU, RAM, battery) and sends it over **serial communication**. The Arduino code interprets this data and updates the display.

Pins used for the display:
- **D2 to D8**: Selected to avoid conflicts with UART, SPI, and I2C connections, ensuring compatibility with other features.
- The **D2** pin should be connected to the rightmost pin of the display, and the **D8** pin should be connected to the leftmost pin. The other pins should be arranged in order.

---

## Performance Notes

### Refresh Rates
To maintain a stable display, segments must be refreshed at least every **5-10 milliseconds**. Beyond 10 milliseconds, flickering becomes noticeable. A custom `keepAlive()` function ensures the display is refreshed within **0.3 milliseconds**, maintaining clarity and stability.

### Interrupts
While initially exploring interrupt-based refreshing, timer conflicts disrupted communication protocols, leading to instability. The current implementation avoids interrupts for simplicity and reliability.

---

## Usage Instructions

1. **Setup**:
   - Upload the Arduino code to the microcontroller.
   - Connect the display to pins **D2 to D8**.
   - Run the `cpu-ram.py` script on your PC (update the COM port if necessary).

2. **Python Script**:
   - The script gathers system data using **psutil** and sends it to the Arduino over serial communication.
   - Compatible with Windows systems (requires testing on other platforms).

3. **Warning**:
   - Ensure the display refreshes frequently to avoid flickering or dimming. Use the `keepAlive()` function as needed.

---

## Technical Notes

- **Weird Baudrate**: The baud rate was chosen for optimal speed and reliability. Flickering screens were avoided by testing multiple baud rates to find the best match.
- **Segment Switching**: The display relies on rapid segment switching to present data. This unique design limits its standalone applications but shines in dynamic setups.

---

## Salvaged Components

- **Display**: Multi-segment, 7-pin.
- **Battery**: LiPo cells from the vaping devices, reusable for other projects.

---

## Known Limitations

- The project is heavily dependent on fast refresh rates.
- Interrupt-driven refresh caused issues with serial communication.
- Python script is tested only on Windows; compatibility with Linux/Mac needs verification.

---

## Future Plans
- Integrate with more advanced systems like Raspberry Pi or ESP32 for additional functionality.
- Create a compact PCB for easier wiring and portability.
- Explore potential use cases in other small projects that require simple, efficient displays.

---

## Note
There is a half-way completed **C++ implementation**, which is not fully tested. It will be completed and later used as a library for the **Arduino IDE**.

## Another Note
Due to compatibility reasons, the file extensions are .cpp, but the code is written in C and is fully compatible with C.


