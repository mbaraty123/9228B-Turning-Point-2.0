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
    while(true) {
      if(imeGetAverageTicks() <= ticks) {
        robotDriveStraight(forward);
      }
  }
} else if(dir == reverse) {
    while(imeGetAverageTicks() >= ticks){
      robotDriveStraight(reverse);
    }
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
/*
void driveDistance(int distance, int speed, void (*functionPtr)(int),
                           void (*start_function)(void *)) {
  //int initial = ime_get_average(false);
  TaskHandle task;
  if (start_function != NULL) {
    task = taskCreate(start_function, TASK_DEFAULT_STACK_SIZE, NULL,
                      TASK_PRIORITY_DEFAULT);
  }

  int initial = imeGetAverageTicks();

  while(abs(imeGetAverageTicks() - initial) < distance){
    robotDriveForward();
    printf("%d", abs(imeGetAverageTicks()));
    wait(30);
  }
  robotStop();

}*/
