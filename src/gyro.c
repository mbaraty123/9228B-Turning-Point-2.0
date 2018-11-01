#include "gyro.h"
#include "API.h"

static Gyro main_gyro;

bool init_main_gyro() {
  main_gyro = gyroInit(GYRO_PORT, GYRO_MULTIPLIER);
  return main_gyro != NULL;
}
