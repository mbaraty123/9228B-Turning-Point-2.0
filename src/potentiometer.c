#include "potentiometer.h"

void potentiometerInit() {
  analogCalibrate(POTENTIOMETER_FLIPPER);
}


int flipperPosition() {
  return analogReadCalibrated(POTENTIOMETER_FLIPPER);
}

void printFlipper() {
  printf("%d\n", flipperPosition());
}
