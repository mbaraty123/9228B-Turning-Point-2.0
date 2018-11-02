#include "encoders.h"

static bool encoders_initialized = false;

bool imeInit() {
  #ifdef IME_NUMBER
    int count = imeInitializeAll();
    if(count != IME_NUMBER) {
      printf("detected only %d\n", count);
      imeReset(0);
      return false;
    }
    imeReset(0);
    imeReset(1);
    imeReset(2);
    imeReset(3);
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
