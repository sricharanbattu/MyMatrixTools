#include "Arduino_LED_Matrix.h"
#include "MyMatrixTools.h"

ArduinoLEDMatrix matrix;
MyMatrixTools myTools;

void setup() {
  matrix.begin();
}

void loop() {
  
  // This loop expands the square from the top-left corner to the bottom-right corner (only till 8 rows though).
  for(int i=0; i<8; i++){
    for(int j=0; j<=i; j++){
      myTools.setLed2D(i, j);
      myTools.setLed2D(j, i);
    }
    matrix.loadFrame(myTools.getFrame());
    delay(200);
  }

  // This loop contracts the square back to the top-left corner.
  for(int i=7; i>=0; i--){
    for(int j=0; j<=i; j++){
      myTools.removeLed2D(i, j);
      myTools.removeLed2D(j, i);
    }
    matrix.loadFrame(myTools.getFrame());
    delay(200);
  }
   
}