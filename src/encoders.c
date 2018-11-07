#include "encoders.h"

bool imeInit() {
  #ifdef IME_NUMBER
    int count = imeInitializeAll();
    if(count != IME_NUMBER) {
      printf("detected only %d\n", count);
      imeReset(0);
      return false;
    }
    imeReset(IME_FRONT_LEFT);
    imeReset(IME_FRONT_RIGHT);
    imeReset(IME_BACK_LEFT);
    imeReset(IME_BACK_RIGHT);
    return true;
  #else
    return imeInitializeAll()
  #endif
}

int imeGetTicks(const unsigned char address) {
  int i = 0;
  imeGet(address, &i);
  return i;
}

int imeGetVelocityA(const unsigned char address) {
  int i = 0;
  imeGetVelocity(address, &i);
  return i;
}

void imeMoveFor(int ticks, Direction dir) {
  if(dir == forward) {
    while(imeGetAverageTicks() <= ticks) {
      robotDriveStraight(forward);
    }
    robotStop();
  } else if(dir == reverse) {
    while(imeGetAverageTicks() >= ticks){
      robotDriveStraight(reverse);
      robotStop();
    }
  } else {
    robotStop();
  }
}

int imeGetAverageTicks() {
  return ((imeGetTicks(IME_FRONT_LEFT) + imeGetTicks(IME_FRONT_RIGHT) +
    imeGetTicks(IME_BACK_LEFT) + imeGetTicks(IME_FRONT_RIGHT)) / 4);
}

void imeResetAll() {
  imeReset(IME_FRONT_LEFT);
  imeReset(IME_FRONT_RIGHT);
  imeReset(IME_BACK_LEFT);
  imeReset(IME_BACK_RIGHT);
}
