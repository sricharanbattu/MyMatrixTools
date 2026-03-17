# MyMatrixTools
A high-level C++ wrapper for the **Arduino Uno R4 WiFi** LED Matrix (12x8).

This library simplifies pixel manipulation by providing 2D coordinate mapping and individual LED control, moving away from complex bitmasking.

## Features
* **2D Mapping:** Use `row` (0-7) and `col` (0-11) instead of bit indexes.
* **Absolute Indexing:** Access any LED via its unique ID (0-95).
* **Individual Control:** Set or Remove specific LEDs without affecting others.
* **Memory Efficient:** Uses bitwise operations on `uint32_t` arrays.

## Installation
1. Download this repository as a ZIP.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library**.
3. *Alternatively*: Extract to your `Documents/Arduino/libraries/` folder.

## Dependencies
* This library requires the official `Arduino_LED_Matrix.h` (pre-installed with the Uno R4 board package).

## Quick Start
```cpp
#include "Arduino_LED_Matrix.h"
#include "MyMatrixTools.h"

ArduinoLEDMatrix matrix;
MyMatrixTools tools;

void setup() {
  matrix.begin();
  tools.setLed2D(3, 5); // Row 3, Column 5
  matrix.loadFrame(tools.getFrame());
}