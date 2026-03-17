#ifndef MY_MATRIX_TOOLS_H
#define MY_MATRIX_TOOLS_H

#include "Arduino.h"

/**
 * @class MyMatrixTools
 * @brief Utility class for managing the Uno R4 WiFi 12x8 LED Matrix.
 */
class MyMatrixTools {
  public:
    MyMatrixTools();
    
    /** @brief Maps 2D coordinates to a 0-95 index. */
    int getLedIndex(uint8_t row, uint8_t col); 

    /** @brief Turns ON a specific LED by its absolute ID (0-95). */
    void setLedByIndex(uint8_t ledId); 

    /** @brief Turns ON a specific LED using 2D coordinates. */
    void setLed2D(uint8_t row, uint8_t col);
    
    /** @brief Turns OFF a specific LED by its absolute ID (0-95). */
    void removeLedByIndex(uint8_t ledId);

    /** @brief Turns OFF a specific LED using 2D coordinates. */
    void removeLed2D(uint8_t row, uint8_t col);

    /** @brief Wipes the entire frame (All LEDs OFF). */
    void clearFrame();

    /** @brief Returns pointer to the 96-bit frame buffer. */
    uint32_t* getFrame();

  private:
    uint32_t _frame[3];
};

#endif