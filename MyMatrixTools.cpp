#include "MyMatrixTools.h"

MyMatrixTools::MyMatrixTools() {
  clearFrame();
}

void MyMatrixTools::clearFrame() {
  _frame[0] = 0; _frame[1] = 0; _frame[2] = 0;
}

int MyMatrixTools::getLedIndex(uint8_t row, uint8_t col) {
  if (row >= 8 || col >= 12) return -1; 
  return (row * 12) + col;
}

void MyMatrixTools::setLedByIndex(uint8_t ledId) {
  if (ledId >= 96) return;
  int arrayIdx = ledId / 32;
  int bitShift = 31 - (ledId % 32);
  _frame[arrayIdx] |= (1UL << bitShift); // OR sets to 1
}

// Logic to turn off a specific bit
void MyMatrixTools::removeLedByIndex(uint8_t ledId) {
  if (ledId >= 96) return;
  int arrayIdx = ledId / 32;
  int bitShift = 31 - (ledId % 32);
  _frame[arrayIdx] &= ~(1UL << bitShift); // AND-NOT sets to 0
}

void MyMatrixTools::setLed2D(uint8_t row, uint8_t col) {
  int id = getLedIndex(row, col);
  if (id != -1) setLedByIndex((uint8_t)id);
}

void MyMatrixTools::removeLed2D(uint8_t row, uint8_t col) {
  int id = getLedIndex(row, col);
  if (id != -1) removeLedByIndex((uint8_t)id);
}

uint32_t* MyMatrixTools::getFrame() {
  return _frame;
}