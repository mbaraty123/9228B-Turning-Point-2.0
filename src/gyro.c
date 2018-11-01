#include "gyro.h"

static Gyro main_gyro;

bool init_main_gyro() {
  main_gyro = gyroInit(GYRO_PORT, GYRO_MULTIPLIER);
  return main_gyro != NULL;
}

int gyroGetA() {
  return gyroGet(main_gyro);
}

void gyroTurn(int degree) {
  if(gyroGetA() >= abs(degree - 180)) {
    while(gyroGetA() != degree) {
      robotSpin(counterclockwise);
    } 
  } else {
    while(gyroGetA() != degree) {
      robotSpin(clockwise);
    }
  }
}
